/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Vrml_SFImageNumber.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_Type.hxx>
#include <Vrml_SFImage.hxx>
#include <Vrml_SFRotation.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <Vrml_AsciiTextJustification.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_AsciiText.hxx>
#include <Vrml_ConeParts.hxx>
#include <Vrml_Cone.hxx>
#include <Vrml_Cube.hxx>
#include <Vrml_CylinderParts.hxx>
#include <Vrml_Cylinder.hxx>
#include <Vrml_IndexedFaceSet.hxx>
#include <Vrml_IndexedLineSet.hxx>
#include <Vrml_PointSet.hxx>
#include <Vrml_Sphere.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <Vrml_Coordinate3.hxx>
#include <Vrml_FontStyleFamily.hxx>
#include <Vrml_FontStyleStyle.hxx>
#include <Vrml_FontStyle.hxx>
#include <TCollection_AsciiString.hxx>
#include <Vrml_Info.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Vec.hxx>
#include <Vrml_LOD.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <Vrml_Material.hxx>
#include <Vrml_MaterialBindingAndNormalBinding.hxx>
#include <Vrml_MaterialBinding.hxx>
#include <Vrml_Normal.hxx>
#include <Vrml_NormalBinding.hxx>
#include <Vrml_Texture2Wrap.hxx>
#include <Vrml_Texture2.hxx>
#include <gp_Vec2d.hxx>
#include <Vrml_Texture2Transform.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <Vrml_TextureCoordinate2.hxx>
#include <Vrml_VertexOrdering.hxx>
#include <Vrml_ShapeType.hxx>
#include <Vrml_FaceType.hxx>
#include <Vrml_ShapeHints.hxx>
#include <gp_Trsf.hxx>
#include <Vrml_MatrixTransform.hxx>
#include <Vrml_Rotation.hxx>
#include <Vrml_Scale.hxx>
#include <Vrml_Transform.hxx>
#include <Vrml_Translation.hxx>
#include <Vrml_OrthographicCamera.hxx>
#include <Vrml_PerspectiveCamera.hxx>
#include <Quantity_Color.hxx>
#include <Vrml_DirectionalLight.hxx>
#include <Vrml_PointLight.hxx>
#include <Vrml_SpotLight.hxx>
#include <Vrml_Group.hxx>
#include <Vrml_SeparatorRenderCulling.hxx>
#include <Vrml_Separator.hxx>
#include <Vrml_Switch.hxx>
#include <Vrml_TransformSeparator.hxx>
#include <Vrml_WWWAnchorMap.hxx>
#include <Vrml_WWWAnchor.hxx>
#include <Vrml_WWWInline.hxx>
#include <Vrml_Instancing.hxx>
#include <Vrml.hxx>

