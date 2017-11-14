#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <VrmlData_ErrorStatus.hxx>
#include <Standard_IStream.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_List.hxx>
#include <VrmlData_Scene.hxx>
#include <NCollection_Map.hxx>
#include <VrmlData_Node.hxx>
#include <Standard_Type.hxx>
#include <gp_Trsf.hxx>
#include <TopoDS_Shape.hxx>
#include <VrmlData_DataMapOfShapeAppearance.hxx>
#include <VrmlData_WorldInfo.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_OStream.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_Transient.hxx>
#include <Quantity_Color.hxx>
#include <VrmlData_Material.hxx>
#include <VrmlData_Texture.hxx>
#include <VrmlData_TextureTransform.hxx>
#include <VrmlData_Appearance.hxx>
#include <VrmlData_ArrayVec3d.hxx>
#include <TopoDS_TShape.hxx>
#include <VrmlData_Geometry.hxx>
#include <VrmlData_Box.hxx>
#include <VrmlData_Color.hxx>
#include <VrmlData_Cone.hxx>
#include <VrmlData_Coordinate.hxx>
#include <VrmlData_Cylinder.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <VrmlData_Faceted.hxx>
#include <NCollection_BaseList.hxx>
#include <VrmlData_ListOfNode.hxx>
#include <VrmlData_Group.hxx>
#include <Bnd_B3f.hxx>
#include <VrmlData_ImageTexture.hxx>
#include <VrmlData_Normal.hxx>
#include <VrmlData_TextureCoordinate.hxx>
#include <VrmlData_IndexedFaceSet.hxx>
#include <VrmlData_IndexedLineSet.hxx>
#include <VrmlData_MapOfNode.hxx>
#include <VrmlData_ShapeConvert.hxx>
#include <VrmlData_ShapeNode.hxx>
#include <VrmlData_Sphere.hxx>
#include <VrmlData_UnknownNode.hxx>

