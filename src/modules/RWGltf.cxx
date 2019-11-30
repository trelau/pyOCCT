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
#include <RWGltf_GltfAccessorCompType.hxx>
#include <RWGltf_GltfAccessorLayout.hxx>
#include <RWGltf_GltfArrayType.hxx>
#include <RWGltf_GltfBufferViewTarget.hxx>
#include <RWGltf_GltfPrimitiveMode.hxx>
#include <RWGltf_GltfRootElement.hxx>
#include <RWMesh_CafReader.hxx>
#include <Standard_Std.hxx>
#include <RWGltf_CafReader.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Message_ProgressIndicator.hxx>
#include <RWGltf_PrimitiveArrayReader.hxx>
#include <NCollection_Vector.hxx>
#include <TopoDS_Face.hxx>
#include <Graphic3d_BndBox3d.hxx>
#include <RWGltf_GltfAccessor.hxx>
#include <RWGltf_GltfBufferView.hxx>
#include <RWGltf_GltfFace.hxx>
#include <NCollection_Buffer.hxx>
#include <RWGltf_GltfPrimArrayData.hxx>
#include <Poly_Triangulation.hxx>
#include <RWGltf_GltfLatePrimitiveArray.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <RWGltf_MaterialMetallicRoughness.hxx>
#include <RWGltf_MaterialCommon.hxx>
#include <NCollection_Sequence.hxx>
#include <Bnd_Box.hxx>
#include <Standard_Transient.hxx>
#include <Image_Texture.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_Vec3.hxx>
#include <RWMesh_CoordinateSystemConverter.hxx>
#include <RWGltf_TriangulationReader.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <gp_Dir.hxx>
#include <Poly_Triangle.hxx>

