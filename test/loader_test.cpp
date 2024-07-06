// SPDX-License-Identifier: MIT
// Copyright (C) 2024 Artem Senichev <artemsen@gmail.com>

extern "C" {
#include "buildcfg.h"
#include "loader.h"
#include "ui.h"
#include "viewer.h"
}

#include <gtest/gtest.h>

// stubs for linker (ui and viewer are not included to tests)
extern "C" {
void ui_add_event(int, fd_event) { }
void viewer_reload() { }
}

class Loader : public ::testing::Test {
protected:
    void TearDown() override { image_free(image); }

    void Load(const char* file)
    {
        enum loader_status status;
        image = loader_load_image(file, &status);
        ASSERT_NE(image, nullptr);
        EXPECT_EQ(status, ldr_success);
        EXPECT_NE(image->frames[0].pm.data[0], 0);
    }
    struct image* image = nullptr;
};

#define TEST_LOADER(n)                    \
    TEST_F(Loader, n)                     \
    {                                     \
        Load(TEST_DATA_DIR "/image." #n); \
    }

TEST_LOADER(bmp);
TEST_LOADER(pnm);
TEST_LOADER(tga);
#ifdef HAVE_LIBEXR
// TEST_LOADER(exr);
#endif
#ifdef HAVE_LIBGIF
TEST_LOADER(gif);
#endif
#ifdef HAVE_LIBHEIF
TEST_LOADER(heif);
#endif
#ifdef HAVE_LIBAVIF
TEST_LOADER(avif);
#endif
#ifdef HAVE_LIBJPEG
TEST_LOADER(jpg);
#endif
#ifdef HAVE_LIBJXL
TEST_LOADER(jxl);
#endif
#ifdef HAVE_LIBPNG
TEST_LOADER(png);
#endif
#ifdef HAVE_LIBRSVG
TEST_LOADER(svg);
#endif
#ifdef HAVE_LIBTIFF
TEST_LOADER(tiff);
#endif
#ifdef HAVE_LIBWEBP
TEST_LOADER(webp);
#endif