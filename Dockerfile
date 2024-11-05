########################################################################################################################
# SB build stage
########################################################################################################################
FROM alpine:3.17.0 AS build

RUN apk update && \
    apk add --no-cache \
        build-base \
        cmake

WORKDIR /SB

COPY include/ ./include/
COPY src/ ./src/
COPY CMakeLists.txt .

WORKDIR /SB/build

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8

########################################################################################################################
# SB image
########################################################################################################################
FROM alpine:3.17.0

RUN apk update && \
    apk add --no-cache \
    libstdc++=12.2.1_git20220924-r4

RUN addgroup -S sbs && adduser -S sbs -G sbs
USER sbs

COPY --from=build \
    /SB/build/sb \
    /usr/local/bin/sb

ENTRYPOINT [ "./usr/local/bin/sb" ]