PYBIND11_MODULE(RWGltf, mod) {

py::module::import("OCCT.RWMesh");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Image");
py::module::import("OCCT.gp");
py::module::import("OCCT.TShort");

// ENUM: RWGLTF_GLTFACCESSORCOMPTYPE
py::enum_<RWGltf_GltfAccessorCompType>(mod, "RWGltf_GltfAccessorCompType", "Low-level glTF enumeration defining Accessor component type.")
	.value("RWGltf_GltfAccessorCompType_UNKNOWN", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_UNKNOWN)
	.value("RWGltf_GltfAccessorCompType_Int8", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_Int8)
	.value("RWGltf_GltfAccessorCompType_UInt8", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_UInt8)
	.value("RWGltf_GltfAccessorCompType_Int16", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_Int16)
	.value("RWGltf_GltfAccessorCompType_UInt16", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_UInt16)
	.value("RWGltf_GltfAccessorCompType_UInt32", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_UInt32)
	.value("RWGltf_GltfAccessorCompType_Float32", RWGltf_GltfAccessorCompType::RWGltf_GltfAccessorCompType_Float32)
	.export_values();


// ENUM: RWGLTF_GLTFACCESSORLAYOUT
py::enum_<RWGltf_GltfAccessorLayout>(mod, "RWGltf_GltfAccessorLayout", "Low-level glTF enumeration defining Accessor layout. Similar to Graphic3d_TypeOfData but does not define actual type and includes matrices.")
	.value("RWGltf_GltfAccessorLayout_UNKNOWN", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_UNKNOWN)
	.value("RWGltf_GltfAccessorLayout_Scalar", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Scalar)
	.value("RWGltf_GltfAccessorLayout_Vec2", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Vec2)
	.value("RWGltf_GltfAccessorLayout_Vec3", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Vec3)
	.value("RWGltf_GltfAccessorLayout_Vec4", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Vec4)
	.value("RWGltf_GltfAccessorLayout_Mat2", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Mat2)
	.value("RWGltf_GltfAccessorLayout_Mat3", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Mat3)
	.value("RWGltf_GltfAccessorLayout_Mat4", RWGltf_GltfAccessorLayout::RWGltf_GltfAccessorLayout_Mat4)
	.export_values();


// ENUM: RWGLTF_GLTFARRAYTYPE
py::enum_<RWGltf_GltfArrayType>(mod, "RWGltf_GltfArrayType", "Low-level glTF enumeration defining Array type.")
	.value("RWGltf_GltfArrayType_UNKNOWN", RWGltf_GltfArrayType::RWGltf_GltfArrayType_UNKNOWN)
	.value("RWGltf_GltfArrayType_Indices", RWGltf_GltfArrayType::RWGltf_GltfArrayType_Indices)
	.value("RWGltf_GltfArrayType_Position", RWGltf_GltfArrayType::RWGltf_GltfArrayType_Position)
	.value("RWGltf_GltfArrayType_Normal", RWGltf_GltfArrayType::RWGltf_GltfArrayType_Normal)
	.value("RWGltf_GltfArrayType_Color", RWGltf_GltfArrayType::RWGltf_GltfArrayType_Color)
	.value("RWGltf_GltfArrayType_TCoord0", RWGltf_GltfArrayType::RWGltf_GltfArrayType_TCoord0)
	.value("RWGltf_GltfArrayType_TCoord1", RWGltf_GltfArrayType::RWGltf_GltfArrayType_TCoord1)
	.value("RWGltf_GltfArrayType_Joint", RWGltf_GltfArrayType::RWGltf_GltfArrayType_Joint)
	.value("RWGltf_GltfArrayType_Weight", RWGltf_GltfArrayType::RWGltf_GltfArrayType_Weight)
	.export_values();


// ENUM: RWGLTF_GLTFBUFFERVIEWTARGET
py::enum_<RWGltf_GltfBufferViewTarget>(mod, "RWGltf_GltfBufferViewTarget", "Low-level glTF enumeration defining BufferView target.")
	.value("RWGltf_GltfBufferViewTarget_UNKNOWN", RWGltf_GltfBufferViewTarget::RWGltf_GltfBufferViewTarget_UNKNOWN)
	.value("RWGltf_GltfBufferViewTarget_ARRAY_BUFFER", RWGltf_GltfBufferViewTarget::RWGltf_GltfBufferViewTarget_ARRAY_BUFFER)
	.value("RWGltf_GltfBufferViewTarget_ELEMENT_ARRAY_BUFFER", RWGltf_GltfBufferViewTarget::RWGltf_GltfBufferViewTarget_ELEMENT_ARRAY_BUFFER)
	.export_values();


// ENUM: RWGLTF_GLTFPRIMITIVEMODE
py::enum_<RWGltf_GltfPrimitiveMode>(mod, "RWGltf_GltfPrimitiveMode", "Low-level glTF enumeration defining Primitive type. Similar to Graphic3d_TypeOfData but does not define actual type and includes matrices.")
	.value("RWGltf_GltfPrimitiveMode_UNKNOWN", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_UNKNOWN)
	.value("RWGltf_GltfPrimitiveMode_Points", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_Points)
	.value("RWGltf_GltfPrimitiveMode_Lines", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_Lines)
	.value("RWGltf_GltfPrimitiveMode_LineLoop", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_LineLoop)
	.value("RWGltf_GltfPrimitiveMode_LineStrip", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_LineStrip)
	.value("RWGltf_GltfPrimitiveMode_Triangles", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_Triangles)
	.value("RWGltf_GltfPrimitiveMode_TriangleStrip", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_TriangleStrip)
	.value("RWGltf_GltfPrimitiveMode_TriangleFan", RWGltf_GltfPrimitiveMode::RWGltf_GltfPrimitiveMode_TriangleFan)
	.export_values();


// ENUM: RWGLTF_GLTFROOTELEMENT
py::enum_<RWGltf_GltfRootElement>(mod, "RWGltf_GltfRootElement", "Root elements within glTF JSON document.")
	.value("RWGltf_GltfRootElement_Asset", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Asset)
	.value("RWGltf_GltfRootElement_Scenes", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Scenes)
	.value("RWGltf_GltfRootElement_Scene", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Scene)
	.value("RWGltf_GltfRootElement_Nodes", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Nodes)
	.value("RWGltf_GltfRootElement_Meshes", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Meshes)
	.value("RWGltf_GltfRootElement_Accessors", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Accessors)
	.value("RWGltf_GltfRootElement_BufferViews", RWGltf_GltfRootElement::RWGltf_GltfRootElement_BufferViews)
	.value("RWGltf_GltfRootElement_Buffers", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Buffers)
	.value("RWGltf_GltfRootElement_NB_MANDATORY", RWGltf_GltfRootElement::RWGltf_GltfRootElement_NB_MANDATORY)
	.value("RWGltf_GltfRootElement_Animations", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Animations)
	.value("RWGltf_GltfRootElement_Materials", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Materials)
	.value("RWGltf_GltfRootElement_Programs", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Programs)
	.value("RWGltf_GltfRootElement_Samplers", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Samplers)
	.value("RWGltf_GltfRootElement_Shaders", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Shaders)
	.value("RWGltf_GltfRootElement_Skins", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Skins)
	.value("RWGltf_GltfRootElement_Techniques", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Techniques)
	.value("RWGltf_GltfRootElement_Textures", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Textures)
	.value("RWGltf_GltfRootElement_Images", RWGltf_GltfRootElement::RWGltf_GltfRootElement_Images)
	.value("RWGltf_GltfRootElement_ExtensionsUsed", RWGltf_GltfRootElement::RWGltf_GltfRootElement_ExtensionsUsed)
	.value("RWGltf_GltfRootElement_ExtensionsRequired", RWGltf_GltfRootElement::RWGltf_GltfRootElement_ExtensionsRequired)
	.value("RWGltf_GltfRootElement_NB", RWGltf_GltfRootElement::RWGltf_GltfRootElement_NB)
	.export_values();


// FUNCTION: RWGLTF_GLTFPARSEACCESSORTYPE
mod.def("RWGltf_GltfParseAccessorType", (RWGltf_GltfAccessorLayout (*) (const char *)) &RWGltf_GltfParseAccessorType, "Parse GltfAccessorLayout from string.", py::arg("theType"));

// FUNCTION: RWGLTF_GLTFPARSEATTRIBTYPE
mod.def("RWGltf_GltfParseAttribType", (RWGltf_GltfArrayType (*) (const char *)) &RWGltf_GltfParseAttribType, "Parse GltfArrayType from string.", py::arg("theType"));

// FUNCTION: RWGLTF_GLTFROOTELEMENTNAME
mod.def("RWGltf_GltfRootElementName", (const char * (*) (RWGltf_GltfRootElement)) &RWGltf_GltfRootElementName, "Root elements within glTF JSON document - names array.", py::arg("theElem"));

// CLASS: RWGLTF_CAFREADER
py::class_<RWGltf_CafReader, opencascade::handle<RWGltf_CafReader>, RWMesh_CafReader> cls_RWGltf_CafReader(mod, "RWGltf_CafReader", "The glTF (GL Transmission Format) mesh reader into XDE document.");

// Constructors
cls_RWGltf_CafReader.def(py::init<>());

// Methods
cls_RWGltf_CafReader.def_static("get_type_name_", (const char * (*)()) &RWGltf_CafReader::get_type_name, "None");
cls_RWGltf_CafReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWGltf_CafReader::get_type_descriptor, "None");
cls_RWGltf_CafReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWGltf_CafReader::*)() const) &RWGltf_CafReader::DynamicType, "None");
cls_RWGltf_CafReader.def("ToParallel", (bool (RWGltf_CafReader::*)() const) &RWGltf_CafReader::ToParallel, "Return TRUE if multithreaded optimizations are allowed; FALSE by default.");
cls_RWGltf_CafReader.def("SetParallel", (void (RWGltf_CafReader::*)(bool)) &RWGltf_CafReader::SetParallel, "Setup multithreaded execution.", py::arg("theToParallel"));
cls_RWGltf_CafReader.def("ToSkipEmptyNodes", (bool (RWGltf_CafReader::*)()) &RWGltf_CafReader::ToSkipEmptyNodes, "Return TRUE if Nodes without Geometry should be ignored, TRUE by default.");
cls_RWGltf_CafReader.def("SetSkipEmptyNodes", (void (RWGltf_CafReader::*)(bool)) &RWGltf_CafReader::SetSkipEmptyNodes, "Set flag to ignore nodes without Geometry.", py::arg("theToSkip"));
cls_RWGltf_CafReader.def("ToUseMeshNameAsFallback", (bool (RWGltf_CafReader::*)()) &RWGltf_CafReader::ToUseMeshNameAsFallback, "Set flag to use Mesh name in case if Node name is empty, TRUE by default.");
cls_RWGltf_CafReader.def("SetMeshNameAsFallback", (void (RWGltf_CafReader::*)(bool)) &RWGltf_CafReader::SetMeshNameAsFallback, "Set flag to use Mesh name in case if Node name is empty.", py::arg("theToFallback"));