PYBIND11_MODULE(VrmlData, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.Bnd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_ErrorStatus.hxx
	py::enum_<VrmlData_ErrorStatus>(mod, "VrmlData_ErrorStatus", "Status of read/write or other operation.")
		.value("VrmlData_StatusOK", VrmlData_ErrorStatus::VrmlData_StatusOK)
		.value("VrmlData_EmptyData", VrmlData_ErrorStatus::VrmlData_EmptyData)
		.value("VrmlData_UnrecoverableError", VrmlData_ErrorStatus::VrmlData_UnrecoverableError)
		.value("VrmlData_GeneralError", VrmlData_ErrorStatus::VrmlData_GeneralError)
		.value("VrmlData_EndOfFile", VrmlData_ErrorStatus::VrmlData_EndOfFile)
		.value("VrmlData_NotVrmlFile", VrmlData_ErrorStatus::VrmlData_NotVrmlFile)
		.value("VrmlData_CannotOpenFile", VrmlData_ErrorStatus::VrmlData_CannotOpenFile)
		.value("VrmlData_VrmlFormatError", VrmlData_ErrorStatus::VrmlData_VrmlFormatError)
		.value("VrmlData_NumericInputError", VrmlData_ErrorStatus::VrmlData_NumericInputError)
		.value("VrmlData_IrrelevantNumber", VrmlData_ErrorStatus::VrmlData_IrrelevantNumber)
		.value("VrmlData_BooleanInputError", VrmlData_ErrorStatus::VrmlData_BooleanInputError)
		.value("VrmlData_StringInputError", VrmlData_ErrorStatus::VrmlData_StringInputError)
		.value("VrmlData_NodeNameUnknown", VrmlData_ErrorStatus::VrmlData_NodeNameUnknown)
		.value("VrmlData_NonPositiveSize", VrmlData_ErrorStatus::VrmlData_NonPositiveSize)
		.value("VrmlData_ReadUnknownNode", VrmlData_ErrorStatus::VrmlData_ReadUnknownNode)
		.value("VrmlData_NonSupportedFeature", VrmlData_ErrorStatus::VrmlData_NonSupportedFeature)
		.value("VrmlData_OutputStreamUndefined", VrmlData_ErrorStatus::VrmlData_OutputStreamUndefined)
		.value("VrmlData_NotImplemented", VrmlData_ErrorStatus::VrmlData_NotImplemented)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Node.hxx
	mod.def("HashCode", (Standard_Integer (*)(const opencascade::handle<VrmlData_Node> &, const Standard_Integer)) &HashCode, "None", py::arg("theNode"), py::arg("theUpper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Node.hxx
	mod.def("IsEqual", (Standard_Boolean (*)(const opencascade::handle<VrmlData_Node> &, const opencascade::handle<VrmlData_Node> &)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_InBuffer.hxx
	py::class_<VrmlData_InBuffer, std::unique_ptr<VrmlData_InBuffer, Deleter<VrmlData_InBuffer>>> cls_VrmlData_InBuffer(mod, "VrmlData_InBuffer", "Structure passed to the methods dealing with input stream.");
	cls_VrmlData_InBuffer.def(py::init<Standard_IStream &>(), py::arg("theStream"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Scene.hxx
	py::class_<VrmlData_Scene, std::unique_ptr<VrmlData_Scene, Deleter<VrmlData_Scene>>> cls_VrmlData_Scene(mod, "VrmlData_Scene", "Block of comments describing class VrmlData_Scene");
	cls_VrmlData_Scene.def(py::init<>());
	cls_VrmlData_Scene.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg(""));
	cls_VrmlData_Scene.def("Status", (VrmlData_ErrorStatus (VrmlData_Scene::*)() const ) &VrmlData_Scene::Status, "Query the status of the previous operation. Normally it should be equal to VrmlData_StatusOK (no error).");
	cls_VrmlData_Scene.def("SetVrmlDir", (void (VrmlData_Scene::*)(const TCollection_ExtendedString &)) &VrmlData_Scene::SetVrmlDir, "Add the given directory path to the list of VRML file search directories. This method forms the list of directories ordered according to the sequence of this method calls. When an Inline node is found, the URLs in that node are matched with these directories. The last (implicit) search directory is the current process directory ('.'). It takes effect if the list is empty or if there is no match with exisiting directories.", py::arg(""));
	cls_VrmlData_Scene.def("SetLinearScale", (void (VrmlData_Scene::*)(const Standard_Real)) &VrmlData_Scene::SetLinearScale, "Set the scale factor that would be further used in methods ReadReal, ReadXYZ and ReadXY. All coordinates, distances and sized are multiplied by this factor during reading the data.", py::arg("theScale"));
	cls_VrmlData_Scene.def("VrmlDirIterator", (NCollection_List<TCollection_ExtendedString>::Iterator (VrmlData_Scene::*)() const ) &VrmlData_Scene::VrmlDirIterator, "Returns the directory iterator, to check the presence of requested VRML file in each iterated directory.");
	cls_VrmlData_Scene.def("GetIterator", (VrmlData_Scene::Iterator (VrmlData_Scene::*)() const ) &VrmlData_Scene::GetIterator, "Iterator of Nodes");
	cls_VrmlData_Scene.def("NamedNodesIterator", (VrmlData_MapOfNode::Iterator (VrmlData_Scene::*)() const ) &VrmlData_Scene::NamedNodesIterator, "Get the iterator of named nodes.");
	cls_VrmlData_Scene.def("Allocator", (const opencascade::handle<NCollection_IncAllocator> & (VrmlData_Scene::*)() const ) &VrmlData_Scene::Allocator, "Allocator used by all nodes contained in the Scene.");
	cls_VrmlData_Scene.def("AddNode", [](VrmlData_Scene &self, const opencascade::handle<VrmlData_Node> & a0) -> const opencascade::handle<VrmlData_Node> & { return self.AddNode(a0); }, py::arg("theN"));
	cls_VrmlData_Scene.def("AddNode", (const opencascade::handle<VrmlData_Node> & (VrmlData_Scene::*)(const opencascade::handle<VrmlData_Node> &, const Standard_Boolean)) &VrmlData_Scene::AddNode, "Add a Node. If theN belongs to another Scene, it is cloned. VrmlData_WorldInfo cannot be added, in this case the method returns a NULL handle.", py::arg("theN"), py::arg("isTopLevel"));
	cls_VrmlData_Scene.def("FindNode", [](VrmlData_Scene &self, const char * a0) -> opencascade::handle<VrmlData_Node> { return self.FindNode(a0); }, py::arg("theName"));
	cls_VrmlData_Scene.def("FindNode", (opencascade::handle<VrmlData_Node> (VrmlData_Scene::*)(const char *, const opencascade::handle<Standard_Type> &) const ) &VrmlData_Scene::FindNode, "Find a node by its name.", py::arg("theName"), py::arg("theType"));
	cls_VrmlData_Scene.def("FindNode", (opencascade::handle<VrmlData_Node> (VrmlData_Scene::*)(const char *, gp_Trsf &) const ) &VrmlData_Scene::FindNode, "Find a node by its name.", py::arg("theName"), py::arg("theLocation"));
	cls_VrmlData_Scene.def("operator<<", (VrmlData_Scene & (VrmlData_Scene::*)(Standard_IStream &)) &VrmlData_Scene::operator<<, "Import from text stream (file or else). This method is protected by Mutex, it is not allowed to read/write two VRML streams concurrently.", py::arg("theInput"));
	cls_VrmlData_Scene.def("GetShape", (TopoDS_Shape (VrmlData_Scene::*)(VrmlData_DataMapOfShapeAppearance &)) &VrmlData_Scene::GetShape, "Convert the scene to a Shape, with the information on materials defined for each sub-shape. This method should be used instead of TopoDS_Shape explicit conversion operator when you need to retrieve the material aspect for each face or edge in the returned topological object.", py::arg("M"));
	cls_VrmlData_Scene.def("WorldInfo", (const opencascade::handle<VrmlData_WorldInfo> & (VrmlData_Scene::*)() const ) &VrmlData_Scene::WorldInfo, "Query the WorldInfo member.");
	cls_VrmlData_Scene.def_static("ReadLine_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &)) &VrmlData_Scene::ReadLine, "Read a VRML line. Empty lines and comments are skipped. The processing starts here from theBuffer.LinePtr; if there is at least one non-empty character (neither space nor comment), this line is used without reading the next one.", py::arg("theBuffer"));
	cls_VrmlData_Scene.def_static("ReadWord_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, TCollection_AsciiString &)) &VrmlData_Scene::ReadWord, "Read a singel word from the input stream, delimited by whitespace.", py::arg("theBuffer"), py::arg("theStr"));
	// FIXME cls_VrmlData_Scene.def("Dump", (void (VrmlData_Scene::*)(Standard_OStream &) const ) &VrmlData_Scene::Dump, "Diagnostic dump of the contents", py::arg("theStream"));
	cls_VrmlData_Scene.def("ReadReal", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, Standard_Real &, Standard_Boolean, Standard_Boolean) const ) &VrmlData_Scene::ReadReal, "Read one real value.", py::arg("theBuffer"), py::arg("theResult"), py::arg("isApplyScale"), py::arg("isOnlyPositive"));
	cls_VrmlData_Scene.def("ReadXYZ", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, gp_XYZ &, Standard_Boolean, Standard_Boolean) const ) &VrmlData_Scene::ReadXYZ, "Read one triplet of real values.", py::arg("theBuffer"), py::arg("theXYZ"), py::arg("isApplyScale"), py::arg("isOnlyPositive"));
	cls_VrmlData_Scene.def("ReadXY", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, gp_XY &, Standard_Boolean, Standard_Boolean) const ) &VrmlData_Scene::ReadXY, "Read one doublet of real values.", py::arg("theBuffer"), py::arg("theXYZ"), py::arg("isApplyScale"), py::arg("isOnlyPositive"));
	// FIXME cls_VrmlData_Scene.def("ReadArrIndex", (VrmlData_ErrorStatus (VrmlData_Scene::*)(VrmlData_InBuffer &, const Standard_Integer **&, Standard_Size &) const ) &VrmlData_Scene::ReadArrIndex, "Read an array of integer indices, for IndexedfaceSet and IndexedLineSet.", py::arg("theBuffer"), py::arg("theArr"), py::arg("theNBl"));
	cls_VrmlData_Scene.def("GetLineError", (Standard_Integer (VrmlData_Scene::*)() const ) &VrmlData_Scene::GetLineError, "Query the line where the error occurred (if the status is not OK)");
	cls_VrmlData_Scene.def("SetIndent", (void (VrmlData_Scene::*)(const Standard_Integer)) &VrmlData_Scene::SetIndent, "Store the indentation for VRML output.", py::arg("nSpc"));
	cls_VrmlData_Scene.def("WriteXYZ", [](VrmlData_Scene &self, const gp_XYZ & a0, const Standard_Boolean a1) -> VrmlData_ErrorStatus { return self.WriteXYZ(a0, a1); }, py::arg("theXYZ"), py::arg("isScale"));
	cls_VrmlData_Scene.def("WriteXYZ", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const gp_XYZ &, const Standard_Boolean, const char *) const ) &VrmlData_Scene::WriteXYZ, "Write a triplet of real values on a separate line.", py::arg("theXYZ"), py::arg("isScale"), py::arg("thePostfix"));
	// FIXME cls_VrmlData_Scene.def("WriteArrIndex", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const char *, const Standard_Integer **, const Standard_Size) const ) &VrmlData_Scene::WriteArrIndex, "Write an array of integer indices, for IndexedFaceSet and IndexedLineSet.", py::arg("thePrefix"), py::arg("theArr"), py::arg("theNbBl"));
	cls_VrmlData_Scene.def("WriteLine", [](VrmlData_Scene &self, const char * a0) -> VrmlData_ErrorStatus { return self.WriteLine(a0); }, py::arg("theLine0"));
	cls_VrmlData_Scene.def("WriteLine", [](VrmlData_Scene &self, const char * a0, const char * a1) -> VrmlData_ErrorStatus { return self.WriteLine(a0, a1); }, py::arg("theLine0"), py::arg("theLine1"));
	cls_VrmlData_Scene.def("WriteLine", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const char *, const char *, const Standard_Integer) const ) &VrmlData_Scene::WriteLine, "Write a string to the output stream respecting the indentation. The string can be defined as two substrings that will be separated by a space. Each of the substrings can be NULL, then it is ignored. If both are NULL, then a single newline is output (without indent).", py::arg("theLine0"), py::arg("theLine1"), py::arg("theIndent"));
	cls_VrmlData_Scene.def("WriteNode", (VrmlData_ErrorStatus (VrmlData_Scene::*)(const char *, const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Scene::WriteNode, "Write the given node to output stream 'myOutput'.", py::arg("thePrefix"), py::arg(""));
	cls_VrmlData_Scene.def("IsDummyWrite", (Standard_Boolean (VrmlData_Scene::*)() const ) &VrmlData_Scene::IsDummyWrite, "Query if the current write operation is dummy, i.e., for the purpose of collecting information before the real write is commenced.");

	// Callback for VrmlData_Node.
	class PyCallback_VrmlData_Node : public VrmlData_Node {
	public:
		using VrmlData_Node::VrmlData_Node;

		VrmlData_ErrorStatus Read(VrmlData_InBuffer & theBuffer) override { PYBIND11_OVERLOAD_PURE(VrmlData_ErrorStatus, VrmlData_Node, Read, theBuffer); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Node.hxx
	py::class_<VrmlData_Node, opencascade::handle<VrmlData_Node>, PyCallback_VrmlData_Node, Standard_Transient> cls_VrmlData_Node(mod, "VrmlData_Node", "Abstract VRML Node");
	cls_VrmlData_Node.def(py::init<>());
	cls_VrmlData_Node.def("Scene", (const VrmlData_Scene & (VrmlData_Node::*)() const ) &VrmlData_Node::Scene, "Query the Scene that contains this Node");
	cls_VrmlData_Node.def("Name", (const char * (VrmlData_Node::*)() const ) &VrmlData_Node::Name, "Query the name");
	cls_VrmlData_Node.def("ReadNode", [](VrmlData_Node &self, VrmlData_InBuffer & a0, opencascade::handle<VrmlData_Node> & a1) -> VrmlData_ErrorStatus { return self.ReadNode(a0, a1); }, py::arg("theBuffer"), py::arg("theNode"));
	cls_VrmlData_Node.def("ReadNode", (VrmlData_ErrorStatus (VrmlData_Node::*)(VrmlData_InBuffer &, opencascade::handle<VrmlData_Node> &, const opencascade::handle<Standard_Type> &)) &VrmlData_Node::ReadNode, "Read a complete node definition from VRML stream", py::arg("theBuffer"), py::arg("theNode"), py::arg("Type"));
	cls_VrmlData_Node.def("Read", (VrmlData_ErrorStatus (VrmlData_Node::*)(VrmlData_InBuffer &)) &VrmlData_Node::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_Node.def("Write", (VrmlData_ErrorStatus (VrmlData_Node::*)(const char *) const ) &VrmlData_Node::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_Node.def("IsDefault", (Standard_Boolean (VrmlData_Node::*)() const ) &VrmlData_Node::IsDefault, "Returns True if the node is default, then it would not be written.");
	cls_VrmlData_Node.def("WriteClosing", (VrmlData_ErrorStatus (VrmlData_Node::*)() const ) &VrmlData_Node::WriteClosing, "Write the closing brace in the end of a node output.");
	cls_VrmlData_Node.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Node::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Node::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified. This method nullifies the argument node if its member myScene differs from that one of the current instance.", py::arg(""));
	cls_VrmlData_Node.def_static("ReadBoolean_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, Standard_Boolean &)) &VrmlData_Node::ReadBoolean, "Read one boolean value (TRUE or FALSE).", py::arg("theBuffer"), py::arg("theResult"));
	cls_VrmlData_Node.def_static("ReadString_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, TCollection_AsciiString &)) &VrmlData_Node::ReadString, "Read one quoted string, the quotes are removed.", py::arg("theBuffer"), py::arg("theRes"));
	cls_VrmlData_Node.def_static("ReadMultiString_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, NCollection_List<TCollection_AsciiString> &)) &VrmlData_Node::ReadMultiString, "Read one quoted string, the quotes are removed.", py::arg("theBuffer"), py::arg("theRes"));
	cls_VrmlData_Node.def_static("ReadInteger_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, long &)) &VrmlData_Node::ReadInteger, "Read one integer value.", py::arg("theBuffer"), py::arg("theResult"));
	cls_VrmlData_Node.def_static("OK_", (Standard_Boolean (*)(const VrmlData_ErrorStatus)) &VrmlData_Node::OK, "None", py::arg("theStat"));
	cls_VrmlData_Node.def_static("OK_", (Standard_Boolean (*)(VrmlData_ErrorStatus &, const VrmlData_ErrorStatus)) &VrmlData_Node::OK, "None", py::arg("outStat"), py::arg("theStat"));
	cls_VrmlData_Node.def_static("GlobalIndent_", (Standard_Integer (*)()) &VrmlData_Node::GlobalIndent, "Define the common Indent in spaces, for writing all nodes.");
	cls_VrmlData_Node.def_static("get_type_name_", (const char * (*)()) &VrmlData_Node::get_type_name, "None");
	cls_VrmlData_Node.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Node::get_type_descriptor, "None");
	cls_VrmlData_Node.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Node::*)() const ) &VrmlData_Node::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Material.hxx
	py::class_<VrmlData_Material, opencascade::handle<VrmlData_Material>, VrmlData_Node> cls_VrmlData_Material(mod, "VrmlData_Material", "Implementation of the Material node");
	cls_VrmlData_Material.def(py::init<>());
	cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theAmbientIntensity"));
	cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theAmbientIntensity"), py::arg("theShininess"));
	cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theAmbientIntensity"), py::arg("theShininess"), py::arg("theTransparency"));
	cls_VrmlData_Material.def("AmbientIntensity", (Standard_Real (VrmlData_Material::*)() const ) &VrmlData_Material::AmbientIntensity, "Query the Ambient Intensity value");
	cls_VrmlData_Material.def("Shininess", (Standard_Real (VrmlData_Material::*)() const ) &VrmlData_Material::Shininess, "Query the Shininess value");
	cls_VrmlData_Material.def("Transparency", (Standard_Real (VrmlData_Material::*)() const ) &VrmlData_Material::Transparency, "Query the Transparency value");
	cls_VrmlData_Material.def("DiffuseColor", (const Quantity_Color & (VrmlData_Material::*)() const ) &VrmlData_Material::DiffuseColor, "Query the Diffuse color");
	cls_VrmlData_Material.def("EmissiveColor", (const Quantity_Color & (VrmlData_Material::*)() const ) &VrmlData_Material::EmissiveColor, "Query the Emissive color");
	cls_VrmlData_Material.def("SpecularColor", (const Quantity_Color & (VrmlData_Material::*)() const ) &VrmlData_Material::SpecularColor, "Query the Specular color");
	cls_VrmlData_Material.def("SetAmbientIntensity", (void (VrmlData_Material::*)(const Standard_Real)) &VrmlData_Material::SetAmbientIntensity, "Set the Ambient Intensity value", py::arg("theAmbientIntensity"));
	cls_VrmlData_Material.def("SetShininess", (void (VrmlData_Material::*)(const Standard_Real)) &VrmlData_Material::SetShininess, "Set the Shininess value", py::arg("theShininess"));
	cls_VrmlData_Material.def("SetTransparency", (void (VrmlData_Material::*)(const Standard_Real)) &VrmlData_Material::SetTransparency, "Set the Transparency value", py::arg("theTransparency"));
	cls_VrmlData_Material.def("SetDiffuseColor", (void (VrmlData_Material::*)(const Quantity_Color &)) &VrmlData_Material::SetDiffuseColor, "Query the Diffuse color", py::arg("theColor"));
	cls_VrmlData_Material.def("SetEmissiveColor", (void (VrmlData_Material::*)(const Quantity_Color &)) &VrmlData_Material::SetEmissiveColor, "Query the Emissive color", py::arg("theColor"));
	cls_VrmlData_Material.def("SetSpecularColor", (void (VrmlData_Material::*)(const Quantity_Color &)) &VrmlData_Material::SetSpecularColor, "Query the Specular color", py::arg("theColor"));
	cls_VrmlData_Material.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Material::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Material::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Material.def("Read", (VrmlData_ErrorStatus (VrmlData_Material::*)(VrmlData_InBuffer &)) &VrmlData_Material::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_Material.def("Write", (VrmlData_ErrorStatus (VrmlData_Material::*)(const char *) const ) &VrmlData_Material::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
	cls_VrmlData_Material.def("IsDefault", (Standard_Boolean (VrmlData_Material::*)() const ) &VrmlData_Material::IsDefault, "Returns True if the node is default, so that it should not be written.");
	cls_VrmlData_Material.def_static("get_type_name_", (const char * (*)()) &VrmlData_Material::get_type_name, "None");
	cls_VrmlData_Material.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Material::get_type_descriptor, "None");
	cls_VrmlData_Material.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Material::*)() const ) &VrmlData_Material::DynamicType, "None");

	// Callback for VrmlData_Texture.
	class PyCallback_VrmlData_Texture : public VrmlData_Texture {
	public:
		using VrmlData_Texture::VrmlData_Texture;

		VrmlData_ErrorStatus Read(VrmlData_InBuffer & theBuffer) override { PYBIND11_OVERLOAD_PURE(VrmlData_ErrorStatus, VrmlData_Texture, Read, theBuffer); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Texture.hxx
	py::class_<VrmlData_Texture, opencascade::handle<VrmlData_Texture>, PyCallback_VrmlData_Texture, VrmlData_Node> cls_VrmlData_Texture(mod, "VrmlData_Texture", "Implementation of the Texture node");
	cls_VrmlData_Texture.def(py::init<>());
	cls_VrmlData_Texture.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Texture.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("theRepeatS"));
	cls_VrmlData_Texture.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("theRepeatS"), py::arg("theRepeatT"));
	cls_VrmlData_Texture.def("RepeatS", (Standard_Boolean (VrmlData_Texture::*)() const ) &VrmlData_Texture::RepeatS, "Query the RepeatS value");
	cls_VrmlData_Texture.def("RepeatT", (Standard_Boolean (VrmlData_Texture::*)() const ) &VrmlData_Texture::RepeatT, "Query the RepeatT value");
	cls_VrmlData_Texture.def("SetRepeatS", (void (VrmlData_Texture::*)(const Standard_Boolean)) &VrmlData_Texture::SetRepeatS, "Set the RepeatS flag", py::arg("theFlag"));
	cls_VrmlData_Texture.def("SetRepeatT", (void (VrmlData_Texture::*)(const Standard_Boolean)) &VrmlData_Texture::SetRepeatT, "Set the RepeatT flag", py::arg("theFlag"));
	cls_VrmlData_Texture.def_static("get_type_name_", (const char * (*)()) &VrmlData_Texture::get_type_name, "None");
	cls_VrmlData_Texture.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Texture::get_type_descriptor, "None");
	cls_VrmlData_Texture.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Texture::*)() const ) &VrmlData_Texture::DynamicType, "None");

	// Callback for VrmlData_TextureTransform.
	class PyCallback_VrmlData_TextureTransform : public VrmlData_TextureTransform {
	public:
		using VrmlData_TextureTransform::VrmlData_TextureTransform;

		VrmlData_ErrorStatus Read(VrmlData_InBuffer & theBuffer) override { PYBIND11_OVERLOAD_PURE(VrmlData_ErrorStatus, VrmlData_TextureTransform, Read, theBuffer); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_TextureTransform.hxx
	py::class_<VrmlData_TextureTransform, opencascade::handle<VrmlData_TextureTransform>, PyCallback_VrmlData_TextureTransform, VrmlData_Node> cls_VrmlData_TextureTransform(mod, "VrmlData_TextureTransform", "Implementation of the TextureTransform node");
	cls_VrmlData_TextureTransform.def(py::init<>());
	cls_VrmlData_TextureTransform.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_TextureTransform.def("Center", (const gp_XY & (VrmlData_TextureTransform::*)() const ) &VrmlData_TextureTransform::Center, "Query the Center");
	cls_VrmlData_TextureTransform.def("Rotation", (Standard_Real (VrmlData_TextureTransform::*)() const ) &VrmlData_TextureTransform::Rotation, "Query the Rotation");
	cls_VrmlData_TextureTransform.def("Scale", (const gp_XY & (VrmlData_TextureTransform::*)() const ) &VrmlData_TextureTransform::Scale, "Query the Scale");
	cls_VrmlData_TextureTransform.def("Translation", (const gp_XY & (VrmlData_TextureTransform::*)() const ) &VrmlData_TextureTransform::Translation, "Query the Translation");
	cls_VrmlData_TextureTransform.def("SetCenter", (void (VrmlData_TextureTransform::*)(const gp_XY &)) &VrmlData_TextureTransform::SetCenter, "Set the Center", py::arg("V"));
	cls_VrmlData_TextureTransform.def("SetRotation", (void (VrmlData_TextureTransform::*)(const Standard_Real)) &VrmlData_TextureTransform::SetRotation, "Set the Rotation", py::arg("V"));
	cls_VrmlData_TextureTransform.def("SetScale", (void (VrmlData_TextureTransform::*)(const gp_XY &)) &VrmlData_TextureTransform::SetScale, "Set the Scale", py::arg("V"));
	cls_VrmlData_TextureTransform.def("SetTranslation", (void (VrmlData_TextureTransform::*)(const gp_XY &)) &VrmlData_TextureTransform::SetTranslation, "Set the Translation", py::arg("V"));
	cls_VrmlData_TextureTransform.def_static("get_type_name_", (const char * (*)()) &VrmlData_TextureTransform::get_type_name, "None");
	cls_VrmlData_TextureTransform.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_TextureTransform::get_type_descriptor, "None");
	cls_VrmlData_TextureTransform.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_TextureTransform::*)() const ) &VrmlData_TextureTransform::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Appearance.hxx
	py::class_<VrmlData_Appearance, opencascade::handle<VrmlData_Appearance>, VrmlData_Node> cls_VrmlData_Appearance(mod, "VrmlData_Appearance", "Implementation of the Appearance node type");
	cls_VrmlData_Appearance.def(py::init<>());
	cls_VrmlData_Appearance.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Appearance.def("Material", (const opencascade::handle<VrmlData_Material> & (VrmlData_Appearance::*)() const ) &VrmlData_Appearance::Material, "Query the Material");
	cls_VrmlData_Appearance.def("Texture", (const opencascade::handle<VrmlData_Texture> & (VrmlData_Appearance::*)() const ) &VrmlData_Appearance::Texture, "Query the Texture");
	cls_VrmlData_Appearance.def("TextureTransform", (const opencascade::handle<VrmlData_TextureTransform> & (VrmlData_Appearance::*)() const ) &VrmlData_Appearance::TextureTransform, "Query the TextureTransform");
	cls_VrmlData_Appearance.def("SetMaterial", (void (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_Material> &)) &VrmlData_Appearance::SetMaterial, "Set the Material", py::arg("theMat"));
	cls_VrmlData_Appearance.def("SetTexture", (void (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_Texture> &)) &VrmlData_Appearance::SetTexture, "Set the Texture", py::arg("theTexture"));
	cls_VrmlData_Appearance.def("SetTextureTransform", (void (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_TextureTransform> &)) &VrmlData_Appearance::SetTextureTransform, "Set the Texture Transform", py::arg("theTT"));
	cls_VrmlData_Appearance.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Appearance::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg(""));
	cls_VrmlData_Appearance.def("Read", (VrmlData_ErrorStatus (VrmlData_Appearance::*)(VrmlData_InBuffer &)) &VrmlData_Appearance::Read, "Read the node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_Appearance.def("Write", (VrmlData_ErrorStatus (VrmlData_Appearance::*)(const char *) const ) &VrmlData_Appearance::Write, "Write the Node from input stream.", py::arg("thePrefix"));
	cls_VrmlData_Appearance.def("IsDefault", (Standard_Boolean (VrmlData_Appearance::*)() const ) &VrmlData_Appearance::IsDefault, "Returns True if the node is default, so that it should not be written.");
	cls_VrmlData_Appearance.def_static("get_type_name_", (const char * (*)()) &VrmlData_Appearance::get_type_name, "None");
	cls_VrmlData_Appearance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Appearance::get_type_descriptor, "None");
	cls_VrmlData_Appearance.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Appearance::*)() const ) &VrmlData_Appearance::DynamicType, "None");

	// Callback for VrmlData_ArrayVec3d.
	class PyCallback_VrmlData_ArrayVec3d : public VrmlData_ArrayVec3d {
	public:
		using VrmlData_ArrayVec3d::VrmlData_ArrayVec3d;

		VrmlData_ErrorStatus Read(VrmlData_InBuffer & theBuffer) override { PYBIND11_OVERLOAD_PURE(VrmlData_ErrorStatus, VrmlData_ArrayVec3d, Read, theBuffer); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_ArrayVec3d.hxx
	py::class_<VrmlData_ArrayVec3d, opencascade::handle<VrmlData_ArrayVec3d>, PyCallback_VrmlData_ArrayVec3d, VrmlData_Node> cls_VrmlData_ArrayVec3d(mod, "VrmlData_ArrayVec3d", "Implementatioon of basic node for Coordinate, Normal and Color (array of triplets).");
	cls_VrmlData_ArrayVec3d.def(py::init<>());
	cls_VrmlData_ArrayVec3d.def(py::init<const VrmlData_Scene &, const char *, const Standard_Size, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nVec"), py::arg("arrVec"));
	cls_VrmlData_ArrayVec3d.def("Length", (Standard_Size (VrmlData_ArrayVec3d::*)() const ) &VrmlData_ArrayVec3d::Length, "Query the number of vectors");
	cls_VrmlData_ArrayVec3d.def("Values", (const gp_XYZ * (VrmlData_ArrayVec3d::*)() const ) &VrmlData_ArrayVec3d::Values, "Query the array");
	cls_VrmlData_ArrayVec3d.def("AllocateValues", (Standard_Boolean (VrmlData_ArrayVec3d::*)(const Standard_Size)) &VrmlData_ArrayVec3d::AllocateValues, "Create a data array and assign the field myArray.", py::arg("theLength"));
	cls_VrmlData_ArrayVec3d.def("SetValues", (void (VrmlData_ArrayVec3d::*)(const Standard_Size, const gp_XYZ *)) &VrmlData_ArrayVec3d::SetValues, "Set the array data", py::arg("nValues"), py::arg("arrValues"));
	cls_VrmlData_ArrayVec3d.def("ReadArray", (VrmlData_ErrorStatus (VrmlData_ArrayVec3d::*)(VrmlData_InBuffer &, const char *, const Standard_Boolean)) &VrmlData_ArrayVec3d::ReadArray, "Read the Node from input stream.", py::arg("theBuffer"), py::arg("theName"), py::arg("isScale"));
	cls_VrmlData_ArrayVec3d.def("WriteArray", (VrmlData_ErrorStatus (VrmlData_ArrayVec3d::*)(const char *, const Standard_Boolean) const ) &VrmlData_ArrayVec3d::WriteArray, "Write the Node to the output stream currently opened in Scene.", py::arg("theName"), py::arg("isScale"));
	cls_VrmlData_ArrayVec3d.def("IsDefault", (Standard_Boolean (VrmlData_ArrayVec3d::*)() const ) &VrmlData_ArrayVec3d::IsDefault, "Returns True if the node is default, so that it should not be written.");
	cls_VrmlData_ArrayVec3d.def_static("get_type_name_", (const char * (*)()) &VrmlData_ArrayVec3d::get_type_name, "None");
	cls_VrmlData_ArrayVec3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_ArrayVec3d::get_type_descriptor, "None");
	cls_VrmlData_ArrayVec3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_ArrayVec3d::*)() const ) &VrmlData_ArrayVec3d::DynamicType, "None");

	// Callback for VrmlData_Geometry.
	class PyCallback_VrmlData_Geometry : public VrmlData_Geometry {
	public:
		using VrmlData_Geometry::VrmlData_Geometry;

		VrmlData_ErrorStatus Read(VrmlData_InBuffer & theBuffer) override { PYBIND11_OVERLOAD_PURE(VrmlData_ErrorStatus, VrmlData_Geometry, Read, theBuffer); }
		const opencascade::handle<TopoDS_TShape> & TShape() override { PYBIND11_OVERLOAD_PURE(const opencascade::handle<TopoDS_TShape> &, VrmlData_Geometry, TShape, ); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Geometry.hxx
	py::class_<VrmlData_Geometry, opencascade::handle<VrmlData_Geometry>, PyCallback_VrmlData_Geometry, VrmlData_Node> cls_VrmlData_Geometry(mod, "VrmlData_Geometry", "Implementation of the Geometry node. Contains the topological representation (TopoDS_Shell) of the VRML geometry");
	cls_VrmlData_Geometry.def(py::init<>());
	cls_VrmlData_Geometry.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Geometry.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Geometry::*)()) &VrmlData_Geometry::TShape, "Query the shape. This method checks the flag myIsModified; if True it should rebuild the shape presentation.");
	cls_VrmlData_Geometry.def_static("get_type_name_", (const char * (*)()) &VrmlData_Geometry::get_type_name, "None");
	cls_VrmlData_Geometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Geometry::get_type_descriptor, "None");
	cls_VrmlData_Geometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Geometry::*)() const ) &VrmlData_Geometry::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Box.hxx
	py::class_<VrmlData_Box, opencascade::handle<VrmlData_Box>, VrmlData_Geometry> cls_VrmlData_Box(mod, "VrmlData_Box", "Inplementation of the Box node. This node is defined by Size vector, assumong that the box center is located in (0., 0., 0.) and that each corner is 0.5*|Size| distance from the center.");
	cls_VrmlData_Box.def(py::init<>());
	cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("sizeX"));
	cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("sizeX"), py::arg("sizeY"));
	cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("sizeX"), py::arg("sizeY"), py::arg("sizeZ"));
	cls_VrmlData_Box.def("Size", (const gp_XYZ & (VrmlData_Box::*)() const ) &VrmlData_Box::Size, "Query the Box size");
	cls_VrmlData_Box.def("SetSize", (void (VrmlData_Box::*)(const gp_XYZ &)) &VrmlData_Box::SetSize, "Set the Box Size", py::arg("theSize"));
	cls_VrmlData_Box.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Box::*)()) &VrmlData_Box::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
	cls_VrmlData_Box.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Box::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Box::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Box.def("Read", (VrmlData_ErrorStatus (VrmlData_Box::*)(VrmlData_InBuffer &)) &VrmlData_Box::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
	cls_VrmlData_Box.def("Write", (VrmlData_ErrorStatus (VrmlData_Box::*)(const char *) const ) &VrmlData_Box::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_Box.def_static("get_type_name_", (const char * (*)()) &VrmlData_Box::get_type_name, "None");
	cls_VrmlData_Box.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Box::get_type_descriptor, "None");
	cls_VrmlData_Box.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Box::*)() const ) &VrmlData_Box::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Color.hxx
	py::class_<VrmlData_Color, opencascade::handle<VrmlData_Color>, VrmlData_ArrayVec3d> cls_VrmlData_Color(mod, "VrmlData_Color", "Implementation of the node Color");
	cls_VrmlData_Color.def(py::init<>());
	cls_VrmlData_Color.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Color.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nColors"));
	cls_VrmlData_Color.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nColors"), py::arg("arrColors"));
	cls_VrmlData_Color.def("Color", (const Quantity_Color (VrmlData_Color::*)(const Standard_Integer) const ) &VrmlData_Color::Color, "Query one color", py::arg("i"));
	cls_VrmlData_Color.def("SetColors", (void (VrmlData_Color::*)(const size_t, const gp_XYZ *)) &VrmlData_Color::SetColors, "Set the array data", py::arg("nColors"), py::arg("arrColors"));
	cls_VrmlData_Color.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Color::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Color::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Color.def("Read", (VrmlData_ErrorStatus (VrmlData_Color::*)(VrmlData_InBuffer &)) &VrmlData_Color::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_Color.def("Write", (VrmlData_ErrorStatus (VrmlData_Color::*)(const char *) const ) &VrmlData_Color::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
	cls_VrmlData_Color.def_static("get_type_name_", (const char * (*)()) &VrmlData_Color::get_type_name, "None");
	cls_VrmlData_Color.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Color::get_type_descriptor, "None");
	cls_VrmlData_Color.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Color::*)() const ) &VrmlData_Color::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Cone.hxx
	py::class_<VrmlData_Cone, opencascade::handle<VrmlData_Cone>, VrmlData_Geometry> cls_VrmlData_Cone(mod, "VrmlData_Cone", "Implementation of the Cone node. The cone is located with its middle of the height segment in (0., 0., 0.) The height is oriented along OY.");
	cls_VrmlData_Cone.def(py::init<>());
	cls_VrmlData_Cone.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Cone.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theBottomRadius"));
	cls_VrmlData_Cone.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theBottomRadius"), py::arg("theHeight"));
	cls_VrmlData_Cone.def("BottomRadius", (Standard_Real (VrmlData_Cone::*)() const ) &VrmlData_Cone::BottomRadius, "Query the Bottom Radius");
	cls_VrmlData_Cone.def("Height", (Standard_Real (VrmlData_Cone::*)() const ) &VrmlData_Cone::Height, "Query the Height");
	cls_VrmlData_Cone.def("HasBottom", (Standard_Boolean (VrmlData_Cone::*)() const ) &VrmlData_Cone::HasBottom, "Query if the bottom circle is included");
	cls_VrmlData_Cone.def("HasSide", (Standard_Boolean (VrmlData_Cone::*)() const ) &VrmlData_Cone::HasSide, "Query if the side surface is included");
	cls_VrmlData_Cone.def("SetBottomRadius", (void (VrmlData_Cone::*)(const Standard_Real)) &VrmlData_Cone::SetBottomRadius, "Set the Bottom Radius", py::arg("theRadius"));
	cls_VrmlData_Cone.def("SetHeight", (void (VrmlData_Cone::*)(const Standard_Real)) &VrmlData_Cone::SetHeight, "Set the Height", py::arg("theHeight"));
	cls_VrmlData_Cone.def("SetFaces", (void (VrmlData_Cone::*)(const Standard_Boolean, const Standard_Boolean)) &VrmlData_Cone::SetFaces, "Set which faces are included", py::arg("hasBottom"), py::arg("hasSide"));
	cls_VrmlData_Cone.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Cone::*)()) &VrmlData_Cone::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
	cls_VrmlData_Cone.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Cone::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Cone::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Cone.def("Read", (VrmlData_ErrorStatus (VrmlData_Cone::*)(VrmlData_InBuffer &)) &VrmlData_Cone::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
	cls_VrmlData_Cone.def("Write", (VrmlData_ErrorStatus (VrmlData_Cone::*)(const char *) const ) &VrmlData_Cone::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_Cone.def_static("get_type_name_", (const char * (*)()) &VrmlData_Cone::get_type_name, "None");
	cls_VrmlData_Cone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Cone::get_type_descriptor, "None");
	cls_VrmlData_Cone.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Cone::*)() const ) &VrmlData_Cone::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Coordinate.hxx
	py::class_<VrmlData_Coordinate, opencascade::handle<VrmlData_Coordinate>, VrmlData_ArrayVec3d> cls_VrmlData_Coordinate(mod, "VrmlData_Coordinate", "Implementation of the node Coordinate");
	cls_VrmlData_Coordinate.def(py::init<>());
	cls_VrmlData_Coordinate.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Coordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"));
	cls_VrmlData_Coordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"), py::arg("arrPoints"));
	cls_VrmlData_Coordinate.def("Coordinate", (const gp_XYZ & (VrmlData_Coordinate::*)(const Standard_Integer) const ) &VrmlData_Coordinate::Coordinate, "Query one point", py::arg("i"));
	cls_VrmlData_Coordinate.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Coordinate::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Coordinate::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Coordinate.def("Read", (VrmlData_ErrorStatus (VrmlData_Coordinate::*)(VrmlData_InBuffer &)) &VrmlData_Coordinate::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_Coordinate.def("Write", (VrmlData_ErrorStatus (VrmlData_Coordinate::*)(const char *) const ) &VrmlData_Coordinate::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
	cls_VrmlData_Coordinate.def_static("get_type_name_", (const char * (*)()) &VrmlData_Coordinate::get_type_name, "None");
	cls_VrmlData_Coordinate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Coordinate::get_type_descriptor, "None");
	cls_VrmlData_Coordinate.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Coordinate::*)() const ) &VrmlData_Coordinate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Cylinder.hxx
	py::class_<VrmlData_Cylinder, opencascade::handle<VrmlData_Cylinder>, VrmlData_Geometry> cls_VrmlData_Cylinder(mod, "VrmlData_Cylinder", "Implementation of the Cylinder node");
	cls_VrmlData_Cylinder.def(py::init<>());
	cls_VrmlData_Cylinder.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Cylinder.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theRadius"));
	cls_VrmlData_Cylinder.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theRadius"), py::arg("theHeight"));
	cls_VrmlData_Cylinder.def("Radius", (Standard_Real (VrmlData_Cylinder::*)() const ) &VrmlData_Cylinder::Radius, "Query the Radius");
	cls_VrmlData_Cylinder.def("Height", (Standard_Real (VrmlData_Cylinder::*)() const ) &VrmlData_Cylinder::Height, "Query the Height");
	cls_VrmlData_Cylinder.def("HasBottom", (Standard_Boolean (VrmlData_Cylinder::*)() const ) &VrmlData_Cylinder::HasBottom, "Query if the bottom circle is included");
	cls_VrmlData_Cylinder.def("HasSide", (Standard_Boolean (VrmlData_Cylinder::*)() const ) &VrmlData_Cylinder::HasSide, "Query if the side surface is included");
	cls_VrmlData_Cylinder.def("HasTop", (Standard_Boolean (VrmlData_Cylinder::*)() const ) &VrmlData_Cylinder::HasTop, "Query if the top surface is included");
	cls_VrmlData_Cylinder.def("SetRadius", (void (VrmlData_Cylinder::*)(const Standard_Real)) &VrmlData_Cylinder::SetRadius, "Set the Radius", py::arg("theRadius"));
	cls_VrmlData_Cylinder.def("SetHeight", (void (VrmlData_Cylinder::*)(const Standard_Real)) &VrmlData_Cylinder::SetHeight, "Set the Height", py::arg("theHeight"));
	cls_VrmlData_Cylinder.def("SetFaces", (void (VrmlData_Cylinder::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &VrmlData_Cylinder::SetFaces, "Set which faces are included", py::arg("hasBottom"), py::arg("hasSide"), py::arg("hasTop"));
	cls_VrmlData_Cylinder.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Cylinder::*)()) &VrmlData_Cylinder::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
	cls_VrmlData_Cylinder.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Cylinder::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Cylinder::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Cylinder.def("Read", (VrmlData_ErrorStatus (VrmlData_Cylinder::*)(VrmlData_InBuffer &)) &VrmlData_Cylinder::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
	cls_VrmlData_Cylinder.def("Write", (VrmlData_ErrorStatus (VrmlData_Cylinder::*)(const char *) const ) &VrmlData_Cylinder::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_Cylinder.def_static("get_type_name_", (const char * (*)()) &VrmlData_Cylinder::get_type_name, "None");
	cls_VrmlData_Cylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Cylinder::get_type_descriptor, "None");
	cls_VrmlData_Cylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Cylinder::*)() const ) &VrmlData_Cylinder::DynamicType, "None");

	// Callback for VrmlData_Faceted.
	class PyCallback_VrmlData_Faceted : public VrmlData_Faceted {
	public:
		using VrmlData_Faceted::VrmlData_Faceted;

		const opencascade::handle<TopoDS_TShape> & TShape() override { PYBIND11_OVERLOAD_PURE(const opencascade::handle<TopoDS_TShape> &, VrmlData_Faceted, TShape, ); }
		VrmlData_ErrorStatus Read(VrmlData_InBuffer & theBuffer) override { PYBIND11_OVERLOAD_PURE(VrmlData_ErrorStatus, VrmlData_Faceted, Read, theBuffer); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Faceted.hxx
	py::class_<VrmlData_Faceted, opencascade::handle<VrmlData_Faceted>, PyCallback_VrmlData_Faceted, VrmlData_Geometry> cls_VrmlData_Faceted(mod, "VrmlData_Faceted", "Common API of faceted Geometry nodes: IndexedFaceSet, ElevationGrid, Extrusion.");
	cls_VrmlData_Faceted.def(py::init<>());
	cls_VrmlData_Faceted.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"), py::arg("isConvex"), py::arg("theCreaseAngle"));
	cls_VrmlData_Faceted.def("IsCCW", (Standard_Boolean (VrmlData_Faceted::*)() const ) &VrmlData_Faceted::IsCCW, "Query 'Is Counter-Clockwise' attribute");
	cls_VrmlData_Faceted.def("IsSolid", (Standard_Boolean (VrmlData_Faceted::*)() const ) &VrmlData_Faceted::IsSolid, "Query 'Is Solid' attribute");
	cls_VrmlData_Faceted.def("IsConvex", (Standard_Boolean (VrmlData_Faceted::*)() const ) &VrmlData_Faceted::IsConvex, "Query 'Is Convex' attribute");
	cls_VrmlData_Faceted.def("CreaseAngle", (Standard_Real (VrmlData_Faceted::*)() const ) &VrmlData_Faceted::CreaseAngle, "Query the Crease Angle");
	cls_VrmlData_Faceted.def("SetCCW", (void (VrmlData_Faceted::*)(const Standard_Boolean)) &VrmlData_Faceted::SetCCW, "Set 'Is Counter-Clockwise' attribute", py::arg("theValue"));
	cls_VrmlData_Faceted.def("SetSolid", (void (VrmlData_Faceted::*)(const Standard_Boolean)) &VrmlData_Faceted::SetSolid, "Set 'Is Solid' attribute", py::arg("theValue"));
	cls_VrmlData_Faceted.def("SetConvex", (void (VrmlData_Faceted::*)(const Standard_Boolean)) &VrmlData_Faceted::SetConvex, "Set 'Is Convex' attribute", py::arg("theValue"));
	cls_VrmlData_Faceted.def("SetCreaseAngle", (void (VrmlData_Faceted::*)(const Standard_Real)) &VrmlData_Faceted::SetCreaseAngle, "Set 'Is Convex' attribute", py::arg("theValue"));
	cls_VrmlData_Faceted.def_static("get_type_name_", (const char * (*)()) &VrmlData_Faceted::get_type_name, "None");
	cls_VrmlData_Faceted.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Faceted::get_type_descriptor, "None");
	cls_VrmlData_Faceted.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Faceted::*)() const ) &VrmlData_Faceted::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Group.hxx
	py::class_<VrmlData_Group, opencascade::handle<VrmlData_Group>, VrmlData_Node> cls_VrmlData_Group(mod, "VrmlData_Group", "Implementation of node 'Group'");
	cls_VrmlData_Group.def(py::init<>());
	cls_VrmlData_Group.def(py::init<const Standard_Boolean>(), py::arg("isTransform"));
	cls_VrmlData_Group.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Group.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isTransform"));
	cls_VrmlData_Group.def("AddNode", (opencascade::handle<VrmlData_Node> & (VrmlData_Group::*)(const opencascade::handle<VrmlData_Node> &)) &VrmlData_Group::AddNode, "Add one node to the Group.", py::arg("theNode"));
	cls_VrmlData_Group.def("RemoveNode", (Standard_Boolean (VrmlData_Group::*)(const opencascade::handle<VrmlData_Node> &)) &VrmlData_Group::RemoveNode, "Remove one node from the Group.", py::arg("theNode"));
	cls_VrmlData_Group.def("NodeIterator", (VrmlData_Group::Iterator (VrmlData_Group::*)() const ) &VrmlData_Group::NodeIterator, "Create iterator on nodes belonging to the Group.");
	cls_VrmlData_Group.def("Box", (const Bnd_B3f & (VrmlData_Group::*)() const ) &VrmlData_Group::Box, "Query the bounding box.");
	cls_VrmlData_Group.def("SetBox", (void (VrmlData_Group::*)(const Bnd_B3f &)) &VrmlData_Group::SetBox, "Set the bounding box.", py::arg("theBox"));
	cls_VrmlData_Group.def("SetTransform", (Standard_Boolean (VrmlData_Group::*)(const gp_Trsf &)) &VrmlData_Group::SetTransform, "Set the transformation. Returns True if the group is Transform type, otherwise do nothing and return False.", py::arg("theTrsf"));
	cls_VrmlData_Group.def("GetTransform", (const gp_Trsf & (VrmlData_Group::*)() const ) &VrmlData_Group::GetTransform, "Query the transform value. For group without transformation this always returns Identity");
	cls_VrmlData_Group.def("IsTransform", (Standard_Boolean (VrmlData_Group::*)() const ) &VrmlData_Group::IsTransform, "Query if the node is Transform type.");
	cls_VrmlData_Group.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Group::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Group::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Group.def("Read", (VrmlData_ErrorStatus (VrmlData_Group::*)(VrmlData_InBuffer &)) &VrmlData_Group::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
	cls_VrmlData_Group.def("Write", (VrmlData_ErrorStatus (VrmlData_Group::*)(const char *) const ) &VrmlData_Group::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_Group.def("FindNode", (opencascade::handle<VrmlData_Node> (VrmlData_Group::*)(const char *, gp_Trsf &) const ) &VrmlData_Group::FindNode, "Find a node by its name, inside this Group", py::arg("theName"), py::arg("theLocation"));
	cls_VrmlData_Group.def("Shape", (void (VrmlData_Group::*)(TopoDS_Shape &, VrmlData_DataMapOfShapeAppearance *)) &VrmlData_Group::Shape, "Get the shape representing the group geometry.", py::arg("theShape"), py::arg("pMapApp"));
	cls_VrmlData_Group.def_static("get_type_name_", (const char * (*)()) &VrmlData_Group::get_type_name, "None");
	cls_VrmlData_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Group::get_type_descriptor, "None");
	cls_VrmlData_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Group::*)() const ) &VrmlData_Group::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_ImageTexture.hxx
	py::class_<VrmlData_ImageTexture, opencascade::handle<VrmlData_ImageTexture>, VrmlData_Texture> cls_VrmlData_ImageTexture(mod, "VrmlData_ImageTexture", "Implementation of the ImageTexture node");
	cls_VrmlData_ImageTexture.def(py::init<>());
	cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *, const char *>(), py::arg("theScene"), py::arg("theName"), py::arg("theURL"));
	cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("theURL"), py::arg("theRepS"));
	cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *, const char *, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("theURL"), py::arg("theRepS"), py::arg("theRepT"));
	cls_VrmlData_ImageTexture.def("URL", (const NCollection_List<TCollection_AsciiString> & (VrmlData_ImageTexture::*)() const ) &VrmlData_ImageTexture::URL, "Query the associated URL.");
	cls_VrmlData_ImageTexture.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_ImageTexture::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_ImageTexture::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_ImageTexture.def("Read", (VrmlData_ErrorStatus (VrmlData_ImageTexture::*)(VrmlData_InBuffer &)) &VrmlData_ImageTexture::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_ImageTexture.def("Write", (VrmlData_ErrorStatus (VrmlData_ImageTexture::*)(const char *) const ) &VrmlData_ImageTexture::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_ImageTexture.def_static("get_type_name_", (const char * (*)()) &VrmlData_ImageTexture::get_type_name, "None");
	cls_VrmlData_ImageTexture.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_ImageTexture::get_type_descriptor, "None");
	cls_VrmlData_ImageTexture.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_ImageTexture::*)() const ) &VrmlData_ImageTexture::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Normal.hxx
	py::class_<VrmlData_Normal, opencascade::handle<VrmlData_Normal>, VrmlData_ArrayVec3d> cls_VrmlData_Normal(mod, "VrmlData_Normal", "Implementation of the node Normal");
	cls_VrmlData_Normal.def(py::init<>());
	cls_VrmlData_Normal.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Normal.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nVec"));
	cls_VrmlData_Normal.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nVec"), py::arg("arrVec"));
	cls_VrmlData_Normal.def("Normal", (const gp_XYZ & (VrmlData_Normal::*)(const Standard_Integer) const ) &VrmlData_Normal::Normal, "Query one normal", py::arg("i"));
	cls_VrmlData_Normal.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Normal::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Normal::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Normal.def("Read", (VrmlData_ErrorStatus (VrmlData_Normal::*)(VrmlData_InBuffer &)) &VrmlData_Normal::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_Normal.def("Write", (VrmlData_ErrorStatus (VrmlData_Normal::*)(const char *) const ) &VrmlData_Normal::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
	cls_VrmlData_Normal.def_static("get_type_name_", (const char * (*)()) &VrmlData_Normal::get_type_name, "None");
	cls_VrmlData_Normal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Normal::get_type_descriptor, "None");
	cls_VrmlData_Normal.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Normal::*)() const ) &VrmlData_Normal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_TextureCoordinate.hxx
	py::class_<VrmlData_TextureCoordinate, opencascade::handle<VrmlData_TextureCoordinate>, VrmlData_Node> cls_VrmlData_TextureCoordinate(mod, "VrmlData_TextureCoordinate", "Implementation of the node TextureCoordinate");
	cls_VrmlData_TextureCoordinate.def(py::init<>());
	cls_VrmlData_TextureCoordinate.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_TextureCoordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"));
	cls_VrmlData_TextureCoordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XY *>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"), py::arg("arrPoints"));
	cls_VrmlData_TextureCoordinate.def("AllocateValues", (Standard_Boolean (VrmlData_TextureCoordinate::*)(const Standard_Size)) &VrmlData_TextureCoordinate::AllocateValues, "Create a data array and assign the field myArray.", py::arg("theLength"));
	cls_VrmlData_TextureCoordinate.def("Length", (size_t (VrmlData_TextureCoordinate::*)()) &VrmlData_TextureCoordinate::Length, "Query the number of points");
	cls_VrmlData_TextureCoordinate.def("Points", (const gp_XY * (VrmlData_TextureCoordinate::*)()) &VrmlData_TextureCoordinate::Points, "Query the points");
	cls_VrmlData_TextureCoordinate.def("SetPoints", (void (VrmlData_TextureCoordinate::*)(const size_t, const gp_XY *)) &VrmlData_TextureCoordinate::SetPoints, "Set the points array", py::arg("nPoints"), py::arg("arrPoints"));
	cls_VrmlData_TextureCoordinate.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_TextureCoordinate::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_TextureCoordinate::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_TextureCoordinate.def("Read", (VrmlData_ErrorStatus (VrmlData_TextureCoordinate::*)(VrmlData_InBuffer &)) &VrmlData_TextureCoordinate::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_TextureCoordinate.def_static("get_type_name_", (const char * (*)()) &VrmlData_TextureCoordinate::get_type_name, "None");
	cls_VrmlData_TextureCoordinate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_TextureCoordinate::get_type_descriptor, "None");
	cls_VrmlData_TextureCoordinate.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_TextureCoordinate::*)() const ) &VrmlData_TextureCoordinate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_IndexedFaceSet.hxx
	py::class_<VrmlData_IndexedFaceSet, opencascade::handle<VrmlData_IndexedFaceSet>, VrmlData_Faceted> cls_VrmlData_IndexedFaceSet(mod, "VrmlData_IndexedFaceSet", "Implementation of IndexedFaceSet node");
	cls_VrmlData_IndexedFaceSet.def(py::init<>());
	cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"));
	cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"));
	cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"), py::arg("isConvex"));
	cls_VrmlData_IndexedFaceSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("isCCW"), py::arg("isSolid"), py::arg("isConvex"), py::arg("theCreaseAngle"));
	cls_VrmlData_IndexedFaceSet.def("Normals", (const opencascade::handle<VrmlData_Normal> & (VrmlData_IndexedFaceSet::*)() const ) &VrmlData_IndexedFaceSet::Normals, "Query the Normals.");
	cls_VrmlData_IndexedFaceSet.def("Colors", (const opencascade::handle<VrmlData_Color> & (VrmlData_IndexedFaceSet::*)() const ) &VrmlData_IndexedFaceSet::Colors, "Query the Colors.");
	cls_VrmlData_IndexedFaceSet.def("TextureCoords", (const opencascade::handle<VrmlData_TextureCoordinate> & (VrmlData_IndexedFaceSet::*)() const ) &VrmlData_IndexedFaceSet::TextureCoords, "Query the Texture Coordinates.");
	cls_VrmlData_IndexedFaceSet.def("Coordinates", (const opencascade::handle<VrmlData_Coordinate> & (VrmlData_IndexedFaceSet::*)() const ) &VrmlData_IndexedFaceSet::Coordinates, "Query the Coordinates.");
	// FIXME cls_VrmlData_IndexedFaceSet.def("Polygons", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const ) &VrmlData_IndexedFaceSet::Polygons, "Query the array of polygons", py::arg("arrPolygons"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("Polygon", (Standard_Integer (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer *&)) &VrmlData_IndexedFaceSet::Polygon, "Query one polygon.", py::arg("iFace"), py::arg("outIndice"));
	cls_VrmlData_IndexedFaceSet.def("SetCoordinates", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Coordinate> &)) &VrmlData_IndexedFaceSet::SetCoordinates, "Set the nodes", py::arg("theCoord"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("SetPolygons", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetPolygons, "Set the polygons", py::arg("nPolygons"), py::arg("thePolygons"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("ArrayNormalInd", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const ) &VrmlData_IndexedFaceSet::ArrayNormalInd, "Query the array of normal indice", py::arg("arrNormalInd"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("IndiceNormals", (Standard_Integer (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer *&)) &VrmlData_IndexedFaceSet::IndiceNormals, "Query normals indice for one face. This method should be called after checking myArrNormalInd != NULL, otherwise exception will be thrown.", py::arg("iFace"), py::arg("outIndice"));
	cls_VrmlData_IndexedFaceSet.def("GetNormal", (gp_XYZ (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer)) &VrmlData_IndexedFaceSet::GetNormal, "Query a normal for one node in the given element. The normal is interpreted according to fields myNormals, myArrNormalInd, myNormalPerVertex, as defined in VRML 2.0.", py::arg("iFace"), py::arg("iVertex"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("SetNormalInd", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetNormalInd, "Set the normals array of indice", py::arg("nIndice"), py::arg("theIndice"));
	cls_VrmlData_IndexedFaceSet.def("SetNormals", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Normal> &)) &VrmlData_IndexedFaceSet::SetNormals, "Set the normals node", py::arg("theNormals"));
	cls_VrmlData_IndexedFaceSet.def("SetNormalPerVertex", (void (VrmlData_IndexedFaceSet::*)(const Standard_Boolean)) &VrmlData_IndexedFaceSet::SetNormalPerVertex, "Set the boolean value 'normalPerVertex'", py::arg("isNormalPerVertex"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("ArrayColorInd", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const ) &VrmlData_IndexedFaceSet::ArrayColorInd, "Query the array of color indice", py::arg("arrColorInd"));
	cls_VrmlData_IndexedFaceSet.def("GetColor", (Quantity_Color (VrmlData_IndexedFaceSet::*)(const Standard_Integer, const Standard_Integer)) &VrmlData_IndexedFaceSet::GetColor, "Query a color for one node in the given element. The color is interpreted according to fields myColors, myArrColorInd, myColorPerVertex, as defined in VRML 2.0.", py::arg("iFace"), py::arg("iVertex"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("SetColorInd", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetColorInd, "Set the colors array of indice", py::arg("nIndice"), py::arg("theIndice"));
	cls_VrmlData_IndexedFaceSet.def("SetColors", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Color> &)) &VrmlData_IndexedFaceSet::SetColors, "Set the Color node", py::arg("theColors"));
	cls_VrmlData_IndexedFaceSet.def("SetColorPerVertex", (void (VrmlData_IndexedFaceSet::*)(const Standard_Boolean)) &VrmlData_IndexedFaceSet::SetColorPerVertex, "Set the boolean value 'colorPerVertex'", py::arg("isColorPerVertex"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("ArrayTextureCoordInd", (size_t (VrmlData_IndexedFaceSet::*)(const Standard_Integer **&) const ) &VrmlData_IndexedFaceSet::ArrayTextureCoordInd, "Query the array of texture coordinate indice", py::arg("arrTextureCoordInd"));
	// FIXME cls_VrmlData_IndexedFaceSet.def("SetTextureCoordInd", (void (VrmlData_IndexedFaceSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedFaceSet::SetTextureCoordInd, "Set the TexCoordiante array of indice", py::arg("nIndice"), py::arg("theIndice"));
	cls_VrmlData_IndexedFaceSet.def("SetTextureCoords", (void (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_TextureCoordinate> &)) &VrmlData_IndexedFaceSet::SetTextureCoords, "Set the Texture Coordinate node", py::arg("tc"));
	cls_VrmlData_IndexedFaceSet.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_IndexedFaceSet::*)()) &VrmlData_IndexedFaceSet::TShape, "Query the shape. This method checks the flag myIsModified; if True it should rebuild the shape presentation.");
	cls_VrmlData_IndexedFaceSet.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_IndexedFaceSet::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_IndexedFaceSet::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_IndexedFaceSet.def("Read", (VrmlData_ErrorStatus (VrmlData_IndexedFaceSet::*)(VrmlData_InBuffer &)) &VrmlData_IndexedFaceSet::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_IndexedFaceSet.def("Write", (VrmlData_ErrorStatus (VrmlData_IndexedFaceSet::*)(const char *) const ) &VrmlData_IndexedFaceSet::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_IndexedFaceSet.def("IsDefault", (Standard_Boolean (VrmlData_IndexedFaceSet::*)() const ) &VrmlData_IndexedFaceSet::IsDefault, "Returns True if the node is default, so that it should not be written.");
	cls_VrmlData_IndexedFaceSet.def_static("get_type_name_", (const char * (*)()) &VrmlData_IndexedFaceSet::get_type_name, "None");
	cls_VrmlData_IndexedFaceSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_IndexedFaceSet::get_type_descriptor, "None");
	cls_VrmlData_IndexedFaceSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_IndexedFaceSet::*)() const ) &VrmlData_IndexedFaceSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_IndexedLineSet.hxx
	py::class_<VrmlData_IndexedLineSet, opencascade::handle<VrmlData_IndexedLineSet>, VrmlData_Geometry> cls_VrmlData_IndexedLineSet(mod, "VrmlData_IndexedLineSet", "Data type to store a set of polygons.");
	cls_VrmlData_IndexedLineSet.def(py::init<>());
	cls_VrmlData_IndexedLineSet.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_IndexedLineSet.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isColorPerVertex"));
	cls_VrmlData_IndexedLineSet.def("Coordinates", (const opencascade::handle<VrmlData_Coordinate> & (VrmlData_IndexedLineSet::*)() const ) &VrmlData_IndexedLineSet::Coordinates, "Query the Coordinates.");
	cls_VrmlData_IndexedLineSet.def("SetCoordinates", (void (VrmlData_IndexedLineSet::*)(const opencascade::handle<VrmlData_Coordinate> &)) &VrmlData_IndexedLineSet::SetCoordinates, "Set the nodes", py::arg("theCoord"));
	cls_VrmlData_IndexedLineSet.def("Colors", (const opencascade::handle<VrmlData_Color> & (VrmlData_IndexedLineSet::*)() const ) &VrmlData_IndexedLineSet::Colors, "Query the Colors.");
	cls_VrmlData_IndexedLineSet.def("SetColors", (void (VrmlData_IndexedLineSet::*)(const opencascade::handle<VrmlData_Color> &)) &VrmlData_IndexedLineSet::SetColors, "Set the Color node", py::arg("theColors"));
	// FIXME cls_VrmlData_IndexedLineSet.def("Polygons", (size_t (VrmlData_IndexedLineSet::*)(const Standard_Integer **&) const ) &VrmlData_IndexedLineSet::Polygons, "Query the array of polygons", py::arg("arrPolygons"));
	// FIXME cls_VrmlData_IndexedLineSet.def("Polygon", (Standard_Integer (VrmlData_IndexedLineSet::*)(const Standard_Integer, const Standard_Integer *&)) &VrmlData_IndexedLineSet::Polygon, "Query one polygon.", py::arg("iPolygon"), py::arg("outIndice"));
	// FIXME cls_VrmlData_IndexedLineSet.def("SetPolygons", (void (VrmlData_IndexedLineSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedLineSet::SetPolygons, "Set the polygons", py::arg("nPolygons"), py::arg("thePolygons"));
	// FIXME cls_VrmlData_IndexedLineSet.def("ArrayColorInd", (size_t (VrmlData_IndexedLineSet::*)(const Standard_Integer **&) const ) &VrmlData_IndexedLineSet::ArrayColorInd, "Query the array of color indice", py::arg("arrColorInd"));
	cls_VrmlData_IndexedLineSet.def("GetColor", (Quantity_Color (VrmlData_IndexedLineSet::*)(const Standard_Integer, const Standard_Integer)) &VrmlData_IndexedLineSet::GetColor, "Query a color for one node in the given element. The color is interpreted according to fields myColors, myArrColorInd, myColorPerVertex, as defined in VRML 2.0.", py::arg("iFace"), py::arg("iVertex"));
	// FIXME cls_VrmlData_IndexedLineSet.def("SetColorInd", (void (VrmlData_IndexedLineSet::*)(const Standard_Size, const Standard_Integer **)) &VrmlData_IndexedLineSet::SetColorInd, "Set the colors array of indice", py::arg("nIndice"), py::arg("theIndice"));
	cls_VrmlData_IndexedLineSet.def("SetColorPerVertex", (void (VrmlData_IndexedLineSet::*)(const Standard_Boolean)) &VrmlData_IndexedLineSet::SetColorPerVertex, "Set the boolean value 'colorPerVertex'", py::arg("isColorPerVertex"));
	cls_VrmlData_IndexedLineSet.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_IndexedLineSet::*)()) &VrmlData_IndexedLineSet::TShape, "Query the shape. This method checks the flag myIsModified; if True it should rebuild the shape presentation.");
	cls_VrmlData_IndexedLineSet.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_IndexedLineSet::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_IndexedLineSet::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_IndexedLineSet.def("Read", (VrmlData_ErrorStatus (VrmlData_IndexedLineSet::*)(VrmlData_InBuffer &)) &VrmlData_IndexedLineSet::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_IndexedLineSet.def("Write", (VrmlData_ErrorStatus (VrmlData_IndexedLineSet::*)(const char *) const ) &VrmlData_IndexedLineSet::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_IndexedLineSet.def("IsDefault", (Standard_Boolean (VrmlData_IndexedLineSet::*)() const ) &VrmlData_IndexedLineSet::IsDefault, "Returns True if the node is default, so that it should not be written.");
	cls_VrmlData_IndexedLineSet.def_static("get_type_name_", (const char * (*)()) &VrmlData_IndexedLineSet::get_type_name, "None");
	cls_VrmlData_IndexedLineSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_IndexedLineSet::get_type_descriptor, "None");
	cls_VrmlData_IndexedLineSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_IndexedLineSet::*)() const ) &VrmlData_IndexedLineSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_WorldInfo.hxx
	py::class_<VrmlData_WorldInfo, opencascade::handle<VrmlData_WorldInfo>, VrmlData_Node> cls_VrmlData_WorldInfo(mod, "VrmlData_WorldInfo", "Data type for WorldInfo node");
	cls_VrmlData_WorldInfo.def(py::init<>());
	cls_VrmlData_WorldInfo.def(py::init<const VrmlData_Scene &>(), py::arg("theScene"));
	cls_VrmlData_WorldInfo.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_WorldInfo.def(py::init<const VrmlData_Scene &, const char *, const char *>(), py::arg("theScene"), py::arg("theName"), py::arg("theTitle"));
	cls_VrmlData_WorldInfo.def("SetTitle", (void (VrmlData_WorldInfo::*)(const char *)) &VrmlData_WorldInfo::SetTitle, "Set or modify the title.", py::arg("theString"));
	cls_VrmlData_WorldInfo.def("AddInfo", (void (VrmlData_WorldInfo::*)(const char *)) &VrmlData_WorldInfo::AddInfo, "Add a string to the list of info strings.", py::arg("theString"));
	cls_VrmlData_WorldInfo.def("Title", (const char * (VrmlData_WorldInfo::*)() const ) &VrmlData_WorldInfo::Title, "Query the title string.");
	cls_VrmlData_WorldInfo.def("InfoIterator", (NCollection_List<const char *>::Iterator (VrmlData_WorldInfo::*)() const ) &VrmlData_WorldInfo::InfoIterator, "Return the iterator of Info strings.");
	cls_VrmlData_WorldInfo.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_WorldInfo::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_WorldInfo::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_WorldInfo.def("Read", (VrmlData_ErrorStatus (VrmlData_WorldInfo::*)(VrmlData_InBuffer &)) &VrmlData_WorldInfo::Read, "Read the Node from input stream.", py::arg("theBuffer"));
	cls_VrmlData_WorldInfo.def("Write", (VrmlData_ErrorStatus (VrmlData_WorldInfo::*)(const char *) const ) &VrmlData_WorldInfo::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
	cls_VrmlData_WorldInfo.def("IsDefault", (Standard_Boolean (VrmlData_WorldInfo::*)() const ) &VrmlData_WorldInfo::IsDefault, "Returns True if the node is default, then it would not be written.");
	cls_VrmlData_WorldInfo.def_static("get_type_name_", (const char * (*)()) &VrmlData_WorldInfo::get_type_name, "None");
	cls_VrmlData_WorldInfo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_WorldInfo::get_type_descriptor, "None");
	cls_VrmlData_WorldInfo.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_WorldInfo::*)() const ) &VrmlData_WorldInfo::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_ShapeConvert.hxx
	py::class_<VrmlData_ShapeConvert, std::unique_ptr<VrmlData_ShapeConvert, Deleter<VrmlData_ShapeConvert>>> cls_VrmlData_ShapeConvert(mod, "VrmlData_ShapeConvert", "Algorithm converting one shape or a set of shapes to VrmlData_Scene.");
	cls_VrmlData_ShapeConvert.def(py::init<VrmlData_Scene &>(), py::arg("theScene"));
	cls_VrmlData_ShapeConvert.def(py::init<VrmlData_Scene &, const Standard_Real>(), py::arg("theScene"), py::arg("theScale"));
	cls_VrmlData_ShapeConvert.def("AddShape", [](VrmlData_ShapeConvert &self, const TopoDS_Shape & a0) -> void { return self.AddShape(a0); }, py::arg("theShape"));
	cls_VrmlData_ShapeConvert.def("AddShape", (void (VrmlData_ShapeConvert::*)(const TopoDS_Shape &, const char *)) &VrmlData_ShapeConvert::AddShape, "Add one shape to the internal list, may be called several times with different shapes.", py::arg("theShape"), py::arg("theName"));
	cls_VrmlData_ShapeConvert.def("Convert", [](VrmlData_ShapeConvert &self, const Standard_Boolean a0, const Standard_Boolean a1) -> void { return self.Convert(a0, a1); }, py::arg("theExtractFaces"), py::arg("theExtractEdges"));
	cls_VrmlData_ShapeConvert.def("Convert", [](VrmlData_ShapeConvert &self, const Standard_Boolean a0, const Standard_Boolean a1, const Standard_Real a2) -> void { return self.Convert(a0, a1, a2); }, py::arg("theExtractFaces"), py::arg("theExtractEdges"), py::arg("theDeflection"));
	cls_VrmlData_ShapeConvert.def("Convert", (void (VrmlData_ShapeConvert::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &VrmlData_ShapeConvert::Convert, "Convert all accumulated shapes and store them in myScene. The internal data structures are cleared in the end of convertion.", py::arg("theExtractFaces"), py::arg("theExtractEdges"), py::arg("theDeflection"), py::arg("theDeflAngle"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_ShapeNode.hxx
	py::class_<VrmlData_ShapeNode, opencascade::handle<VrmlData_ShapeNode>, VrmlData_Node> cls_VrmlData_ShapeNode(mod, "VrmlData_ShapeNode", "Implementation of the Shape node type");
	cls_VrmlData_ShapeNode.def(py::init<>());
	cls_VrmlData_ShapeNode.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_ShapeNode.def("Appearance", (const opencascade::handle<VrmlData_Appearance> & (VrmlData_ShapeNode::*)() const ) &VrmlData_ShapeNode::Appearance, "Query the Appearance.");
	cls_VrmlData_ShapeNode.def("Geometry", (const opencascade::handle<VrmlData_Geometry> & (VrmlData_ShapeNode::*)() const ) &VrmlData_ShapeNode::Geometry, "Query the Geometry.");
	cls_VrmlData_ShapeNode.def("SetAppearance", (void (VrmlData_ShapeNode::*)(const opencascade::handle<VrmlData_Appearance> &)) &VrmlData_ShapeNode::SetAppearance, "Set the Appearance", py::arg("theAppear"));
	cls_VrmlData_ShapeNode.def("SetGeometry", (void (VrmlData_ShapeNode::*)(const opencascade::handle<VrmlData_Geometry> &)) &VrmlData_ShapeNode::SetGeometry, "Set the Geometry", py::arg("theGeometry"));
	cls_VrmlData_ShapeNode.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_ShapeNode::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_ShapeNode::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_ShapeNode.def("Read", (VrmlData_ErrorStatus (VrmlData_ShapeNode::*)(VrmlData_InBuffer &)) &VrmlData_ShapeNode::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
	cls_VrmlData_ShapeNode.def("Write", (VrmlData_ErrorStatus (VrmlData_ShapeNode::*)(const char *) const ) &VrmlData_ShapeNode::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_ShapeNode.def("IsDefault", (Standard_Boolean (VrmlData_ShapeNode::*)() const ) &VrmlData_ShapeNode::IsDefault, "Check if the Shape Node is writeable.");
	cls_VrmlData_ShapeNode.def_static("get_type_name_", (const char * (*)()) &VrmlData_ShapeNode::get_type_name, "None");
	cls_VrmlData_ShapeNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_ShapeNode::get_type_descriptor, "None");
	cls_VrmlData_ShapeNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_ShapeNode::*)() const ) &VrmlData_ShapeNode::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_Sphere.hxx
	py::class_<VrmlData_Sphere, opencascade::handle<VrmlData_Sphere>, VrmlData_Geometry> cls_VrmlData_Sphere(mod, "VrmlData_Sphere", "Implementation of the Sphere node.");
	cls_VrmlData_Sphere.def(py::init<>());
	cls_VrmlData_Sphere.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_Sphere.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theRadius"));
	cls_VrmlData_Sphere.def("Radius", (Standard_Real (VrmlData_Sphere::*)() const ) &VrmlData_Sphere::Radius, "Query the sphere radius");
	cls_VrmlData_Sphere.def("SetRadius", (void (VrmlData_Sphere::*)(const Standard_Real)) &VrmlData_Sphere::SetRadius, "Set the spere radius", py::arg("theRadius"));
	cls_VrmlData_Sphere.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Sphere::*)()) &VrmlData_Sphere::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
	cls_VrmlData_Sphere.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Sphere::*)(const opencascade::handle<VrmlData_Node> &) const ) &VrmlData_Sphere::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
	cls_VrmlData_Sphere.def("Read", (VrmlData_ErrorStatus (VrmlData_Sphere::*)(VrmlData_InBuffer &)) &VrmlData_Sphere::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
	cls_VrmlData_Sphere.def("Write", (VrmlData_ErrorStatus (VrmlData_Sphere::*)(const char *) const ) &VrmlData_Sphere::Write, "Write the Node to output stream.", py::arg("thePrefix"));
	cls_VrmlData_Sphere.def_static("get_type_name_", (const char * (*)()) &VrmlData_Sphere::get_type_name, "None");
	cls_VrmlData_Sphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Sphere::get_type_descriptor, "None");
	cls_VrmlData_Sphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Sphere::*)() const ) &VrmlData_Sphere::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlData_UnknownNode.hxx
	py::class_<VrmlData_UnknownNode, opencascade::handle<VrmlData_UnknownNode>, VrmlData_Node> cls_VrmlData_UnknownNode(mod, "VrmlData_UnknownNode", "Definition of UnknownNode -- placeholder for node types that are not processed now.");
	cls_VrmlData_UnknownNode.def(py::init<>());
	cls_VrmlData_UnknownNode.def(py::init<const VrmlData_Scene &>(), py::arg("theScene"));
	cls_VrmlData_UnknownNode.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
	cls_VrmlData_UnknownNode.def(py::init<const VrmlData_Scene &, const char *, const char *>(), py::arg("theScene"), py::arg("theName"), py::arg("theTitle"));
	cls_VrmlData_UnknownNode.def("Read", (VrmlData_ErrorStatus (VrmlData_UnknownNode::*)(VrmlData_InBuffer &)) &VrmlData_UnknownNode::Read, "Read the unknown node, till the last closing brace of it.", py::arg("theBuffer"));
	cls_VrmlData_UnknownNode.def("GetTitle", (const TCollection_AsciiString & (VrmlData_UnknownNode::*)() const ) &VrmlData_UnknownNode::GetTitle, "Query the title of the unknown node.");
	cls_VrmlData_UnknownNode.def("IsDefault", (Standard_Boolean (VrmlData_UnknownNode::*)() const ) &VrmlData_UnknownNode::IsDefault, "Check if the Node is non-writeable -- always returns true.");
	cls_VrmlData_UnknownNode.def_static("get_type_name_", (const char * (*)()) &VrmlData_UnknownNode::get_type_name, "None");
	cls_VrmlData_UnknownNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_UnknownNode::get_type_descriptor, "None");
	cls_VrmlData_UnknownNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_UnknownNode::*)() const ) &VrmlData_UnknownNode::DynamicType, "None");

	/* FIXME
	// VrmlData_DataMapOfShapeAppearance
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<VrmlData_ListOfNode, std::unique_ptr<VrmlData_ListOfNode, Deleter<VrmlData_ListOfNode>>, NCollection_BaseList> cls_VrmlData_ListOfNode(mod, "VrmlData_ListOfNode", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_VrmlData_ListOfNode.def(py::init<>());
	cls_VrmlData_ListOfNode.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_VrmlData_ListOfNode.def(py::init([] (const VrmlData_ListOfNode &other) {return new VrmlData_ListOfNode(other);}), "Copy constructor", py::arg("other"));
	cls_VrmlData_ListOfNode.def("begin", (VrmlData_ListOfNode::iterator (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::begin, "Returns an iterator pointing to the first element in the list.");
	cls_VrmlData_ListOfNode.def("end", (VrmlData_ListOfNode::iterator (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_VrmlData_ListOfNode.def("cbegin", (VrmlData_ListOfNode::const_iterator (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_VrmlData_ListOfNode.def("cend", (VrmlData_ListOfNode::const_iterator (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_VrmlData_ListOfNode.def("Size", (Standard_Integer (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::Size, "Size - Number of items");
	cls_VrmlData_ListOfNode.def("Assign", (VrmlData_ListOfNode & (VrmlData_ListOfNode::*)(const VrmlData_ListOfNode &)) &VrmlData_ListOfNode::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_VrmlData_ListOfNode.def("assign", (VrmlData_ListOfNode & (VrmlData_ListOfNode::*)(const VrmlData_ListOfNode &)) &VrmlData_ListOfNode::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_VrmlData_ListOfNode.def("Clear", [](VrmlData_ListOfNode &self) -> void { return self.Clear(); });
	cls_VrmlData_ListOfNode.def("Clear", (void (VrmlData_ListOfNode::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &VrmlData_ListOfNode::Clear, "Clear this list", py::arg("theAllocator"));
	cls_VrmlData_ListOfNode.def("First", (const opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::First, "First item");
	cls_VrmlData_ListOfNode.def("First", (opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)()) &VrmlData_ListOfNode::First, "First item (non-const)");
	cls_VrmlData_ListOfNode.def("Last", (const opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)() const ) &VrmlData_ListOfNode::Last, "Last item");
	cls_VrmlData_ListOfNode.def("Last", (opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)()) &VrmlData_ListOfNode::Last, "Last item (non-const)");
	cls_VrmlData_ListOfNode.def("Append", (opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)(const opencascade::handle<VrmlData_Node> &)) &VrmlData_ListOfNode::Append, "Append one item at the end", py::arg("theItem"));
	cls_VrmlData_ListOfNode.def("Append", (void (VrmlData_ListOfNode::*)(const opencascade::handle<VrmlData_Node> &, VrmlData_ListOfNode::Iterator &)) &VrmlData_ListOfNode::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_VrmlData_ListOfNode.def("Append", (void (VrmlData_ListOfNode::*)(VrmlData_ListOfNode &)) &VrmlData_ListOfNode::Append, "Append another list at the end", py::arg("theOther"));
	cls_VrmlData_ListOfNode.def("Prepend", (opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)(const opencascade::handle<VrmlData_Node> &)) &VrmlData_ListOfNode::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_VrmlData_ListOfNode.def("Prepend", (void (VrmlData_ListOfNode::*)(VrmlData_ListOfNode &)) &VrmlData_ListOfNode::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_VrmlData_ListOfNode.def("RemoveFirst", (void (VrmlData_ListOfNode::*)()) &VrmlData_ListOfNode::RemoveFirst, "RemoveFirst item");
	cls_VrmlData_ListOfNode.def("Remove", (void (VrmlData_ListOfNode::*)(VrmlData_ListOfNode::Iterator &)) &VrmlData_ListOfNode::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_VrmlData_ListOfNode.def("InsertBefore", (opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)(const opencascade::handle<VrmlData_Node> &, VrmlData_ListOfNode::Iterator &)) &VrmlData_ListOfNode::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_VrmlData_ListOfNode.def("InsertBefore", (void (VrmlData_ListOfNode::*)(VrmlData_ListOfNode &, VrmlData_ListOfNode::Iterator &)) &VrmlData_ListOfNode::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_VrmlData_ListOfNode.def("InsertAfter", (opencascade::handle<VrmlData_Node> & (VrmlData_ListOfNode::*)(const opencascade::handle<VrmlData_Node> &, VrmlData_ListOfNode::Iterator &)) &VrmlData_ListOfNode::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_VrmlData_ListOfNode.def("InsertAfter", (void (VrmlData_ListOfNode::*)(VrmlData_ListOfNode &, VrmlData_ListOfNode::Iterator &)) &VrmlData_ListOfNode::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_VrmlData_ListOfNode.def("Reverse", (void (VrmlData_ListOfNode::*)()) &VrmlData_ListOfNode::Reverse, "Reverse the list");
	cls_VrmlData_ListOfNode.def("__iter__", [](const VrmlData_ListOfNode &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	/* FIXME
	// VrmlData_MapOfNode
	*/


}
