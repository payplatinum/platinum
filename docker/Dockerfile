FROM ubuntu:16.04
COPY qtbase.patch /opt/
COPY compile-db.sh /opt/
COPY compile-m.sh /opt/

RUN \
     apt-get -qq update && apt-get -qq install lzip git p7zip-full autoconf automake autopoint \
           bash bison bzip2 cmake flex gettext git g++ gperf intltool libffi-dev libtool libltdl-dev \ 
           libssl-dev libxml-parser-perl make openssl patch perl pkg-config python ruby scons sed unzip wget xz-utils \
    g++-multilib \
    libc6-dev-i386 \
    libgdk-pixbuf2.0-dev \
    libtool-bin  
RUN    cd /opt/ && git clone https://github.com/payplatinum/platinum.git && git clone https://github.com/mxe/mxe.git   && \
    cd /opt/mxe && git apply --ignore-space-change --ignore-whitespace /opt/qtbase.patch
RUN cd /opt && wget -nv http://download.oracle.com/berkeley-db/db-5.3.28.tar.gz && tar zxf db-5.3.28.tar.gz && cp /opt/compile-db.sh db-5.3.28/ && chmod ugo+x db-5.3.28/compile-db.sh
RUN cd /opt && wget -nv http://miniupnp.free.fr/files/miniupnpc-1.6.20120509.tar.gz && tar zxf miniupnpc-1.6.20120509.tar.gz && cp /opt/compile-m.sh miniupnpc-1.6.20120509/ && chmod ugo+x miniupnpc-1.6.20120509/compile-m.sh
RUN cd /opt/mxe && make openssl1.0 MXE_PLUGIN_DIRS=plugins/examples/openssl1.0/ 

RUN cd /opt/mxe && make MXE_TARGETS="i686-w64-mingw32.static" boost 
RUN cd /opt/mxe && make MXE_TARGETS="i686-w64-mingw32.static" qttools
RUN cd /opt/db-5.3.28 && cp /opt/compile-db.sh /opt/db-5.3.28/ && ./compile-db.sh
RUN cd /opt/miniupnpc-1.6.20120509 && cp /opt/compile-m.sh /opt/miniupnpc-1.6.20120509/ && ./compile-m.sh
COPY compile-win.sh /opt/
RUN cd /opt/platinum/ && cp /opt/compile-win.sh /opt/platinum/ && git checkout delete-bittrex
RUN cd /opt/platinum/src/leveldb/ && export MXE_PATH=/opt/mxe && TARGET_OS=NATIVE_WINDOWS CC=$MXE_PATH/usr/bin/i686-w64-mingw32.static-gcc CXX=$MXE_PATH/usr/bin/i686-w64-mingw32.static-g++ make -j12 libleveldb.a libmemenv.a
RUN cd /opt/platinum/src/secp256k1 && export MXE_PATH=/opt/mxe &&  export PATH=$MXE_PATH/usr/bin:$PATH  && ./autogen.sh && \
                 ./configure HAVE_DLFCN_H=0 HAVE_LIBCRYPTO=0 HAVE_LIBGMP=0 USE_FIELD_INV_BUILTIN=1 USE_FIELD_INV_NUM=0 USE_NUM_GMP=0 USE_NUM_NONE=1 \
                 USE_SCALAR_INV_BUILTIN=1 USE_SCALAR_INV_NUM=0 --enable-module-recovery=yes --enable-openssl-tests=no --enable-static --disable-shared \
                  --prefix=$MXE_PATH/usr/i686-w64-mingw32.static --host=i686-w64-mingw32.static  
RUN cd /opt/platinum/src/secp256k1 && export MXE_PATH=/opt/mxe && export PATH=$MXE_PATH/usr/bin:$PATH && make 
RUN cd /opt/platinum/ && export MXE_PATH=/opt/mxe && export PATH=$MXE_PATH/usr/bin:$PATH && bash /opt/platinum/compile-win.sh
RUN ls -la /opt/platinum/release/Platinum-qt.exe

ENTRYPOINT ["bash"] 
