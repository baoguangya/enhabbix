# enhabbix
Enhanced version of Zabbix 5.0

parameters  | original range | expanded range
------------|----------------|----------------
CacheSize|128K-8G|128K-32G
HistoryCacheSize|128K-2G|128K-8G
HistoryIndexCacheSize|128K-2G|128K-8G
TrendCacheSize|128K-2G|128K-8G
ValueCacheSize|0,128K-64G|0,128K-256G
VMwareCacheSize|256K-2G|256K-8G


parameters  | original range | expanded range
------------|----------------|----------------
StartAlerters|1-100|1-1000
StartDBSyncers|1-100|1-1000
StartDiscoverers|0-250|0-2500
StartEscalators|1-100|1-1000
StartHTTPPollers|0-1000|0-10000
StartIPMIPollers|0-1000|0-10000
StartJavaPollers|0-1000|0-10000
StartLLDProcessors|1-100|1-1000
StartPingers|0-1000|0-10000
StartPollers|0-1000|0-10000
StartPollersUnreachable|0-1000|0-10000
StartPreprocessors|1-1000|1-10000
StartProxyPollers|0-250|0-2500
StartTimers|1-1000|1-10000
StartTrappers|0-1000|0-10000
StartVMwareCollectors|0-250|0-2500
