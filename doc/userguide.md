E-MailRelay User Guide
======================

What is it?
-----------
E-MailRelay is an e-mail store-and-forward message transfer agent and proxy
server. It runs on Unix-like operating systems (including Linux and Mac OS X),
and on Windows.

E-MailRelay does three things: it stores any incoming e-mail messages that
it receives, it forwards e-mail messages on to another remote e-mail server,
and it serves up stored e-mail messages to local e-mail reader programs. More
technically, it acts as a [SMTP][] storage daemon, a SMTP forwarding agent, and
a POP3 server.

Whenever an e-mail message is received it can be passed through a user-defined
program, such as a spam filter, which can drop, re-address or edit messages as
they pass through.

![whatisit.png](whatisit.png)

E-MailRelay uses the same non-blocking i/o model as Squid and nginx giving
excellent scalability and resource usage.

C++ source code is available and distribution is permitted under the GNU
General Public License V3.

What it's not
-------------
E-MailRelay does not do routing of individual messages; it is not a routing [MTA][].
It forwards all e-mail messages to a pre-configured SMTP server, regardless of
any message addressing or DNS redirects.

Why use it?
-----------
E-MailRelay is a simple tool that does SMTP. For simple tasks it is likely
to be easier to understand and configure than a more general purpose MTA.

Typical applications of E-MailRelay include:

* spam filtering and virus checking incoming mail
* adding digital signatures or legal disclaimers to outgoing mail
* store-and-forward for outgoing mail across an intermittent internet connection
* adding authentication and encryption where the existing infrastructure does not support it
* taking messages in with SMTP and serving them to local [POP][] clients
* giving multiple POP clients independent copies of incoming e-mail
* SMTP proxying by running as a proxy server on a firewall machine

The code has few dependencies on third-party libraries or run-time environments
so it is easy to build and install.

E-MailRelay is designed to be policy-free, so that you can implement your own
policies for message retries, bounces, local mailbox delivery, spam filtering
etc. through external scripts.

Running E-MailRelay
-------------------
To use E-MailRelay in store-and-forward mode use the `--as-server` option to
start the storage daemon in the background, and then do delivery of spooled
messages by running with the `--as-client` option.

![serverclient.png](serverclient.png)

For example, to start a storage daemon listening on port 587 use a command
like this:

        emailrelay --as-server --port 587 --spool-dir /tmp

And then to forward the spooled mail to `smtp.example.com` run something
like this:

        emailrelay --as-client smtp.example.com:25 --spool-dir /tmp

To get behaviour more like a proxy you can add the `--poll` and `--forward-to`
options so that messages are forwarded continuously rather than on-demand.

![forwardto.png](forwardto.png)

This example starts a store-and-forward server that forwards spooled-up e-mail
every minute:

        emailrelay --as-server --poll 60 --forward-to smtp.example.com:25

Or for a proxy server that forwards each message soon after it has been
received, you can use `--as-proxy` or add `--forward-on-disconnect`:

        emailrelay --as-server --forward-on-disconnect --forward-to smtp.example.com:25

To edit or filter e-mail as it passes through the proxy specify your filter
program with the `--filter` option, something like this:

        emailrelay --as-proxy smtp.example.com:25 --filter addsig.js

To run E-MailRelay as a POP server without SMTP use `--pop` and `--no-smtp`:

        emailrelay --pop --no-smtp --log --close-stderr

The `emailrelay-submit` utility can be used to put messages straight into the
spool directory so that the POP clients can fetch them.

By default E-MailRelay will always reject connections from remote networks. To
allow connections from anywhere use the `--remote-clients` option, but please
check your firewall settings to make sure this cannot be exploited by spammers.

For more information on the command-line options refer to the reference guide
or run:

        emailrelay --help --verbose

Configuration
-------------
The `emailrelay` program itself is mostly configured through command-line
options (such as `--port` and `--forward-to`).

In most installations on Unix-like system the E-MailRelay server will be
started up by the boot-time script called `emailrelay` in the `/etc/init.d`
directory, and this script uses the configuration file `/etc/emailrelay.conf` to
define the server command-line. Each entry in the configuration file corresponds
to an E-MailRelay command-line option, so you can edit this file to add and
remove server options. Refer to the reference guide for a complete list of
configuration options.

On Windows the installation program creates a startup batch file called
`emailrelay-start.bat` that contains all the server command-line options and
you can edit this file to change the server configuration. You can also set up
your own shortcuts to the E-MailRelay executable and add and remove command-line
options using the shortcut properties tab.

If you are using authentication then you will have to create the text files
containing your authentication secrets (account names, passwords and password
hashes). The `--server-auth`, `--client-auth` and `--pop-auth` command-line
options are used to point to these files.