// CLASS: RWGLTF_GLTFACCESSOR
py::class_<RWGltf_GltfAccessor> cls_RWGltf_GltfAccessor(mod, "RWGltf_GltfAccessor", "Low-level glTF data structure defining Accessor.");

// Constructors
cls_RWGltf_GltfAccessor.def(py::init<>());

// Fields
cls_RWGltf_GltfAccessor.def_readwrite("Id", &RWGltf_GltfAccessor::Id, "identifier");
cls_RWGltf_GltfAccessor.def_readwrite("ByteOffset", &RWGltf_GltfAccessor::ByteOffset, "byte offset");
cls_RWGltf_GltfAccessor.def_readwrite("Count", &RWGltf_GltfAccessor::Count, "size");
cls_RWGltf_GltfAccessor.def_readwrite("ByteStride", &RWGltf_GltfAccessor::ByteStride, "[0, 255] for glTF 1.0");
cls_RWGltf_GltfAccessor.def_readwrite("Type", &RWGltf_GltfAccessor::Type, "layout type");
cls_RWGltf_GltfAccessor.def_readwrite("ComponentType", &RWGltf_GltfAccessor::ComponentType, "component type");
cls_RWGltf_GltfAccessor.def_readwrite("BndBox", &RWGltf_GltfAccessor::BndBox, "bounding box");

