/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Font_TextFormatter.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Font.hxx>
#include <NCollection_Vector.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <NCollection_Handle.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_VertexBufferEditor.hxx>
#include <OpenGl_TextBuilder.hxx>

void bind_OpenGl_TextBuilder(py::module &mod){

py::class_<OpenGl_TextBuilder> cls_OpenGl_TextBuilder(mod, "OpenGl_TextBuilder", "This class generates primitive array required for rendering textured text using OpenGl_Font instance.");

// Constructors
cls_OpenGl_TextBuilder.def(py::init<>());

// Fields

// Methods
cls_OpenGl_TextBuilder.def("Perform", (void (OpenGl_TextBuilder::*)(const Font_TextFormatter &, const opencascade::handle<OpenGl_Context> &, OpenGl_Font &, NCollection_Vector<GLuint> &, NCollection_Vector<opencascade::handle<OpenGl_VertexBuffer> > &, NCollection_Vector<opencascade::handle<OpenGl_VertexBuffer> > &)) &OpenGl_TextBuilder::Perform, "Creates texture quads for the given text.", py::arg("theFormatter"), py::arg("theContext"), py::arg("theFont"), py::arg("theTextures"), py::arg("theVertsPerTexture"), py::arg("theTCrdsPerTexture"));

// Enums

}