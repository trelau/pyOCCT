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
#include <gp_Pnt.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <LocOpe_PntFace.hxx>

void bind_LocOpe_PntFace(py::module &mod){

py::class_<LocOpe_PntFace, std::unique_ptr<LocOpe_PntFace>> cls_LocOpe_PntFace(mod, "LocOpe_PntFace", "None");

// Constructors
cls_LocOpe_PntFace.def(py::init<>());
cls_LocOpe_PntFace.def(py::init<const gp_Pnt &, const TopoDS_Face &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("F"), py::arg("Or"), py::arg("Param"), py::arg("UPar"), py::arg("VPar"));

// Fields

// Methods
// cls_LocOpe_PntFace.def_static("operator new_", (void * (*)(size_t)) &LocOpe_PntFace::operator new, "None", py::arg("theSize"));
// cls_LocOpe_PntFace.def_static("operator delete_", (void (*)(void *)) &LocOpe_PntFace::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_PntFace.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_PntFace::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_PntFace.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_PntFace::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_PntFace.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_PntFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_PntFace.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_PntFace::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_PntFace.def("Pnt", (const gp_Pnt & (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Pnt, "None");
cls_LocOpe_PntFace.def("Face", (const TopoDS_Face & (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Face, "None");
cls_LocOpe_PntFace.def("Orientation", (TopAbs_Orientation (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Orientation, "None");
cls_LocOpe_PntFace.def("ChangeOrientation", (TopAbs_Orientation & (LocOpe_PntFace::*)()) &LocOpe_PntFace::ChangeOrientation, "None");
cls_LocOpe_PntFace.def("Parameter", (Standard_Real (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Parameter, "None");
cls_LocOpe_PntFace.def("UParameter", (Standard_Real (LocOpe_PntFace::*)() const) &LocOpe_PntFace::UParameter, "None");
cls_LocOpe_PntFace.def("VParameter", (Standard_Real (LocOpe_PntFace::*)() const) &LocOpe_PntFace::VParameter, "None");

// Enums

}