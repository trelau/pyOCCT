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
#include <RWObj_SubMeshReason.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_ProgressIndicator.hxx>
#include <RWObj.hxx>
#include <TCollection_AsciiString.hxx>
#include <Quantity_Color.hxx>
#include <RWObj_Material.hxx>
#include <RWObj_SubMesh.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <RWObj_Reader.hxx>
#include <Standard_Type.hxx>
#include <NCollection_IndexedMap.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <RWMesh_CoordinateSystemConverter.hxx>
#include <gp_Pnt.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_Vec2.hxx>
#include <gp_XYZ.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Vector.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <RWObj_TriangulationReader.hxx>
#include <Poly_Triangle.hxx>
#include <TopoDS_Compound.hxx>
#include <RWMesh_CafReader.hxx>
#include <RWObj_CafReader.hxx>
#include <RWObj_MtlReader.hxx>

PYBIND11_MODULE(RWObj, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.RWMesh");
py::module::import("OCCT.gp");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.TopoDS");

// ENUM: RWOBJ_SUBMESHREASON
py::enum_<RWObj_SubMeshReason>(mod, "RWObj_SubMeshReason", "Reason for creating a new group within OBJ reader.")
	.value("RWObj_SubMeshReason_NewObject", RWObj_SubMeshReason::RWObj_SubMeshReason_NewObject)
	.value("RWObj_SubMeshReason_NewGroup", RWObj_SubMeshReason::RWObj_SubMeshReason_NewGroup)
	.value("RWObj_SubMeshReason_NewMaterial", RWObj_SubMeshReason::RWObj_SubMeshReason_NewMaterial)
	.value("RWObj_SubMeshReason_NewSmoothGroup", RWObj_SubMeshReason::RWObj_SubMeshReason_NewSmoothGroup)
	.export_values();


// CLASS: RWOBJ
py::class_<RWObj> cls_RWObj(mod, "RWObj", "This class provides methods to read and write triangulation from / to the OBJ files.");

// Constructors
cls_RWObj.def(py::init<>());

// Methods
cls_RWObj.def_static("ReadFile_", [](const Standard_CString a0) -> opencascade::handle<Poly_Triangulation> { return RWObj::ReadFile(a0); });
cls_RWObj.def_static("ReadFile_", (opencascade::handle<Poly_Triangulation> (*)(const Standard_CString, const opencascade::handle<Message_ProgressIndicator> &)) &RWObj::ReadFile, "Read specified OBJ file and returns its content as triangulation. In case of error, returns Null handle.", py::arg("theFile"), py::arg("aProgInd"));

// CLASS: RWOBJ_MATERIAL
py::class_<RWObj_Material> cls_RWObj_Material(mod, "RWObj_Material", "Material definition for OBJ file format.");

// Constructors
cls_RWObj_Material.def(py::init<>());

// Fields
cls_RWObj_Material.def_readwrite("Name", &RWObj_Material::Name, "material name (identifier) as defined in MTL file");
cls_RWObj_Material.def_readwrite("DiffuseTexture", &RWObj_Material::DiffuseTexture, "path to the texture image file defining diffuse color");
cls_RWObj_Material.def_readwrite("SpecularTexture", &RWObj_Material::SpecularTexture, "path to the texture image file defining specular color");
cls_RWObj_Material.def_readwrite("BumpTexture", &RWObj_Material::BumpTexture, "path to the texture image file defining normal map");
cls_RWObj_Material.def_readwrite("AmbientColor", &RWObj_Material::AmbientColor, "None");
cls_RWObj_Material.def_readwrite("DiffuseColor", &RWObj_Material::DiffuseColor, "None");
cls_RWObj_Material.def_readwrite("SpecularColor", &RWObj_Material::SpecularColor, "None");
cls_RWObj_Material.def_readwrite("Shininess", &RWObj_Material::Shininess, "None");
cls_RWObj_Material.def_readwrite("Transparency", &RWObj_Material::Transparency, "None");

// CLASS: RWOBJ_SUBMESH
py::class_<RWObj_SubMesh> cls_RWObj_SubMesh(mod, "RWObj_SubMesh", "Sub-mesh definition for OBJ reader.");

// Constructors
cls_RWObj_SubMesh.def(py::init<>());

// Fields
cls_RWObj_SubMesh.def_readwrite("Object", &RWObj_SubMesh::Object, "name of active object");
cls_RWObj_SubMesh.def_readwrite("Group", &RWObj_SubMesh::Group, "name of active group");
cls_RWObj_SubMesh.def_readwrite("SmoothGroup", &RWObj_SubMesh::SmoothGroup, "name of active smoothing group");
cls_RWObj_SubMesh.def_readwrite("Material", &RWObj_SubMesh::Material, "name of active material");

// CLASS: RWOBJ_READER
py::class_<RWObj_Reader, opencascade::handle<RWObj_Reader>, Standard_Transient> cls_RWObj_Reader(mod, "RWObj_Reader", "An abstract class implementing procedure to read OBJ file.");

// Methods
cls_RWObj_Reader.def_static("get_type_name_", (const char * (*)()) &RWObj_Reader::get_type_name, "None");
cls_RWObj_Reader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWObj_Reader::get_type_descriptor, "None");
cls_RWObj_Reader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWObj_Reader::*)() const) &RWObj_Reader::DynamicType, "None");
cls_RWObj_Reader.def("Read", (Standard_Boolean (RWObj_Reader::*)(const TCollection_AsciiString &, const opencascade::handle<Message_ProgressIndicator> &)) &RWObj_Reader::Read, "Reads data from OBJ file. Unicode paths can be given in UTF-8 encoding. Returns true if success, false on error or user break.", py::arg("theFile"), py::arg("theProgress"));
cls_RWObj_Reader.def("Probe", (Standard_Boolean (RWObj_Reader::*)(const TCollection_AsciiString &, const opencascade::handle<Message_ProgressIndicator> &)) &RWObj_Reader::Probe, "Probe data from OBJ file (comments, external references) without actually reading mesh data. Although mesh data will not be collected, the full file content will be parsed, due to OBJ format limitations.", py::arg("theFile"), py::arg("theProgress"));
cls_RWObj_Reader.def("FileComments", (const TCollection_AsciiString & (RWObj_Reader::*)() const) &RWObj_Reader::FileComments, "Returns file comments (lines starting with # at the beginning of file).");
cls_RWObj_Reader.def("ExternalFiles", (const NCollection_IndexedMap<TCollection_AsciiString> & (RWObj_Reader::*)() const) &RWObj_Reader::ExternalFiles, "Return the list of external file references.");
cls_RWObj_Reader.def("NbProbeNodes", (Standard_Integer (RWObj_Reader::*)() const) &RWObj_Reader::NbProbeNodes, "Number of probed nodes.");
cls_RWObj_Reader.def("NbProbeElems", (Standard_Integer (RWObj_Reader::*)() const) &RWObj_Reader::NbProbeElems, "None");
cls_RWObj_Reader.def("MemoryLimit", (Standard_Size (RWObj_Reader::*)() const) &RWObj_Reader::MemoryLimit, "Returns memory limit in bytes; -1 (no limit) by default.");
cls_RWObj_Reader.def("SetMemoryLimit", (void (RWObj_Reader::*)(Standard_Size)) &RWObj_Reader::SetMemoryLimit, "Specify memory limit in bytes, so that import will be aborted by specified limit before memory allocation error occurs.", py::arg("theMemLimit"));
cls_RWObj_Reader.def("Transformation", (const RWMesh_CoordinateSystemConverter & (RWObj_Reader::*)() const) &RWObj_Reader::Transformation, "Return transformation from one coordinate system to another; no transformation by default.");
cls_RWObj_Reader.def("SetTransformation", (void (RWObj_Reader::*)(const RWMesh_CoordinateSystemConverter &)) &RWObj_Reader::SetTransformation, "Setup transformation from one coordinate system to another. OBJ file might be exported following various coordinate system conventions, so that it might be useful automatically transform data during file reading.", py::arg("theCSConverter"));
cls_RWObj_Reader.def("IsSinglePrecision", (Standard_Boolean (RWObj_Reader::*)() const) &RWObj_Reader::IsSinglePrecision, "Return single precision flag for reading vertex data (coordinates); FALSE by default.");
cls_RWObj_Reader.def("SetSinglePrecision", (void (RWObj_Reader::*)(Standard_Boolean)) &RWObj_Reader::SetSinglePrecision, "Setup single/double precision flag for reading vertex data (coordinates).", py::arg("theIsSinglePrecision"));

