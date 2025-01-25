*After branching off for a major version release of CI AI COIN Core, use this
template to create the initial release notes draft.*

*The release notes draft is a temporary file that can be added to by anyone. See
[/doc/developer-notes.md#release-notes](/doc/developer-notes.md#release-notes)
for the process.*

*Create the draft, named* "*version* Release Notes Draft"
*(e.g. "0.20.0 Release Notes Draft"), as a collaborative wiki in:*

https://github.com/CI AI COIN-core/CI AI COIN-devwiki/wiki/

*Before the final release, move the notes back to this git repository.*

*version* Release Notes Draft
===============================

CI AI COIN Core version *version* is now available from:

  <https://CI AI COINcore.org/bin/CI AI COIN-core-*version*/>

This release includes new features, various bug fixes and performance
improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/CI AI COIN/CI AI COIN/issues>

To receive security and update notifications, please subscribe to:

  <https://CI AI COINcore.org/en/list/announcements/join/>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over `/Applications/CI AI COIN-Qt` (on Mac)
or `CI AI COINd`/`CI AI COIN-qt` (on Linux).

Upgrading directly from a version of CI AI COIN Core that has reached its EOL is
possible, but it might take some time if the datadir needs to be migrated. Old
wallet versions of CI AI COIN Core are generally supported.

Compatibility
==============

CI AI COIN Core is supported and extensively tested on operating systems using
the Linux kernel, macOS 10.10+, and Windows 7 and newer. It is not recommended
to use CI AI COIN Core on unsupported systems.

CI AI COIN Core should also work on most other Unix-like systems but is not
as frequently tested on them.

From CI AI COIN Core 0.17.0 onwards, macOS versions earlier than 10.10 are no
longer supported, as CI AI COIN Core is now built using Qt 5.9.x which requires
macOS 10.10+. Additionally, CI AI COIN Core does not yet change appearance when
macOS "dark mode" is activated.

In addition to previously supported CPU platforms, this release's pre-compiled
distribution provides binaries for the RISC-V platform.

Notable changes
===============

New RPCs
--------

New settings
------------

Updated settings
----------------

Updated RPCs
------------

Note: some low-level RPC changes mainly useful for testing are described in the
Low-level Changes section below.

GUI changes
-----------

Wallet
------

- The wallet now by default uses bech32 addresses when using RPC, and creates native segwit change outputs.

Low-level changes
=================

Tests
-----

- `-fallbackfee` was 0 (disabled) by default for the main chain, but 0.0002 by default for the test chains. Now it is 0
  by default for all chains. Testnet and regtest users will have to add `fallbackfee=0.0002` to their configuration if
  they weren't setting it and they want it to keep working like before. (#16524)

Credits
=======

Thanks to everyone who directly contributed to this release:


As well as to everyone that helped with translations on
[Transifex](https://www.transifex.com/CI AI COIN/CI AI COIN/).
