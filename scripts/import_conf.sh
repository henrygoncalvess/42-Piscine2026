#!/usr/bin/env bash

echo -e "\033[1;33m- - - - - - - - - - - - - - - - - - - -\033[0m\n"

echo -e "\033[1;33mCriando Symlinks com GNU Stow\033[0m\n"

# Paths to clean before stowing (avoids conflicts with pre-existing dirs/files).
CONF_TARGETS=(
  "$HOME/.config/Code"
  "$HOME/.config/kitty"
  "$HOME/.config/oh_my_posh_config"
  "$HOME/.config/nvim"
  "$HOME/.bash_profile"
  "$HOME/.bashrc"
  "$HOME/.zshrc"
  "$HOME/.face"
  "$HOME/.vscode"
)

STOW_PACKAGES=(conf_home conf_posh conf_code conf_shell conf_kitty conf_nvim)

echo -e "\033[1;33mRemovendo arquivos existentes para evitar conflitos\033[0m\n"
for target in "${CONF_TARGETS[@]}"; do
  if [ -e "$target" ] || [ -L "$target" ]; then
    echo "Limpando: $target"
    rm -rf "$target"
  fi
done

echo -e "\n\033[1;33mAplicando Stow\033[0m\n"
cd "$HOME/42sp" || exit 1

# Aplica as configurações no diretório Home (que já existe)
stow -v -t "$HOME" "${STOW_PACKAGES[@]}"

echo -e "\n\033[3;32m✔ Symlinks criados com sucesso!\033[0m\n"

echo -e "\033[1;33m- - - - - - - - - - - - - - - - - - - -\033[0m\n"
