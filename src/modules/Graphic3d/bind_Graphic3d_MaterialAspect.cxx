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
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TypeOfMaterial.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <TCollection_AsciiString.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_BSDF.hxx>
#include <Graphic3d_TypeOfReflection.hxx>
#include <Graphic3d_MaterialAspect.hxx>

void bind_Graphic3d_MaterialAspect(py::module &mod){

py::class_<Graphic3d_MaterialAspect, std::unique_ptr<Graphic3d_MaterialAspect, Deleter<Graphic3d_MaterialAspect>>> cls_Graphic3d_MaterialAspect(mod, "Graphic3d_MaterialAspect", "This class allows the definition of the type of a surface. Aspect attributes of a 3d face. Keywords: Material, FillArea, Shininess, Ambient, Color, Diffuse, Specular, Transparency, Emissive, ReflectionMode, BackFace, FrontFace, Reflection, Absorbtion");

// Constructors
cls_Graphic3d_MaterialAspect.def(py::init<>());
cls_Graphic3d_MaterialAspect.def(py::init<const Graphic3d_NameOfMaterial>(), py::arg("theName"));

// Fields

// Methods
// cls_Graphic3d_MaterialAspect.def_static("operator new_", (void * (*)(size_t)) &Graphic3d_MaterialAspect::operator new, "None", py::arg("theSize"));
// cls_Graphic3d_MaterialAspect.def_static("operator delete_", (void (*)(void *)) &Graphic3d_MaterialAspect::operator delete, "None", py::arg("theAddress"));
// cls_Graphic3d_MaterialAspect.def_static("operator new[]_", (void * (*)(size_t)) &Graphic3d_MaterialAspect::operator new[], "None", py::arg("theSize"));
// cls_Graphic3d_MaterialAspect.def_static("operator delete[]_", (void (*)(void *)) &Graphic3d_MaterialAspect::operator delete[], "None", py::arg("theAddress"));
// cls_Graphic3d_MaterialAspect.def_static("operator new_", (void * (*)(size_t, void *)) &Graphic3d_MaterialAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Graphic3d_MaterialAspect.def_static("operator delete_", (void (*)(void *, void *)) &Graphic3d_MaterialAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_Graphic3d_MaterialAspect.def_static("NumberOfMaterials_", (Standard_Integer (*)()) &Graphic3d_MaterialAspect::NumberOfMaterials, "Returns the number of predefined textures.");
cls_Graphic3d_MaterialAspect.def_static("MaterialName_", (Standard_CString (*)(const Standard_Integer)) &Graphic3d_MaterialAspect::MaterialName, "Returns the name of the predefined material of specified rank within range [1, NumberOfMaterials()].", py::arg("theRank"));
cls_Graphic3d_MaterialAspect.def_static("MaterialType_", (Graphic3d_TypeOfMaterial (*)(const Standard_Integer)) &Graphic3d_MaterialAspect::MaterialType, "Returns the type of the predefined material of specified rank within range [1, NumberOfMaterials()].", py::arg("theRank"));
cls_Graphic3d_MaterialAspect.def_static("MaterialFromName_", (Graphic3d_NameOfMaterial (*)(const Standard_CString)) &Graphic3d_MaterialAspect::MaterialFromName, "Returns the material for specified name or Graphic3d_NOM_DEFAULT if name is unknown.", py::arg("theName"));
cls_Graphic3d_MaterialAspect.def("Name", (Graphic3d_NameOfMaterial (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Name, "Returns the material name (within predefined enumeration).");
cls_Graphic3d_MaterialAspect.def("RequestedName", (Graphic3d_NameOfMaterial (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::RequestedName, "Returns the material name within predefined enumeration which has been requested (before modifications).");
cls_Graphic3d_MaterialAspect.def("StringName", (const TCollection_AsciiString & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::StringName, "Returns the given name of this material. This might be: - given name set by method ::SetMaterialName() - standard name for a material within enumeration - 'UserDefined' for non-standard material without name specified externally.");
cls_Graphic3d_MaterialAspect.def("MaterialName", (Standard_CString (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::MaterialName, "Returns the given name of this material. This might be:");
cls_Graphic3d_MaterialAspect.def("SetMaterialName", (void (Graphic3d_MaterialAspect::*)(const TCollection_AsciiString &)) &Graphic3d_MaterialAspect::SetMaterialName, "The current material become a 'UserDefined' material. Set the name of the 'UserDefined' material.", py::arg("theName"));
cls_Graphic3d_MaterialAspect.def("Reset", (void (Graphic3d_MaterialAspect::*)()) &Graphic3d_MaterialAspect::Reset, "Resets the material with the original values according to the material name but leave the current color values untouched for the material of type ASPECT.");
cls_Graphic3d_MaterialAspect.def("Color", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Color, "Returns the diffuse color of the surface.");
cls_Graphic3d_MaterialAspect.def("SetColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetColor, "Modifies the ambient and diffuse color of the surface.", py::arg("theColor"));
cls_Graphic3d_MaterialAspect.def("Transparency", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Transparency, "Returns the transparency coefficient of the surface (1.0 - Alpha); 0.0 means opaque.");
cls_Graphic3d_MaterialAspect.def("Alpha", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Alpha, "Returns the alpha coefficient of the surface (1.0 - Transparency); 1.0 means opaque.");
cls_Graphic3d_MaterialAspect.def("SetTransparency", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetTransparency, "Modifies the transparency coefficient of the surface, where 0 is opaque and 1 is fully transparent. Transparency is applicable to materials that have at least one of reflection modes (ambient, diffuse, specular or emissive) enabled. See also SetReflectionModeOn() and SetReflectionModeOff() methods.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("SetAlpha", (void (Graphic3d_MaterialAspect::*)(Standard_ShortReal)) &Graphic3d_MaterialAspect::SetAlpha, "Modifies the alpha coefficient of the surface, where 1.0 is opaque and 0.0 is fully transparent.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("AmbientColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::AmbientColor, "Returns the ambient color of the surface.");
cls_Graphic3d_MaterialAspect.def("SetAmbientColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetAmbientColor, "Modifies the ambient color of the surface.", py::arg("theColor"));
cls_Graphic3d_MaterialAspect.def("DiffuseColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::DiffuseColor, "Returns the diffuse color of the surface.");
cls_Graphic3d_MaterialAspect.def("SetDiffuseColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetDiffuseColor, "Modifies the diffuse color of the surface.", py::arg("theColor"));
cls_Graphic3d_MaterialAspect.def("SpecularColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::SpecularColor, "Returns the specular color of the surface.");
cls_Graphic3d_MaterialAspect.def("SetSpecularColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetSpecularColor, "Modifies the specular color of the surface.", py::arg("theColor"));
cls_Graphic3d_MaterialAspect.def("EmissiveColor", (const Quantity_Color & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::EmissiveColor, "Returns the emissive color of the surface.");
cls_Graphic3d_MaterialAspect.def("SetEmissiveColor", (void (Graphic3d_MaterialAspect::*)(const Quantity_Color &)) &Graphic3d_MaterialAspect::SetEmissiveColor, "Modifies the emissive color of the surface.", py::arg("theColor"));
cls_Graphic3d_MaterialAspect.def("Ambient", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Ambient, "Returns the reflection properties of the surface.");
cls_Graphic3d_MaterialAspect.def("SetAmbient", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetAmbient, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("Diffuse", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Diffuse, "Returns the reflection properties of the surface.");
cls_Graphic3d_MaterialAspect.def("SetDiffuse", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetDiffuse, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("Specular", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Specular, "Returns the reflection properties of the surface.");
cls_Graphic3d_MaterialAspect.def("SetSpecular", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetSpecular, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("Emissive", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Emissive, "Returns the emissive coefficient of the surface.");
cls_Graphic3d_MaterialAspect.def("SetEmissive", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetEmissive, "Modifies the reflection properties of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("Shininess", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::Shininess, "Returns the luminosity of the surface.");
cls_Graphic3d_MaterialAspect.def("SetShininess", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetShininess, "Modifies the luminosity of the surface. Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("IncreaseShine", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::IncreaseShine, "Increases or decreases the luminosity.", py::arg("theDelta"));
cls_Graphic3d_MaterialAspect.def("RefractionIndex", (Standard_ShortReal (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::RefractionIndex, "Returns the refraction index of the material");
cls_Graphic3d_MaterialAspect.def("SetRefractionIndex", (void (Graphic3d_MaterialAspect::*)(const Standard_ShortReal)) &Graphic3d_MaterialAspect::SetRefractionIndex, "Modifies the refraction index of the material. Warning: Raises MaterialDefinitionError if given value is a lesser than 1.0.", py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("BSDF", (const Graphic3d_BSDF & (Graphic3d_MaterialAspect::*)() const) &Graphic3d_MaterialAspect::BSDF, "Returns BSDF (bidirectional scattering distribution function).");
cls_Graphic3d_MaterialAspect.def("SetBSDF", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_BSDF &)) &Graphic3d_MaterialAspect::SetBSDF, "Modifies the BSDF (bidirectional scattering distribution function).", py::arg("theBSDF"));
cls_Graphic3d_MaterialAspect.def("ReflectionMode", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection) const) &Graphic3d_MaterialAspect::ReflectionMode, "Returns TRUE if the reflection mode is active, FALSE otherwise.", py::arg("theType"));
cls_Graphic3d_MaterialAspect.def("SetReflectionMode", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection, const Standard_Boolean)) &Graphic3d_MaterialAspect::SetReflectionMode, "Activates or deactivates the reflective properties of the surface with specified reflection type.", py::arg("theType"), py::arg("theValue"));
cls_Graphic3d_MaterialAspect.def("SetReflectionModeOn", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection)) &Graphic3d_MaterialAspect::SetReflectionModeOn, "Activates the reflective properties of the surface with specified reflection type.", py::arg("theType"));
cls_Graphic3d_MaterialAspect.def("SetReflectionModeOff", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfReflection)) &Graphic3d_MaterialAspect::SetReflectionModeOff, "Deactivates the reflective properties of the surface with specified reflection type.", py::arg("theType"));
cls_Graphic3d_MaterialAspect.def("MaterialType", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfMaterial) const) &Graphic3d_MaterialAspect::MaterialType, "Returns TRUE if type of this material is equal to specified type.", py::arg("theType"));
cls_Graphic3d_MaterialAspect.def("SetMaterialType", (void (Graphic3d_MaterialAspect::*)(const Graphic3d_TypeOfMaterial)) &Graphic3d_MaterialAspect::SetMaterialType, "Set material type.", py::arg("theType"));
cls_Graphic3d_MaterialAspect.def("IsDifferent", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const) &Graphic3d_MaterialAspect::IsDifferent, "Returns TRUE if this material differs from specified one.", py::arg("theOther"));
cls_Graphic3d_MaterialAspect.def("__ne__", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const) &Graphic3d_MaterialAspect::operator!=, py::is_operator(), "Returns TRUE if this material differs from specified one.", py::arg("theOther"));
cls_Graphic3d_MaterialAspect.def("IsEqual", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const) &Graphic3d_MaterialAspect::IsEqual, "Returns TRUE if this material is identical to specified one.", py::arg("theOther"));
cls_Graphic3d_MaterialAspect.def("__eq__", (Standard_Boolean (Graphic3d_MaterialAspect::*)(const Graphic3d_MaterialAspect &) const) &Graphic3d_MaterialAspect::operator==, py::is_operator(), "Returns TRUE if this material is identical to specified one.", py::arg("theOther"));

// Enums

}