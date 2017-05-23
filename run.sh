#!/usr/bin/env bash


./build/test_face_verification.bin   \
    ./1.jpg \
    ./2.jpg \
    ./cmssFaceEngine/FaceIdentification/model/cmss_fd_frontal_v1.0.bin  \
    ./cmssFaceEngine/FaceIdentification/model/cmss_fa_v1.1.bin \
    ./cmssFaceEngine/FaceIdentification/model/cmss_fr_v1.0.bin