There is also a graphical configuration program called `emailrelay-gui` that
may be available to help with configuring the system. This is mostly intended
to be used once at installation time since it is the basis of the Windows
installer, but it can also be used to do some simple reconfiguration of an
already-installed system. It takes you through a sequence of configuration
pages and then on the last page creates or updates the configuration files, ie.
the authentication secrets file and the configuration file `emailrelay.conf`
or `emailrelay-start.bat`.

Logging
-------
If the `--log` option is used then E-MailRelay program sends warnings and error
messages to its standard error stream, and to the `syslog` system on Unix or
to the Event Viewer on Windows.

The standard error stream logging can be redirected to a file by using the
`--log-file` option, and daily log files can be created by using `%d` in the
filename.

For more verbose logging add the `--verbose` option to the command-line.

Preventing open mail relay
--------------------------
If you are running E-MailRelay as a server with a permanent connection to the
internet it is important to prevent open mail relay because this can be
exploited by spammers and get you into trouble with your ISP. By default open
mail relaying is not possible because E-MailRelay does not accept IP connections
from remote clients. However, if you use the `--remote-clients` option then you
need to be more careful.

If the only required access to the E-MailRelay server is from a local network
and not from the internet then just set up your firewall to block incoming
connections on ports 25 (SMTP) and 110 (POP) and also use the `--interface`
option on the E-MailRelay command-line so that it only listens for incoming
connections on the local network.

If you do need to accept connections from the internet then you should require
all clients to authenticate themselves by using the `--server-auth` option on
the E-MailRelay command-line. If you also want local clients running on your
internal network to be able to bypass this authentication then you can put those
trusted IP addresses in the E-MailRelay secrets file with an authentication
mechanism of `none`. Refer to the reference guide for more information.

Running as a POP server
-----------------------
E-MailRelay can run as a POP server so that e-mail client programs can retrieve
messages from the E-MailRelay spool directory directly.

To allow POP access to spooled messages use a command-line something like this:

        emailrelay --as-server --pop --pop-auth=/etc/pop.auth

You will need to create the authentication secrets file (`pop.auth` in this
example) containing usernames and passwords. A simple example would look
like this:

        server plain user1 password1
        server plain user2 password2

It can sometimes be useful to serve up the same e-mail messages to multiple POP
clients. For example, you might use several e-mail clients on your local network
and you would like to see your mail on all of them equally. The `--pop-by-name`
option is intended to be used in this scenario; each e-mail client sees its own
copy of the e-mail messages, stored in its own sub-directory of the main spool
directory. The name of the sub-directory is simply the name that the client uses
to authenticate with the E-MailRelay server. You just need to create the
sub-directory for each client and then specify `emailrelay-filter-copy`
as the E-MailRelay `--filter` program.

Refer to the documentation of the various `--pop` command-line options for
more detail: `--pop`, `--pop-port`, `--pop-auth`, `--pop-no-delete` and
`--pop-by-name`.

Triggering delivery
-------------------
If you are using E-MailRelay on Unix to store and forward e-mail over an
intermittent link to the internet such as dial-up or wireless networking, then
you might need to set things up so that the network tells E-MailRelay when to
start forwarding e-mail.

On Linux systems you should find that there are special directories where you
can install your own hook scripts that are called whenever a dial-up or wireless
network connection is established. For dial-up this might be `/etc/ppp/ip-up.d`,
and for wireless `/etc/network/if-up.d`.

Just create a two-line script like this in the relevant directory:

        #!/bin/sh
        exec /usr/local/sbin/emailrelay --as-client=smtp.example.com:smtp

and make it executable using `chmod +x`.

Failed e-mails
--------------
If e-mail messages cannot be forwarded by the E-MailRelay system then the
envelope files in the spool directory are given a `.bad` suffix. The reason for
the failure will be recorded in the envelope file itself.

You should check for `.bad` envelope files in the E-MailRelay spool directory
from time to time. If you want them to be retried next time then just remove
the `.bad` filename suffix.

You can run the `emailrelay-resubmit` script periodically to automate this; it
removes the `.bad` suffix from files in the spool directory as long as they
have not been retried too many times already.

Usage patterns
--------------
The simplest ways of using E-MailRelay for SMTP are to run it as a proxy or to
do store-and-forward, but many other configurations are possible. For example,
multiple E-MailRelay servers can run in parallel sharing the same spool
directory, or they can be chained in series to that e-mail messages get
transferred from one to the next.

Remember that messages can be introduced directly into the E-MailRelay spool
directory using the `emailrelay-submit` utility, and they can be moved out again
at any time, as long as the envelope file is not locked (ie. with a special
filename extension). Your `--filter` program can edit messages in any way you
want, and it can even delete the current message from the spool directory.

