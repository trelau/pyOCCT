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
#include <gp_Vec.hxx>
#include <Vrml_SFRotation.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_PerspectiveCamera.hxx>

void bind_Vrml_PerspectiveCamera(py::module &mod){

py::class_<Vrml_PerspectiveCamera, std::unique_ptr<Vrml_PerspectiveCamera, Deleter<Vrml_PerspectiveCamera>>> cls_Vrml_PerspectiveCamera(mod, "Vrml_PerspectiveCamera", "specifies a PerspectiveCamera node of VRML specifying properties of cameras. A perspective camera defines a perspective projection from a viewpoint. The viewing volume for a perspective camera is a truncated right pyramid.");

// Constructors
cls_Vrml_PerspectiveCamera.def(py::init<>());
cls_Vrml_PerspectiveCamera.def(py::init<const gp_Vec &, const Vrml_SFRotation &, const Standard_Real, const Standard_Real>(), py::arg("aPosition"), py::arg("aOrientation"), py::arg("aFocalDistance"), py::arg("aHeightAngle"));

// Fields

// Methods
// cls_Vrml_PerspectiveCamera.def_static("operator new_", (void * (*)(size_t)) &Vrml_PerspectiveCamera::operator new, "None", py::arg("theSize"));
// cls_Vrml_PerspectiveCamera.def_static("operator delete_", (void (*)(void *)) &Vrml_PerspectiveCamera::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_PerspectiveCamera.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_PerspectiveCamera::operator new[], "None", py::arg("theSize"));
// cls_Vrml_PerspectiveCamera.def_static("operator delete[]_", (void (*)(void *)) &Vrml_PerspectiveCamera::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_PerspectiveCamera.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_PerspectiveCamera::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_PerspectiveCamera.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_PerspectiveCamera::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_PerspectiveCamera.def("SetPosition", (void (Vrml_PerspectiveCamera::*)(const gp_Vec &)) &Vrml_PerspectiveCamera::SetPosition, "None", py::arg("aPosition"));
cls_Vrml_PerspectiveCamera.def("Position", (gp_Vec (Vrml_PerspectiveCamera::*)() const) &Vrml_PerspectiveCamera::Position, "None");
cls_Vrml_PerspectiveCamera.def("SetOrientation", (void (Vrml_PerspectiveCamera::*)(const Vrml_SFRotation &)) &Vrml_PerspectiveCamera::SetOrientation, "None", py::arg("aOrientation"));
cls_Vrml_PerspectiveCamera.def("Orientation", (Vrml_SFRotation (Vrml_PerspectiveCamera::*)() const) &Vrml_PerspectiveCamera::Orientation, "None");
cls_Vrml_PerspectiveCamera.def("SetFocalDistance", (void (Vrml_PerspectiveCamera::*)(const Standard_Real)) &Vrml_PerspectiveCamera::SetFocalDistance, "None", py::arg("aFocalDistance"));
cls_Vrml_PerspectiveCamera.def("FocalDistance", (Standard_Real (Vrml_PerspectiveCamera::*)() const) &Vrml_PerspectiveCamera::FocalDistance, "None");
cls_Vrml_PerspectiveCamera.def("SetAngle", (void (Vrml_PerspectiveCamera::*)(const Standard_Real)) &Vrml_PerspectiveCamera::SetAngle, "None", py::arg("aHeightAngle"));
cls_Vrml_PerspectiveCamera.def("Angle", (Standard_Real (Vrml_PerspectiveCamera::*)() const) &Vrml_PerspectiveCamera::Angle, "None");
cls_Vrml_PerspectiveCamera.def("Print", (Standard_OStream & (Vrml_PerspectiveCamera::*)(Standard_OStream &) const) &Vrml_PerspectiveCamera::Print, "None", py::arg("anOStream"));

// Enums

}