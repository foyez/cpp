FROM alpine:latest

# Install dependencies
RUN apk update && apk add --no-cache \
    valgrind \
    gcc g++ make \
    lsof \
    vim git \
    coreutils grep

# To make shell colorful
RUN git config --global color.ui auto && \
    git config --global color.status auto && \
    git config --global color.branch auto && \
    git config --global color.diff auto && \
    echo "alias ls='ls --color=auto'" >> /root/.profile && \
    echo "alias grep='grep --color=auto'" >> /root/.profile && \
    echo 'export PS1="\033[1;32m\u@\h\033[0m:\033[1;34m\w\033[0m\\$ "' >> /root/.profile

CMD ["sh", "-l"]