PYBIND11_MODULE(Vrml, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Quantity");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_VertexOrdering.hxx
	py::enum_<Vrml_VertexOrdering>(mod, "Vrml_VertexOrdering", "None")
		.value("Vrml_UNKNOWN_ORDERING", Vrml_VertexOrdering::Vrml_UNKNOWN_ORDERING)
		.value("Vrml_CLOCKWISE", Vrml_VertexOrdering::Vrml_CLOCKWISE)
		.value("Vrml_COUNTERCLOCKWISE", Vrml_VertexOrdering::Vrml_COUNTERCLOCKWISE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_ShapeType.hxx
	py::enum_<Vrml_ShapeType>(mod, "Vrml_ShapeType", "None")
		.value("Vrml_UNKNOWN_SHAPE_TYPE", Vrml_ShapeType::Vrml_UNKNOWN_SHAPE_TYPE)
		.value("Vrml_SOLID", Vrml_ShapeType::Vrml_SOLID)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_FaceType.hxx
	py::enum_<Vrml_FaceType>(mod, "Vrml_FaceType", "None")
		.value("Vrml_UNKNOWN_FACE_TYPE", Vrml_FaceType::Vrml_UNKNOWN_FACE_TYPE)
		.value("Vrml_CONVEX", Vrml_FaceType::Vrml_CONVEX)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_AsciiTextJustification.hxx
	py::enum_<Vrml_AsciiTextJustification>(mod, "Vrml_AsciiTextJustification", "None")
		.value("Vrml_LEFT", Vrml_AsciiTextJustification::Vrml_LEFT)
		.value("Vrml_CENTER", Vrml_AsciiTextJustification::Vrml_CENTER)
		.value("Vrml_RIGHT", Vrml_AsciiTextJustification::Vrml_RIGHT)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_ConeParts.hxx
	py::enum_<Vrml_ConeParts>(mod, "Vrml_ConeParts", "None")
		.value("Vrml_ConeSIDES", Vrml_ConeParts::Vrml_ConeSIDES)
		.value("Vrml_ConeBOTTOM", Vrml_ConeParts::Vrml_ConeBOTTOM)
		.value("Vrml_ConeALL", Vrml_ConeParts::Vrml_ConeALL)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_CylinderParts.hxx
	py::enum_<Vrml_CylinderParts>(mod, "Vrml_CylinderParts", "None")
		.value("Vrml_CylinderSIDES", Vrml_CylinderParts::Vrml_CylinderSIDES)
		.value("Vrml_CylinderTOP", Vrml_CylinderParts::Vrml_CylinderTOP)
		.value("Vrml_CylinderBOTTOM", Vrml_CylinderParts::Vrml_CylinderBOTTOM)
		.value("Vrml_CylinderALL", Vrml_CylinderParts::Vrml_CylinderALL)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_FontStyleFamily.hxx
	py::enum_<Vrml_FontStyleFamily>(mod, "Vrml_FontStyleFamily", "None")
		.value("Vrml_SERIF", Vrml_FontStyleFamily::Vrml_SERIF)
		.value("Vrml_SANS", Vrml_FontStyleFamily::Vrml_SANS)
		.value("Vrml_TYPEWRITER", Vrml_FontStyleFamily::Vrml_TYPEWRITER)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_FontStyleStyle.hxx
	py::enum_<Vrml_FontStyleStyle>(mod, "Vrml_FontStyleStyle", "None")
		.value("Vrml_NONE", Vrml_FontStyleStyle::Vrml_NONE)
		.value("Vrml_BOLD", Vrml_FontStyleStyle::Vrml_BOLD)
		.value("Vrml_ITALIC", Vrml_FontStyleStyle::Vrml_ITALIC)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_MaterialBindingAndNormalBinding.hxx
	py::enum_<Vrml_MaterialBindingAndNormalBinding>(mod, "Vrml_MaterialBindingAndNormalBinding", "None")
		.value("Vrml_DEFAULT", Vrml_MaterialBindingAndNormalBinding::Vrml_DEFAULT)
		.value("Vrml_OVERALL", Vrml_MaterialBindingAndNormalBinding::Vrml_OVERALL)
		.value("Vrml_PER_PART", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_PART)
		.value("Vrml_PER_PART_INDEXED", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_PART_INDEXED)
		.value("Vrml_PER_FACE", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_FACE)
		.value("Vrml_PER_FACE_INDEXED", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_FACE_INDEXED)
		.value("Vrml_PER_VERTEX", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_VERTEX)
		.value("Vrml_PER_VERTEX_INDEXED", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_VERTEX_INDEXED)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_SeparatorRenderCulling.hxx
	py::enum_<Vrml_SeparatorRenderCulling>(mod, "Vrml_SeparatorRenderCulling", "None")
		.value("Vrml_OFF", Vrml_SeparatorRenderCulling::Vrml_OFF)
		.value("Vrml_ON", Vrml_SeparatorRenderCulling::Vrml_ON)
		.value("Vrml_AUTO", Vrml_SeparatorRenderCulling::Vrml_AUTO)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_SFImageNumber.hxx
	py::enum_<Vrml_SFImageNumber>(mod, "Vrml_SFImageNumber", "qualifies VRML geometry shapes.")
		.value("Vrml_NULL", Vrml_SFImageNumber::Vrml_NULL)
		.value("Vrml_ONE", Vrml_SFImageNumber::Vrml_ONE)
		.value("Vrml_TWO", Vrml_SFImageNumber::Vrml_TWO)
		.value("Vrml_THREE", Vrml_SFImageNumber::Vrml_THREE)
		.value("Vrml_FOUR", Vrml_SFImageNumber::Vrml_FOUR)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Texture2Wrap.hxx
	py::enum_<Vrml_Texture2Wrap>(mod, "Vrml_Texture2Wrap", "None")
		.value("Vrml_REPEAT", Vrml_Texture2Wrap::Vrml_REPEAT)
		.value("Vrml_CLAMP", Vrml_Texture2Wrap::Vrml_CLAMP)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_WWWAnchorMap.hxx
	py::enum_<Vrml_WWWAnchorMap>(mod, "Vrml_WWWAnchorMap", "None")
		.value("Vrml_MAP_NONE", Vrml_WWWAnchorMap::Vrml_MAP_NONE)
		.value("Vrml_POINT", Vrml_WWWAnchorMap::Vrml_POINT)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_SFImage.hxx
	py::class_<Vrml_SFImage, opencascade::handle<Vrml_SFImage>, Standard_Transient> cls_Vrml_SFImage(mod, "Vrml_SFImage", "defines SFImage type of VRML field types.");
	cls_Vrml_SFImage.def(py::init<>());
	cls_Vrml_SFImage.def(py::init<const Standard_Integer, const Standard_Integer, const Vrml_SFImageNumber, const opencascade::handle<TColStd_HArray1OfInteger> &>(), py::arg("aWidth"), py::arg("aHeight"), py::arg("aNumber"), py::arg("anArray"));
	cls_Vrml_SFImage.def("SetWidth", (void (Vrml_SFImage::*)(const Standard_Integer)) &Vrml_SFImage::SetWidth, "None", py::arg("aWidth"));
	cls_Vrml_SFImage.def("Width", (Standard_Integer (Vrml_SFImage::*)() const ) &Vrml_SFImage::Width, "None");
	cls_Vrml_SFImage.def("SetHeight", (void (Vrml_SFImage::*)(const Standard_Integer)) &Vrml_SFImage::SetHeight, "None", py::arg("aHeight"));
	cls_Vrml_SFImage.def("Height", (Standard_Integer (Vrml_SFImage::*)() const ) &Vrml_SFImage::Height, "None");
	cls_Vrml_SFImage.def("SetNumber", (void (Vrml_SFImage::*)(const Vrml_SFImageNumber)) &Vrml_SFImage::SetNumber, "None", py::arg("aNumber"));
	cls_Vrml_SFImage.def("Number", (Vrml_SFImageNumber (Vrml_SFImage::*)() const ) &Vrml_SFImage::Number, "None");
	cls_Vrml_SFImage.def("SetArray", (void (Vrml_SFImage::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_SFImage::SetArray, "None", py::arg("anArray"));
	cls_Vrml_SFImage.def("Array", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_SFImage::*)() const ) &Vrml_SFImage::Array, "None");
	cls_Vrml_SFImage.def("ArrayFlag", (Standard_Boolean (Vrml_SFImage::*)() const ) &Vrml_SFImage::ArrayFlag, "None");
	cls_Vrml_SFImage.def_static("get_type_name_", (const char * (*)()) &Vrml_SFImage::get_type_name, "None");
	cls_Vrml_SFImage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_SFImage::get_type_descriptor, "None");
	cls_Vrml_SFImage.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_SFImage::*)() const ) &Vrml_SFImage::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_SFRotation.hxx
	py::class_<Vrml_SFRotation, std::unique_ptr<Vrml_SFRotation, Deleter<Vrml_SFRotation>>> cls_Vrml_SFRotation(mod, "Vrml_SFRotation", "defines SFRotation type of VRML field types. The 4 values represent an axis of rotation followed by amount of right-handed rotation about the that axis, in radians.");
	cls_Vrml_SFRotation.def(py::init<>());
	cls_Vrml_SFRotation.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aRotationX"), py::arg("aRotationY"), py::arg("aRotationZ"), py::arg("anAngle"));
	cls_Vrml_SFRotation.def("SetRotationX", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetRotationX, "None", py::arg("aRotationX"));
	cls_Vrml_SFRotation.def("RotationX", (Standard_Real (Vrml_SFRotation::*)() const ) &Vrml_SFRotation::RotationX, "None");
	cls_Vrml_SFRotation.def("SetRotationY", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetRotationY, "None", py::arg("aRotationY"));
	cls_Vrml_SFRotation.def("RotationY", (Standard_Real (Vrml_SFRotation::*)() const ) &Vrml_SFRotation::RotationY, "None");
	cls_Vrml_SFRotation.def("SetRotationZ", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetRotationZ, "None", py::arg("aRotationZ"));
	cls_Vrml_SFRotation.def("RotationZ", (Standard_Real (Vrml_SFRotation::*)() const ) &Vrml_SFRotation::RotationZ, "None");
	cls_Vrml_SFRotation.def("SetAngle", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetAngle, "None", py::arg("anAngle"));
	cls_Vrml_SFRotation.def("Angle", (Standard_Real (Vrml_SFRotation::*)() const ) &Vrml_SFRotation::Angle, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_AsciiText.hxx
	py::class_<Vrml_AsciiText, opencascade::handle<Vrml_AsciiText>, Standard_Transient> cls_Vrml_AsciiText(mod, "Vrml_AsciiText", "defines a AsciiText node of VRML specifying geometry shapes. This node represents strings of text characters from ASCII coded character set. All subsequent strings advance y by -( size * spacing). The justification field determines the placement of the strings in the x dimension. LEFT (the default) places the left edge of each string at x=0. CENTER places the center of each string at x=0. RIGHT places the right edge of each string at x=0. Text is rendered from left to right, top to bottom in the font set by FontStyle. The default value for the wigth field indicates the natural width should be used for that string.");
	cls_Vrml_AsciiText.def(py::init<>());
	cls_Vrml_AsciiText.def(py::init<const opencascade::handle<TColStd_HArray1OfAsciiString> &, const Standard_Real, const Vrml_AsciiTextJustification, const Standard_Real>(), py::arg("aString"), py::arg("aSpacing"), py::arg("aJustification"), py::arg("aWidth"));
	cls_Vrml_AsciiText.def("SetString", (void (Vrml_AsciiText::*)(const opencascade::handle<TColStd_HArray1OfAsciiString> &)) &Vrml_AsciiText::SetString, "None", py::arg("aString"));
	cls_Vrml_AsciiText.def("String", (opencascade::handle<TColStd_HArray1OfAsciiString> (Vrml_AsciiText::*)() const ) &Vrml_AsciiText::String, "None");
	cls_Vrml_AsciiText.def("SetSpacing", (void (Vrml_AsciiText::*)(const Standard_Real)) &Vrml_AsciiText::SetSpacing, "None", py::arg("aSpacing"));
	cls_Vrml_AsciiText.def("Spacing", (Standard_Real (Vrml_AsciiText::*)() const ) &Vrml_AsciiText::Spacing, "None");
	cls_Vrml_AsciiText.def("SetJustification", (void (Vrml_AsciiText::*)(const Vrml_AsciiTextJustification)) &Vrml_AsciiText::SetJustification, "None", py::arg("aJustification"));
	cls_Vrml_AsciiText.def("Justification", (Vrml_AsciiTextJustification (Vrml_AsciiText::*)() const ) &Vrml_AsciiText::Justification, "None");
	cls_Vrml_AsciiText.def("SetWidth", (void (Vrml_AsciiText::*)(const Standard_Real)) &Vrml_AsciiText::SetWidth, "None", py::arg("aWidth"));
	cls_Vrml_AsciiText.def("Width", (Standard_Real (Vrml_AsciiText::*)() const ) &Vrml_AsciiText::Width, "None");
	cls_Vrml_AsciiText.def("Print", (Standard_OStream & (Vrml_AsciiText::*)(Standard_OStream &) const ) &Vrml_AsciiText::Print, "None", py::arg("anOStream"));
	cls_Vrml_AsciiText.def_static("get_type_name_", (const char * (*)()) &Vrml_AsciiText::get_type_name, "None");
	cls_Vrml_AsciiText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_AsciiText::get_type_descriptor, "None");
	cls_Vrml_AsciiText.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_AsciiText::*)() const ) &Vrml_AsciiText::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Cone.hxx
	py::class_<Vrml_Cone, std::unique_ptr<Vrml_Cone, Deleter<Vrml_Cone>>> cls_Vrml_Cone(mod, "Vrml_Cone", "defines a Cone node of VRML specifying geometry shapes. This node represents a simple cone, whose central axis is aligned with the y-axis. By default , the cone is centred at (0,0,0) and has size of -1 to +1 in the all three directions. the cone has a radius of 1 at the bottom and height of 2, with its apex at 1 and its bottom at -1. The cone has two parts: the sides and the bottom");
	cls_Vrml_Cone.def(py::init<>());
	cls_Vrml_Cone.def(py::init<const Vrml_ConeParts>(), py::arg("aParts"));
	cls_Vrml_Cone.def(py::init<const Vrml_ConeParts, const Standard_Real>(), py::arg("aParts"), py::arg("aBottomRadius"));
	cls_Vrml_Cone.def(py::init<const Vrml_ConeParts, const Standard_Real, const Standard_Real>(), py::arg("aParts"), py::arg("aBottomRadius"), py::arg("aHeight"));
	cls_Vrml_Cone.def("SetParts", (void (Vrml_Cone::*)(const Vrml_ConeParts)) &Vrml_Cone::SetParts, "None", py::arg("aParts"));
	cls_Vrml_Cone.def("Parts", (Vrml_ConeParts (Vrml_Cone::*)() const ) &Vrml_Cone::Parts, "None");
	cls_Vrml_Cone.def("SetBottomRadius", (void (Vrml_Cone::*)(const Standard_Real)) &Vrml_Cone::SetBottomRadius, "None", py::arg("aBottomRadius"));
	cls_Vrml_Cone.def("BottomRadius", (Standard_Real (Vrml_Cone::*)() const ) &Vrml_Cone::BottomRadius, "None");
	cls_Vrml_Cone.def("SetHeight", (void (Vrml_Cone::*)(const Standard_Real)) &Vrml_Cone::SetHeight, "None", py::arg("aHeight"));
	cls_Vrml_Cone.def("Height", (Standard_Real (Vrml_Cone::*)() const ) &Vrml_Cone::Height, "None");
	cls_Vrml_Cone.def("Print", (Standard_OStream & (Vrml_Cone::*)(Standard_OStream &) const ) &Vrml_Cone::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Cube.hxx
	py::class_<Vrml_Cube, std::unique_ptr<Vrml_Cube, Deleter<Vrml_Cube>>> cls_Vrml_Cube(mod, "Vrml_Cube", "defines a Cube node of VRML specifying geometry shapes. This node represents a cuboid aligned with the coordinate axes. By default , the cube is centred at (0,0,0) and measures 2 units in each dimension, from -1 to +1. A cube's width is its extent along its object-space X axis, its height is its extent along the object-space Y axis, and its depth is its extent along its object-space Z axis.");
	cls_Vrml_Cube.def(py::init<>());
	cls_Vrml_Cube.def(py::init<const Standard_Real>(), py::arg("aWidth"));
	cls_Vrml_Cube.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("aWidth"), py::arg("aHeight"));
	cls_Vrml_Cube.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aWidth"), py::arg("aHeight"), py::arg("aDepth"));
	cls_Vrml_Cube.def("SetWidth", (void (Vrml_Cube::*)(const Standard_Real)) &Vrml_Cube::SetWidth, "None", py::arg("aWidth"));
	cls_Vrml_Cube.def("Width", (Standard_Real (Vrml_Cube::*)() const ) &Vrml_Cube::Width, "None");
	cls_Vrml_Cube.def("SetHeight", (void (Vrml_Cube::*)(const Standard_Real)) &Vrml_Cube::SetHeight, "None", py::arg("aHeight"));
	cls_Vrml_Cube.def("Height", (Standard_Real (Vrml_Cube::*)() const ) &Vrml_Cube::Height, "None");
	cls_Vrml_Cube.def("SetDepth", (void (Vrml_Cube::*)(const Standard_Real)) &Vrml_Cube::SetDepth, "None", py::arg("aDepth"));
	cls_Vrml_Cube.def("Depth", (Standard_Real (Vrml_Cube::*)() const ) &Vrml_Cube::Depth, "None");
	cls_Vrml_Cube.def("Print", (Standard_OStream & (Vrml_Cube::*)(Standard_OStream &) const ) &Vrml_Cube::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Cylinder.hxx
	py::class_<Vrml_Cylinder, std::unique_ptr<Vrml_Cylinder, Deleter<Vrml_Cylinder>>> cls_Vrml_Cylinder(mod, "Vrml_Cylinder", "defines a Cylinder node of VRML specifying geometry shapes. This node represents a simple capped cylinder centred around the y-axis. By default , the cylinder is centred at (0,0,0) and has size of -1 to +1 in the all three dimensions. The cylinder has three parts: the sides, the top (y=+1) and the bottom (y=-1)");
	cls_Vrml_Cylinder.def(py::init<>());
	cls_Vrml_Cylinder.def(py::init<const Vrml_CylinderParts>(), py::arg("aParts"));
	cls_Vrml_Cylinder.def(py::init<const Vrml_CylinderParts, const Standard_Real>(), py::arg("aParts"), py::arg("aRadius"));
	cls_Vrml_Cylinder.def(py::init<const Vrml_CylinderParts, const Standard_Real, const Standard_Real>(), py::arg("aParts"), py::arg("aRadius"), py::arg("aHeight"));
	cls_Vrml_Cylinder.def("SetParts", (void (Vrml_Cylinder::*)(const Vrml_CylinderParts)) &Vrml_Cylinder::SetParts, "None", py::arg("aParts"));
	cls_Vrml_Cylinder.def("Parts", (Vrml_CylinderParts (Vrml_Cylinder::*)() const ) &Vrml_Cylinder::Parts, "None");
	cls_Vrml_Cylinder.def("SetRadius", (void (Vrml_Cylinder::*)(const Standard_Real)) &Vrml_Cylinder::SetRadius, "None", py::arg("aRadius"));
	cls_Vrml_Cylinder.def("Radius", (Standard_Real (Vrml_Cylinder::*)() const ) &Vrml_Cylinder::Radius, "None");
	cls_Vrml_Cylinder.def("SetHeight", (void (Vrml_Cylinder::*)(const Standard_Real)) &Vrml_Cylinder::SetHeight, "None", py::arg("aHeight"));
	cls_Vrml_Cylinder.def("Height", (Standard_Real (Vrml_Cylinder::*)() const ) &Vrml_Cylinder::Height, "None");
	cls_Vrml_Cylinder.def("Print", (Standard_OStream & (Vrml_Cylinder::*)(Standard_OStream &) const ) &Vrml_Cylinder::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_IndexedFaceSet.hxx
	py::class_<Vrml_IndexedFaceSet, opencascade::handle<Vrml_IndexedFaceSet>, Standard_Transient> cls_Vrml_IndexedFaceSet(mod, "Vrml_IndexedFaceSet", "defines a IndexedFaceSet node of VRML specifying geometry shapes. This node represents a 3D shape formed by constructing faces (polygons) from vertices located at the current coordinates. IndexedFaceSet uses the indices in its coordIndex to define polygonal faces. An index of -1 separates faces (so a -1 at the end of the list is optional).");
	cls_Vrml_IndexedFaceSet.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &>(), py::arg("aCoordIndex"), py::arg("aMaterialIndex"), py::arg("aNormalIndex"), py::arg("aTextureCoordIndex"));
	cls_Vrml_IndexedFaceSet.def(py::init<>());
	cls_Vrml_IndexedFaceSet.def("SetCoordIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetCoordIndex, "None", py::arg("aCoordIndex"));
	cls_Vrml_IndexedFaceSet.def("CoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const ) &Vrml_IndexedFaceSet::CoordIndex, "None");
	cls_Vrml_IndexedFaceSet.def("SetMaterialIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetMaterialIndex, "None", py::arg("aMaterialIndex"));
	cls_Vrml_IndexedFaceSet.def("MaterialIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const ) &Vrml_IndexedFaceSet::MaterialIndex, "None");
	cls_Vrml_IndexedFaceSet.def("SetNormalIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetNormalIndex, "None", py::arg("aNormalIndex"));
	cls_Vrml_IndexedFaceSet.def("NormalIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const ) &Vrml_IndexedFaceSet::NormalIndex, "None");
	cls_Vrml_IndexedFaceSet.def("SetTextureCoordIndex", (void (Vrml_IndexedFaceSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedFaceSet::SetTextureCoordIndex, "None", py::arg("aTextureCoordIndex"));
	cls_Vrml_IndexedFaceSet.def("TextureCoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedFaceSet::*)() const ) &Vrml_IndexedFaceSet::TextureCoordIndex, "None");
	cls_Vrml_IndexedFaceSet.def("Print", (Standard_OStream & (Vrml_IndexedFaceSet::*)(Standard_OStream &) const ) &Vrml_IndexedFaceSet::Print, "None", py::arg("anOStream"));
	cls_Vrml_IndexedFaceSet.def_static("get_type_name_", (const char * (*)()) &Vrml_IndexedFaceSet::get_type_name, "None");
	cls_Vrml_IndexedFaceSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_IndexedFaceSet::get_type_descriptor, "None");
	cls_Vrml_IndexedFaceSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_IndexedFaceSet::*)() const ) &Vrml_IndexedFaceSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_IndexedLineSet.hxx
	py::class_<Vrml_IndexedLineSet, opencascade::handle<Vrml_IndexedLineSet>, Standard_Transient> cls_Vrml_IndexedLineSet(mod, "Vrml_IndexedLineSet", "defines a IndexedLineSet node of VRML specifying geometry shapes. This node represents a 3D shape formed by constructing polylines from vertices located at the current coordinates. IndexedLineSet uses the indices in its coordIndex field to specify the polylines. An index of -1 separates one polyline from the next (thus, a final -1 is optional). the current polyline has ended and the next one begins. Treatment of the current material and normal binding is as follows: The PER_PART binding specifies a material or normal for each segment of the line. The PER_FACE binding specifies a material or normal for each polyline. PER_VERTEX specifies a material or normal for each vertex. The corresponding _INDEXED bindings are the same, but use the materialIndex or normalIndex indices. The DEFAULT material binding is equal to OVERALL. The DEFAULT normal binding is equal to PER_VERTEX_INDEXED; if insufficient normals exist in the state, the lines will be drawn unlit. The same rules for texture coordinate generation as IndexedFaceSet are used.");
	cls_Vrml_IndexedLineSet.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &>(), py::arg("aCoordIndex"), py::arg("aMaterialIndex"), py::arg("aNormalIndex"), py::arg("aTextureCoordIndex"));
	cls_Vrml_IndexedLineSet.def(py::init<>());
	cls_Vrml_IndexedLineSet.def("SetCoordIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetCoordIndex, "None", py::arg("aCoordIndex"));
	cls_Vrml_IndexedLineSet.def("CoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const ) &Vrml_IndexedLineSet::CoordIndex, "None");
	cls_Vrml_IndexedLineSet.def("SetMaterialIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetMaterialIndex, "None", py::arg("aMaterialIndex"));
	cls_Vrml_IndexedLineSet.def("MaterialIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const ) &Vrml_IndexedLineSet::MaterialIndex, "None");
	cls_Vrml_IndexedLineSet.def("SetNormalIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetNormalIndex, "None", py::arg("aNormalIndex"));
	cls_Vrml_IndexedLineSet.def("NormalIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const ) &Vrml_IndexedLineSet::NormalIndex, "None");
	cls_Vrml_IndexedLineSet.def("SetTextureCoordIndex", (void (Vrml_IndexedLineSet::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_IndexedLineSet::SetTextureCoordIndex, "None", py::arg("aTextureCoordIndex"));
	cls_Vrml_IndexedLineSet.def("TextureCoordIndex", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_IndexedLineSet::*)() const ) &Vrml_IndexedLineSet::TextureCoordIndex, "None");
	cls_Vrml_IndexedLineSet.def("Print", (Standard_OStream & (Vrml_IndexedLineSet::*)(Standard_OStream &) const ) &Vrml_IndexedLineSet::Print, "None", py::arg("anOStream"));
	cls_Vrml_IndexedLineSet.def_static("get_type_name_", (const char * (*)()) &Vrml_IndexedLineSet::get_type_name, "None");
	cls_Vrml_IndexedLineSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_IndexedLineSet::get_type_descriptor, "None");
	cls_Vrml_IndexedLineSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_IndexedLineSet::*)() const ) &Vrml_IndexedLineSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_PointSet.hxx
	py::class_<Vrml_PointSet, std::unique_ptr<Vrml_PointSet, Deleter<Vrml_PointSet>>> cls_Vrml_PointSet(mod, "Vrml_PointSet", "defines a PointSet node of VRML specifying geometry shapes.");
	cls_Vrml_PointSet.def(py::init<>());
	cls_Vrml_PointSet.def(py::init<const Standard_Integer>(), py::arg("aStartIndex"));
	cls_Vrml_PointSet.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aStartIndex"), py::arg("aNumPoints"));
	cls_Vrml_PointSet.def("SetStartIndex", (void (Vrml_PointSet::*)(const Standard_Integer)) &Vrml_PointSet::SetStartIndex, "None", py::arg("aStartIndex"));
	cls_Vrml_PointSet.def("StartIndex", (Standard_Integer (Vrml_PointSet::*)() const ) &Vrml_PointSet::StartIndex, "None");
	cls_Vrml_PointSet.def("SetNumPoints", (void (Vrml_PointSet::*)(const Standard_Integer)) &Vrml_PointSet::SetNumPoints, "None", py::arg("aNumPoints"));
	cls_Vrml_PointSet.def("NumPoints", (Standard_Integer (Vrml_PointSet::*)() const ) &Vrml_PointSet::NumPoints, "None");
	cls_Vrml_PointSet.def("Print", (Standard_OStream & (Vrml_PointSet::*)(Standard_OStream &) const ) &Vrml_PointSet::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Sphere.hxx
	py::class_<Vrml_Sphere, std::unique_ptr<Vrml_Sphere, Deleter<Vrml_Sphere>>> cls_Vrml_Sphere(mod, "Vrml_Sphere", "defines a Sphere node of VRML specifying geometry shapes. This node represents a sphere. By default , the sphere is centred at (0,0,0) and has a radius of 1.");
	cls_Vrml_Sphere.def(py::init<>());
	cls_Vrml_Sphere.def(py::init<const Standard_Real>(), py::arg("aRadius"));
	cls_Vrml_Sphere.def("SetRadius", (void (Vrml_Sphere::*)(const Standard_Real)) &Vrml_Sphere::SetRadius, "None", py::arg("aRadius"));
	cls_Vrml_Sphere.def("Radius", (Standard_Real (Vrml_Sphere::*)() const ) &Vrml_Sphere::Radius, "None");
	cls_Vrml_Sphere.def("Print", (Standard_OStream & (Vrml_Sphere::*)(Standard_OStream &) const ) &Vrml_Sphere::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Coordinate3.hxx
	py::class_<Vrml_Coordinate3, opencascade::handle<Vrml_Coordinate3>, Standard_Transient> cls_Vrml_Coordinate3(mod, "Vrml_Coordinate3", "defines a Coordinate3 node of VRML specifying properties of geometry and its appearance. This node defines a set of 3D coordinates to be used by a subsequent IndexedFaceSet, IndexedLineSet, or PointSet node. This node does not produce a visible result during rendering; it simply replaces the current coordinates in the rendering state for subsequent nodes to use.");
	cls_Vrml_Coordinate3.def(py::init<const opencascade::handle<TColgp_HArray1OfVec> &>(), py::arg("aPoint"));
	cls_Vrml_Coordinate3.def(py::init<>());
	cls_Vrml_Coordinate3.def("SetPoint", (void (Vrml_Coordinate3::*)(const opencascade::handle<TColgp_HArray1OfVec> &)) &Vrml_Coordinate3::SetPoint, "None", py::arg("aPoint"));
	cls_Vrml_Coordinate3.def("Point", (opencascade::handle<TColgp_HArray1OfVec> (Vrml_Coordinate3::*)() const ) &Vrml_Coordinate3::Point, "None");
	cls_Vrml_Coordinate3.def("Print", (Standard_OStream & (Vrml_Coordinate3::*)(Standard_OStream &) const ) &Vrml_Coordinate3::Print, "None", py::arg("anOStream"));
	cls_Vrml_Coordinate3.def_static("get_type_name_", (const char * (*)()) &Vrml_Coordinate3::get_type_name, "None");
	cls_Vrml_Coordinate3.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_Coordinate3::get_type_descriptor, "None");
	cls_Vrml_Coordinate3.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_Coordinate3::*)() const ) &Vrml_Coordinate3::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_FontStyle.hxx
	py::class_<Vrml_FontStyle, std::unique_ptr<Vrml_FontStyle, Deleter<Vrml_FontStyle>>> cls_Vrml_FontStyle(mod, "Vrml_FontStyle", "defines a FontStyle node of VRML of properties of geometry and its appearance. The size field specifies the height (in object space units) of glyphs rendered and determines the vertical spacing of adjacent lines of text.");
	cls_Vrml_FontStyle.def(py::init<>());
	cls_Vrml_FontStyle.def(py::init<const Standard_Real>(), py::arg("aSize"));
	cls_Vrml_FontStyle.def(py::init<const Standard_Real, const Vrml_FontStyleFamily>(), py::arg("aSize"), py::arg("aFamily"));
	cls_Vrml_FontStyle.def(py::init<const Standard_Real, const Vrml_FontStyleFamily, const Vrml_FontStyleStyle>(), py::arg("aSize"), py::arg("aFamily"), py::arg("aStyle"));
	cls_Vrml_FontStyle.def("SetSize", (void (Vrml_FontStyle::*)(const Standard_Real)) &Vrml_FontStyle::SetSize, "None", py::arg("aSize"));
	cls_Vrml_FontStyle.def("Size", (Standard_Real (Vrml_FontStyle::*)() const ) &Vrml_FontStyle::Size, "None");
	cls_Vrml_FontStyle.def("SetFamily", (void (Vrml_FontStyle::*)(const Vrml_FontStyleFamily)) &Vrml_FontStyle::SetFamily, "None", py::arg("aFamily"));
	cls_Vrml_FontStyle.def("Family", (Vrml_FontStyleFamily (Vrml_FontStyle::*)() const ) &Vrml_FontStyle::Family, "None");
	cls_Vrml_FontStyle.def("SetStyle", (void (Vrml_FontStyle::*)(const Vrml_FontStyleStyle)) &Vrml_FontStyle::SetStyle, "None", py::arg("aStyle"));
	cls_Vrml_FontStyle.def("Style", (Vrml_FontStyleStyle (Vrml_FontStyle::*)() const ) &Vrml_FontStyle::Style, "None");
	cls_Vrml_FontStyle.def("Print", (Standard_OStream & (Vrml_FontStyle::*)(Standard_OStream &) const ) &Vrml_FontStyle::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Info.hxx
	py::class_<Vrml_Info, std::unique_ptr<Vrml_Info, Deleter<Vrml_Info>>> cls_Vrml_Info(mod, "Vrml_Info", "defines a Info node of VRML specifying properties of geometry and its appearance. It is used to store information in the scene graph, Typically for application-specific purposes, copyright messages, or other strings.");
	cls_Vrml_Info.def(py::init<>());
	cls_Vrml_Info.def(py::init<const TCollection_AsciiString &>(), py::arg("aString"));
	cls_Vrml_Info.def("SetString", (void (Vrml_Info::*)(const TCollection_AsciiString &)) &Vrml_Info::SetString, "None", py::arg("aString"));
	cls_Vrml_Info.def("String", (TCollection_AsciiString (Vrml_Info::*)() const ) &Vrml_Info::String, "None");
	cls_Vrml_Info.def("Print", (Standard_OStream & (Vrml_Info::*)(Standard_OStream &) const ) &Vrml_Info::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_LOD.hxx
	py::class_<Vrml_LOD, opencascade::handle<Vrml_LOD>, Standard_Transient> cls_Vrml_LOD(mod, "Vrml_LOD", "defines a LOD (level of detailization) node of VRML specifying properties of geometry and its appearance. This group node is used to allow applications to switch between various representations of objects automatically. The children of this node typically represent the same object or objects at the varying of Levels Of Detail (LOD), from highest detail to lowest.");
	cls_Vrml_LOD.def(py::init<>());
	cls_Vrml_LOD.def(py::init<const opencascade::handle<TColStd_HArray1OfReal> &, const gp_Vec &>(), py::arg("aRange"), py::arg("aCenter"));
	cls_Vrml_LOD.def("SetRange", (void (Vrml_LOD::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Vrml_LOD::SetRange, "None", py::arg("aRange"));
	cls_Vrml_LOD.def("Range", (opencascade::handle<TColStd_HArray1OfReal> (Vrml_LOD::*)() const ) &Vrml_LOD::Range, "None");
	cls_Vrml_LOD.def("SetCenter", (void (Vrml_LOD::*)(const gp_Vec &)) &Vrml_LOD::SetCenter, "None", py::arg("aCenter"));
	cls_Vrml_LOD.def("Center", (gp_Vec (Vrml_LOD::*)() const ) &Vrml_LOD::Center, "None");
	cls_Vrml_LOD.def("Print", (Standard_OStream & (Vrml_LOD::*)(Standard_OStream &) const ) &Vrml_LOD::Print, "None", py::arg("anOStream"));
	cls_Vrml_LOD.def_static("get_type_name_", (const char * (*)()) &Vrml_LOD::get_type_name, "None");
	cls_Vrml_LOD.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_LOD::get_type_descriptor, "None");
	cls_Vrml_LOD.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_LOD::*)() const ) &Vrml_LOD::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Material.hxx
	py::class_<Vrml_Material, opencascade::handle<Vrml_Material>, Standard_Transient> cls_Vrml_Material(mod, "Vrml_Material", "defines a Material node of VRML specifying properties of geometry and its appearance. This node defines the current surface material properties for all subsequent shapes. Material sets several components of the current material during traversal. Different shapes interpret materials with multiple values differently. To bind materials to shapes, use a MaterialBinding node.");
	cls_Vrml_Material.def(py::init<const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("aAmbientColor"), py::arg("aDiffuseColor"), py::arg("aSpecularColor"), py::arg("aEmissiveColor"), py::arg("aShininess"), py::arg("aTransparency"));
	cls_Vrml_Material.def(py::init<>());
	cls_Vrml_Material.def("SetAmbientColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetAmbientColor, "None", py::arg("aAmbientColor"));
	cls_Vrml_Material.def("AmbientColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const ) &Vrml_Material::AmbientColor, "None");
	cls_Vrml_Material.def("SetDiffuseColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetDiffuseColor, "None", py::arg("aDiffuseColor"));
	cls_Vrml_Material.def("DiffuseColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const ) &Vrml_Material::DiffuseColor, "None");
	cls_Vrml_Material.def("SetSpecularColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetSpecularColor, "None", py::arg("aSpecularColor"));
	cls_Vrml_Material.def("SpecularColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const ) &Vrml_Material::SpecularColor, "None");
	cls_Vrml_Material.def("SetEmissiveColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetEmissiveColor, "None", py::arg("aEmissiveColor"));
	cls_Vrml_Material.def("EmissiveColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const ) &Vrml_Material::EmissiveColor, "None");
	cls_Vrml_Material.def("SetShininess", (void (Vrml_Material::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Vrml_Material::SetShininess, "None", py::arg("aShininess"));
	cls_Vrml_Material.def("Shininess", (opencascade::handle<TColStd_HArray1OfReal> (Vrml_Material::*)() const ) &Vrml_Material::Shininess, "None");
	cls_Vrml_Material.def("SetTransparency", (void (Vrml_Material::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Vrml_Material::SetTransparency, "None", py::arg("aTransparency"));
	cls_Vrml_Material.def("Transparency", (opencascade::handle<TColStd_HArray1OfReal> (Vrml_Material::*)() const ) &Vrml_Material::Transparency, "None");
	cls_Vrml_Material.def("Print", (Standard_OStream & (Vrml_Material::*)(Standard_OStream &) const ) &Vrml_Material::Print, "None", py::arg("anOStream"));
	cls_Vrml_Material.def_static("get_type_name_", (const char * (*)()) &Vrml_Material::get_type_name, "None");
	cls_Vrml_Material.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_Material::get_type_descriptor, "None");
	cls_Vrml_Material.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_Material::*)() const ) &Vrml_Material::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_MaterialBinding.hxx
	py::class_<Vrml_MaterialBinding, std::unique_ptr<Vrml_MaterialBinding, Deleter<Vrml_MaterialBinding>>> cls_Vrml_MaterialBinding(mod, "Vrml_MaterialBinding", "defines a MaterialBinding node of VRML specifying properties of geometry and its appearance. Material nodes may contain more than one material. This node specifies how the current materials are bound to shapes that follow in the scene graph. Each shape node may interpret bindings differently. For example, a Sphere node is always drawn using the first material in the material node, no matter what the current MaterialBinding, while a Cube node may use six different materials to draw each of its six faces, depending on the MaterialBinding.");
	cls_Vrml_MaterialBinding.def(py::init<const Vrml_MaterialBindingAndNormalBinding>(), py::arg("aValue"));
	cls_Vrml_MaterialBinding.def(py::init<>());
	cls_Vrml_MaterialBinding.def("SetValue", (void (Vrml_MaterialBinding::*)(const Vrml_MaterialBindingAndNormalBinding)) &Vrml_MaterialBinding::SetValue, "None", py::arg("aValue"));
	cls_Vrml_MaterialBinding.def("Value", (Vrml_MaterialBindingAndNormalBinding (Vrml_MaterialBinding::*)() const ) &Vrml_MaterialBinding::Value, "None");
	cls_Vrml_MaterialBinding.def("Print", (Standard_OStream & (Vrml_MaterialBinding::*)(Standard_OStream &) const ) &Vrml_MaterialBinding::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Normal.hxx
	py::class_<Vrml_Normal, opencascade::handle<Vrml_Normal>, Standard_Transient> cls_Vrml_Normal(mod, "Vrml_Normal", "defines a Normal node of VRML specifying properties of geometry and its appearance. This node defines a set of 3D surface normal vectors to be used by vertex-based shape nodes (IndexedFaceSet, IndexedLineSet, PointSet) that follow it in the scene graph. This node does not produce a visible result during rendering; it simply replaces the current normals in the rendering state for subsequent nodes to use. This node contains one multiple-valued field that contains the normal vectors.");
	cls_Vrml_Normal.def(py::init<const opencascade::handle<TColgp_HArray1OfVec> &>(), py::arg("aVector"));
	cls_Vrml_Normal.def(py::init<>());
	cls_Vrml_Normal.def("SetVector", (void (Vrml_Normal::*)(const opencascade::handle<TColgp_HArray1OfVec> &)) &Vrml_Normal::SetVector, "None", py::arg("aVector"));
	cls_Vrml_Normal.def("Vector", (opencascade::handle<TColgp_HArray1OfVec> (Vrml_Normal::*)() const ) &Vrml_Normal::Vector, "None");
	cls_Vrml_Normal.def("Print", (Standard_OStream & (Vrml_Normal::*)(Standard_OStream &) const ) &Vrml_Normal::Print, "None", py::arg("anOStream"));
	cls_Vrml_Normal.def_static("get_type_name_", (const char * (*)()) &Vrml_Normal::get_type_name, "None");
	cls_Vrml_Normal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_Normal::get_type_descriptor, "None");
	cls_Vrml_Normal.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_Normal::*)() const ) &Vrml_Normal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_NormalBinding.hxx
	py::class_<Vrml_NormalBinding, std::unique_ptr<Vrml_NormalBinding, Deleter<Vrml_NormalBinding>>> cls_Vrml_NormalBinding(mod, "Vrml_NormalBinding", "defines a NormalBinding node of VRML specifying properties of geometry and its appearance. This node specifies how the current normals are bound to shapes that follow in the scene graph. Each shape node may interpret bindings differently. The bindings for faces and vertices are meaningful only for shapes that are made from faces and vertices. Similarly, the indexed bindings are only used by the shapes that allow indexing. For bindings that require multiple normals, be sure to have at least as many normals defined as are necessary; otherwise, errors will occur.");
	cls_Vrml_NormalBinding.def(py::init<const Vrml_MaterialBindingAndNormalBinding>(), py::arg("aValue"));
	cls_Vrml_NormalBinding.def(py::init<>());
	cls_Vrml_NormalBinding.def("SetValue", (void (Vrml_NormalBinding::*)(const Vrml_MaterialBindingAndNormalBinding)) &Vrml_NormalBinding::SetValue, "None", py::arg("aValue"));
	cls_Vrml_NormalBinding.def("Value", (Vrml_MaterialBindingAndNormalBinding (Vrml_NormalBinding::*)() const ) &Vrml_NormalBinding::Value, "None");
	cls_Vrml_NormalBinding.def("Print", (Standard_OStream & (Vrml_NormalBinding::*)(Standard_OStream &) const ) &Vrml_NormalBinding::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Texture2.hxx
	py::class_<Vrml_Texture2, std::unique_ptr<Vrml_Texture2, Deleter<Vrml_Texture2>>> cls_Vrml_Texture2(mod, "Vrml_Texture2", "defines a Texture2 node of VRML specifying properties of geometry and its appearance. This property node defines a texture map and parameters for that map The texture can be read from the URL specified by the filename field. To turn off texturing, set the filename field to an empty string (''). Textures can alsobe specified inline by setting the image field to contain the texture data. By default : myFilename ('') myImage (0 0 0) myWrapS (Vrml_REPEAT) myWrapT (Vrml_REPEAT)");
	cls_Vrml_Texture2.def(py::init<>());
	cls_Vrml_Texture2.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Vrml_SFImage> &, const Vrml_Texture2Wrap, const Vrml_Texture2Wrap>(), py::arg("aFilename"), py::arg("aImage"), py::arg("aWrapS"), py::arg("aWrapT"));
	cls_Vrml_Texture2.def("SetFilename", (void (Vrml_Texture2::*)(const TCollection_AsciiString &)) &Vrml_Texture2::SetFilename, "None", py::arg("aFilename"));
	cls_Vrml_Texture2.def("Filename", (TCollection_AsciiString (Vrml_Texture2::*)() const ) &Vrml_Texture2::Filename, "None");
	cls_Vrml_Texture2.def("SetImage", (void (Vrml_Texture2::*)(const opencascade::handle<Vrml_SFImage> &)) &Vrml_Texture2::SetImage, "None", py::arg("aImage"));
	cls_Vrml_Texture2.def("Image", (opencascade::handle<Vrml_SFImage> (Vrml_Texture2::*)() const ) &Vrml_Texture2::Image, "None");
	cls_Vrml_Texture2.def("SetWrapS", (void (Vrml_Texture2::*)(const Vrml_Texture2Wrap)) &Vrml_Texture2::SetWrapS, "None", py::arg("aWrapS"));
	cls_Vrml_Texture2.def("WrapS", (Vrml_Texture2Wrap (Vrml_Texture2::*)() const ) &Vrml_Texture2::WrapS, "None");
	cls_Vrml_Texture2.def("SetWrapT", (void (Vrml_Texture2::*)(const Vrml_Texture2Wrap)) &Vrml_Texture2::SetWrapT, "None", py::arg("aWrapT"));
	cls_Vrml_Texture2.def("WrapT", (Vrml_Texture2Wrap (Vrml_Texture2::*)() const ) &Vrml_Texture2::WrapT, "None");
	cls_Vrml_Texture2.def("Print", (Standard_OStream & (Vrml_Texture2::*)(Standard_OStream &) const ) &Vrml_Texture2::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Texture2Transform.hxx
	py::class_<Vrml_Texture2Transform, std::unique_ptr<Vrml_Texture2Transform, Deleter<Vrml_Texture2Transform>>> cls_Vrml_Texture2Transform(mod, "Vrml_Texture2Transform", "defines a Texture2Transform node of VRML specifying properties of geometry and its appearance. This node defines a 2D transformation applied to texture coordinates. This affect the way textures are applied to the surfaces of subsequent shapes. Transformation consisits of(in order) a non-uniform scale about an arbitrary center point, a rotation about that same point, and a translation. This allows a user to change the size and position of the textures on the shape. By default : myTranslation (0 0) myRotation (0) myScaleFactor (1 1) myCenter (0 0)");
	cls_Vrml_Texture2Transform.def(py::init<>());
	cls_Vrml_Texture2Transform.def(py::init<const gp_Vec2d &, const Standard_Real, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("aTranslation"), py::arg("aRotation"), py::arg("aScaleFactor"), py::arg("aCenter"));
	cls_Vrml_Texture2Transform.def("SetTranslation", (void (Vrml_Texture2Transform::*)(const gp_Vec2d &)) &Vrml_Texture2Transform::SetTranslation, "None", py::arg("aTranslation"));
	cls_Vrml_Texture2Transform.def("Translation", (gp_Vec2d (Vrml_Texture2Transform::*)() const ) &Vrml_Texture2Transform::Translation, "None");
	cls_Vrml_Texture2Transform.def("SetRotation", (void (Vrml_Texture2Transform::*)(const Standard_Real)) &Vrml_Texture2Transform::SetRotation, "None", py::arg("aRotation"));
	cls_Vrml_Texture2Transform.def("Rotation", (Standard_Real (Vrml_Texture2Transform::*)() const ) &Vrml_Texture2Transform::Rotation, "None");
	cls_Vrml_Texture2Transform.def("SetScaleFactor", (void (Vrml_Texture2Transform::*)(const gp_Vec2d &)) &Vrml_Texture2Transform::SetScaleFactor, "None", py::arg("aScaleFactor"));
	cls_Vrml_Texture2Transform.def("ScaleFactor", (gp_Vec2d (Vrml_Texture2Transform::*)() const ) &Vrml_Texture2Transform::ScaleFactor, "None");
	cls_Vrml_Texture2Transform.def("SetCenter", (void (Vrml_Texture2Transform::*)(const gp_Vec2d &)) &Vrml_Texture2Transform::SetCenter, "None", py::arg("aCenter"));
	cls_Vrml_Texture2Transform.def("Center", (gp_Vec2d (Vrml_Texture2Transform::*)() const ) &Vrml_Texture2Transform::Center, "None");
	cls_Vrml_Texture2Transform.def("Print", (Standard_OStream & (Vrml_Texture2Transform::*)(Standard_OStream &) const ) &Vrml_Texture2Transform::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_TextureCoordinate2.hxx
	py::class_<Vrml_TextureCoordinate2, opencascade::handle<Vrml_TextureCoordinate2>, Standard_Transient> cls_Vrml_TextureCoordinate2(mod, "Vrml_TextureCoordinate2", "defines a TextureCoordinate2 node of VRML specifying properties of geometry and its appearance. This node defines a set of 2D coordinates to be used to map textures to the vertices of subsequent PointSet, IndexedLineSet, or IndexedFaceSet objects. It replaces the current texture coordinates in the rendering state for the shapes to use. Texture coordinates range from 0 to 1 across the texture. The horizontal coordinate, called S, is specified first, followed by vertical coordinate, T. By default : myPoint (0 0)");
	cls_Vrml_TextureCoordinate2.def(py::init<>());
	cls_Vrml_TextureCoordinate2.def(py::init<const opencascade::handle<TColgp_HArray1OfVec2d> &>(), py::arg("aPoint"));
	cls_Vrml_TextureCoordinate2.def("SetPoint", (void (Vrml_TextureCoordinate2::*)(const opencascade::handle<TColgp_HArray1OfVec2d> &)) &Vrml_TextureCoordinate2::SetPoint, "None", py::arg("aPoint"));
	cls_Vrml_TextureCoordinate2.def("Point", (opencascade::handle<TColgp_HArray1OfVec2d> (Vrml_TextureCoordinate2::*)() const ) &Vrml_TextureCoordinate2::Point, "None");
	cls_Vrml_TextureCoordinate2.def("Print", (Standard_OStream & (Vrml_TextureCoordinate2::*)(Standard_OStream &) const ) &Vrml_TextureCoordinate2::Print, "None", py::arg("anOStream"));
	cls_Vrml_TextureCoordinate2.def_static("get_type_name_", (const char * (*)()) &Vrml_TextureCoordinate2::get_type_name, "None");
	cls_Vrml_TextureCoordinate2.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_TextureCoordinate2::get_type_descriptor, "None");
	cls_Vrml_TextureCoordinate2.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_TextureCoordinate2::*)() const ) &Vrml_TextureCoordinate2::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_ShapeHints.hxx
	py::class_<Vrml_ShapeHints, std::unique_ptr<Vrml_ShapeHints, Deleter<Vrml_ShapeHints>>> cls_Vrml_ShapeHints(mod, "Vrml_ShapeHints", "defines a ShapeHints node of VRML specifying properties of geometry and its appearance. The ShapeHints node indicates that IndexedFaceSets are solid, contain ordered vertices, or contain convex faces. These hints allow VRML implementations to optimize certain rendering features. Optimizations that may be performed include enabling back-face culling and disabling two-sided lighting. For example, if an object is solid and has ordered vertices, an implementation may turn on backface culling and turn off two-sided lighting. To ensure that an IndexedFaceSet can be viewed from either direction, set shapeType to be UNKNOWN_SHAPE_TYPE. If you know that your shapes are closed and will alwsys be viewed from the outside, set vertexOrdering to be either CLOCKWISE or COUNTERCLOCKWISE (depending on how you built your object), and set shapeType to be SOLID. Placing this near the top of your VRML file will allow the scene to be rendered much faster. The ShapeHints node also affects how default normals are generated. When an IndexedFaceSet has to generate default normals, it uses the creaseAngle field to determine which edges should be smoothly shaded and which ones should have a sharp crease. The crease angle is the angle between surface normals on adjacent polygons. For example, a crease angle of .5 radians (the default value) means that an edge between two adjacent polygonal faces will be smooth shaded if the normals to the two faces form an angle that is less than .5 radians (about 30 degrees). Otherwise, it will be faceted.");
	cls_Vrml_ShapeHints.def(py::init<>());
	cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering>(), py::arg("aVertexOrdering"));
	cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering, const Vrml_ShapeType>(), py::arg("aVertexOrdering"), py::arg("aShapeType"));
	cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering, const Vrml_ShapeType, const Vrml_FaceType>(), py::arg("aVertexOrdering"), py::arg("aShapeType"), py::arg("aFaceType"));
	cls_Vrml_ShapeHints.def(py::init<const Vrml_VertexOrdering, const Vrml_ShapeType, const Vrml_FaceType, const Standard_Real>(), py::arg("aVertexOrdering"), py::arg("aShapeType"), py::arg("aFaceType"), py::arg("aAngle"));
	cls_Vrml_ShapeHints.def("SetVertexOrdering", (void (Vrml_ShapeHints::*)(const Vrml_VertexOrdering)) &Vrml_ShapeHints::SetVertexOrdering, "None", py::arg("aVertexOrdering"));
	cls_Vrml_ShapeHints.def("VertexOrdering", (Vrml_VertexOrdering (Vrml_ShapeHints::*)() const ) &Vrml_ShapeHints::VertexOrdering, "None");
	cls_Vrml_ShapeHints.def("SetShapeType", (void (Vrml_ShapeHints::*)(const Vrml_ShapeType)) &Vrml_ShapeHints::SetShapeType, "None", py::arg("aShapeType"));
	cls_Vrml_ShapeHints.def("ShapeType", (Vrml_ShapeType (Vrml_ShapeHints::*)() const ) &Vrml_ShapeHints::ShapeType, "None");
	cls_Vrml_ShapeHints.def("SetFaceType", (void (Vrml_ShapeHints::*)(const Vrml_FaceType)) &Vrml_ShapeHints::SetFaceType, "None", py::arg("aFaceType"));
	cls_Vrml_ShapeHints.def("FaceType", (Vrml_FaceType (Vrml_ShapeHints::*)() const ) &Vrml_ShapeHints::FaceType, "None");
	cls_Vrml_ShapeHints.def("SetAngle", (void (Vrml_ShapeHints::*)(const Standard_Real)) &Vrml_ShapeHints::SetAngle, "None", py::arg("aAngle"));
	cls_Vrml_ShapeHints.def("Angle", (Standard_Real (Vrml_ShapeHints::*)() const ) &Vrml_ShapeHints::Angle, "None");
	cls_Vrml_ShapeHints.def("Print", (Standard_OStream & (Vrml_ShapeHints::*)(Standard_OStream &) const ) &Vrml_ShapeHints::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_MatrixTransform.hxx
	py::class_<Vrml_MatrixTransform, std::unique_ptr<Vrml_MatrixTransform, Deleter<Vrml_MatrixTransform>>> cls_Vrml_MatrixTransform(mod, "Vrml_MatrixTransform", "defines a MatrixTransform node of VRML specifying matrix and transform properties. This node defines 3D transformation with a 4 by 4 matrix. By default : a11=1 a12=0 a13=0 a14=0 a21=0 a22=1 a23=0 a24=0 a31=0 a32=0 a33=1 a34=0 a41=0 a42=0 a43=0 a44=1 It is written to the file in row-major order as 16 Real numbers separated by whitespace. For example , matrix expressing a translation of 7.3 units along the X axis is written as: 1 0 0 0 0 1 0 0 0 0 1 0 7.3 0 0 1");
	cls_Vrml_MatrixTransform.def(py::init<>());
	cls_Vrml_MatrixTransform.def(py::init<const gp_Trsf &>(), py::arg("aMatrix"));
	cls_Vrml_MatrixTransform.def("SetMatrix", (void (Vrml_MatrixTransform::*)(const gp_Trsf &)) &Vrml_MatrixTransform::SetMatrix, "None", py::arg("aMatrix"));
	cls_Vrml_MatrixTransform.def("Matrix", (gp_Trsf (Vrml_MatrixTransform::*)() const ) &Vrml_MatrixTransform::Matrix, "None");
	cls_Vrml_MatrixTransform.def("Print", (Standard_OStream & (Vrml_MatrixTransform::*)(Standard_OStream &) const ) &Vrml_MatrixTransform::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Rotation.hxx
	py::class_<Vrml_Rotation, std::unique_ptr<Vrml_Rotation, Deleter<Vrml_Rotation>>> cls_Vrml_Rotation(mod, "Vrml_Rotation", "defines a Rotation node of VRML specifying matrix and transform properties. This node defines a 3D rotation about an arbitrary axis through the origin. By default : myRotation = (0 0 1 0)");
	cls_Vrml_Rotation.def(py::init<>());
	cls_Vrml_Rotation.def(py::init<const Vrml_SFRotation &>(), py::arg("aRotation"));
	cls_Vrml_Rotation.def("SetRotation", (void (Vrml_Rotation::*)(const Vrml_SFRotation &)) &Vrml_Rotation::SetRotation, "None", py::arg("aRotation"));
	cls_Vrml_Rotation.def("Rotation", (Vrml_SFRotation (Vrml_Rotation::*)() const ) &Vrml_Rotation::Rotation, "None");
	cls_Vrml_Rotation.def("Print", (Standard_OStream & (Vrml_Rotation::*)(Standard_OStream &) const ) &Vrml_Rotation::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Scale.hxx
	py::class_<Vrml_Scale, std::unique_ptr<Vrml_Scale, Deleter<Vrml_Scale>>> cls_Vrml_Scale(mod, "Vrml_Scale", "defines a Scale node of VRML specifying transform properties. This node defines a 3D scaling about the origin. By default : myRotation = (1 1 1)");
	cls_Vrml_Scale.def(py::init<>());
	cls_Vrml_Scale.def(py::init<const gp_Vec &>(), py::arg("aScaleFactor"));
	cls_Vrml_Scale.def("SetScaleFactor", (void (Vrml_Scale::*)(const gp_Vec &)) &Vrml_Scale::SetScaleFactor, "None", py::arg("aScaleFactor"));
	cls_Vrml_Scale.def("ScaleFactor", (gp_Vec (Vrml_Scale::*)() const ) &Vrml_Scale::ScaleFactor, "None");
	cls_Vrml_Scale.def("Print", (Standard_OStream & (Vrml_Scale::*)(Standard_OStream &) const ) &Vrml_Scale::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Transform.hxx
	py::class_<Vrml_Transform, std::unique_ptr<Vrml_Transform, Deleter<Vrml_Transform>>> cls_Vrml_Transform(mod, "Vrml_Transform", "defines a Transform of VRML specifying transform properties. This node defines a geometric 3D transformation consisting of (in order) a (possibly) non-uniform scale about an arbitrary point, a rotation about an arbitrary point and axis and translation. By default : myTranslation (0,0,0) myRotation (0,0,1,0) myScaleFactor (1,1,1) myScaleOrientation (0,0,1,0) myCenter (0,0,0)");
	cls_Vrml_Transform.def(py::init<>());
	cls_Vrml_Transform.def(py::init<const gp_Vec &, const Vrml_SFRotation &, const gp_Vec &, const Vrml_SFRotation &, const gp_Vec &>(), py::arg("aTranslation"), py::arg("aRotation"), py::arg("aScaleFactor"), py::arg("aScaleOrientation"), py::arg("aCenter"));
	cls_Vrml_Transform.def("SetTranslation", (void (Vrml_Transform::*)(const gp_Vec &)) &Vrml_Transform::SetTranslation, "None", py::arg("aTranslation"));
	cls_Vrml_Transform.def("Translation", (gp_Vec (Vrml_Transform::*)() const ) &Vrml_Transform::Translation, "None");
	cls_Vrml_Transform.def("SetRotation", (void (Vrml_Transform::*)(const Vrml_SFRotation &)) &Vrml_Transform::SetRotation, "None", py::arg("aRotation"));
	cls_Vrml_Transform.def("Rotation", (Vrml_SFRotation (Vrml_Transform::*)() const ) &Vrml_Transform::Rotation, "None");
	cls_Vrml_Transform.def("SetScaleFactor", (void (Vrml_Transform::*)(const gp_Vec &)) &Vrml_Transform::SetScaleFactor, "None", py::arg("aScaleFactor"));
	cls_Vrml_Transform.def("ScaleFactor", (gp_Vec (Vrml_Transform::*)() const ) &Vrml_Transform::ScaleFactor, "None");
	cls_Vrml_Transform.def("SetScaleOrientation", (void (Vrml_Transform::*)(const Vrml_SFRotation &)) &Vrml_Transform::SetScaleOrientation, "None", py::arg("aScaleOrientation"));
	cls_Vrml_Transform.def("ScaleOrientation", (Vrml_SFRotation (Vrml_Transform::*)() const ) &Vrml_Transform::ScaleOrientation, "None");
	cls_Vrml_Transform.def("SetCenter", (void (Vrml_Transform::*)(const gp_Vec &)) &Vrml_Transform::SetCenter, "None", py::arg("aCenter"));
	cls_Vrml_Transform.def("Center", (gp_Vec (Vrml_Transform::*)() const ) &Vrml_Transform::Center, "None");
	cls_Vrml_Transform.def("Print", (Standard_OStream & (Vrml_Transform::*)(Standard_OStream &) const ) &Vrml_Transform::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Translation.hxx
	py::class_<Vrml_Translation, std::unique_ptr<Vrml_Translation, Deleter<Vrml_Translation>>> cls_Vrml_Translation(mod, "Vrml_Translation", "defines a Translation of VRML specifying transform properties. This node defines a translation by 3D vector. By default : myTranslation (0,0,0)");
	cls_Vrml_Translation.def(py::init<>());
	cls_Vrml_Translation.def(py::init<const gp_Vec &>(), py::arg("aTranslation"));
	cls_Vrml_Translation.def("SetTranslation", (void (Vrml_Translation::*)(const gp_Vec &)) &Vrml_Translation::SetTranslation, "None", py::arg("aTranslation"));
	cls_Vrml_Translation.def("Translation", (gp_Vec (Vrml_Translation::*)() const ) &Vrml_Translation::Translation, "None");
	cls_Vrml_Translation.def("Print", (Standard_OStream & (Vrml_Translation::*)(Standard_OStream &) const ) &Vrml_Translation::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_OrthographicCamera.hxx
	py::class_<Vrml_OrthographicCamera, std::unique_ptr<Vrml_OrthographicCamera, Deleter<Vrml_OrthographicCamera>>> cls_Vrml_OrthographicCamera(mod, "Vrml_OrthographicCamera", "specifies a OrthographicCamera node of VRML specifying properties of cameras. An orthographic camera defines a parallel projection from a viewpoint. This camera does not diminish objects with distance, as a PerspectiveCamera does. The viewing volume for an orthographic camera is a rectangular parallelepiped (a box).");
	cls_Vrml_OrthographicCamera.def(py::init<>());
	cls_Vrml_OrthographicCamera.def(py::init<const gp_Vec &, const Vrml_SFRotation &, const Standard_Real, const Standard_Real>(), py::arg("aPosition"), py::arg("aOrientation"), py::arg("aFocalDistance"), py::arg("aHeight"));
	cls_Vrml_OrthographicCamera.def("SetPosition", (void (Vrml_OrthographicCamera::*)(const gp_Vec &)) &Vrml_OrthographicCamera::SetPosition, "None", py::arg("aPosition"));
	cls_Vrml_OrthographicCamera.def("Position", (gp_Vec (Vrml_OrthographicCamera::*)() const ) &Vrml_OrthographicCamera::Position, "None");
	cls_Vrml_OrthographicCamera.def("SetOrientation", (void (Vrml_OrthographicCamera::*)(const Vrml_SFRotation &)) &Vrml_OrthographicCamera::SetOrientation, "None", py::arg("aOrientation"));
	cls_Vrml_OrthographicCamera.def("Orientation", (Vrml_SFRotation (Vrml_OrthographicCamera::*)() const ) &Vrml_OrthographicCamera::Orientation, "None");
	cls_Vrml_OrthographicCamera.def("SetFocalDistance", (void (Vrml_OrthographicCamera::*)(const Standard_Real)) &Vrml_OrthographicCamera::SetFocalDistance, "None", py::arg("aFocalDistance"));
	cls_Vrml_OrthographicCamera.def("FocalDistance", (Standard_Real (Vrml_OrthographicCamera::*)() const ) &Vrml_OrthographicCamera::FocalDistance, "None");
	cls_Vrml_OrthographicCamera.def("SetHeight", (void (Vrml_OrthographicCamera::*)(const Standard_Real)) &Vrml_OrthographicCamera::SetHeight, "None", py::arg("aHeight"));
	cls_Vrml_OrthographicCamera.def("Height", (Standard_Real (Vrml_OrthographicCamera::*)() const ) &Vrml_OrthographicCamera::Height, "None");
	cls_Vrml_OrthographicCamera.def("Print", (Standard_OStream & (Vrml_OrthographicCamera::*)(Standard_OStream &) const ) &Vrml_OrthographicCamera::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_PerspectiveCamera.hxx
	py::class_<Vrml_PerspectiveCamera, std::unique_ptr<Vrml_PerspectiveCamera, Deleter<Vrml_PerspectiveCamera>>> cls_Vrml_PerspectiveCamera(mod, "Vrml_PerspectiveCamera", "specifies a PerspectiveCamera node of VRML specifying properties of cameras. A perspective camera defines a perspective projection from a viewpoint. The viewing volume for a perspective camera is a truncated right pyramid.");
	cls_Vrml_PerspectiveCamera.def(py::init<>());
	cls_Vrml_PerspectiveCamera.def(py::init<const gp_Vec &, const Vrml_SFRotation &, const Standard_Real, const Standard_Real>(), py::arg("aPosition"), py::arg("aOrientation"), py::arg("aFocalDistance"), py::arg("aHeightAngle"));
	cls_Vrml_PerspectiveCamera.def("SetPosition", (void (Vrml_PerspectiveCamera::*)(const gp_Vec &)) &Vrml_PerspectiveCamera::SetPosition, "None", py::arg("aPosition"));
	cls_Vrml_PerspectiveCamera.def("Position", (gp_Vec (Vrml_PerspectiveCamera::*)() const ) &Vrml_PerspectiveCamera::Position, "None");
	cls_Vrml_PerspectiveCamera.def("SetOrientation", (void (Vrml_PerspectiveCamera::*)(const Vrml_SFRotation &)) &Vrml_PerspectiveCamera::SetOrientation, "None", py::arg("aOrientation"));
	cls_Vrml_PerspectiveCamera.def("Orientation", (Vrml_SFRotation (Vrml_PerspectiveCamera::*)() const ) &Vrml_PerspectiveCamera::Orientation, "None");
	cls_Vrml_PerspectiveCamera.def("SetFocalDistance", (void (Vrml_PerspectiveCamera::*)(const Standard_Real)) &Vrml_PerspectiveCamera::SetFocalDistance, "None", py::arg("aFocalDistance"));
	cls_Vrml_PerspectiveCamera.def("FocalDistance", (Standard_Real (Vrml_PerspectiveCamera::*)() const ) &Vrml_PerspectiveCamera::FocalDistance, "None");
	cls_Vrml_PerspectiveCamera.def("SetAngle", (void (Vrml_PerspectiveCamera::*)(const Standard_Real)) &Vrml_PerspectiveCamera::SetAngle, "None", py::arg("aHeightAngle"));
	cls_Vrml_PerspectiveCamera.def("Angle", (Standard_Real (Vrml_PerspectiveCamera::*)() const ) &Vrml_PerspectiveCamera::Angle, "None");
	cls_Vrml_PerspectiveCamera.def("Print", (Standard_OStream & (Vrml_PerspectiveCamera::*)(Standard_OStream &) const ) &Vrml_PerspectiveCamera::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_DirectionalLight.hxx
	py::class_<Vrml_DirectionalLight, std::unique_ptr<Vrml_DirectionalLight, Deleter<Vrml_DirectionalLight>>> cls_Vrml_DirectionalLight(mod, "Vrml_DirectionalLight", "defines a directional light node of VRML specifying properties of lights. This node defines a directional light source that illuminates along rays parallel to a given 3-dimentional vector Color is written as an RGB triple. Light intensity must be in the range 0.0 to 1.0, inclusive.");
	cls_Vrml_DirectionalLight.def(py::init<>());
	cls_Vrml_DirectionalLight.def(py::init<const Standard_Boolean, const Standard_Real, const Quantity_Color &, const gp_Vec &>(), py::arg("aOnOff"), py::arg("aIntensity"), py::arg("aColor"), py::arg("aDirection"));
	cls_Vrml_DirectionalLight.def("SetOnOff", (void (Vrml_DirectionalLight::*)(const Standard_Boolean)) &Vrml_DirectionalLight::SetOnOff, "None", py::arg("aOnOff"));
	cls_Vrml_DirectionalLight.def("OnOff", (Standard_Boolean (Vrml_DirectionalLight::*)() const ) &Vrml_DirectionalLight::OnOff, "None");
	cls_Vrml_DirectionalLight.def("SetIntensity", (void (Vrml_DirectionalLight::*)(const Standard_Real)) &Vrml_DirectionalLight::SetIntensity, "None", py::arg("aIntensity"));
	cls_Vrml_DirectionalLight.def("Intensity", (Standard_Real (Vrml_DirectionalLight::*)() const ) &Vrml_DirectionalLight::Intensity, "None");
	cls_Vrml_DirectionalLight.def("SetColor", (void (Vrml_DirectionalLight::*)(const Quantity_Color &)) &Vrml_DirectionalLight::SetColor, "None", py::arg("aColor"));
	cls_Vrml_DirectionalLight.def("Color", (Quantity_Color (Vrml_DirectionalLight::*)() const ) &Vrml_DirectionalLight::Color, "None");
	cls_Vrml_DirectionalLight.def("SetDirection", (void (Vrml_DirectionalLight::*)(const gp_Vec &)) &Vrml_DirectionalLight::SetDirection, "None", py::arg("aDirection"));
	cls_Vrml_DirectionalLight.def("Direction", (gp_Vec (Vrml_DirectionalLight::*)() const ) &Vrml_DirectionalLight::Direction, "None");
	cls_Vrml_DirectionalLight.def("Print", (Standard_OStream & (Vrml_DirectionalLight::*)(Standard_OStream &) const ) &Vrml_DirectionalLight::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_PointLight.hxx
	py::class_<Vrml_PointLight, std::unique_ptr<Vrml_PointLight, Deleter<Vrml_PointLight>>> cls_Vrml_PointLight(mod, "Vrml_PointLight", "defines a point light node of VRML specifying properties of lights. This node defines a point light source at a fixed 3D location A point source illuminates equally in all directions; that is omni-directional. Color is written as an RGB triple. Light intensity must be in the range 0.0 to 1.0, inclusive.");
	cls_Vrml_PointLight.def(py::init<>());
	cls_Vrml_PointLight.def(py::init<const Standard_Boolean, const Standard_Real, const Quantity_Color &, const gp_Vec &>(), py::arg("aOnOff"), py::arg("aIntensity"), py::arg("aColor"), py::arg("aLocation"));
	cls_Vrml_PointLight.def("SetOnOff", (void (Vrml_PointLight::*)(const Standard_Boolean)) &Vrml_PointLight::SetOnOff, "None", py::arg("aOnOff"));
	cls_Vrml_PointLight.def("OnOff", (Standard_Boolean (Vrml_PointLight::*)() const ) &Vrml_PointLight::OnOff, "None");
	cls_Vrml_PointLight.def("SetIntensity", (void (Vrml_PointLight::*)(const Standard_Real)) &Vrml_PointLight::SetIntensity, "None", py::arg("aIntensity"));
	cls_Vrml_PointLight.def("Intensity", (Standard_Real (Vrml_PointLight::*)() const ) &Vrml_PointLight::Intensity, "None");
	cls_Vrml_PointLight.def("SetColor", (void (Vrml_PointLight::*)(const Quantity_Color &)) &Vrml_PointLight::SetColor, "None", py::arg("aColor"));
	cls_Vrml_PointLight.def("Color", (Quantity_Color (Vrml_PointLight::*)() const ) &Vrml_PointLight::Color, "None");
	cls_Vrml_PointLight.def("SetLocation", (void (Vrml_PointLight::*)(const gp_Vec &)) &Vrml_PointLight::SetLocation, "None", py::arg("aLocation"));
	cls_Vrml_PointLight.def("Location", (gp_Vec (Vrml_PointLight::*)() const ) &Vrml_PointLight::Location, "None");
	cls_Vrml_PointLight.def("Print", (Standard_OStream & (Vrml_PointLight::*)(Standard_OStream &) const ) &Vrml_PointLight::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_SpotLight.hxx
	py::class_<Vrml_SpotLight, std::unique_ptr<Vrml_SpotLight, Deleter<Vrml_SpotLight>>> cls_Vrml_SpotLight(mod, "Vrml_SpotLight", "specifies a spot light node of VRML nodes specifying properties of lights. This node defines a spotlight light source. A spotlight is placed at a fixed location in 3D-space and illuminates in a cone along a particular direction. The intensity of the illumination drops off exponentially as a ray of light diverges from this direction toward the edges of cone. The rate of drop-off and agle of the cone are controlled by the dropOfRate and cutOffAngle Color is written as an RGB triple. Light intensity must be in the range 0.0 to 1.0, inclusive.");
	cls_Vrml_SpotLight.def(py::init<>());
	cls_Vrml_SpotLight.def(py::init<const Standard_Boolean, const Standard_Real, const Quantity_Color &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real>(), py::arg("aOnOff"), py::arg("aIntensity"), py::arg("aColor"), py::arg("aLocation"), py::arg("aDirection"), py::arg("aDropOffRate"), py::arg("aCutOffAngle"));
	cls_Vrml_SpotLight.def("SetOnOff", (void (Vrml_SpotLight::*)(const Standard_Boolean)) &Vrml_SpotLight::SetOnOff, "None", py::arg("anOnOff"));
	cls_Vrml_SpotLight.def("OnOff", (Standard_Boolean (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::OnOff, "None");
	cls_Vrml_SpotLight.def("SetIntensity", (void (Vrml_SpotLight::*)(const Standard_Real)) &Vrml_SpotLight::SetIntensity, "None", py::arg("aIntensity"));
	cls_Vrml_SpotLight.def("Intensity", (Standard_Real (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::Intensity, "None");
	cls_Vrml_SpotLight.def("SetColor", (void (Vrml_SpotLight::*)(const Quantity_Color &)) &Vrml_SpotLight::SetColor, "None", py::arg("aColor"));
	cls_Vrml_SpotLight.def("Color", (Quantity_Color (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::Color, "None");
	cls_Vrml_SpotLight.def("SetLocation", (void (Vrml_SpotLight::*)(const gp_Vec &)) &Vrml_SpotLight::SetLocation, "None", py::arg("aLocation"));
	cls_Vrml_SpotLight.def("Location", (gp_Vec (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::Location, "None");
	cls_Vrml_SpotLight.def("SetDirection", (void (Vrml_SpotLight::*)(const gp_Vec &)) &Vrml_SpotLight::SetDirection, "None", py::arg("aDirection"));
	cls_Vrml_SpotLight.def("Direction", (gp_Vec (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::Direction, "None");
	cls_Vrml_SpotLight.def("SetDropOffRate", (void (Vrml_SpotLight::*)(const Standard_Real)) &Vrml_SpotLight::SetDropOffRate, "None", py::arg("aDropOffRate"));
	cls_Vrml_SpotLight.def("DropOffRate", (Standard_Real (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::DropOffRate, "None");
	cls_Vrml_SpotLight.def("SetCutOffAngle", (void (Vrml_SpotLight::*)(const Standard_Real)) &Vrml_SpotLight::SetCutOffAngle, "None", py::arg("aCutOffAngle"));
	cls_Vrml_SpotLight.def("CutOffAngle", (Standard_Real (Vrml_SpotLight::*)() const ) &Vrml_SpotLight::CutOffAngle, "None");
	cls_Vrml_SpotLight.def("Print", (Standard_OStream & (Vrml_SpotLight::*)(Standard_OStream &) const ) &Vrml_SpotLight::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Group.hxx
	py::class_<Vrml_Group, std::unique_ptr<Vrml_Group, Deleter<Vrml_Group>>> cls_Vrml_Group(mod, "Vrml_Group", "defines a Group node of VRML specifying group properties. This node defines the base class for all group nodes. Group is a node that contains an ordered list of child nodes. This node is simply a container for the child nodes and does not alter the traversal state in any way. During traversal, state accumulated for a child is passed on to each successive child and then to the parents of the group (Group does not push or pop traversal state as separator does).");
	cls_Vrml_Group.def(py::init<>());
	cls_Vrml_Group.def("Print", (Standard_OStream & (Vrml_Group::*)(Standard_OStream &)) &Vrml_Group::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Separator.hxx
	py::class_<Vrml_Separator, std::unique_ptr<Vrml_Separator, Deleter<Vrml_Separator>>> cls_Vrml_Separator(mod, "Vrml_Separator", "defines a Separator node of VRML specifying group properties. This group node performs a push (save) of the traversal state before traversing its children and a pop (restore) after traversing them. This isolates the separator's children from the rest of the scene graph. A separator can include lights, cameras, coordinates, normals, bindings, and all other properties. Separators can also perform render culling. Render culling skips over traversal of the separator's children if they are not going to be rendered, based on the comparison of the separator's bounding box with the current view volume. Culling is controlled by the renderCulling field. These are set to AUTO by default, allowing the implementation to decide whether or not to cull.");
	cls_Vrml_Separator.def(py::init<const Vrml_SeparatorRenderCulling>(), py::arg("aRenderCulling"));
	cls_Vrml_Separator.def(py::init<>());
	cls_Vrml_Separator.def("SetRenderCulling", (void (Vrml_Separator::*)(const Vrml_SeparatorRenderCulling)) &Vrml_Separator::SetRenderCulling, "None", py::arg("aRenderCulling"));
	cls_Vrml_Separator.def("RenderCulling", (Vrml_SeparatorRenderCulling (Vrml_Separator::*)() const ) &Vrml_Separator::RenderCulling, "None");
	cls_Vrml_Separator.def("Print", (Standard_OStream & (Vrml_Separator::*)(Standard_OStream &)) &Vrml_Separator::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Switch.hxx
	py::class_<Vrml_Switch, std::unique_ptr<Vrml_Switch, Deleter<Vrml_Switch>>> cls_Vrml_Switch(mod, "Vrml_Switch", "defines a Switch node of VRML specifying group properties. This group node traverses one, none, or all of its children. One can use this node to switch on and off the effects of some properties or to switch between different properties. The whichChild field specifies the index of the child to traverse, where the first child has index 0. A value of -1 (the default) means do not traverse any children. A value of -3 traverses all children, making the switch behave exactly like a regular Group.");
	cls_Vrml_Switch.def(py::init<>());
	cls_Vrml_Switch.def(py::init<const Standard_Integer>(), py::arg("aWhichChild"));
	cls_Vrml_Switch.def("SetWhichChild", (void (Vrml_Switch::*)(const Standard_Integer)) &Vrml_Switch::SetWhichChild, "None", py::arg("aWhichChild"));
	cls_Vrml_Switch.def("WhichChild", (Standard_Integer (Vrml_Switch::*)() const ) &Vrml_Switch::WhichChild, "None");
	cls_Vrml_Switch.def("Print", (Standard_OStream & (Vrml_Switch::*)(Standard_OStream &) const ) &Vrml_Switch::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_TransformSeparator.hxx
	py::class_<Vrml_TransformSeparator, std::unique_ptr<Vrml_TransformSeparator, Deleter<Vrml_TransformSeparator>>> cls_Vrml_TransformSeparator(mod, "Vrml_TransformSeparator", "defines a TransformSeparator node of VRML specifying group properties. This group node is similar to separator node in that it saves state before traversing its children and restores it afterwards. This node can be used to isolate transformations to light sources or objects.");
	cls_Vrml_TransformSeparator.def(py::init<>());
	cls_Vrml_TransformSeparator.def("Print", (Standard_OStream & (Vrml_TransformSeparator::*)(Standard_OStream &)) &Vrml_TransformSeparator::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_WWWAnchor.hxx
	py::class_<Vrml_WWWAnchor, std::unique_ptr<Vrml_WWWAnchor, Deleter<Vrml_WWWAnchor>>> cls_Vrml_WWWAnchor(mod, "Vrml_WWWAnchor", "defines a WWWAnchor node of VRML specifying group properties. The WWWAnchor group node loads a new scene into a VRML browser when one of its children is closen. Exactly how a user 'chooses' a child of the WWWAnchor is up to the VRML browser. WWWAnchor with an empty ('') name does nothing when its children are chosen. WWWAnchor behaves like a Separator, pushing the traversal state before traversing its children and popping it afterwards.");
	cls_Vrml_WWWAnchor.def(py::init<>());
	cls_Vrml_WWWAnchor.def(py::init<const TCollection_AsciiString &>(), py::arg("aName"));
	cls_Vrml_WWWAnchor.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("aName"), py::arg("aDescription"));
	cls_Vrml_WWWAnchor.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &, const Vrml_WWWAnchorMap>(), py::arg("aName"), py::arg("aDescription"), py::arg("aMap"));
	cls_Vrml_WWWAnchor.def("SetName", (void (Vrml_WWWAnchor::*)(const TCollection_AsciiString &)) &Vrml_WWWAnchor::SetName, "None", py::arg("aName"));
	cls_Vrml_WWWAnchor.def("Name", (TCollection_AsciiString (Vrml_WWWAnchor::*)() const ) &Vrml_WWWAnchor::Name, "None");
	cls_Vrml_WWWAnchor.def("SetDescription", (void (Vrml_WWWAnchor::*)(const TCollection_AsciiString &)) &Vrml_WWWAnchor::SetDescription, "None", py::arg("aDescription"));
	cls_Vrml_WWWAnchor.def("Description", (TCollection_AsciiString (Vrml_WWWAnchor::*)() const ) &Vrml_WWWAnchor::Description, "None");
	cls_Vrml_WWWAnchor.def("SetMap", (void (Vrml_WWWAnchor::*)(const Vrml_WWWAnchorMap)) &Vrml_WWWAnchor::SetMap, "None", py::arg("aMap"));
	cls_Vrml_WWWAnchor.def("Map", (Vrml_WWWAnchorMap (Vrml_WWWAnchor::*)() const ) &Vrml_WWWAnchor::Map, "None");
	cls_Vrml_WWWAnchor.def("Print", (Standard_OStream & (Vrml_WWWAnchor::*)(Standard_OStream &) const ) &Vrml_WWWAnchor::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_WWWInline.hxx
	py::class_<Vrml_WWWInline, std::unique_ptr<Vrml_WWWInline, Deleter<Vrml_WWWInline>>> cls_Vrml_WWWInline(mod, "Vrml_WWWInline", "defines a WWWInline node of VRML specifying group properties. The WWWInline group node reads its children from anywhere in the World Wide Web. Exactly when its children are read is not defined; reading the children may be delayed until the WWWInline is actually displayed. WWWInline with an empty ('') name does nothing. WWWInline behaves like a Separator, pushing the traversal state before traversing its children and popping it afterwards. By defaults: myName ('') myBboxSize (0,0,0) myBboxCenter (0,0,0)");
	cls_Vrml_WWWInline.def(py::init<>());
	cls_Vrml_WWWInline.def(py::init<const TCollection_AsciiString &, const gp_Vec &, const gp_Vec &>(), py::arg("aName"), py::arg("aBboxSize"), py::arg("aBboxCenter"));
	cls_Vrml_WWWInline.def("SetName", (void (Vrml_WWWInline::*)(const TCollection_AsciiString &)) &Vrml_WWWInline::SetName, "None", py::arg("aName"));
	cls_Vrml_WWWInline.def("Name", (TCollection_AsciiString (Vrml_WWWInline::*)() const ) &Vrml_WWWInline::Name, "None");
	cls_Vrml_WWWInline.def("SetBboxSize", (void (Vrml_WWWInline::*)(const gp_Vec &)) &Vrml_WWWInline::SetBboxSize, "None", py::arg("aBboxSize"));
	cls_Vrml_WWWInline.def("BboxSize", (gp_Vec (Vrml_WWWInline::*)() const ) &Vrml_WWWInline::BboxSize, "None");
	cls_Vrml_WWWInline.def("SetBboxCenter", (void (Vrml_WWWInline::*)(const gp_Vec &)) &Vrml_WWWInline::SetBboxCenter, "None", py::arg("aBboxCenter"));
	cls_Vrml_WWWInline.def("BboxCenter", (gp_Vec (Vrml_WWWInline::*)() const ) &Vrml_WWWInline::BboxCenter, "None");
	cls_Vrml_WWWInline.def("Print", (Standard_OStream & (Vrml_WWWInline::*)(Standard_OStream &) const ) &Vrml_WWWInline::Print, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml_Instancing.hxx
	py::class_<Vrml_Instancing, std::unique_ptr<Vrml_Instancing, Deleter<Vrml_Instancing>>> cls_Vrml_Instancing(mod, "Vrml_Instancing", "defines 'instancing' - using the same instance of a node multiple times. It is accomplished by using the 'DEF' and 'USE' keywords. The DEF keyword both defines a named node, and creates a single instance of it. The USE keyword indicates that the most recently defined instance should be used again. If several nades were given the same name, then the last DEF encountered during parsing 'wins'. DEF/USE is limited to a single file.");
	cls_Vrml_Instancing.def(py::init<const TCollection_AsciiString &>(), py::arg("aString"));
	cls_Vrml_Instancing.def("DEF", (Standard_OStream & (Vrml_Instancing::*)(Standard_OStream &) const ) &Vrml_Instancing::DEF, "Adds 'USE <myName>' in anOStream (VRML file).", py::arg("anOStream"));
	cls_Vrml_Instancing.def("USE", (Standard_OStream & (Vrml_Instancing::*)(Standard_OStream &) const ) &Vrml_Instancing::USE, "None", py::arg("anOStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Vrml.hxx
	py::class_<Vrml, std::unique_ptr<Vrml, Deleter<Vrml>>> cls_Vrml(mod, "Vrml", "Vrml package implements the specification of the VRML ( Virtual Reality Modeling Language ). VRML is a standard language for describing interactive 3-D objects and worlds delivered across Internet. Actual version of Vrml package have made for objects of VRML version 1.0. This package is used by VrmlConverter package. The developer should already be familiar with VRML specification before using this package.");
	cls_Vrml.def(py::init<>());
	cls_Vrml.def_static("VrmlHeaderWriter_", (Standard_OStream & (*)(Standard_OStream &)) &Vrml::VrmlHeaderWriter, "Writes a header in anOStream (VRML file). Writes one line of commentary in anOStream (VRML file).", py::arg("anOStream"));
	cls_Vrml.def_static("CommentWriter_", (Standard_OStream & (*)(const Standard_CString, Standard_OStream &)) &Vrml::CommentWriter, "None", py::arg("aComment"), py::arg("anOStream"));


}
