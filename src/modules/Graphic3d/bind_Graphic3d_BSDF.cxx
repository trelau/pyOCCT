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
#include <Graphic3d_Vec4.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_BSDF.hxx>
#include <Standard_TypeDef.hxx>

void bind_Graphic3d_BSDF(py::module &mod){

py::class_<Graphic3d_BSDF, std::unique_ptr<Graphic3d_BSDF>> cls_Graphic3d_BSDF(mod, "Graphic3d_BSDF", "Describes material's BSDF (Bidirectional Scattering Distribution Function) used for physically-based rendering (in path tracing engine). BSDF is represented as weighted mixture of basic BRDFs/BTDFs (Bidirectional Reflectance (Transmittance) Distribution Functions).");

// Constructors
cls_Graphic3d_BSDF.def(py::init<>());

// Fields
cls_Graphic3d_BSDF.def_readwrite("Kc", &Graphic3d_BSDF::Kc, "Weight of coat specular/glossy BRDF.");
cls_Graphic3d_BSDF.def_readwrite("Kd", &Graphic3d_BSDF::Kd, "Weight of base diffuse BRDF.");
cls_Graphic3d_BSDF.def_readwrite("Ks", &Graphic3d_BSDF::Ks, "Weight of base specular/glossy BRDF.");
cls_Graphic3d_BSDF.def_readwrite("Kt", &Graphic3d_BSDF::Kt, "Weight of base specular/glossy BTDF.");
cls_Graphic3d_BSDF.def_readwrite("Le", &Graphic3d_BSDF::Le, "Radiance emitted by the surface.");
cls_Graphic3d_BSDF.def_readwrite("Absorption", &Graphic3d_BSDF::Absorption, "Volume scattering color/density.");
cls_Graphic3d_BSDF.def_readwrite("FresnelCoat", &Graphic3d_BSDF::FresnelCoat, "Parameters of Fresnel reflectance of coat layer.");
cls_Graphic3d_BSDF.def_readwrite("FresnelBase", &Graphic3d_BSDF::FresnelBase, "Parameters of Fresnel reflectance of base layer.");

// Methods
cls_Graphic3d_BSDF.def_static("CreateDiffuse_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &)) &Graphic3d_BSDF::CreateDiffuse, "Creates BSDF describing diffuse (Lambertian) surface.", py::arg("theWeight"));
cls_Graphic3d_BSDF.def_static("CreateMetallic_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &, const Graphic3d_Fresnel &, const Standard_ShortReal)) &Graphic3d_BSDF::CreateMetallic, "Creates BSDF describing polished metallic-like surface.", py::arg("theWeight"), py::arg("theFresnel"), py::arg("theRoughness"));
cls_Graphic3d_BSDF.def_static("CreateTransparent_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &, const Graphic3d_Vec3 &, const Standard_ShortReal)) &Graphic3d_BSDF::CreateTransparent, "Creates BSDF describing transparent object. Transparent BSDF models simple transparency without refraction (the ray passes straight through the surface).", py::arg("theWeight"), py::arg("theAbsorptionColor"), py::arg("theAbsorptionCoeff"));
cls_Graphic3d_BSDF.def_static("CreateGlass_", (Graphic3d_BSDF (*)(const Graphic3d_Vec3 &, const Graphic3d_Vec3 &, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_BSDF::CreateGlass, "Creates BSDF describing glass-like object. Glass-like BSDF mixes refraction and reflection effects at grazing angles using physically-based Fresnel dielectric model.", py::arg("theWeight"), py::arg("theAbsorptionColor"), py::arg("theAbsorptionCoeff"), py::arg("theRefractionIndex"));
cls_Graphic3d_BSDF.def("Normalize", (void (Graphic3d_BSDF::*)()) &Graphic3d_BSDF::Normalize, "Normalizes BSDF components.");
cls_Graphic3d_BSDF.def("__eq__", (bool (Graphic3d_BSDF::*)(const Graphic3d_BSDF &) const) &Graphic3d_BSDF::operator==, py::is_operator(), "Performs comparison of two BSDFs.", py::arg("theOther"));

// Enums

}