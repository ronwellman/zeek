
include(ZeekPlugin)

include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

zeek_plugin_begin(Zeek BenchmarkReader)
zeek_plugin_cc(Benchmark.cc Plugin.cc)
zeek_plugin_bif(benchmark.bif)
zeek_plugin_end()
