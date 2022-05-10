#!/bin/bash

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

brew install cmake

brew install freetype

brew install openssl

brew install libffi

brew install sfml

echo "Finished! Make sure you download Xcode + Xcode cmd line binaries. https://developer.apple.com/download/all/?q=Xcode"