FROM ghcr.io/retlek-systems-inc/rs_cmake/sw-arm-none-eabi:latest

# Add the SVD files for STM32
RUN mkdir -p /usr/local
WORKDIR /usr/local
RUN git clone https://github.com/Marus/cortex-debug-dp-stm32l4.git


# Install the stlink util
WORKDIR /usr/local
RUN apt update
RUN apt install -y libusb-1.0-0-dev && \
    apt install -y libncurses-dev && \
    apt install -y screen && \
    apt install -y libtool && \
    apt install -y pkg-config && \
    apt install -y autoconf && \
    apt install -y automake && \
    apt install -y texinfo && \
    apt install -y libgtk-3-dev && \
    apt install -y make && \
    apt install -y gdb

RUN git clone https://github.com/stlink-org/stlink \
    && cd stlink \
    && git checkout v1.8.0 \
    && make clean \
    && make release \
    && make install \
    && mkdir -p /etc/udev/rules.d \
    && cp config/udev/rules.d/49-stlinkv* /etc/udev/rules.d/ \
    && cd ..

RUN apt install -y gdb

ARG USERNAME
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Check if a user with UID 1000 exists and remove it
RUN if id -u $USER_GID >/dev/null 2>&1; then \
        existing_user=$(getent passwd $USER_GID | cut -d: -f1) && \
        userdel -r $existing_user; \
    fi

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt update \
    && apt install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME
    
# Add the user to the dialout group - needed to access the USB serial device for UART
RUN usermod -a -G dialout $USERNAME

ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8