Sample init scripts and service configuration for CB AI COINd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/CB AI COINd.service:    systemd service unit configuration
    contrib/init/CB AI COINd.openrc:     OpenRC compatible SysV style init script
    contrib/init/CB AI COINd.openrcconf: OpenRC conf.d file
    contrib/init/CB AI COINd.conf:       Upstart service configuration file
    contrib/init/CB AI COINd.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "CB AI COIN" user
and group.  They must be created before attempting to use these scripts.
The macOS configuration assumes CB AI COINd will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, CB AI COINd requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, CB AI COINd will shut down promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that CB AI COINd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If CB AI COINd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running CB AI COINd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `share/examples/CB AI COIN.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/CB AI COINd`
Configuration file:  `/etc/CB AI COIN/CB AI COIN.conf`
Data directory:      `/var/lib/CB AI COINd`
PID file:            `/var/run/CB AI COINd/CB AI COINd.pid` (OpenRC and Upstart) or `/run/CB AI COINd/CB AI COINd.pid` (systemd)
Lock file:           `/var/lock/subsys/CB AI COINd` (CentOS)

The PID directory (if applicable) and data directory should both be owned by the
CB AI COIN user and group. It is advised for security reasons to make the
configuration file and data directory only readable by the CB AI COIN user and
group. Access to CB AI COIN-cli and other CB AI COINd rpc clients can then be
controlled by group membership.

NOTE: When using the systemd .service file, the creation of the aforementioned
directories and the setting of their permissions is automatically handled by
systemd. Directories are given a permission of 710, giving the CB AI COIN group
access to files under it _if_ the files themselves give permission to the
CB AI COIN group to do so (e.g. when `-sysperms` is specified). This does not allow
for the listing of files under the directory.

NOTE: It is not currently possible to override `datadir` in
`/etc/CB AI COIN/CB AI COIN.conf` with the current systemd, OpenRC, and Upstart init
files out-of-the-box. This is because the command line options specified in the
init files take precedence over the configurations in
`/etc/CB AI COIN/CB AI COIN.conf`. However, some init systems have their own
configuration mechanisms that would allow for overriding the command line
options specified in the init files (e.g. setting `BITCOIND_DATADIR` for
OpenRC).

### macOS

Binary:              `/usr/local/bin/CB AI COINd`
Configuration file:  `~/Library/Application Support/CB AI COIN/CB AI COIN.conf`
Data directory:      `~/Library/Application Support/CB AI COIN`
Lock file:           `~/Library/Application Support/CB AI COIN/.lock`

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start CB AI COINd` and to enable for system startup run
`systemctl enable CB AI COINd`

NOTE: When installing for systemd in Debian/Ubuntu the .service file needs to be copied to the /lib/systemd/system directory instead.

### OpenRC

Rename CB AI COINd.openrc to CB AI COINd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/CB AI COINd start` and configure it to run on startup with
`rc-update add CB AI COINd`

### Upstart (for Debian/Ubuntu based distributions)

Upstart is the default init system for Debian/Ubuntu versions older than 15.04. If you are using version 15.04 or newer and haven't manually configured upstart you should follow the systemd instructions instead.

Drop CB AI COINd.conf in /etc/init.  Test by running `service CB AI COINd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy CB AI COINd.init to /etc/init.d/CB AI COINd. Test by running `service CB AI COINd start`.

Using this script, you can adjust the path and flags to the CB AI COINd program by
setting the BITCOIND and FLAGS environment variables in the file
/etc/sysconfig/CB AI COINd. You can also use the DAEMONOPTS environment variable here.

### macOS

Copy org.CB AI COIN.CB AI COINd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.CB AI COIN.CB AI COINd.plist`.

This Launch Agent will cause CB AI COINd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run CB AI COINd as the current user.
You will need to modify org.CB AI COIN.CB AI COINd.plist if you intend to use it as a
Launch Daemon with a dedicated CB AI COIN user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
