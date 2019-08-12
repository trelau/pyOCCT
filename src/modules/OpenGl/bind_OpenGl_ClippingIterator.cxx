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
#include <OpenGl_Clipping.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Vector.hxx>

void bind_OpenGl_ClippingIterator(py::module &mod){

py::class_<OpenGl_ClippingIterator, std::unique_ptr<OpenGl_ClippingIterator, Deleter<OpenGl_ClippingIterator>>> cls_OpenGl_ClippingIterator(mod, "OpenGl_ClippingIterator", "The iterator through clipping planes.");

// Constructors
cls_OpenGl_ClippingIterator.def(py::init<const OpenGl_Clipping &>(), py::arg("theClipping"));

// Fields

// Methods
cls_OpenGl_ClippingIterator.def("More", (bool (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::More, "Return true if iterator points to the valid clipping plane.");
cls_OpenGl_ClippingIterator.def("Next", (void (OpenGl_ClippingIterator::*)()) &OpenGl_ClippingIterator::Next, "Go to the next clipping plane.");
cls_OpenGl_ClippingIterator.def("IsDisabled", (bool (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::IsDisabled, "Return true if plane has been temporarily disabled either by Graphic3d_ClipPlane->IsOn() property or by temporary filter.");
cls_OpenGl_ClippingIterator.def("Value", (const opencascade::handle<Graphic3d_ClipPlane> & (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::Value, "Return the plane at current iterator position.");
cls_OpenGl_ClippingIterator.def("IsGlobal", (bool (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::IsGlobal, "Return true if plane from the global (view) list.");
cls_OpenGl_ClippingIterator.def("PlaneIndex", (Standard_Integer (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::PlaneIndex, "Return the plane index.");

// Enums

}