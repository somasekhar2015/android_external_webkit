/*
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef CSSFontFace_h
#define CSSFontFace_h

#include <wtf/RefCounted.h>
#include <wtf/Vector.h>

namespace WebCore {

class CSSFontFaceSource;
class CSSSegmentedFontFace;
class FontDescription;
class SimpleFontData;

class CSSFontFace : public RefCounted<CSSFontFace> {
public:
    CSSFontFace()
        : RefCounted<CSSFontFace>(0)
        , m_segmentedFontFace(0)
    {
    }

    virtual ~CSSFontFace();

    void setSegmentedFontFace(CSSSegmentedFontFace* segmentedFontFace) { m_segmentedFontFace = segmentedFontFace; }

    bool isLoaded() const;
    virtual bool isValid() const;

    virtual void addSource(CSSFontFaceSource*);

    void fontLoaded(CSSFontFaceSource*);

    virtual SimpleFontData* getFontData(const FontDescription&, bool syntheticBold, bool syntheticItalic);

private:
    CSSSegmentedFontFace* m_segmentedFontFace;
    Vector<CSSFontFaceSource*> m_sources;
};

}

#endif