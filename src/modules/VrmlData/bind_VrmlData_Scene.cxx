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
#include <VrmlData_ListOfNode.hxx>
#include <NCollection_List.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_Scene.hxx>
#include <VrmlData_MapOfNode.hxx>
#include <NCollection_Map.hxx>
#include <VrmlData_Node.hxx>
#include <Standard_Type.hxx>
#include <gp_Trsf.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <TopoDS_Shape.hxx>
#include <VrmlData_DataMapOfShapeAppearance.hxx>
#include <VrmlData_WorldInfo.hxx>
#include <VrmlData_InBuffer.hxx>
#include <TCollection_AsciiString.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_Mutex.hxx>
#include <VrmlData_Group.hxx>

void bind_VrmlData_Scene(py::module &mod){

py::class_<VrmlData_Scene, std::unique_ptr<VrmlData_Scene, Deleter<VrmlData_Scene>>> cls_VrmlData_Scene(mod, "VrmlData_Scene", "Block of comments describing class VrmlData_Scene");

// Constructors
cls_VrmlData_Scene.def(py::init<>());
cls_VrmlData_Scene.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg(""));

// Fields

// Methods
cls_VrmlData_Scene.def("Status", (VrmlData_ErrorStatus (VrmlData_Scene::*)() const) &VrmlData_Scene::Status, "Query the status of the previous operation. Normally it should be equal to VrmlData_StatusOK (no error).");
cls_VrmlData_Scene.def("SetVrmlDir", (void (VrmlData_Scene::*)(const TCollection_ExtendedString &)) &VrmlData_Scene::SetVrmlDir, "Add the given directory path to the list of VRML file search directories. This method forms the list of directories ordered according to the sequence of this method calls. When an Inline node is found, the URLs in that node are matched with these directories. The last (implicit) search directory is the current process directory ('.'). It takes effect if the list is empty or if there is no match with exisiting directories.", py::arg(""));
cls_VrmlData_Scene.def("SetLinearScale", (void (VrmlData_Scene::*)(const Standard_Real)) &VrmlData_Scene::SetLinearScale, "Set the scale factor that would be further used in methods ReadReal, ReadXYZ and ReadXY. All coordinates, distances and sized are multiplied by this factor during reading the data.", py::arg("theScale"));
cls_VrmlData_Scene.def("VrmlDirIterator", (NCollection_List<TCollection_ExtendedString>::Iterator (VrmlData_Scene::*)() const) &VrmlData_Scene::VrmlDirIterator, "Returns the directory iterator, to check the presence of requested VRML file in each iterated directory.");
cls_VrmlData_Scene.def("GetIterator", (VrmlData_Scene::Iterator (VrmlData_Scene::*)() const) &VrmlData_Scene::GetIterator, "Iterator of Nodes");
cls_VrmlData_Scene.def("NamedNodesIterator", (VrmlData_MapOfNode::Iterator (VrmlData_Scene::*)() const) &VrmlData_Scene::NamedNodesIterator, "Get the iterator of named nodes.");
cls_VrmlData_Scene.def("Allocator", (const opencascade::handle<NCollection_IncAllocator> & (VrmlData_Scene::*)() const) &VrmlData_Scene::Allocator, "Allocator used by all nodes contained in the Scene.");
cls_VrmlData_Scene.def("AddNode", [](VrmlData_Scene &self, const opencascade::handle<VrmlData_Node> & a0) -> const opencascade::handle<VrmlData_Node> & { return self.AddNode(a0); });
cls_VrmlData_Scene.def("AddNode", (const opencascade::handle<VrmlData_Node> & (VrmlData_Scene::*)(const opencascade::handle<VrmlData_Node> &, const Standard_Boolean)) &VrmlData_Scene::AddNode, "Add a Node. If theN belongs to another Scene, it is cloned. VrmlData_WorldInfo cannot be added, in this case the method returns a NULL handle.", py::arg("theN"), py::arg("isTopLevel"));
cls_VrmlData_Scene.def("FindNode", [](VrmlData_Scene &self, const char * a0) -> opencascade::handle<VrmlData_Node> { return self.FindNode(a0); });
cls_VrmlData_Scene.def("FindNode", (opencascade::handle<VrmlData_Node> (VrmlData_Scene::*)(const char *, const opencascade::handle<Standard_Type> &) const) &VrmlData_Scene::FindNode, "Find a node by its name.", py::arg("theName"), py::arg("theType"));
cls_VrmlData_Scene.def("FindNode", (opencascade::handle<VrmlData_Node> (VrmlData_Scene::*)(const char *, gp_Trsf &) const) &VrmlData_Scene::FindNode, "Find a node by its name.", py::arg("theName"), py::arg("theLocation"));
cls_VrmlData_Scene.def("bits_left", (VrmlData_Scene & (VrmlData_Scene::*)(Standard_IStream &)) &VrmlData_Scene::operator<<, py::is_operator(), "Import from text stream (file or else). This method is protected by Mutex, it is not allowed to read/write two VRML streams concurrently.", py::arg("theInput"));
cls_VrmlData_Scene.def("GetShape", (TopoDS_Shape (VrmlData_Scene::*)(VrmlData_DataMapOfShapeAppearance &)) &VrmlData_Scene::GetShape, "Convert the scene to a Shape, with the information on materials defined for each sub-shape. This method should be used instead of TopoDS_Shape explicit conversion operator when you need to retrieve the material aspect for each face or edge in the returned topological object.", py::arg("M"));
cls_VrmlData_Scene.def("WorldInfo", (const opencascade::handle<VrmlData_WorldInfo> & (VrmlData_Scene::*)() const) &VrmlData_Scene::WorldInfo, "Query the WorldInfo member.");
cls_VrmlData_Scene.def_static("ReadLine_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &)) &VrmlData_Scene::ReadLine, "Read a VRML line. Empty lines and comments are skipped. The processing starts here from theBuffer.LinePtr; if there is at least one non-empty character (neither space nor comment), this line is used without reading the next one.", py::arg("theBuffer"));
cls_VrmlData_Scene.def_static("ReadWord_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, TCollection_AsciiString &)) &VrmlData_Scene::ReadWord, "Read a singel word from the input stream, delimited by whitespace.", py::arg("theBuffer"), py::arg("theStr"));
cls_VrmlData_Scene.def("Dump", (void (VrmlData_Scene::*)(Standard_OStream &) const) &VrmlData_Scene::Dump, "Diagnostic dump of the contents", py::arg("theStream"));
cls_VrmlData_Scene.def("ReadReal", [](VrmlData_Scene &self, VrmlData_InBuffer & theBuffer, Standard_Real & theResult, Standard_Boolean isApplyScale, Standard_Boolean isOnlyPositive){ VrmlData_ErrorStatus rv = self.ReadReal(theBuffer, theResult, isApplyScale, isOnlyPositive); return std::tuple<VrmlData_ErrorStatus, Standard_Real &>(rv, theResult); }, "Read one real value.", py::arg("theBuffer"), py::arg("theResult"), py::arg("isApplyScale"), py::arg("isOnlyPositive"));
cls_VrmlData_Scene.def("ReadXYZ", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, gp_XYZ &, Standard_Boolean, Standard_Boolean) const) &VrmlData_Scene::ReadXYZ, "Read one triplet of real values.", py::arg("theBuffer"), py::arg("theXYZ"), py::arg("isApplyScale"), py::arg("isOnlyPositive"));
cls_VrmlData_Scene.def("ReadXY", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, gp_XY &, Standard_Boolean, Standard_Boolean) const) &VrmlData_Scene::ReadXY, "Read one doublet of real values.", py::arg("theBuffer"), py::arg("theXYZ"), py::arg("isApplyScale"), py::arg("isOnlyPositive"));
// cls_VrmlData_Scene.def("ReadArrIndex", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, const Standard_Integer **&, Standard_Size &) const) &VrmlData_Scene::ReadArrIndex, "Read an array of integer indices, for IndexedfaceSet and IndexedLineSet.", py::arg("theBuffer"), py::arg("theArr"), py::arg("theNBl"));
cls_VrmlData_Scene.def("GetLineError", (Standard_Integer (VrmlData_Scene::*)() const) &VrmlData_Scene::GetLineError, "Query the line where the error occurred (if the status is not OK)");
cls_VrmlData_Scene.def("SetIndent", (void (VrmlData_Scene::*)(const Standard_Integer)) &VrmlData_Scene::SetIndent, "Store the indentation for VRML output.", py::arg("nSpc"));
cls_VrmlData_Scene.def("WriteXYZ", [](VrmlData_Scene &self, const gp_XYZ & a0, const Standard_Boolean a1) -> VrmlData_ErrorStatus { return self.WriteXYZ(a0, a1); });
cls_VrmlData_Scene.def("WriteXYZ", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const gp_XYZ &, const Standard_Boolean, const char *) const) &VrmlData_Scene::WriteXYZ, "Write a triplet of real values on a separate line.", py::arg("theXYZ"), py::arg("isScale"), py::arg("thePostfix"));
// cls_VrmlData_Scene.def("WriteArrIndex", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const char *, const Standard_Integer **, const Standard_Size) const) &VrmlData_Scene::WriteArrIndex, "Write an array of integer indices, for IndexedFaceSet and IndexedLineSet.", py::arg("thePrefix"), py::arg("theArr"), py::arg("theNbBl"));
cls_VrmlData_Scene.def("WriteLine", [](VrmlData_Scene &self, const char * a0) -> VrmlData_ErrorStatus { return self.WriteLine(a0); });
cls_VrmlData_Scene.def("WriteLine", [](VrmlData_Scene &self, const char * a0, const char * a1) -> VrmlData_ErrorStatus { return self.WriteLine(a0, a1); });
cls_VrmlData_Scene.def("WriteLine", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const char *, const char *, const Standard_Integer) const) &VrmlData_Scene::WriteLine, "Write a string to the output stream respecting the indentation. The string can be defined as two substrings that will be separated by a space. Each of the substrings can be NULL, then it is ignored. If both are NULL, then a single newline is output (without indent).", py::arg("theLine0"), py::arg("theLine1"), py::arg("theIndent"));
cls_VrmlData_Scene.def("WriteNode", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const char *, const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Scene::WriteNode, "Write the given node to output stream 'myOutput'.", py::arg("thePrefix"), py::arg(""));
cls_VrmlData_Scene.def("IsDummyWrite", (Standard_Boolean (VrmlData_Scene::*)() const) &VrmlData_Scene::IsDummyWrite, "Query if the current write operation is dummy, i.e., for the purpose of collecting information before the real write is commenced.");

// Enums

}