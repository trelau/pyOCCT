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
#ifndef __OpenGl_VertexBufferEditor__
#define __OpenGl_VertexBufferEditor__

#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_VertexBufferEditor.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <NCollection_Array1.hxx>

template <typename theVec_t>
void bind_OpenGl_VertexBufferEditor(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<OpenGl_VertexBufferEditor<theVec_t>> cls_OpenGl_VertexBufferEditor(mod, name.c_str(), "Auxiliary class to iteratively modify data of existing VBO. It provides iteration interface with delayed CPU->GPU memory transfer to avoid slow per-element data transfer. User should explicitly call Flush() method to ensure that all data is transferred to VBO. Temporary buffer on CPU side can be initialized with lesser capacity than VBO to allow re-usage of shared buffer with fixed size between VBOs.", local);

// Constructors
cls_OpenGl_VertexBufferEditor.def(py::init<>());
cls_OpenGl_VertexBufferEditor.def(py::init<const Standard_Integer>(), py::arg("theTmpBufferLength"));
cls_OpenGl_VertexBufferEditor.def(py::init<theVec_t *, const Standard_Integer>(), py::arg("theTmpBuffer"), py::arg("theTmpBufferLength"));

// Fields

// Methods
cls_OpenGl_VertexBufferEditor.def("Init", (Standard_Boolean (OpenGl_VertexBufferEditor<theVec_t>::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_VertexBuffer> &)) &OpenGl_VertexBufferEditor<theVec_t>::Init, "Initialize editor for specified VBO. theGlCtx - bound OpenGL context to edit VBO theVbo - VBO to edit", py::arg("theGlCtx"), py::arg("theVbo"));
cls_OpenGl_VertexBufferEditor.def("Value", (theVec_t & (OpenGl_VertexBufferEditor<theVec_t>::*)()) &OpenGl_VertexBufferEditor<theVec_t>::Value, "Modify current element in VBO.");
cls_OpenGl_VertexBufferEditor.def("Next", (Standard_Boolean (OpenGl_VertexBufferEditor<theVec_t>::*)()) &OpenGl_VertexBufferEditor<theVec_t>::Next, "Move to the next position in VBO.");
cls_OpenGl_VertexBufferEditor.def("Flush", (Standard_Boolean (OpenGl_VertexBufferEditor<theVec_t>::*)()) &OpenGl_VertexBufferEditor<theVec_t>::Flush, "Push current data from local buffer to VBO.");
cls_OpenGl_VertexBufferEditor.def("GetVBO", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_VertexBufferEditor<theVec_t>::*)() const) &OpenGl_VertexBufferEditor<theVec_t>::GetVBO, "Returns assigned VBO");

// Enums

}

#endif