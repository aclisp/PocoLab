PocoLab
=======

It is a C++ HTTP server based on POCO C++ Libraries. This project is obsolete. New C++ projects should start with Qt. However we should never think of starting a project in C++, right? Go or Rust is the preferable options.

Performance Monitor
-------------------

* Curve
  - threadpool.capacity (max)
  - threadpool.used
  - threadpool.allocated
  - threadpool.available
  - server.currentThreads
  - server.currentConnections


* Curve 
  - server.maxQueued (max)
  - server.queuedConnections

* Counter
  - server.totalConnections
  - server.refusedConnections

* High water mark
  - server.maxConcurrentConnections

