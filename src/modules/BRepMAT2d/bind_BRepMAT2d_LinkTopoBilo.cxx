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
#include <BRepMAT2d_Explorer.hxx>
#include <BRepMAT2d_BisectingLocus.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MAT_BasicElt.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.hxx>
#include <BRepMAT2d_DataMapOfBasicEltShape.hxx>
#include <BRepMAT2d_LinkTopoBilo.hxx>

void bind_BRepMAT2d_LinkTopoBilo(py::module &mod){

py::class_<BRepMAT2d_LinkTopoBilo, std::unique_ptr<BRepMAT2d_LinkTopoBilo>> cls_BRepMAT2d_LinkTopoBilo(mod, "BRepMAT2d_LinkTopoBilo", "Constucts links between the Wire or the Face of the explorer and the BasicElts contained in the bisecting locus.");

// Constructors
cls_BRepMAT2d_LinkTopoBilo.def(py::init<>());
cls_BRepMAT2d_LinkTopoBilo.def(py::init<const BRepMAT2d_Explorer &, const BRepMAT2d_BisectingLocus &>(), py::arg("Explo"), py::arg("BiLo"));

// Fields

// Methods
// cls_BRepMAT2d_LinkTopoBilo.def_static("operator new_", (void * (*)(size_t)) &BRepMAT2d_LinkTopoBilo::operator new, "None", py::arg("theSize"));
// cls_BRepMAT2d_LinkTopoBilo.def_static("operator delete_", (void (*)(void *)) &BRepMAT2d_LinkTopoBilo::operator delete, "None", py::arg("theAddress"));
// cls_BRepMAT2d_LinkTopoBilo.def_static("operator new[]_", (void * (*)(size_t)) &BRepMAT2d_LinkTopoBilo::operator new[], "None", py::arg("theSize"));
// cls_BRepMAT2d_LinkTopoBilo.def_static("operator delete[]_", (void (*)(void *)) &BRepMAT2d_LinkTopoBilo::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMAT2d_LinkTopoBilo.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMAT2d_LinkTopoBilo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMAT2d_LinkTopoBilo.def_static("operator delete_", (void (*)(void *, void *)) &BRepMAT2d_LinkTopoBilo::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMAT2d_LinkTopoBilo.def("Perform", (void (BRepMAT2d_LinkTopoBilo::*)(const BRepMAT2d_Explorer &, const BRepMAT2d_BisectingLocus &)) &BRepMAT2d_LinkTopoBilo::Perform, "Constructs the links Between S and BiLo.", py::arg("Explo"), py::arg("BiLo"));
cls_BRepMAT2d_LinkTopoBilo.def("Init", (void (BRepMAT2d_LinkTopoBilo::*)(const TopoDS_Shape &)) &BRepMAT2d_LinkTopoBilo::Init, "Initialise the Iterator on <S> <S> is an edge or a vertex of the initial wire or face. raises if <S> is not an edge or a vertex.", py::arg("S"));
cls_BRepMAT2d_LinkTopoBilo.def("More", (Standard_Boolean (BRepMAT2d_LinkTopoBilo::*)()) &BRepMAT2d_LinkTopoBilo::More, "Returns True if there is a current BasicElt.");
cls_BRepMAT2d_LinkTopoBilo.def("Next", (void (BRepMAT2d_LinkTopoBilo::*)()) &BRepMAT2d_LinkTopoBilo::Next, "Proceed to the next BasicElt.");
cls_BRepMAT2d_LinkTopoBilo.def("Value", (opencascade::handle<MAT_BasicElt> (BRepMAT2d_LinkTopoBilo::*)() const) &BRepMAT2d_LinkTopoBilo::Value, "Returns the current BasicElt.");
cls_BRepMAT2d_LinkTopoBilo.def("GeneratingShape", (TopoDS_Shape (BRepMAT2d_LinkTopoBilo::*)(const opencascade::handle<MAT_BasicElt> &) const) &BRepMAT2d_LinkTopoBilo::GeneratingShape, "Returns the Shape linked to <aBE>.", py::arg("aBE"));

// Enums

}