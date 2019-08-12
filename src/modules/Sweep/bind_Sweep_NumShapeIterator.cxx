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
#include <Standard.hxx>
#include <Sweep_NumShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <Sweep_NumShapeIterator.hxx>

void bind_Sweep_NumShapeIterator(py::module &mod){

py::class_<Sweep_NumShapeIterator, std::unique_ptr<Sweep_NumShapeIterator, Deleter<Sweep_NumShapeIterator>>> cls_Sweep_NumShapeIterator(mod, "Sweep_NumShapeIterator", "This class provides iteration services required by the Swept Primitives for a Directing NumShape Line.");

// Constructors
cls_Sweep_NumShapeIterator.def(py::init<>());

// Fields

// Methods
// cls_Sweep_NumShapeIterator.def_static("operator new_", (void * (*)(size_t)) &Sweep_NumShapeIterator::operator new, "None", py::arg("theSize"));
// cls_Sweep_NumShapeIterator.def_static("operator delete_", (void (*)(void *)) &Sweep_NumShapeIterator::operator delete, "None", py::arg("theAddress"));
// cls_Sweep_NumShapeIterator.def_static("operator new[]_", (void * (*)(size_t)) &Sweep_NumShapeIterator::operator new[], "None", py::arg("theSize"));
// cls_Sweep_NumShapeIterator.def_static("operator delete[]_", (void (*)(void *)) &Sweep_NumShapeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Sweep_NumShapeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Sweep_NumShapeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Sweep_NumShapeIterator.def_static("operator delete_", (void (*)(void *, void *)) &Sweep_NumShapeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Sweep_NumShapeIterator.def("Init", (void (Sweep_NumShapeIterator::*)(const Sweep_NumShape &)) &Sweep_NumShapeIterator::Init, "Resest the NumShapeIterator on sub-shapes of <aShape>.", py::arg("aShape"));
cls_Sweep_NumShapeIterator.def("More", (Standard_Boolean (Sweep_NumShapeIterator::*)() const) &Sweep_NumShapeIterator::More, "Returns True if there is a current sub-shape.");
cls_Sweep_NumShapeIterator.def("Next", (void (Sweep_NumShapeIterator::*)()) &Sweep_NumShapeIterator::Next, "Moves to the next sub-shape.");
cls_Sweep_NumShapeIterator.def("Value", (const Sweep_NumShape & (Sweep_NumShapeIterator::*)() const) &Sweep_NumShapeIterator::Value, "Returns the current sub-shape.");
cls_Sweep_NumShapeIterator.def("Orientation", (TopAbs_Orientation (Sweep_NumShapeIterator::*)() const) &Sweep_NumShapeIterator::Orientation, "Returns the orientation of the current sub-shape.");

// Enums

}