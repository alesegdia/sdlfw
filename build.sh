#!/usr/bin/env bash

cd assetgentool
./update_assets.sh
cd ..
cd build && make && cd ..