When using E-MailRelay as a POP server the `--pop-by-name` feature can be used
to serve up different spooled messages according to the username that the
client authenticated with. Rather than use `emailrelay-filter-copy` to
distribute incoming e-mail messages into all subdirectories you could use a
custom script to do it based on the message addressing.

The POP server can also be used for checking e-mails that are taken out of the
normal store-and-forward flow. For example, a `--filter` script that checks for
spam could move suspicious e-mails into a subdirectory of the spool directory
that is accessible via the `--pop-by-name` feature.

Rate limiting
-------------
If you need to slow the rate at which e-mails are forwarded you can use a
`--client-filter` program to introduce a delay. On Windows this JavaScript
program would give you a delay of a minute:

        WScript.Sleep( 60000 ) ;
        WScript.Quit( 0 ) ;

However, this can cause timeouts at the server, so a better approach is to use
`--client-filter exit:102` so that only one e-mail message is forwarded on each
polling cycle, and then use `--poll 60` to limit it to one e-mail per minute.

SpamAssassin
------------
The E-MailRelay server can use [SpamAssassin](http://spamassassin.apache.org)
to mark or reject potential spam.

It's easiest to run SpamAssassin's `spamd` program in the background and let
E-MailRelay send incoming messages to it over the network. By default
SpamAssassin `spamd` uses port 783 so you should use an E-MailRelay
command-line option of `--filter spam-edit:127.0.0.1:783` if you want spam
messages to pass through with a warning added, or `--filter spam:127.0.0.1:783`
if you want spam messages to be rejected outright.

Alternatively you can run SpamAssassin on demand for each message. To get
E-MailRelay to reject spam outright you can just use `spamassassin -e` as
your E-MailRelay `--filter` program:

        emailrelay --as-server --filter="/usr/bin/spamassassin -e"

Or on Windows:

        emailrelay --as-server --filter="c:/perl/site/bin/spamassassin.bat -e"

To get spam messages identified by SpamAssassin but still pass through the
E-MailRelay system you will have to have a small `--filter` script to collect
the output from the `spamassassin` program and write it back into the
E-MailRelay content file.

On Unix your `--filter` shell script could look something like this:

        #!/bin/sh
        spamassassin "$1" > "$1.tmp"
        mv "$1.tmp" "$1"
        exit 0

On Windows an equivalent batch script would be:

        c:\perl\site\bin\spamassassin.bat %1 > %1.tmp
        ren %1.tmp %1
        exit 0

Google mail
-----------
To send mail via Google mail's SMTP gateway you will need to create a client
secrets file containing your account details and also enable [TLS][] support in
E-MailRelay by using the `--client-tls` option.

The secrets file should contain one line of text something like this:

        client plain myname@gmail.com my+20password

If your password contains a space, equals or plus sign, or any control
character then you will need to replace those characters with their
corresponding hexadecimal ascii value, something like `+20` or `+2B`.

Refer to your secrets file by using `--client-auth` on the E-MailRelay
command-line, and also add in the `--client-tls` option:

        emailrelay --as-proxy=smtp.gmail.com:587 --client-tls --client-auth=/etc/emailrelay.auth ...

Connection tunnelling
---------------------
E-MailRelay can send mail out via a [SOCKS][] v4 proxy, which makes it easy to route
your mail through an encrypted tunnel created by `ssh -N -D` or via the Tor
anonymising network.

For example, this will run an E-MailRelay proxy on port 587 that routes via a
local Tor server on port 9050 to the mail server at smtp.example.com:

        emailrelay --port 587 --as-proxy=smtp.example.com:25@localhost:9050 --domain=anonymous.net --anonymous --connection-timeout=300

Blocklists and dynamic firewalls
--------------------------------
E-MailRelay can consult with remote [DNSBL][] blocklist servers in order to block
incoming connections from known spammers. Refer to the documentation of the
`--dnsbl` option for more details.

It is also possible to integrate E-MailRelay with intrusion detection systems
such as `fail2ban` that monitor log files and dynamically modify your iptables
firewall. Use E-MailRelay's `--log-address` command-line option so that the
remote IP address of any badly-behaved remote user is logged and made available
to `fail2ban`.





[DNSBL]: https://en.wikipedia.org/wiki/DNSBL
[MTA]: https://en.wikipedia.org/wiki/Message_transfer_agent
[POP]: https://en.wikipedia.org/wiki/Post_Office_Protocol
[SMTP]: https://en.wikipedia.org/wiki/Simple_Mail_Transfer_Protocol
[SOCKS]: https://en.wikipedia.org/wiki/SOCKS
[TLS]: https://en.wikipedia.org/wiki/Transport_Layer_Security

_____________________________________
Copyright (C) 2001-2021 Graeme Walker
