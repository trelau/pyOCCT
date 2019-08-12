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
#include <GProp_GProps.hxx>
#include <Standard.hxx>
#include <BRepGProp_Face.hxx>
#include <gp_Pnt.hxx>
#include <BRepGProp_Domain.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepGProp_Sinert.hxx>

void bind_BRepGProp_Sinert(py::module &mod){

py::class_<BRepGProp_Sinert, std::unique_ptr<BRepGProp_Sinert, Deleter<BRepGProp_Sinert>>, GProp_GProps> cls_BRepGProp_Sinert(mod, "BRepGProp_Sinert", "Computes the global properties of a face in 3D space. The face 's requirements to evaluate the global properties are defined in the template FaceTool from package GProp.");

// Constructors
cls_BRepGProp_Sinert.def(py::init<>());
cls_BRepGProp_Sinert.def(py::init<const BRepGProp_Face &, const gp_Pnt &>(), py::arg("S"), py::arg("SLocation"));
cls_BRepGProp_Sinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &>(), py::arg("S"), py::arg("D"), py::arg("SLocation"));
cls_BRepGProp_Sinert.def(py::init<BRepGProp_Face &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("SLocation"), py::arg("Eps"));
cls_BRepGProp_Sinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("D"), py::arg("SLocation"), py::arg("Eps"));

// Fields

// Methods
// cls_BRepGProp_Sinert.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_Sinert::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_Sinert.def_static("operator delete_", (void (*)(void *)) &BRepGProp_Sinert::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_Sinert.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_Sinert::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_Sinert.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_Sinert::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_Sinert.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_Sinert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_Sinert.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_Sinert::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_Sinert.def("SetLocation", (void (BRepGProp_Sinert::*)(const gp_Pnt &)) &BRepGProp_Sinert::SetLocation, "None", py::arg("SLocation"));
cls_BRepGProp_Sinert.def("Perform", (void (BRepGProp_Sinert::*)(const BRepGProp_Face &)) &BRepGProp_Sinert::Perform, "None", py::arg("S"));
cls_BRepGProp_Sinert.def("Perform", (void (BRepGProp_Sinert::*)(BRepGProp_Face &, BRepGProp_Domain &)) &BRepGProp_Sinert::Perform, "None", py::arg("S"), py::arg("D"));
cls_BRepGProp_Sinert.def("Perform", (Standard_Real (BRepGProp_Sinert::*)(BRepGProp_Face &, const Standard_Real)) &BRepGProp_Sinert::Perform, "None", py::arg("S"), py::arg("Eps"));
cls_BRepGProp_Sinert.def("Perform", (Standard_Real (BRepGProp_Sinert::*)(BRepGProp_Face &, BRepGProp_Domain &, const Standard_Real)) &BRepGProp_Sinert::Perform, "None", py::arg("S"), py::arg("D"), py::arg("Eps"));
cls_BRepGProp_Sinert.def("GetEpsilon", (Standard_Real (BRepGProp_Sinert::*)()) &BRepGProp_Sinert::GetEpsilon, "If previously used method contained Eps parameter get actual relative error of the computation, else return 1.0.");

// Enums

}