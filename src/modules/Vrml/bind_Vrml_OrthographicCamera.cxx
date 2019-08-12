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
#include <Vrml_OrthographicCamera.hxx>

void bind_Vrml_OrthographicCamera(py::module &mod){

py::class_<Vrml_OrthographicCamera, std::unique_ptr<Vrml_OrthographicCamera, Deleter<Vrml_OrthographicCamera>>> cls_Vrml_OrthographicCamera(mod, "Vrml_OrthographicCamera", "specifies a OrthographicCamera node of VRML specifying properties of cameras. An orthographic camera defines a parallel projection from a viewpoint. This camera does not diminish objects with distance, as a PerspectiveCamera does. The viewing volume for an orthographic camera is a rectangular parallelepiped (a box).");

// Constructors
cls_Vrml_OrthographicCamera.def(py::init<>());
cls_Vrml_OrthographicCamera.def(py::init<const gp_Vec &, const Vrml_SFRotation &, const Standard_Real, const Standard_Real>(), py::arg("aPosition"), py::arg("aOrientation"), py::arg("aFocalDistance"), py::arg("aHeight"));

// Fields

// Methods
// cls_Vrml_OrthographicCamera.def_static("operator new_", (void * (*)(size_t)) &Vrml_OrthographicCamera::operator new, "None", py::arg("theSize"));
// cls_Vrml_OrthographicCamera.def_static("operator delete_", (void (*)(void *)) &Vrml_OrthographicCamera::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_OrthographicCamera.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_OrthographicCamera::operator new[], "None", py::arg("theSize"));
// cls_Vrml_OrthographicCamera.def_static("operator delete[]_", (void (*)(void *)) &Vrml_OrthographicCamera::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_OrthographicCamera.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_OrthographicCamera::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_OrthographicCamera.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_OrthographicCamera::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_OrthographicCamera.def("SetPosition", (void (Vrml_OrthographicCamera::*)(const gp_Vec &)) &Vrml_OrthographicCamera::SetPosition, "None", py::arg("aPosition"));
cls_Vrml_OrthographicCamera.def("Position", (gp_Vec (Vrml_OrthographicCamera::*)() const) &Vrml_OrthographicCamera::Position, "None");
cls_Vrml_OrthographicCamera.def("SetOrientation", (void (Vrml_OrthographicCamera::*)(const Vrml_SFRotation &)) &Vrml_OrthographicCamera::SetOrientation, "None", py::arg("aOrientation"));
cls_Vrml_OrthographicCamera.def("Orientation", (Vrml_SFRotation (Vrml_OrthographicCamera::*)() const) &Vrml_OrthographicCamera::Orientation, "None");
cls_Vrml_OrthographicCamera.def("SetFocalDistance", (void (Vrml_OrthographicCamera::*)(const Standard_Real)) &Vrml_OrthographicCamera::SetFocalDistance, "None", py::arg("aFocalDistance"));
cls_Vrml_OrthographicCamera.def("FocalDistance", (Standard_Real (Vrml_OrthographicCamera::*)() const) &Vrml_OrthographicCamera::FocalDistance, "None");
cls_Vrml_OrthographicCamera.def("SetHeight", (void (Vrml_OrthographicCamera::*)(const Standard_Real)) &Vrml_OrthographicCamera::SetHeight, "None", py::arg("aHeight"));
cls_Vrml_OrthographicCamera.def("Height", (Standard_Real (Vrml_OrthographicCamera::*)() const) &Vrml_OrthographicCamera::Height, "None");
cls_Vrml_OrthographicCamera.def("Print", (Standard_OStream & (Vrml_OrthographicCamera::*)(Standard_OStream &) const) &Vrml_OrthographicCamera::Print, "None", py::arg("anOStream"));

// Enums

}