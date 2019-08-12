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
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_BSDF.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Vec4.hxx>

void bind_Graphic3d_Fresnel(py::module &mod){

py::class_<Graphic3d_Fresnel, std::unique_ptr<Graphic3d_Fresnel, Deleter<Graphic3d_Fresnel>>> cls_Graphic3d_Fresnel(mod, "Graphic3d_Fresnel", "Describes Fresnel reflectance parameters.");

// Constructors
cls_Graphic3d_Fresnel.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_Fresnel.def_static("CreateSchlick_", (Graphic3d_Fresnel (*)(const Graphic3d_Vec3 &)) &Graphic3d_Fresnel::CreateSchlick, "Creates Schlick's approximation of Fresnel factor.", py::arg("theSpecularColor"));
cls_Graphic3d_Fresnel.def_static("CreateConstant_", (Graphic3d_Fresnel (*)(const Standard_ShortReal)) &Graphic3d_Fresnel::CreateConstant, "Creates Fresnel factor for constant reflection.", py::arg("theReflection"));
cls_Graphic3d_Fresnel.def_static("CreateDielectric_", (Graphic3d_Fresnel (*)(Standard_ShortReal)) &Graphic3d_Fresnel::CreateDielectric, "Creates Fresnel factor for physical-based dielectric model.", py::arg("theRefractionIndex"));
cls_Graphic3d_Fresnel.def_static("CreateConductor_", (Graphic3d_Fresnel (*)(Standard_ShortReal, Standard_ShortReal)) &Graphic3d_Fresnel::CreateConductor, "Creates Fresnel factor for physical-based conductor model.", py::arg("theRefractionIndex"), py::arg("theAbsorptionIndex"));
cls_Graphic3d_Fresnel.def_static("CreateConductor_", (Graphic3d_Fresnel (*)(const Graphic3d_Vec3 &, const Graphic3d_Vec3 &)) &Graphic3d_Fresnel::CreateConductor, "Creates Fresnel factor for physical-based conductor model (spectral version).", py::arg("theRefractionIndex"), py::arg("theAbsorptionIndex"));
cls_Graphic3d_Fresnel.def("Serialize", (Graphic3d_Vec4 (Graphic3d_Fresnel::*)() const) &Graphic3d_Fresnel::Serialize, "Returns serialized representation of Fresnel factor.");
cls_Graphic3d_Fresnel.def("__eq__", (bool (Graphic3d_Fresnel::*)(const Graphic3d_Fresnel &) const) &Graphic3d_Fresnel::operator==, py::is_operator(), "Performs comparison of two objects describing Fresnel factor.", py::arg("theOther"));
cls_Graphic3d_Fresnel.def("FresnelType", (Graphic3d_FresnelModel (Graphic3d_Fresnel::*)() const) &Graphic3d_Fresnel::FresnelType, "Returns type of Fresnel.");

// Enums

}