// CLASS: RWOBJ_ISHAPERECEIVER
py::class_<RWObj_IShapeReceiver> cls_RWObj_IShapeReceiver(mod, "RWObj_IShapeReceiver", "Interface to store shape attributes into document.");

// Methods
cls_RWObj_IShapeReceiver.def("BindNamedShape", (void (RWObj_IShapeReceiver::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const RWObj_Material *, const Standard_Boolean)) &RWObj_IShapeReceiver::BindNamedShape, "", py::arg("theShape"), py::arg("theName"), py::arg("theMaterial"), py::arg("theIsRootShape"));

// CLASS: RWOBJ_TRIANGULATIONREADER
py::class_<RWObj_TriangulationReader, opencascade::handle<RWObj_TriangulationReader>, RWObj_Reader> cls_RWObj_TriangulationReader(mod, "RWObj_TriangulationReader", "RWObj_Reader implementation dumping OBJ file into Poly_Triangulation.");

// Constructors
cls_RWObj_TriangulationReader.def(py::init<>());

// Methods
cls_RWObj_TriangulationReader.def_static("get_type_name_", (const char * (*)()) &RWObj_TriangulationReader::get_type_name, "None");
cls_RWObj_TriangulationReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWObj_TriangulationReader::get_type_descriptor, "None");
cls_RWObj_TriangulationReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWObj_TriangulationReader::*)() const) &RWObj_TriangulationReader::DynamicType, "None");
cls_RWObj_TriangulationReader.def("SetCreateShapes", (void (RWObj_TriangulationReader::*)(Standard_Boolean)) &RWObj_TriangulationReader::SetCreateShapes, "Set flag to create shapes.", py::arg("theToCreateShapes"));
cls_RWObj_TriangulationReader.def("SetShapeReceiver", (void (RWObj_TriangulationReader::*)(RWObj_IShapeReceiver *)) &RWObj_TriangulationReader::SetShapeReceiver, "Set shape receiver callback.", py::arg("theReceiver"));
cls_RWObj_TriangulationReader.def("GetTriangulation", (opencascade::handle<Poly_Triangulation> (RWObj_TriangulationReader::*)()) &RWObj_TriangulationReader::GetTriangulation, "Create Poly_Triangulation from collected data");
cls_RWObj_TriangulationReader.def("ResultShape", (TopoDS_Shape (RWObj_TriangulationReader::*)()) &RWObj_TriangulationReader::ResultShape, "Return result shape.");