// CLASS: RWGLTF_GLTFBUFFERVIEW
py::class_<RWGltf_GltfBufferView> cls_RWGltf_GltfBufferView(mod, "RWGltf_GltfBufferView", "Low-level glTF data structure defining BufferView.");

// Constructors
cls_RWGltf_GltfBufferView.def(py::init<>());

// Fields
cls_RWGltf_GltfBufferView.def_readwrite("Id", &RWGltf_GltfBufferView::Id, "None");
cls_RWGltf_GltfBufferView.def_readwrite("ByteOffset", &RWGltf_GltfBufferView::ByteOffset, "None");
cls_RWGltf_GltfBufferView.def_readwrite("ByteLength", &RWGltf_GltfBufferView::ByteLength, "None");
cls_RWGltf_GltfBufferView.def_readwrite("ByteStride", &RWGltf_GltfBufferView::ByteStride, "[0, 255]");
cls_RWGltf_GltfBufferView.def_readwrite("Target", &RWGltf_GltfBufferView::Target, "None");

// CLASS: RWGLTF_GLTFFACE
py::class_<RWGltf_GltfFace> cls_RWGltf_GltfFace(mod, "RWGltf_GltfFace", "Low-level glTF data structure holding single Face (one primitive array) definition.");

// Fields
cls_RWGltf_GltfFace.def_readwrite("NodePos", &RWGltf_GltfFace::NodePos, "accessor for nodal positions");
cls_RWGltf_GltfFace.def_readwrite("NodeNorm", &RWGltf_GltfFace::NodeNorm, "accessor for nodal normals");
cls_RWGltf_GltfFace.def_readwrite("NodeUV", &RWGltf_GltfFace::NodeUV, "accessor for nodal UV texture coordinates");
cls_RWGltf_GltfFace.def_readwrite("Indices", &RWGltf_GltfFace::Indices, "accessor for indexes");

// CLASS: RWGLTF_GLTFPRIMARRAYDATA
py::class_<RWGltf_GltfPrimArrayData> cls_RWGltf_GltfPrimArrayData(mod, "RWGltf_GltfPrimArrayData", "An element within primitive array - vertex attribute or element indexes.");

// Constructors
cls_RWGltf_GltfPrimArrayData.def(py::init<>());
cls_RWGltf_GltfPrimArrayData.def(py::init<RWGltf_GltfArrayType>(), py::arg("theType"));

// Fields
cls_RWGltf_GltfPrimArrayData.def_readwrite("StreamData", &RWGltf_GltfPrimArrayData::StreamData, "None");
cls_RWGltf_GltfPrimArrayData.def_readwrite("StreamUri", &RWGltf_GltfPrimArrayData::StreamUri, "None");
cls_RWGltf_GltfPrimArrayData.def_readwrite("StreamOffset", &RWGltf_GltfPrimArrayData::StreamOffset, "None");
cls_RWGltf_GltfPrimArrayData.def_readwrite("Accessor", &RWGltf_GltfPrimArrayData::Accessor, "None");
cls_RWGltf_GltfPrimArrayData.def_readwrite("Type", &RWGltf_GltfPrimArrayData::Type, "None");

