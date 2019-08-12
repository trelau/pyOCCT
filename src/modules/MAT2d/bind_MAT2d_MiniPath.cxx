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
#include <MAT2d_SequenceOfSequenceOfGeometry.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT2d_SequenceOfConnexion.hxx>
#include <Standard_Handle.hxx>
#include <MAT2d_Connexion.hxx>
#include <MAT2d_DataMapOfIntegerSequenceOfConnexion.hxx>
#include <MAT2d_DataMapOfIntegerConnexion.hxx>
#include <MAT2d_MiniPath.hxx>

void bind_MAT2d_MiniPath(py::module &mod){

py::class_<MAT2d_MiniPath, std::unique_ptr<MAT2d_MiniPath, Deleter<MAT2d_MiniPath>>> cls_MAT2d_MiniPath(mod, "MAT2d_MiniPath", "MiniPath computes a path to link all the lines in a set of lines. The path is described as a set of connexions.");

// Constructors
cls_MAT2d_MiniPath.def(py::init<>());

// Fields

// Methods
// cls_MAT2d_MiniPath.def_static("operator new_", (void * (*)(size_t)) &MAT2d_MiniPath::operator new, "None", py::arg("theSize"));
// cls_MAT2d_MiniPath.def_static("operator delete_", (void (*)(void *)) &MAT2d_MiniPath::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_MiniPath.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_MiniPath::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_MiniPath.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_MiniPath::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_MiniPath.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_MiniPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_MiniPath.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_MiniPath::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_MiniPath.def("Perform", (void (MAT2d_MiniPath::*)(const MAT2d_SequenceOfSequenceOfGeometry &, const Standard_Integer, const Standard_Boolean)) &MAT2d_MiniPath::Perform, "Computes the path to link the lines in <Figure>. the path starts on the line of index <IndStart> <Sense> = True if the Circuit turns in the trigonometric sense.", py::arg("Figure"), py::arg("IndStart"), py::arg("Sense"));
cls_MAT2d_MiniPath.def("RunOnConnexions", (void (MAT2d_MiniPath::*)()) &MAT2d_MiniPath::RunOnConnexions, "Run on the set of connexions to compute the path. the path is an exploration of the tree which contains the connexions and their reverses. if the tree of connexions is A / | B E / | | C D F");
cls_MAT2d_MiniPath.def("Path", (const MAT2d_SequenceOfConnexion & (MAT2d_MiniPath::*)() const) &MAT2d_MiniPath::Path, "Returns the sequence of connexions corresponding to the path.");
cls_MAT2d_MiniPath.def("IsConnexionsFrom", (Standard_Boolean (MAT2d_MiniPath::*)(const Standard_Integer) const) &MAT2d_MiniPath::IsConnexionsFrom, "Returns <True> if there is one Connexion which starts on line designed by <Index>.", py::arg("Index"));
cls_MAT2d_MiniPath.def("ConnexionsFrom", (MAT2d_SequenceOfConnexion & (MAT2d_MiniPath::*)(const Standard_Integer)) &MAT2d_MiniPath::ConnexionsFrom, "Returns the connexions which start on line designed by <Index>.", py::arg("Index"));
cls_MAT2d_MiniPath.def("IsRoot", (Standard_Boolean (MAT2d_MiniPath::*)(const Standard_Integer) const) &MAT2d_MiniPath::IsRoot, "Returns <True> if the line designed by <Index> is the root.", py::arg("Index"));
cls_MAT2d_MiniPath.def("Father", (opencascade::handle<MAT2d_Connexion> (MAT2d_MiniPath::*)(const Standard_Integer)) &MAT2d_MiniPath::Father, "Returns the connexion which ends on line designed by <Index>.", py::arg("Index"));

// Enums

}