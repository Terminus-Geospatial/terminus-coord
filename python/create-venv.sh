#!/usr/bin/env bash

VENV_PATH="`dirname $0`/venv"
REQ_PATH="`dirname $0`/requirements.txt"

#  Create environment
if [ -d "${VENV_PATH}" ]; then
    echo "Virtual environment already exists."
else
    python3 -m venv ${VENV_PATH}
fi

#  Activate environment
. ${VENV_PATH}/bin/activate

#  Update PIP
pip install --upgrade pip

#  Install dependencies
pip install -r ${REQ_PATH}