// CLASS: RWOBJ_CAFREADER
py::class_<RWObj_CafReader, opencascade::handle<RWObj_CafReader>, RWMesh_CafReader> cls_RWObj_CafReader(mod, "RWObj_CafReader", "The OBJ mesh reader into XDE document.", py::multiple_inheritance());

// Constructors
cls_RWObj_CafReader.def(py::init<>());

// Methods
cls_RWObj_CafReader.def_static("get_type_name_", (const char * (*)()) &RWObj_CafReader::get_type_name, "None");
cls_RWObj_CafReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWObj_CafReader::get_type_descriptor, "None");
cls_RWObj_CafReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWObj_CafReader::*)() const) &RWObj_CafReader::DynamicType, "None");
cls_RWObj_CafReader.def("IsSinglePrecision", (Standard_Boolean (RWObj_CafReader::*)() const) &RWObj_CafReader::IsSinglePrecision, "Return single precision flag for reading vertex data (coordinates); FALSE by default.");
cls_RWObj_CafReader.def("SetSinglePrecision", (void (RWObj_CafReader::*)(Standard_Boolean)) &RWObj_CafReader::SetSinglePrecision, "Setup single/double precision flag for reading vertex data (coordinates).", py::arg("theIsSinglePrecision"));

// CLASS: RWOBJ_MTLREADER
/*
py::class_<RWObj_MtlReader> cls_RWObj_MtlReader(mod, "RWObj_MtlReader", "Reader of mtl files.");

// Constructors
cls_RWObj_MtlReader.def(py::init<NCollection_DataMap<TCollection_AsciiString, RWObj_Material> &>(), py::arg("theMaterials"));

// Methods
cls_RWObj_MtlReader.def("Read", (bool (RWObj_MtlReader::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &RWObj_MtlReader::Read, "Read the file.", py::arg("theFolder"), py::arg("theFile"));
*/


}