// CLASS: RWGLTF_GLTFLATEPRIMITIVEARRAY
py::class_<RWGltf_GltfLatePrimitiveArray, opencascade::handle<RWGltf_GltfLatePrimitiveArray>, Poly_Triangulation> cls_RWGltf_GltfLatePrimitiveArray(mod, "RWGltf_GltfLatePrimitiveArray", "Mesh data wrapper for delayed primitive array loading from glTF file. Class inherits Poly_Triangulation so that it can be put temporarily into TopoDS_Face within assembly structure, to be replaced with proper Poly_Triangulation loaded later on.");

// Constructors
cls_RWGltf_GltfLatePrimitiveArray.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("theId"), py::arg("theName"));

// Methods
cls_RWGltf_GltfLatePrimitiveArray.def_static("get_type_name_", (const char * (*)()) &RWGltf_GltfLatePrimitiveArray::get_type_name, "None");
cls_RWGltf_GltfLatePrimitiveArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWGltf_GltfLatePrimitiveArray::get_type_descriptor, "None");
cls_RWGltf_GltfLatePrimitiveArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::DynamicType, "None");
cls_RWGltf_GltfLatePrimitiveArray.def("Id", (const TCollection_AsciiString & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::Id, "Entity id.");
cls_RWGltf_GltfLatePrimitiveArray.def("Name", (const TCollection_AsciiString & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::Name, "Entity name.");
cls_RWGltf_GltfLatePrimitiveArray.def("SetName", (void (RWGltf_GltfLatePrimitiveArray::*)(const TCollection_AsciiString &)) &RWGltf_GltfLatePrimitiveArray::SetName, "Assign entity name.", py::arg("theName"));
cls_RWGltf_GltfLatePrimitiveArray.def("PrimitiveMode", (RWGltf_GltfPrimitiveMode (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::PrimitiveMode, "Return type of primitive array.");
cls_RWGltf_GltfLatePrimitiveArray.def("SetPrimitiveMode", (void (RWGltf_GltfLatePrimitiveArray::*)(RWGltf_GltfPrimitiveMode)) &RWGltf_GltfLatePrimitiveArray::SetPrimitiveMode, "Set type of primitive array.", py::arg("theMode"));
cls_RWGltf_GltfLatePrimitiveArray.def("HasStyle", (bool (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::HasStyle, "Return true if primitive array has assigned material");
cls_RWGltf_GltfLatePrimitiveArray.def("BaseColor", (Quantity_ColorRGBA (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::BaseColor, "Return base color.");
cls_RWGltf_GltfLatePrimitiveArray.def("MaterialPbr", (const opencascade::handle<RWGltf_MaterialMetallicRoughness> & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::MaterialPbr, "Return PBR material definition.");
cls_RWGltf_GltfLatePrimitiveArray.def("SetMaterialPbr", (void (RWGltf_GltfLatePrimitiveArray::*)(const opencascade::handle<RWGltf_MaterialMetallicRoughness> &)) &RWGltf_GltfLatePrimitiveArray::SetMaterialPbr, "Set PBR material definition.", py::arg("theMat"));
cls_RWGltf_GltfLatePrimitiveArray.def("MaterialCommon", (const opencascade::handle<RWGltf_MaterialCommon> & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::MaterialCommon, "Return common (obsolete) material definition.");
cls_RWGltf_GltfLatePrimitiveArray.def("SetMaterialCommon", (void (RWGltf_GltfLatePrimitiveArray::*)(const opencascade::handle<RWGltf_MaterialCommon> &)) &RWGltf_GltfLatePrimitiveArray::SetMaterialCommon, "Set common (obsolete) material definition.", py::arg("theMat"));
cls_RWGltf_GltfLatePrimitiveArray.def("Data", (const NCollection_Sequence<RWGltf_GltfPrimArrayData> & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::Data, "Return primitive array data elements.");
cls_RWGltf_GltfLatePrimitiveArray.def("AddPrimArrayData", (RWGltf_GltfPrimArrayData & (RWGltf_GltfLatePrimitiveArray::*)(RWGltf_GltfArrayType)) &RWGltf_GltfLatePrimitiveArray::AddPrimArrayData, "Add primitive array data element.", py::arg("theType"));
cls_RWGltf_GltfLatePrimitiveArray.def("BoundingBox", (const Bnd_Box & (RWGltf_GltfLatePrimitiveArray::*)() const) &RWGltf_GltfLatePrimitiveArray::BoundingBox, "Return bounding box defined within glTF file, or VOID if not specified.");
cls_RWGltf_GltfLatePrimitiveArray.def("SetBoundingBox", (void (RWGltf_GltfLatePrimitiveArray::*)(const Bnd_Box &)) &RWGltf_GltfLatePrimitiveArray::SetBoundingBox, "This method sets input bounding box and assigns a FAKE data to underlying Poly_Triangulation as Min/Max corners of bounding box, so that standard tools like BRepBndLib::Add() can be used transparently for computing bounding box of this face.", py::arg("theBox"));

// CLASS: RWGLTF_MATERIALCOMMON
py::class_<RWGltf_MaterialCommon, opencascade::handle<RWGltf_MaterialCommon>, Standard_Transient> cls_RWGltf_MaterialCommon(mod, "RWGltf_MaterialCommon", "glTF 1.0 format common (obsolete) material definition.");

// Constructors
cls_RWGltf_MaterialCommon.def(py::init<>());

// Fields
cls_RWGltf_MaterialCommon.def_readwrite("AmbientTexture", &RWGltf_MaterialCommon::AmbientTexture, "image defining ambient color");
cls_RWGltf_MaterialCommon.def_readwrite("DiffuseTexture", &RWGltf_MaterialCommon::DiffuseTexture, "image defining diffuse color");
cls_RWGltf_MaterialCommon.def_readwrite("SpecularTexture", &RWGltf_MaterialCommon::SpecularTexture, "image defining specular color");
cls_RWGltf_MaterialCommon.def_readwrite("Id", &RWGltf_MaterialCommon::Id, "material identifier");
cls_RWGltf_MaterialCommon.def_readwrite("Name", &RWGltf_MaterialCommon::Name, "material name");
cls_RWGltf_MaterialCommon.def_readwrite("AmbientColor", &RWGltf_MaterialCommon::AmbientColor, "None");
cls_RWGltf_MaterialCommon.def_readwrite("DiffuseColor", &RWGltf_MaterialCommon::DiffuseColor, "None");
cls_RWGltf_MaterialCommon.def_readwrite("SpecularColor", &RWGltf_MaterialCommon::SpecularColor, "None");
cls_RWGltf_MaterialCommon.def_readwrite("EmissiveColor", &RWGltf_MaterialCommon::EmissiveColor, "None");
cls_RWGltf_MaterialCommon.def_readwrite("Shininess", &RWGltf_MaterialCommon::Shininess, "None");
cls_RWGltf_MaterialCommon.def_readwrite("Transparency", &RWGltf_MaterialCommon::Transparency, "None");

// CLASS: RWGLTF_MATERIALMETALLICROUGHNESS
py::class_<RWGltf_MaterialMetallicRoughness, opencascade::handle<RWGltf_MaterialMetallicRoughness>, Standard_Transient> cls_RWGltf_MaterialMetallicRoughness(mod, "RWGltf_MaterialMetallicRoughness", "glTF 2.0 format PBR material definition.");

// Constructors
cls_RWGltf_MaterialMetallicRoughness.def(py::init<>());

// Fields
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("BaseColorTexture", &RWGltf_MaterialMetallicRoughness::BaseColorTexture, "RGB texture for the base color");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("MetallicRoughnessTexture", &RWGltf_MaterialMetallicRoughness::MetallicRoughnessTexture, "RG texture packing the metallic and roughness properties together");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("EmissiveTexture", &RWGltf_MaterialMetallicRoughness::EmissiveTexture, "RGB emissive map controls the color and intensity of the light being emitted by the material");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("OcclusionTexture", &RWGltf_MaterialMetallicRoughness::OcclusionTexture, "R occlusion map indicating areas of indirect lighting");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("NormalTexture", &RWGltf_MaterialMetallicRoughness::NormalTexture, "normal map");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("Id", &RWGltf_MaterialMetallicRoughness::Id, "material identifier");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("Name", &RWGltf_MaterialMetallicRoughness::Name, "material name");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("BaseColor", &RWGltf_MaterialMetallicRoughness::BaseColor, "base color (or scale factor to the texture); [1.0, 1.0, 1.0, 1.0] by default");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("EmissiveFactor", &RWGltf_MaterialMetallicRoughness::EmissiveFactor, "emissive color; [0.0, 0.0, 0.0] by default");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("Metallic", &RWGltf_MaterialMetallicRoughness::Metallic, "metalness (or scale factor to the texture) within range [0.0, 1.0]; 1.0 by default");
cls_RWGltf_MaterialMetallicRoughness.def_readwrite("Roughness", &RWGltf_MaterialMetallicRoughness::Roughness, "roughness (or scale factor to the texture) within range [0.0, 1.0]; 1.0 by default");

// CLASS: RWGLTF_GLTFSHAREDISTREAM
py::class_<RWGltf_GltfSharedIStream> cls_RWGltf_GltfSharedIStream(mod, "RWGltf_GltfSharedIStream", "The interface for shared file.");

// Fields
// cls_RWGltf_GltfSharedIStream.def_readwrite("Stream", &RWGltf_GltfSharedIStream::Stream, "shared file");
cls_RWGltf_GltfSharedIStream.def_readwrite("Path", &RWGltf_GltfSharedIStream::Path, "path to currently opened stream");

// CLASS: RWGLTF_PRIMITIVEARRAYREADER
py::class_<RWGltf_PrimitiveArrayReader, opencascade::handle<RWGltf_PrimitiveArrayReader>, Standard_Transient> cls_RWGltf_PrimitiveArrayReader(mod, "RWGltf_PrimitiveArrayReader", "Interface for reading primitive array from glTF buffer.");

// Methods
cls_RWGltf_PrimitiveArrayReader.def_static("get_type_name_", (const char * (*)()) &RWGltf_PrimitiveArrayReader::get_type_name, "None");
cls_RWGltf_PrimitiveArrayReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWGltf_PrimitiveArrayReader::get_type_descriptor, "None");
cls_RWGltf_PrimitiveArrayReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWGltf_PrimitiveArrayReader::*)() const) &RWGltf_PrimitiveArrayReader::DynamicType, "None");
cls_RWGltf_PrimitiveArrayReader.def("ErrorPrefix", (const TCollection_AsciiString & (RWGltf_PrimitiveArrayReader::*)() const) &RWGltf_PrimitiveArrayReader::ErrorPrefix, "Return prefix for reporting issues.");
cls_RWGltf_PrimitiveArrayReader.def("SetErrorPrefix", (void (RWGltf_PrimitiveArrayReader::*)(const TCollection_AsciiString &)) &RWGltf_PrimitiveArrayReader::SetErrorPrefix, "Set prefix for reporting issues.", py::arg("theErrPrefix"));
cls_RWGltf_PrimitiveArrayReader.def("CoordinateSystemConverter", (const RWMesh_CoordinateSystemConverter & (RWGltf_PrimitiveArrayReader::*)() const) &RWGltf_PrimitiveArrayReader::CoordinateSystemConverter, "Return transformation from glTF to OCCT coordinate system.");
cls_RWGltf_PrimitiveArrayReader.def("SetCoordinateSystemConverter", (void (RWGltf_PrimitiveArrayReader::*)(const RWMesh_CoordinateSystemConverter &)) &RWGltf_PrimitiveArrayReader::SetCoordinateSystemConverter, "Set transformation from glTF to OCCT coordinate system.", py::arg("theConverter"));
cls_RWGltf_PrimitiveArrayReader.def("Load", (opencascade::handle<Poly_Triangulation> (RWGltf_PrimitiveArrayReader::*)(const opencascade::handle<RWGltf_GltfLatePrimitiveArray> &)) &RWGltf_PrimitiveArrayReader::Load, "Load primitive array.", py::arg("theMesh"));

// CLASS: RWGLTF_TRIANGULATIONREADER
py::class_<RWGltf_TriangulationReader, opencascade::handle<RWGltf_TriangulationReader>, RWGltf_PrimitiveArrayReader> cls_RWGltf_TriangulationReader(mod, "RWGltf_TriangulationReader", "RWGltf_PrimitiveArrayReader implementation creating Poly_Triangulation.");

// Constructors
cls_RWGltf_TriangulationReader.def(py::init<>());

// Methods
cls_RWGltf_TriangulationReader.def_static("get_type_name_", (const char * (*)()) &RWGltf_TriangulationReader::get_type_name, "None");
cls_RWGltf_TriangulationReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWGltf_TriangulationReader::get_type_descriptor, "None");
cls_RWGltf_TriangulationReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWGltf_TriangulationReader::*)() const) &RWGltf_TriangulationReader::DynamicType, "None");


}
