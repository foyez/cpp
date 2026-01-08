FROM debian:bookworm-slim

# Set environment variables for ZSH with absolute path
ENV ZSH="/root/.oh-my-zsh"
ENV ZSH_CUSTOM="$ZSH/custom"

RUN apt-get update && apt-get install -y \
    gcc make valgrind libcriterion-dev libreadline-dev clang-format \
    git zsh vim curl python3 python3-pip && \
    # Install c-formatter-42 via pip
    git clone --single-branch --branch bug/cross-plaform https://github.com/foyez/c_formatter_42 /tmp/c_formatter_42 && \
    pip3 install --break-system-packages /tmp/c_formatter_42 && rm -rf /tmp/c_formatter_42 && \
    # Install norminette
    pip install --break-system-packages -U norminette && \
    # Install Oh My Zsh unattended
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" --unattended && \
    # Install ZSH plugins
    git clone https://github.com/zsh-users/zsh-completions.git $ZSH_CUSTOM/plugins/zsh-completions && \
    git clone https://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions && \
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git $ZSH_CUSTOM/plugins/zsh-syntax-highlighting && \
    # Enable plugins in .zshrc
    sed -i 's/plugins=(git)/plugins=(git zsh-completions zsh-autosuggestions zsh-syntax-highlighting)/' /root/.zshrc && \
    # Add .gitconfig settings
    mkdir -p /root && \
    echo '[user]' > /root/.gitconfig && \
    echo '  email = foyezar@gmail.com' >> /root/.gitconfig && \
    echo '  name = Kazi Foyez Ahmed' >> /root/.gitconfig && \
    echo '[alias]' >> /root/.gitconfig && \
    echo "  s = status -sb" >> /root/.gitconfig && \
    echo "  st = status" >> /root/.gitconfig && \
    echo "  lg = log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit" >> /root/.gitconfig && \
    echo '[color]' >> /root/.gitconfig && \
    echo '  ui = auto' >> /root/.gitconfig && \
    echo '[push]' >> /root/.gitconfig && \
    echo '  default = current' >> /root/.gitconfig && \
    echo '[stash]' >> /root/.gitconfig && \
    echo '  showPatch = true' >> /root/.gitconfig && \
    echo '[rebase]' >> /root/.gitconfig && \
    echo '  autostash = true' >> /root/.gitconfig && \
    echo '[pull]' >> /root/.gitconfig && \
    echo '  rebase = true' >> /root/.gitconfig && \
    echo '[delta]' >> /root/.gitconfig && \
    echo '  plus-style = syntax "#012800"' >> /root/.gitconfig && \
    echo '  minus-style = normal "#340001"' >> /root/.gitconfig && \
    echo '  syntax-theme = Monokai Extended' >> /root/.gitconfig && \
    echo '[interactive]' >> /root/.gitconfig && \
    echo '  diffFilter = delta --color-only' >> /root/.gitconfig && \
    echo '[fetch]' >> /root/.gitconfig && \
    echo '  prune = true' >> /root/.gitconfig && \
    echo '  pruneTags = true' >> /root/.gitconfig && \
    echo '  writeCommitGraph = true' >> /root/.gitconfig && \
    # Clean up to reduce image size
    apt-get remove -y curl && apt-get autoremove -y && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set Zsh as the default shell
CMD [ "zsh" ]
