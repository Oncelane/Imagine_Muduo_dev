# 编译server
g++ test_server.cpp -I ../include -I ../thirdparty/Imagine_Tool/Imagine_Log/include -I ../thirdparty/Imagine_Tool/Imagine_Time/include -I ../thirdparty/Imagine_Tool/thirdparty/yaml-cpp/include -L../lib/ -limagine_muduo -limagine_tool -limagine_time -lyaml-cpp -o test_server -Wl,-rpath,./../lib/

# 编译client
g++ test_client.cpp -o test_client