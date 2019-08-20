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
#include <OpenGl_Element.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_Buffer.hxx>
#include <Graphic3d_BoundBuffer.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <Graphic3d_Vec4.hxx>
#include <OpenGl_Vec.hxx>
#include <Standard.hxx>
#include <OpenGl_PrimitiveArray.hxx>

void bind_OpenGl_PrimitiveArray(py::module &mod){

py::class_<OpenGl_PrimitiveArray, std::unique_ptr<OpenGl_PrimitiveArray>, OpenGl_Element> cls_OpenGl_PrimitiveArray(mod, "OpenGl_PrimitiveArray", "Class for rendering of arbitrary primitive array.");

// Constructors
cls_OpenGl_PrimitiveArray.def(py::init<const OpenGl_GraphicDriver *>(), py::arg("theDriver"));
cls_OpenGl_PrimitiveArray.def(py::init<const OpenGl_GraphicDriver *, const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &>(), py::arg("theDriver"), py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"));

// Fields

// Methods
cls_OpenGl_PrimitiveArray.def("Render", (void (OpenGl_PrimitiveArray::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_PrimitiveArray::Render, "Render primitives to the window", py::arg("theWorkspace"));
cls_OpenGl_PrimitiveArray.def("Release", (void (OpenGl_PrimitiveArray::*)(OpenGl_Context *)) &OpenGl_PrimitiveArray::Release, "Release OpenGL resources (VBOs)", py::arg("theContext"));
cls_OpenGl_PrimitiveArray.def("IsInitialized", (Standard_Boolean (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::IsInitialized, "Return true if VBOs initialization has been performed. VBO initialization is performed during first Render() call. Notice that this flag does not indicate VBOs validity.");
cls_OpenGl_PrimitiveArray.def("Invalidate", (void (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Invalidate, "Invalidate VBO content without destruction.");
cls_OpenGl_PrimitiveArray.def("DrawMode", (GLint (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::DrawMode, "Returns primitive type (GL_LINES, GL_TRIANGLES and others)");
cls_OpenGl_PrimitiveArray.def("IsFillDrawMode", (Standard_Boolean (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::IsFillDrawMode, "Return TRUE if primitive type generates shaded triangulation.");
cls_OpenGl_PrimitiveArray.def("Indices", (const opencascade::handle<Graphic3d_IndexBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Indices, "Returns indices array");
cls_OpenGl_PrimitiveArray.def("Attributes", (const opencascade::handle<Graphic3d_Buffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Attributes, "Returns attributes array");
cls_OpenGl_PrimitiveArray.def("Bounds", (const opencascade::handle<Graphic3d_BoundBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Bounds, "Returns bounds array");
cls_OpenGl_PrimitiveArray.def("GetUID", (Standard_Size (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::GetUID, "Returns unique ID of primitive array.");
cls_OpenGl_PrimitiveArray.def("InitBuffers", (void (OpenGl_PrimitiveArray::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &)) &OpenGl_PrimitiveArray::InitBuffers, "Initialize indices, attributes and bounds with new data.", py::arg("theContext"), py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"));
cls_OpenGl_PrimitiveArray.def("IndexVbo", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::IndexVbo, "Returns index VBO.");
cls_OpenGl_PrimitiveArray.def("AttributesVbo", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::AttributesVbo, "Returns attributes VBO.");
// cls_OpenGl_PrimitiveArray.def_static("operator new_", (void * (*)(size_t)) &OpenGl_PrimitiveArray::operator new, "None", py::arg("theSize"));
// cls_OpenGl_PrimitiveArray.def_static("operator delete_", (void (*)(void *)) &OpenGl_PrimitiveArray::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_PrimitiveArray.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_PrimitiveArray::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_PrimitiveArray.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_PrimitiveArray::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_PrimitiveArray.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_PrimitiveArray::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_PrimitiveArray.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_PrimitiveArray::operator delete, "None", py::arg(""), py::arg(""));

// Enums
cls_OpenGl_PrimitiveArray.attr("DRAW_MODE_NONE") = py::cast(int(OpenGl_PrimitiveArray::DRAW_MODE_NONE));

}