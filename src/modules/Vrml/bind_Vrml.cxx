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
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Vrml_SFImage.hxx>
#include <Vrml_SFRotation.hxx>
#include <Vrml_AsciiText.hxx>
#include <Vrml_Cone.hxx>
#include <Vrml_Cube.hxx>
#include <Vrml_Cylinder.hxx>
#include <Vrml_IndexedFaceSet.hxx>
#include <Vrml_IndexedLineSet.hxx>
#include <Vrml_PointSet.hxx>
#include <Vrml_Sphere.hxx>
#include <Vrml_Coordinate3.hxx>
#include <Vrml_FontStyle.hxx>
#include <Vrml_Info.hxx>
#include <Vrml_LOD.hxx>
#include <Vrml_Material.hxx>
#include <Vrml_MaterialBinding.hxx>
#include <Vrml_Normal.hxx>
#include <Vrml_NormalBinding.hxx>
#include <Vrml_Texture2.hxx>
#include <Vrml_Texture2Transform.hxx>
#include <Vrml_TextureCoordinate2.hxx>
#include <Vrml_ShapeHints.hxx>
#include <Vrml_MatrixTransform.hxx>
#include <Vrml_Rotation.hxx>
#include <Vrml_Scale.hxx>
#include <Vrml_Transform.hxx>
#include <Vrml_Translation.hxx>
#include <Vrml_OrthographicCamera.hxx>
#include <Vrml_PerspectiveCamera.hxx>
#include <Vrml_DirectionalLight.hxx>
#include <Vrml_PointLight.hxx>
#include <Vrml_SpotLight.hxx>
#include <Vrml_Group.hxx>
#include <Vrml_Separator.hxx>
#include <Vrml_Switch.hxx>
#include <Vrml_TransformSeparator.hxx>
#include <Vrml_WWWAnchor.hxx>
#include <Vrml_WWWInline.hxx>
#include <Vrml_Instancing.hxx>
#include <Vrml.hxx>

void bind_Vrml(py::module &mod){

py::class_<Vrml, std::unique_ptr<Vrml, Deleter<Vrml>>> cls_Vrml(mod, "Vrml", "Vrml package implements the specification of the VRML ( Virtual Reality Modeling Language ). VRML is a standard language for describing interactive 3-D objects and worlds delivered across Internet. Actual version of Vrml package have made for objects of VRML version 1.0. This package is used by VrmlConverter package. The developer should already be familiar with VRML specification before using this package.");

// Constructors

// Fields

// Methods
// cls_Vrml.def_static("operator new_", (void * (*)(size_t)) &Vrml::operator new, "None", py::arg("theSize"));
// cls_Vrml.def_static("operator delete_", (void (*)(void *)) &Vrml::operator delete, "None", py::arg("theAddress"));
// cls_Vrml.def_static("operator new[]_", (void * (*)(size_t)) &Vrml::operator new[], "None", py::arg("theSize"));
// cls_Vrml.def_static("operator delete[]_", (void (*)(void *)) &Vrml::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml.def_static("operator delete_", (void (*)(void *, void *)) &Vrml::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml.def_static("VrmlHeaderWriter_", (Standard_OStream & (*)(Standard_OStream &)) &Vrml::VrmlHeaderWriter, "Writes a header in anOStream (VRML file). Writes one line of commentary in anOStream (VRML file).", py::arg("anOStream"));
cls_Vrml.def_static("CommentWriter_", (Standard_OStream & (*)(const Standard_CString, Standard_OStream &)) &Vrml::CommentWriter, "None", py::arg("aComment"), py::arg("anOStream"));

// Enums

}