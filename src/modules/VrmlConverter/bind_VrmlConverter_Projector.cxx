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
#include <Standard_Transient.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlConverter_TypeOfCamera.hxx>
#include <VrmlConverter_TypeOfLight.hxx>
#include <Standard_OStream.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Standard_Handle.hxx>
#include <VrmlConverter_Projector.hxx>
#include <Standard_Type.hxx>
#include <Vrml_PerspectiveCamera.hxx>
#include <Vrml_OrthographicCamera.hxx>
#include <Vrml_DirectionalLight.hxx>
#include <Vrml_PointLight.hxx>
#include <Vrml_SpotLight.hxx>
#include <Vrml_MatrixTransform.hxx>

void bind_VrmlConverter_Projector(py::module &mod){

py::class_<VrmlConverter_Projector, opencascade::handle<VrmlConverter_Projector>, Standard_Transient> cls_VrmlConverter_Projector(mod, "VrmlConverter_Projector", "defines projector and calculates properties of cameras and lights from Vrml ( OrthograpicCamera, PerspectiveCamera, DirectionalLight, PointLight, SpotLight and MatrixTransform ) to display all scene shapes with arbitrary locations for requested the Projection Vector, High Point Direction and the Focus and adds them ( method Add ) to anOSream.");

// Constructors
cls_VrmlConverter_Projector.def(py::init<const TopTools_Array1OfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Shapes"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"));
cls_VrmlConverter_Projector.def(py::init<const TopTools_Array1OfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const VrmlConverter_TypeOfCamera>(), py::arg("Shapes"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"), py::arg("Camera"));
cls_VrmlConverter_Projector.def(py::init<const TopTools_Array1OfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const VrmlConverter_TypeOfCamera, const VrmlConverter_TypeOfLight>(), py::arg("Shapes"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"), py::arg("Camera"), py::arg("Light"));

// Fields

// Methods
cls_VrmlConverter_Projector.def("SetCamera", (void (VrmlConverter_Projector::*)(const VrmlConverter_TypeOfCamera)) &VrmlConverter_Projector::SetCamera, "None", py::arg("aCamera"));
cls_VrmlConverter_Projector.def("Camera", (VrmlConverter_TypeOfCamera (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::Camera, "None");
cls_VrmlConverter_Projector.def("SetLight", (void (VrmlConverter_Projector::*)(const VrmlConverter_TypeOfLight)) &VrmlConverter_Projector::SetLight, "None", py::arg("aLight"));
cls_VrmlConverter_Projector.def("Light", (VrmlConverter_TypeOfLight (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::Light, "None");
cls_VrmlConverter_Projector.def("Add", (void (VrmlConverter_Projector::*)(Standard_OStream &) const) &VrmlConverter_Projector::Add, "Adds into anOStream if they are defined in Create. PerspectiveCamera, OrthographicCamera, DirectionLight, PointLight, SpotLight with MatrixTransform from VrmlConverter;", py::arg("anOStream"));
cls_VrmlConverter_Projector.def("Projector", (HLRAlgo_Projector (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::Projector, "None");
cls_VrmlConverter_Projector.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_Projector::get_type_name, "None");
cls_VrmlConverter_Projector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_Projector::get_type_descriptor, "None");
cls_VrmlConverter_Projector.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::DynamicType, "None");

// Enums

}