#include <pyOCCT_Common.hpp>

#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TNaming_Evolution.hxx>
#include <Standard_Handle.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_PtrNode.hxx>
#include <TDF_Label.hxx>
#include <TNaming_Builder.hxx>
#include <TNaming_Iterator.hxx>
#include <TNaming_NewShapeIterator.hxx>
#include <TNaming_OldShapeIterator.hxx>
#include <TNaming_NameType.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <TNaming_ListOfNamedShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <TDF_LabelMap.hxx>
#include <TNaming_Name.hxx>
#include <TNaming_Naming.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF_AttributeIndexedMap.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TNaming_TranslateTool.hxx>
#include <TopLoc_Location.hxx>
#include <TNaming_CopyShape.hxx>
#include <Standard_Transient.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TNaming_Translator.hxx>
#include <TNaming_DataMapOfShapePtrRefShape.hxx>
#include <TDF_DeltaOnAddition.hxx>
#include <TNaming_UsedShapes.hxx>
#include <TNaming_MapOfNamedShape.hxx>
#include <TDF_LabelList.hxx>
#include <TNaming_Tool.hxx>
#include <TNaming_SameShapeIterator.hxx>
#include <TDF_AttributeMap.hxx>
#include <TNaming_Selector.hxx>
#include <TNaming_DeltaOnRemoval.hxx>
#include <TNaming_DeltaOnModification.hxx>
#include <TNaming_RefShape.hxx>
#include <TNaming_Scope.hxx>
#include <TNaming_Localizer.hxx>
#include <TNaming_Identifier.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TNaming_ShapesSet.hxx>
#include <TNaming_IteratorOnShapesSet.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TNaming_NamingTool.hxx>
#include <gp_Trsf.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Shell.hxx>
#include <TDF_IDList.hxx>
#include <TNaming.hxx>
#include <TNaming_PtrRefShape.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <TNaming_DataMapOfShapeShapesSet.hxx>
#include <TNaming_ListOfIndexedDataMapOfShapeListOfShape.hxx>
#include <TNaming_ListOfMapOfShape.hxx>
#include <TNaming_NamedShapeHasher.hxx>
#include <NCollection_Map.hxx>
#include <TNaming_NCollections.hxx>
#include <TNaming_PtrAttribute.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TNaming, mod) {

	// IMPORT
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Evolution.hxx
	py::enum_<TNaming_Evolution>(mod, "TNaming_Evolution", "Defines the type of evolution in old shape - new shape pairs. The definitions - in the form of the terms of the enumeration - are needed by the TNaming_NamedShape attribute and indicate what entities this attribute records as follows: - PRIMITIVE - New entities; in each pair, old shape is a null shape and new shape is a created entity. - GENERATED - Entities created from other entities; in each pair, old shape is the generator and new shape is the created entity. - MODIFY - Split or merged entities, in each pair, old shape is the entity before the operation and new shape is the new entity after the operation. - DELETE - Deletion of entities; in each pair, old shape is a deleted entity and new shape is null. - SELECTED - Named topological entities; in each pair, the new shape is a named entity and the old shape is not used.")
		.value("TNaming_PRIMITIVE", TNaming_Evolution::TNaming_PRIMITIVE)
		.value("TNaming_GENERATED", TNaming_Evolution::TNaming_GENERATED)
		.value("TNaming_MODIFY", TNaming_Evolution::TNaming_MODIFY)
		.value("TNaming_DELETE", TNaming_Evolution::TNaming_DELETE)
		.value("TNaming_REPLACE", TNaming_Evolution::TNaming_REPLACE)
		.value("TNaming_SELECTED", TNaming_Evolution::TNaming_SELECTED)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NameType.hxx
	py::enum_<TNaming_NameType>(mod, "TNaming_NameType", "to store naming characteristcs")
		.value("TNaming_UNKNOWN", TNaming_NameType::TNaming_UNKNOWN)
		.value("TNaming_IDENTITY", TNaming_NameType::TNaming_IDENTITY)
		.value("TNaming_MODIFUNTIL", TNaming_NameType::TNaming_MODIFUNTIL)
		.value("TNaming_GENERATION", TNaming_NameType::TNaming_GENERATION)
		.value("TNaming_INTERSECTION", TNaming_NameType::TNaming_INTERSECTION)
		.value("TNaming_UNION", TNaming_NameType::TNaming_UNION)
		.value("TNaming_SUBSTRACTION", TNaming_NameType::TNaming_SUBSTRACTION)
		.value("TNaming_CONSTSHAPE", TNaming_NameType::TNaming_CONSTSHAPE)
		.value("TNaming_FILTERBYNEIGHBOURGS", TNaming_NameType::TNaming_FILTERBYNEIGHBOURGS)
		.value("TNaming_ORIENTATION", TNaming_NameType::TNaming_ORIENTATION)
		.value("TNaming_WIREIN", TNaming_NameType::TNaming_WIREIN)
		.value("TNaming_SHELLIN", TNaming_NameType::TNaming_SHELLIN)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NamedShape.hxx
	py::class_<TNaming_NamedShape, opencascade::handle<TNaming_NamedShape>, TDF_Attribute> cls_TNaming_NamedShape(mod, "TNaming_NamedShape", "The basis to define an attribute for the storage of topology and naming data. This attribute contains two parts: - The type of evolution, a term of the enumeration TNaming_Evolution - A list of pairs of shapes called the 'old' shape and the 'new' shape. The meaning depends on the type of evolution.");
	cls_TNaming_NamedShape.def(py::init<>());
	cls_TNaming_NamedShape.def_static("GetID_", (const Standard_GUID & (*)()) &TNaming_NamedShape::GetID, "class method ============ Returns the GUID for named shapes.");
	cls_TNaming_NamedShape.def("IsEmpty", (Standard_Boolean (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::IsEmpty, "None");
	cls_TNaming_NamedShape.def("Get", (TopoDS_Shape (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::Get, "Returns the shapes contained in <NS>. Returns a null shape if IsEmpty.");
	cls_TNaming_NamedShape.def("Evolution", (TNaming_Evolution (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::Evolution, "Returns the Evolution of the attribute.");
	cls_TNaming_NamedShape.def("Version", (Standard_Integer (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::Version, "Returns the Version of the attribute.");
	cls_TNaming_NamedShape.def("SetVersion", (void (TNaming_NamedShape::*)(const Standard_Integer)) &TNaming_NamedShape::SetVersion, "Set the Version of the attribute.", py::arg("version"));
	cls_TNaming_NamedShape.def("Clear", (void (TNaming_NamedShape::*)()) &TNaming_NamedShape::Clear, "None");
	cls_TNaming_NamedShape.def("ID", (const Standard_GUID & (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::ID, "Returns the ID of the attribute.");
	cls_TNaming_NamedShape.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::BackupCopy, "Copies the attribute contents into a new other attribute. It is used by Backup().");
	cls_TNaming_NamedShape.def("Restore", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_Attribute> &)) &TNaming_NamedShape::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
	cls_TNaming_NamedShape.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TNaming_NamedShape::*)(const opencascade::handle<TDF_Attribute> &) const ) &TNaming_NamedShape::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute.", py::arg("anOldAttribute"));
	cls_TNaming_NamedShape.def("DeltaOnModification", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_DeltaOnModification> &)) &TNaming_NamedShape::DeltaOnModification, "Applies a DeltaOnModification to <me>.", py::arg("aDelta"));
	cls_TNaming_NamedShape.def("DeltaOnRemoval", (opencascade::handle<TDF_DeltaOnRemoval> (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::DeltaOnRemoval, "Makes a DeltaOnRemoval on <me> because <me> has disappeared from the DS.");
	cls_TNaming_NamedShape.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
	cls_TNaming_NamedShape.def("Paste", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TNaming_NamedShape::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
	cls_TNaming_NamedShape.def("References", (void (TNaming_NamedShape::*)(const opencascade::handle<TDF_DataSet> &) const ) &TNaming_NamedShape::References, "Adds the directly referenced attributes and labels to <aDataSet>. 'Directly' means we have only to look at the first level of references.", py::arg("aDataSet"));
	cls_TNaming_NamedShape.def("BeforeRemoval", (void (TNaming_NamedShape::*)()) &TNaming_NamedShape::BeforeRemoval, "None");
	cls_TNaming_NamedShape.def("BeforeUndo", [](TNaming_NamedShape &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); }, py::arg("anAttDelta"));
	cls_TNaming_NamedShape.def("BeforeUndo", (Standard_Boolean (TNaming_NamedShape::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TNaming_NamedShape::BeforeUndo, "Something to do before applying <anAttDelta>", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TNaming_NamedShape.def("AfterUndo", [](TNaming_NamedShape &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); }, py::arg("anAttDelta"));
	cls_TNaming_NamedShape.def("AfterUndo", (Standard_Boolean (TNaming_NamedShape::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TNaming_NamedShape::AfterUndo, "Something to do after applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
	// FIXME cls_TNaming_NamedShape.def("Dump", (Standard_OStream & (TNaming_NamedShape::*)(Standard_OStream &) const ) &TNaming_NamedShape::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
	cls_TNaming_NamedShape.def_static("get_type_name_", (const char * (*)()) &TNaming_NamedShape::get_type_name, "None");
	cls_TNaming_NamedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_NamedShape::get_type_descriptor, "None");
	cls_TNaming_NamedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_NamedShape::*)() const ) &TNaming_NamedShape::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_PtrNode.hxx
	py::class_<TNaming_Node, std::unique_ptr<TNaming_Node, Deleter<TNaming_Node>>> cls_TNaming_Node(mod, "TNaming_Node", "None");
	cls_TNaming_Node.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Builder.hxx
	py::class_<TNaming_Builder, std::unique_ptr<TNaming_Builder, Deleter<TNaming_Builder>>> cls_TNaming_Builder(mod, "TNaming_Builder", "A tool to create and maintain topological attributes. Constructor creates an empty TNaming_NamedShape attribute at the given label. It allows adding 'old shape' and 'new shape' pairs with the specified evolution to this named shape. One evolution type per one builder must be used.");
	cls_TNaming_Builder.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
	cls_TNaming_Builder.def("Generated", (void (TNaming_Builder::*)(const TopoDS_Shape &)) &TNaming_Builder::Generated, "Records the shape newShape which was generated during a topological construction. As an example, consider the case of a face generated in construction of a box.", py::arg("newShape"));
	cls_TNaming_Builder.def("Generated", (void (TNaming_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming_Builder::Generated, "Records the shape newShape which was generated from the shape oldShape during a topological construction. As an example, consider the case of a face generated from an edge in construction of a prism.", py::arg("oldShape"), py::arg("newShape"));
	cls_TNaming_Builder.def("Delete", (void (TNaming_Builder::*)(const TopoDS_Shape &)) &TNaming_Builder::Delete, "Records the shape oldShape which was deleted from the current label. As an example, consider the case of a face removed by a Boolean operation.", py::arg("oldShape"));
	cls_TNaming_Builder.def("Modify", (void (TNaming_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming_Builder::Modify, "Records the shape newShape which is a modification of the shape oldShape. As an example, consider the case of a face split or merged in a Boolean operation.", py::arg("oldShape"), py::arg("newShape"));
	cls_TNaming_Builder.def("Select", (void (TNaming_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming_Builder::Select, "Add a Shape to the current label , This Shape is unmodified. Used for example to define a set of shapes under a label.", py::arg("aShape"), py::arg("inShape"));
	cls_TNaming_Builder.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_Builder::*)() const ) &TNaming_Builder::NamedShape, "Returns the NamedShape which has been built or is under construction.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Iterator.hxx
	py::class_<TNaming_Iterator, std::unique_ptr<TNaming_Iterator, Deleter<TNaming_Iterator>>> cls_TNaming_Iterator(mod, "TNaming_Iterator", "A tool to visit the contents of a named shape attribute. Pairs of shapes in the attribute are iterated, one being the pre-modification or the old shape, and the other the post-modification or the new shape. This allows you to have a full access to all contents of an attribute. If, on the other hand, you are only interested in topological entities stored in the attribute, you can use the functions GetShape and CurrentShape in TNaming_Tool.");
	cls_TNaming_Iterator.def(py::init<const opencascade::handle<TNaming_NamedShape> &>(), py::arg("anAtt"));
	cls_TNaming_Iterator.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
	cls_TNaming_Iterator.def(py::init<const TDF_Label &, const Standard_Integer>(), py::arg("aLabel"), py::arg("aTrans"));
	cls_TNaming_Iterator.def("More", (Standard_Boolean (TNaming_Iterator::*)() const ) &TNaming_Iterator::More, "Returns True if there is a current Item in the iteration.");
	cls_TNaming_Iterator.def("Next", (void (TNaming_Iterator::*)()) &TNaming_Iterator::Next, "Moves the iteration to the next Item");
	cls_TNaming_Iterator.def("OldShape", (const TopoDS_Shape & (TNaming_Iterator::*)() const ) &TNaming_Iterator::OldShape, "Returns the old shape in this iterator object. This shape can be a null one.");
	cls_TNaming_Iterator.def("NewShape", (const TopoDS_Shape & (TNaming_Iterator::*)() const ) &TNaming_Iterator::NewShape, "Returns the new shape in this iterator object.");
	cls_TNaming_Iterator.def("IsModification", (Standard_Boolean (TNaming_Iterator::*)() const ) &TNaming_Iterator::IsModification, "Returns true if the new shape is a modification (split, fuse,etc...) of the old shape.");
	cls_TNaming_Iterator.def("Evolution", (TNaming_Evolution (TNaming_Iterator::*)() const ) &TNaming_Iterator::Evolution, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NewShapeIterator.hxx
	py::class_<TNaming_NewShapeIterator, std::unique_ptr<TNaming_NewShapeIterator, Deleter<TNaming_NewShapeIterator>>> cls_TNaming_NewShapeIterator(mod, "TNaming_NewShapeIterator", "Iterates on all the descendants of a shape");
	cls_TNaming_NewShapeIterator.def(py::init<const TopoDS_Shape &, const Standard_Integer, const TDF_Label &>(), py::arg("aShape"), py::arg("Transaction"), py::arg("access"));
	cls_TNaming_NewShapeIterator.def(py::init<const TopoDS_Shape &, const TDF_Label &>(), py::arg("aShape"), py::arg("access"));
	cls_TNaming_NewShapeIterator.def(py::init([] (const TNaming_NewShapeIterator &other) {return new TNaming_NewShapeIterator(other);}), "Copy constructor", py::arg("other"));
	cls_TNaming_NewShapeIterator.def(py::init<const TNaming_Iterator &>(), py::arg("anIterator"));
	cls_TNaming_NewShapeIterator.def("More", (Standard_Boolean (TNaming_NewShapeIterator::*)() const ) &TNaming_NewShapeIterator::More, "None");
	cls_TNaming_NewShapeIterator.def("Next", (void (TNaming_NewShapeIterator::*)()) &TNaming_NewShapeIterator::Next, "None");
	cls_TNaming_NewShapeIterator.def("Label", (TDF_Label (TNaming_NewShapeIterator::*)() const ) &TNaming_NewShapeIterator::Label, "None");
	cls_TNaming_NewShapeIterator.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_NewShapeIterator::*)() const ) &TNaming_NewShapeIterator::NamedShape, "None");
	cls_TNaming_NewShapeIterator.def("Shape", (const TopoDS_Shape & (TNaming_NewShapeIterator::*)() const ) &TNaming_NewShapeIterator::Shape, "Warning! Can be a Null Shape if a descendant is deleted.");
	cls_TNaming_NewShapeIterator.def("IsModification", (Standard_Boolean (TNaming_NewShapeIterator::*)() const ) &TNaming_NewShapeIterator::IsModification, "True if the new shape is a modification (split, fuse,etc...) of the old shape.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_OldShapeIterator.hxx
	py::class_<TNaming_OldShapeIterator, std::unique_ptr<TNaming_OldShapeIterator, Deleter<TNaming_OldShapeIterator>>> cls_TNaming_OldShapeIterator(mod, "TNaming_OldShapeIterator", "Iterates on all the ascendants of a shape");
	cls_TNaming_OldShapeIterator.def(py::init<const TopoDS_Shape &, const Standard_Integer, const TDF_Label &>(), py::arg("aShape"), py::arg("Transaction"), py::arg("access"));
	cls_TNaming_OldShapeIterator.def(py::init<const TopoDS_Shape &, const TDF_Label &>(), py::arg("aShape"), py::arg("access"));
	cls_TNaming_OldShapeIterator.def(py::init([] (const TNaming_OldShapeIterator &other) {return new TNaming_OldShapeIterator(other);}), "Copy constructor", py::arg("other"));
	cls_TNaming_OldShapeIterator.def(py::init<const TNaming_Iterator &>(), py::arg("anIterator"));
	cls_TNaming_OldShapeIterator.def("More", (Standard_Boolean (TNaming_OldShapeIterator::*)() const ) &TNaming_OldShapeIterator::More, "None");
	cls_TNaming_OldShapeIterator.def("Next", (void (TNaming_OldShapeIterator::*)()) &TNaming_OldShapeIterator::Next, "None");
	cls_TNaming_OldShapeIterator.def("Label", (TDF_Label (TNaming_OldShapeIterator::*)() const ) &TNaming_OldShapeIterator::Label, "None");
	cls_TNaming_OldShapeIterator.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_OldShapeIterator::*)() const ) &TNaming_OldShapeIterator::NamedShape, "None");
	cls_TNaming_OldShapeIterator.def("Shape", (const TopoDS_Shape & (TNaming_OldShapeIterator::*)() const ) &TNaming_OldShapeIterator::Shape, "None");
	cls_TNaming_OldShapeIterator.def("IsModification", (Standard_Boolean (TNaming_OldShapeIterator::*)() const ) &TNaming_OldShapeIterator::IsModification, "True if the new shape is a modification (split, fuse,etc...) of the old shape.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Name.hxx
	py::class_<TNaming_Name, std::unique_ptr<TNaming_Name, Deleter<TNaming_Name>>> cls_TNaming_Name(mod, "TNaming_Name", "store the arguments of Naming.");
	cls_TNaming_Name.def(py::init<>());
	cls_TNaming_Name.def("Type", (void (TNaming_Name::*)(const TNaming_NameType)) &TNaming_Name::Type, "None", py::arg("aType"));
	cls_TNaming_Name.def("ShapeType", (void (TNaming_Name::*)(const TopAbs_ShapeEnum)) &TNaming_Name::ShapeType, "None", py::arg("aType"));
	cls_TNaming_Name.def("Shape", (void (TNaming_Name::*)(const TopoDS_Shape &)) &TNaming_Name::Shape, "None", py::arg("theShape"));
	cls_TNaming_Name.def("Append", (void (TNaming_Name::*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Name::Append, "None", py::arg("arg"));
	cls_TNaming_Name.def("StopNamedShape", (void (TNaming_Name::*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Name::StopNamedShape, "None", py::arg("arg"));
	cls_TNaming_Name.def("Index", (void (TNaming_Name::*)(const Standard_Integer)) &TNaming_Name::Index, "None", py::arg("I"));
	cls_TNaming_Name.def("ContextLabel", (void (TNaming_Name::*)(const TDF_Label &)) &TNaming_Name::ContextLabel, "None", py::arg("theLab"));
	cls_TNaming_Name.def("Orientation", (void (TNaming_Name::*)(const TopAbs_Orientation)) &TNaming_Name::Orientation, "None", py::arg("theOrientation"));
	cls_TNaming_Name.def("Type", (TNaming_NameType (TNaming_Name::*)() const ) &TNaming_Name::Type, "None");
	cls_TNaming_Name.def("ShapeType", (TopAbs_ShapeEnum (TNaming_Name::*)() const ) &TNaming_Name::ShapeType, "None");
	cls_TNaming_Name.def("Shape", (TopoDS_Shape (TNaming_Name::*)() const ) &TNaming_Name::Shape, "None");
	cls_TNaming_Name.def("Arguments", (const TNaming_ListOfNamedShape & (TNaming_Name::*)() const ) &TNaming_Name::Arguments, "None");
	cls_TNaming_Name.def("StopNamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_Name::*)() const ) &TNaming_Name::StopNamedShape, "None");
	cls_TNaming_Name.def("Index", (Standard_Integer (TNaming_Name::*)() const ) &TNaming_Name::Index, "None");
	cls_TNaming_Name.def("ContextLabel", (const TDF_Label & (TNaming_Name::*)() const ) &TNaming_Name::ContextLabel, "None");
	cls_TNaming_Name.def("Orientation", (TopAbs_Orientation (TNaming_Name::*)() const ) &TNaming_Name::Orientation, "None");
	cls_TNaming_Name.def("Solve", (Standard_Boolean (TNaming_Name::*)(const TDF_Label &, const TDF_LabelMap &) const ) &TNaming_Name::Solve, "None", py::arg("aLab"), py::arg("Valid"));
	cls_TNaming_Name.def("Paste", (void (TNaming_Name::*)(TNaming_Name &, const opencascade::handle<TDF_RelocationTable> &) const ) &TNaming_Name::Paste, "None", py::arg("into"), py::arg("RT"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Naming.hxx
	py::class_<TNaming_Naming, opencascade::handle<TNaming_Naming>, TDF_Attribute> cls_TNaming_Naming(mod, "TNaming_Naming", "This attribute store the topological naming of any selected shape, when this shape is not already attached to a specific label. This class is also used to solve it when the argumentsof the toipological naming are modified.");
	cls_TNaming_Naming.def(py::init<>());
	cls_TNaming_Naming.def_static("GetID_", (const Standard_GUID & (*)()) &TNaming_Naming::GetID, "following code from TDesignStd ==============================");
	cls_TNaming_Naming.def_static("Insert_", (opencascade::handle<TNaming_Naming> (*)(const TDF_Label &)) &TNaming_Naming::Insert, "None", py::arg("under"));
	cls_TNaming_Naming.def_static("Name_", [](const TDF_Label & a0, const TopoDS_Shape & a1, const TopoDS_Shape & a2) -> opencascade::handle<TNaming_NamedShape> { return TNaming_Naming::Name(a0, a1, a2); }, py::arg("where"), py::arg("Selection"), py::arg("Context"));
	cls_TNaming_Naming.def_static("Name_", [](const TDF_Label & a0, const TopoDS_Shape & a1, const TopoDS_Shape & a2, const Standard_Boolean a3) -> opencascade::handle<TNaming_NamedShape> { return TNaming_Naming::Name(a0, a1, a2, a3); }, py::arg("where"), py::arg("Selection"), py::arg("Context"), py::arg("Geometry"));
	cls_TNaming_Naming.def_static("Name_", [](const TDF_Label & a0, const TopoDS_Shape & a1, const TopoDS_Shape & a2, const Standard_Boolean a3, const Standard_Boolean a4) -> opencascade::handle<TNaming_NamedShape> { return TNaming_Naming::Name(a0, a1, a2, a3, a4); }, py::arg("where"), py::arg("Selection"), py::arg("Context"), py::arg("Geometry"), py::arg("KeepOrientation"));
	cls_TNaming_Naming.def_static("Name_", (opencascade::handle<TNaming_NamedShape> (*)(const TDF_Label &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TNaming_Naming::Name, "Creates a Namimg attribute at label <where> to identify the shape <Selection>. Geometry is Standard_True if we are only interested by the underlying geometry (e.g. setting a constraint). <Context> is used to find neighbours of <S> when required by the naming. If KeepOrientation is True the Selection orientation is taken into account. BNproblem == True points out that Context sub-shapes in DF have orientation differences with Context shape itself. instance method ===============", py::arg("where"), py::arg("Selection"), py::arg("Context"), py::arg("Geometry"), py::arg("KeepOrientation"), py::arg("BNproblem"));
	cls_TNaming_Naming.def("IsDefined", (Standard_Boolean (TNaming_Naming::*)() const ) &TNaming_Naming::IsDefined, "None");
	cls_TNaming_Naming.def("GetName", (const TNaming_Name & (TNaming_Naming::*)() const ) &TNaming_Naming::GetName, "None");
	cls_TNaming_Naming.def("ChangeName", (TNaming_Name & (TNaming_Naming::*)()) &TNaming_Naming::ChangeName, "None");
	cls_TNaming_Naming.def("Regenerate", (Standard_Boolean (TNaming_Naming::*)(TDF_LabelMap &)) &TNaming_Naming::Regenerate, "regenerate only the Name associated to me", py::arg("scope"));
	cls_TNaming_Naming.def("Solve", (Standard_Boolean (TNaming_Naming::*)(TDF_LabelMap &)) &TNaming_Naming::Solve, "Regenerate recursively the whole name with scope. If scope is empty it means that all the labels of the framework are valid.", py::arg("scope"));
	cls_TNaming_Naming.def("ID", (const Standard_GUID & (TNaming_Naming::*)() const ) &TNaming_Naming::ID, "Deferred methods from TDF_Attribute ===================================");
	cls_TNaming_Naming.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TNaming_Naming::*)() const ) &TNaming_Naming::NewEmpty, "None");
	cls_TNaming_Naming.def("Restore", (void (TNaming_Naming::*)(const opencascade::handle<TDF_Attribute> &)) &TNaming_Naming::Restore, "None", py::arg("With"));
	cls_TNaming_Naming.def("Paste", (void (TNaming_Naming::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TNaming_Naming::Paste, "None", py::arg("Into"), py::arg("RT"));
	cls_TNaming_Naming.def("References", (void (TNaming_Naming::*)(const opencascade::handle<TDF_DataSet> &) const ) &TNaming_Naming::References, "None", py::arg("aDataSet"));
	// FIXME cls_TNaming_Naming.def("Dump", (Standard_OStream & (TNaming_Naming::*)(Standard_OStream &) const ) &TNaming_Naming::Dump, "None", py::arg("anOS"));
	cls_TNaming_Naming.def("ExtendedDump", (void (TNaming_Naming::*)(Standard_OStream &, const TDF_IDFilter &, TDF_AttributeIndexedMap &) const ) &TNaming_Naming::ExtendedDump, "None", py::arg("anOS"), py::arg("aFilter"), py::arg("aMap"));
	cls_TNaming_Naming.def_static("get_type_name_", (const char * (*)()) &TNaming_Naming::get_type_name, "None");
	cls_TNaming_Naming.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_Naming::get_type_descriptor, "None");
	cls_TNaming_Naming.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_Naming::*)() const ) &TNaming_Naming::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_CopyShape.hxx
	py::class_<TNaming_CopyShape, std::unique_ptr<TNaming_CopyShape, Deleter<TNaming_CopyShape>>> cls_TNaming_CopyShape(mod, "TNaming_CopyShape", "None");
	cls_TNaming_CopyShape.def(py::init<>());
	cls_TNaming_CopyShape.def_static("CopyTool_", (void (*)(const TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &, TopoDS_Shape &)) &TNaming_CopyShape::CopyTool, "Makes copy a set of shape(s), using the aMap", py::arg("aShape"), py::arg("aMap"), py::arg("aResult"));
	cls_TNaming_CopyShape.def_static("Translate_", (void (*)(const TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &, TopoDS_Shape &, const opencascade::handle<TNaming_TranslateTool> &)) &TNaming_CopyShape::Translate, "Translates a Transient shape(s) to Transient", py::arg("aShape"), py::arg("aMap"), py::arg("aResult"), py::arg("TrTool"));
	cls_TNaming_CopyShape.def_static("Translate_", (TopLoc_Location (*)(const TopLoc_Location &, TColStd_IndexedDataMapOfTransientTransient &)) &TNaming_CopyShape::Translate, "Translates a Topological Location to an other Top. Location", py::arg("L"), py::arg("aMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_TranslateTool.hxx
	py::class_<TNaming_TranslateTool, opencascade::handle<TNaming_TranslateTool>, Standard_Transient> cls_TNaming_TranslateTool(mod, "TNaming_TranslateTool", "tool to copy underlying TShape of a Shape. The TranslateTool class is provided to support the translation of topological data structures Transient to Transient.");
	cls_TNaming_TranslateTool.def("Add", (void (TNaming_TranslateTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const ) &TNaming_TranslateTool::Add, "None", py::arg("S1"), py::arg("S2"));
	cls_TNaming_TranslateTool.def("MakeVertex", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeVertex, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeEdge", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeEdge, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeWire", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeWire, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeFace", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeFace, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeShell", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeShell, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeSolid", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeSolid, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeCompSolid", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeCompSolid, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("MakeCompound", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const ) &TNaming_TranslateTool::MakeCompound, "None", py::arg("S"));
	cls_TNaming_TranslateTool.def("UpdateVertex", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &) const ) &TNaming_TranslateTool::UpdateVertex, "None", py::arg("S1"), py::arg("S2"), py::arg("M"));
	cls_TNaming_TranslateTool.def("UpdateEdge", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &) const ) &TNaming_TranslateTool::UpdateEdge, "None", py::arg("S1"), py::arg("S2"), py::arg("M"));
	cls_TNaming_TranslateTool.def("UpdateFace", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &) const ) &TNaming_TranslateTool::UpdateFace, "None", py::arg("S1"), py::arg("S2"), py::arg("M"));
	cls_TNaming_TranslateTool.def("UpdateShape", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &TNaming_TranslateTool::UpdateShape, "None", py::arg("S1"), py::arg("S2"));
	cls_TNaming_TranslateTool.def_static("get_type_name_", (const char * (*)()) &TNaming_TranslateTool::get_type_name, "None");
	cls_TNaming_TranslateTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_TranslateTool::get_type_descriptor, "None");
	cls_TNaming_TranslateTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_TranslateTool::*)() const ) &TNaming_TranslateTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Translator.hxx
	py::class_<TNaming_Translator, std::unique_ptr<TNaming_Translator, Deleter<TNaming_Translator>>> cls_TNaming_Translator(mod, "TNaming_Translator", "only for Shape Copy test - to move in DNaming");
	cls_TNaming_Translator.def(py::init<>());
	cls_TNaming_Translator.def("Add", (void (TNaming_Translator::*)(const TopoDS_Shape &)) &TNaming_Translator::Add, "None", py::arg("aShape"));
	cls_TNaming_Translator.def("Perform", (void (TNaming_Translator::*)()) &TNaming_Translator::Perform, "None");
	cls_TNaming_Translator.def("IsDone", (Standard_Boolean (TNaming_Translator::*)() const ) &TNaming_Translator::IsDone, "None");
	cls_TNaming_Translator.def("Copied", (const TopoDS_Shape (TNaming_Translator::*)(const TopoDS_Shape &) const ) &TNaming_Translator::Copied, "returns copied shape", py::arg("aShape"));
	cls_TNaming_Translator.def("Copied", (const TopTools_DataMapOfShapeShape & (TNaming_Translator::*)() const ) &TNaming_Translator::Copied, "returns DataMap of results; (shape <-> copied shape)");
	cls_TNaming_Translator.def("DumpMap", [](TNaming_Translator &self) -> void { return self.DumpMap(); });
	cls_TNaming_Translator.def("DumpMap", (void (TNaming_Translator::*)(const Standard_Boolean) const ) &TNaming_Translator::DumpMap, "None", py::arg("isWrite"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_UsedShapes.hxx
	py::class_<TNaming_UsedShapes, opencascade::handle<TNaming_UsedShapes>, TDF_Attribute> cls_TNaming_UsedShapes(mod, "TNaming_UsedShapes", "Global attribute located under root label to store all the shapes handled by the framework Set of Shapes Used in a Data from TDF Only one instance by Data, it always Stored as Attribute of The Root.");
	cls_TNaming_UsedShapes.def("Destroy", (void (TNaming_UsedShapes::*)()) &TNaming_UsedShapes::Destroy, "None");
	cls_TNaming_UsedShapes.def("Map", (TNaming_DataMapOfShapePtrRefShape & (TNaming_UsedShapes::*)()) &TNaming_UsedShapes::Map, "None");
	cls_TNaming_UsedShapes.def("ID", (const Standard_GUID & (TNaming_UsedShapes::*)() const ) &TNaming_UsedShapes::ID, "Returns the ID of the attribute.");
	cls_TNaming_UsedShapes.def_static("GetID_", (const Standard_GUID & (*)()) &TNaming_UsedShapes::GetID, "Returns the ID: 2a96b614-ec8b-11d0-bee7-080009dc3333.");
	cls_TNaming_UsedShapes.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TNaming_UsedShapes::*)() const ) &TNaming_UsedShapes::BackupCopy, "Copies the attribute contents into a new other attribute. It is used by Backup().");
	cls_TNaming_UsedShapes.def("Restore", (void (TNaming_UsedShapes::*)(const opencascade::handle<TDF_Attribute> &)) &TNaming_UsedShapes::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
	cls_TNaming_UsedShapes.def("BeforeRemoval", (void (TNaming_UsedShapes::*)()) &TNaming_UsedShapes::BeforeRemoval, "Clears the table.");
	cls_TNaming_UsedShapes.def("AfterUndo", [](TNaming_UsedShapes &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); }, py::arg("anAttDelta"));
	cls_TNaming_UsedShapes.def("AfterUndo", (Standard_Boolean (TNaming_UsedShapes::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TNaming_UsedShapes::AfterUndo, "Something to do after applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TNaming_UsedShapes.def("DeltaOnAddition", (opencascade::handle<TDF_DeltaOnAddition> (TNaming_UsedShapes::*)() const ) &TNaming_UsedShapes::DeltaOnAddition, "this method returns a null handle (no delta).");
	cls_TNaming_UsedShapes.def("DeltaOnRemoval", (opencascade::handle<TDF_DeltaOnRemoval> (TNaming_UsedShapes::*)() const ) &TNaming_UsedShapes::DeltaOnRemoval, "this method returns a null handle (no delta).");
	cls_TNaming_UsedShapes.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TNaming_UsedShapes::*)() const ) &TNaming_UsedShapes::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
	cls_TNaming_UsedShapes.def("Paste", (void (TNaming_UsedShapes::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TNaming_UsedShapes::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
	cls_TNaming_UsedShapes.def("References", (void (TNaming_UsedShapes::*)(const opencascade::handle<TDF_DataSet> &) const ) &TNaming_UsedShapes::References, "Adds the directly referenced attributes and labels to <aDataSet>. 'Directly' means we have only to look at the first level of references.", py::arg("aDataSet"));
	// FIXME cls_TNaming_UsedShapes.def("Dump", (Standard_OStream & (TNaming_UsedShapes::*)(Standard_OStream &) const ) &TNaming_UsedShapes::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
	cls_TNaming_UsedShapes.def_static("get_type_name_", (const char * (*)()) &TNaming_UsedShapes::get_type_name, "None");
	cls_TNaming_UsedShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_UsedShapes::get_type_descriptor, "None");
	cls_TNaming_UsedShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_UsedShapes::*)() const ) &TNaming_UsedShapes::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Tool.hxx
	py::class_<TNaming_Tool, std::unique_ptr<TNaming_Tool, Deleter<TNaming_Tool>>> cls_TNaming_Tool(mod, "TNaming_Tool", "A tool to get information on the topology of a named shape attribute. This information is typically a TopoDS_Shape object. Using this tool, relations between named shapes are also accessible.");
	cls_TNaming_Tool.def(py::init<>());
	cls_TNaming_Tool.def_static("CurrentShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::CurrentShape, "Returns the last Modification of <NS>. Returns the shape CurrentShape contained in the named shape attribute NS. CurrentShape is the current state of the entities if they have been modified in other attributes of the same data structure. Each call to this function creates a new compound.", py::arg("NS"));
	cls_TNaming_Tool.def_static("CurrentShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &, const TDF_LabelMap &)) &TNaming_Tool::CurrentShape, "Returns the shape CurrentShape contained in the named shape attribute NS, and present in the updated attribute map Updated. CurrentShape is the current state of the entities if they have been modified in other attributes of the same data structure. Each call to this function creates a new compound. Warning Only the contents of Updated are searched.R", py::arg("NS"), py::arg("Updated"));
	cls_TNaming_Tool.def_static("CurrentNamedShape_", (opencascade::handle<TNaming_NamedShape> (*)(const opencascade::handle<TNaming_NamedShape> &, const TDF_LabelMap &)) &TNaming_Tool::CurrentNamedShape, "Returns the NamedShape of the last Modification of <NS>. This shape is identified by a label.", py::arg("NS"), py::arg("Updated"));
	cls_TNaming_Tool.def_static("CurrentNamedShape_", (opencascade::handle<TNaming_NamedShape> (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::CurrentNamedShape, "Returns NamedShape the last Modification of <NS>.", py::arg("NS"));
	cls_TNaming_Tool.def_static("NamedShape_", (opencascade::handle<TNaming_NamedShape> (*)(const TopoDS_Shape &, const TDF_Label &)) &TNaming_Tool::NamedShape, "Returns the named shape attribute defined by the shape aShape and the label anAccess. This attribute is returned as a new shape. You call this function, if you need to create a topological attribute for existing data. Example class MyPkg_MyClass { public: Standard_Boolean SameEdge(const Handle(OCafTest_Line)& , const Handle(CafTest_Line)& ); };", py::arg("aShape"), py::arg("anAcces"));
	cls_TNaming_Tool.def_static("GetShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::GetShape, "Returns the entities stored in the named shape attribute NS. If there is only one old-new pair, the new shape is returned. Otherwise, a Compound is returned. This compound is made out of all the new shapes found. Each call to this function creates a new compound.", py::arg("NS"));
	cls_TNaming_Tool.def_static("OriginalShape_", (TopoDS_Shape (*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::OriginalShape, "Returns the shape contained as OldShape in <NS>", py::arg("NS"));
	cls_TNaming_Tool.def_static("GeneratedShape_", (TopoDS_Shape (*)(const TopoDS_Shape &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Tool::GeneratedShape, "Returns the shape generated from S or by a modification of S and contained in the named shape Generation.", py::arg("S"), py::arg("Generation"));
	cls_TNaming_Tool.def_static("Collect_", [](const opencascade::handle<TNaming_NamedShape> & a0, TNaming_MapOfNamedShape & a1) -> void { return TNaming_Tool::Collect(a0, a1); }, py::arg("NS"), py::arg("Labels"));
	cls_TNaming_Tool.def_static("Collect_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, TNaming_MapOfNamedShape &, const Standard_Boolean)) &TNaming_Tool::Collect, "None", py::arg("NS"), py::arg("Labels"), py::arg("OnlyModif"));
	cls_TNaming_Tool.def_static("HasLabel_", (Standard_Boolean (*)(const TDF_Label &, const TopoDS_Shape &)) &TNaming_Tool::HasLabel, "Returns True if <aShape> appears under a label.(DP)", py::arg("access"), py::arg("aShape"));
	cls_TNaming_Tool.def_static("Label_", [](const TDF_Label & access, const TopoDS_Shape & aShape, Standard_Integer & TransDef){ TDF_Label rv = TNaming_Tool::Label(access, aShape, TransDef); return std::tuple<TDF_Label, Standard_Integer &>(rv, TransDef); }, "Returns the label of the first apparition of <aShape>. Transdef is a value of the transaction of the first apparition of <aShape>.", py::arg("access"), py::arg("aShape"), py::arg("TransDef"));
	cls_TNaming_Tool.def_static("InitialShape_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TDF_Label &, TDF_LabelList &)) &TNaming_Tool::InitialShape, "Returns the shape created from the shape aShape contained in the attribute anAcces.", py::arg("aShape"), py::arg("anAcces"), py::arg("Labels"));
	cls_TNaming_Tool.def_static("ValidUntil_", (Standard_Integer (*)(const TDF_Label &, const TopoDS_Shape &)) &TNaming_Tool::ValidUntil, "Returns the last transaction where the creation of S is valid.", py::arg("access"), py::arg("S"));
	cls_TNaming_Tool.def_static("FindShape_", (void (*)(const TDF_LabelMap &, const TDF_LabelMap &, const opencascade::handle<TNaming_NamedShape> &, TopoDS_Shape &)) &TNaming_Tool::FindShape, "Returns the current shape (a Wire or a Shell) built (in the data framework) from the the shapes of the argument named shape. It is used for IDENTITY name type computation.", py::arg("Valid"), py::arg("Forbiden"), py::arg("Arg"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_SameShapeIterator.hxx
	py::class_<TNaming_SameShapeIterator, std::unique_ptr<TNaming_SameShapeIterator, Deleter<TNaming_SameShapeIterator>>> cls_TNaming_SameShapeIterator(mod, "TNaming_SameShapeIterator", "To iterate on all the label which contained a given shape.");
	cls_TNaming_SameShapeIterator.def(py::init<const TopoDS_Shape &, const TDF_Label &>(), py::arg("aShape"), py::arg("access"));
	cls_TNaming_SameShapeIterator.def("More", (Standard_Boolean (TNaming_SameShapeIterator::*)() const ) &TNaming_SameShapeIterator::More, "None");
	cls_TNaming_SameShapeIterator.def("Next", (void (TNaming_SameShapeIterator::*)()) &TNaming_SameShapeIterator::Next, "None");
	cls_TNaming_SameShapeIterator.def("Label", (TDF_Label (TNaming_SameShapeIterator::*)() const ) &TNaming_SameShapeIterator::Label, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Selector.hxx
	py::class_<TNaming_Selector, std::unique_ptr<TNaming_Selector, Deleter<TNaming_Selector>>> cls_TNaming_Selector(mod, "TNaming_Selector", "This class provides a single API for selection of shapes. This involves both identification and selection of shapes in the data framework. If the selected shape is modified, this selector will solve its identifications. This class is the user interface for topological naming resources. * The <IsIdentified> method returns (if exists) the NamedShape which contains a given shape. The definition of an identified shape is : a Shape handled by a NamedShape (this shape is the only one stored) , which has the TNaming_PRImITIVE evolution");
	cls_TNaming_Selector.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
	cls_TNaming_Selector.def_static("IsIdentified_", [](const TDF_Label & a0, const TopoDS_Shape & a1, opencascade::handle<TNaming_NamedShape> & a2) -> Standard_Boolean { return TNaming_Selector::IsIdentified(a0, a1, a2); }, py::arg("access"), py::arg("selection"), py::arg("NS"));
	cls_TNaming_Selector.def_static("IsIdentified_", (Standard_Boolean (*)(const TDF_Label &, const TopoDS_Shape &, opencascade::handle<TNaming_NamedShape> &, const Standard_Boolean)) &TNaming_Selector::IsIdentified, "To know if a shape is already identified (not selected) =======================================================", py::arg("access"), py::arg("selection"), py::arg("NS"), py::arg("Geometry"));
	cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> Standard_Boolean { return self.Select(a0, a1); }, py::arg("Selection"), py::arg("Context"));
	cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Boolean { return self.Select(a0, a1, a2); }, py::arg("Selection"), py::arg("Context"), py::arg("Geometry"));
	cls_TNaming_Selector.def("Select", (Standard_Boolean (TNaming_Selector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean) const ) &TNaming_Selector::Select, "Creates a topological naming on the label aLabel given as an argument at construction time. If successful, the shape Selection - found in the shape Context - is now identified in the named shape returned in NamedShape. If Geometry is true, NamedShape contains the first appearance of Selection. This syntax is more robust than the previous syntax for this method.", py::arg("Selection"), py::arg("Context"), py::arg("Geometry"), py::arg("KeepOrientatation"));
	cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.Select(a0); }, py::arg("Selection"));
	cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.Select(a0, a1); }, py::arg("Selection"), py::arg("Geometry"));
	cls_TNaming_Selector.def("Select", (Standard_Boolean (TNaming_Selector::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean) const ) &TNaming_Selector::Select, "Creates a topological naming on the label aLabel given as an argument at construction time. If successful, the shape Selection is now identified in the named shape returned in NamedShape. If Geometry is true, NamedShape contains the first appearance of Selection.", py::arg("Selection"), py::arg("Geometry"), py::arg("KeepOrientatation"));
	cls_TNaming_Selector.def("Solve", (Standard_Boolean (TNaming_Selector::*)(TDF_LabelMap &) const ) &TNaming_Selector::Solve, "Updates the topological naming on the label aLabel given as an argument at construction time. The underlying shape returned in the method NamedShape is updated. To read this shape, use the method TNaming_Tool::GetShape", py::arg("Valid"));
	cls_TNaming_Selector.def("Arguments", (void (TNaming_Selector::*)(TDF_AttributeMap &) const ) &TNaming_Selector::Arguments, "Returns the attribute list args. This list contains the named shape on which the topological naming was built.", py::arg("args"));
	cls_TNaming_Selector.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_Selector::*)() const ) &TNaming_Selector::NamedShape, "Returns the NamedShape build or under construction, which contains the topological naming..");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_DeltaOnRemoval.hxx
	py::class_<TNaming_DeltaOnRemoval, opencascade::handle<TNaming_DeltaOnRemoval>, TDF_DeltaOnRemoval> cls_TNaming_DeltaOnRemoval(mod, "TNaming_DeltaOnRemoval", "None");
	cls_TNaming_DeltaOnRemoval.def(py::init<const opencascade::handle<TNaming_NamedShape> &>(), py::arg("NS"));
	cls_TNaming_DeltaOnRemoval.def("Apply", (void (TNaming_DeltaOnRemoval::*)()) &TNaming_DeltaOnRemoval::Apply, "Applies the delta to the attribute.");
	cls_TNaming_DeltaOnRemoval.def_static("get_type_name_", (const char * (*)()) &TNaming_DeltaOnRemoval::get_type_name, "None");
	cls_TNaming_DeltaOnRemoval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_DeltaOnRemoval::get_type_descriptor, "None");
	cls_TNaming_DeltaOnRemoval.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_DeltaOnRemoval::*)() const ) &TNaming_DeltaOnRemoval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_DeltaOnModification.hxx
	py::class_<TNaming_DeltaOnModification, opencascade::handle<TNaming_DeltaOnModification>, TDF_DeltaOnModification> cls_TNaming_DeltaOnModification(mod, "TNaming_DeltaOnModification", "This class provides default services for an AttributeDelta on a MODIFICATION action.");
	cls_TNaming_DeltaOnModification.def(py::init<const opencascade::handle<TNaming_NamedShape> &>(), py::arg("NS"));
	cls_TNaming_DeltaOnModification.def("Apply", (void (TNaming_DeltaOnModification::*)()) &TNaming_DeltaOnModification::Apply, "Applies the delta to the attribute.");
	cls_TNaming_DeltaOnModification.def_static("get_type_name_", (const char * (*)()) &TNaming_DeltaOnModification::get_type_name, "None");
	cls_TNaming_DeltaOnModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_DeltaOnModification::get_type_descriptor, "None");
	cls_TNaming_DeltaOnModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_DeltaOnModification::*)() const ) &TNaming_DeltaOnModification::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_RefShape.hxx
	py::class_<TNaming_RefShape, std::unique_ptr<TNaming_RefShape, Deleter<TNaming_RefShape>>> cls_TNaming_RefShape(mod, "TNaming_RefShape", "None");
	cls_TNaming_RefShape.def(py::init<>());
	cls_TNaming_RefShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_TNaming_RefShape.def("Shape", (void (TNaming_RefShape::*)(const TopoDS_Shape &)) &TNaming_RefShape::Shape, "None", py::arg("S"));
	cls_TNaming_RefShape.def("FirstUse", (void (TNaming_RefShape::*)(const TNaming_PtrNode &)) &TNaming_RefShape::FirstUse, "None", py::arg("aPtr"));
	cls_TNaming_RefShape.def("FirstUse", (TNaming_PtrNode (TNaming_RefShape::*)() const ) &TNaming_RefShape::FirstUse, "None");
	cls_TNaming_RefShape.def("Shape", (const TopoDS_Shape & (TNaming_RefShape::*)() const ) &TNaming_RefShape::Shape, "None");
	cls_TNaming_RefShape.def("Label", (TDF_Label (TNaming_RefShape::*)() const ) &TNaming_RefShape::Label, "None");
	cls_TNaming_RefShape.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_RefShape::*)() const ) &TNaming_RefShape::NamedShape, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Scope.hxx
	py::class_<TNaming_Scope, std::unique_ptr<TNaming_Scope, Deleter<TNaming_Scope>>> cls_TNaming_Scope(mod, "TNaming_Scope", "this class manage a scope of labels ===================================");
	cls_TNaming_Scope.def(py::init<>());
	cls_TNaming_Scope.def(py::init<const Standard_Boolean>(), py::arg("WithValid"));
	cls_TNaming_Scope.def(py::init<TDF_LabelMap &>(), py::arg("valid"));
	cls_TNaming_Scope.def("WithValid", (Standard_Boolean (TNaming_Scope::*)() const ) &TNaming_Scope::WithValid, "None");
	cls_TNaming_Scope.def("WithValid", (void (TNaming_Scope::*)(const Standard_Boolean)) &TNaming_Scope::WithValid, "None", py::arg("mode"));
	cls_TNaming_Scope.def("ClearValid", (void (TNaming_Scope::*)()) &TNaming_Scope::ClearValid, "None");
	cls_TNaming_Scope.def("Valid", (void (TNaming_Scope::*)(const TDF_Label &)) &TNaming_Scope::Valid, "None", py::arg("L"));
	cls_TNaming_Scope.def("ValidChildren", [](TNaming_Scope &self, const TDF_Label & a0) -> void { return self.ValidChildren(a0); }, py::arg("L"));
	cls_TNaming_Scope.def("ValidChildren", (void (TNaming_Scope::*)(const TDF_Label &, const Standard_Boolean)) &TNaming_Scope::ValidChildren, "None", py::arg("L"), py::arg("withroot"));
	cls_TNaming_Scope.def("Unvalid", (void (TNaming_Scope::*)(const TDF_Label &)) &TNaming_Scope::Unvalid, "None", py::arg("L"));
	cls_TNaming_Scope.def("UnvalidChildren", [](TNaming_Scope &self, const TDF_Label & a0) -> void { return self.UnvalidChildren(a0); }, py::arg("L"));
	cls_TNaming_Scope.def("UnvalidChildren", (void (TNaming_Scope::*)(const TDF_Label &, const Standard_Boolean)) &TNaming_Scope::UnvalidChildren, "None", py::arg("L"), py::arg("withroot"));
	cls_TNaming_Scope.def("IsValid", (Standard_Boolean (TNaming_Scope::*)(const TDF_Label &) const ) &TNaming_Scope::IsValid, "None", py::arg("L"));
	cls_TNaming_Scope.def("GetValid", (const TDF_LabelMap & (TNaming_Scope::*)() const ) &TNaming_Scope::GetValid, "None");
	cls_TNaming_Scope.def("ChangeValid", (TDF_LabelMap & (TNaming_Scope::*)()) &TNaming_Scope::ChangeValid, "None");
	cls_TNaming_Scope.def("CurrentShape", (TopoDS_Shape (TNaming_Scope::*)(const opencascade::handle<TNaming_NamedShape> &) const ) &TNaming_Scope::CurrentShape, "Returns the current value of <NS> according to the Valid Scope.", py::arg("NS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Identifier.hxx
	py::class_<TNaming_Identifier, std::unique_ptr<TNaming_Identifier, Deleter<TNaming_Identifier>>> cls_TNaming_Identifier(mod, "TNaming_Identifier", "None");
	cls_TNaming_Identifier.def(py::init<const TDF_Label &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Lab"), py::arg("S"), py::arg("Context"), py::arg("Geom"));
	cls_TNaming_Identifier.def(py::init<const TDF_Label &, const TopoDS_Shape &, const opencascade::handle<TNaming_NamedShape> &, const Standard_Boolean>(), py::arg("Lab"), py::arg("S"), py::arg("ContextNS"), py::arg("Geom"));
	cls_TNaming_Identifier.def("IsDone", (Standard_Boolean (TNaming_Identifier::*)() const ) &TNaming_Identifier::IsDone, "None");
	cls_TNaming_Identifier.def("Type", (TNaming_NameType (TNaming_Identifier::*)() const ) &TNaming_Identifier::Type, "None");
	cls_TNaming_Identifier.def("IsFeature", (Standard_Boolean (TNaming_Identifier::*)()) &TNaming_Identifier::IsFeature, "None");
	cls_TNaming_Identifier.def("Feature", (opencascade::handle<TNaming_NamedShape> (TNaming_Identifier::*)() const ) &TNaming_Identifier::Feature, "None");
	cls_TNaming_Identifier.def("InitArgs", (void (TNaming_Identifier::*)()) &TNaming_Identifier::InitArgs, "None");
	cls_TNaming_Identifier.def("MoreArgs", (Standard_Boolean (TNaming_Identifier::*)() const ) &TNaming_Identifier::MoreArgs, "None");
	cls_TNaming_Identifier.def("NextArg", (void (TNaming_Identifier::*)()) &TNaming_Identifier::NextArg, "None");
	cls_TNaming_Identifier.def("ArgIsFeature", (Standard_Boolean (TNaming_Identifier::*)() const ) &TNaming_Identifier::ArgIsFeature, "None");
	cls_TNaming_Identifier.def("FeatureArg", (opencascade::handle<TNaming_NamedShape> (TNaming_Identifier::*)()) &TNaming_Identifier::FeatureArg, "None");
	cls_TNaming_Identifier.def("ShapeArg", (TopoDS_Shape (TNaming_Identifier::*)()) &TNaming_Identifier::ShapeArg, "None");
	cls_TNaming_Identifier.def("ShapeContext", (TopoDS_Shape (TNaming_Identifier::*)() const ) &TNaming_Identifier::ShapeContext, "None");
	cls_TNaming_Identifier.def("NamedShapeOfGeneration", (opencascade::handle<TNaming_NamedShape> (TNaming_Identifier::*)() const ) &TNaming_Identifier::NamedShapeOfGeneration, "None");
	cls_TNaming_Identifier.def("AncestorIdentification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const TopoDS_Shape &)) &TNaming_Identifier::AncestorIdentification, "None", py::arg("Localizer"), py::arg("Context"));
	cls_TNaming_Identifier.def("PrimitiveIdentification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Identifier::PrimitiveIdentification, "None", py::arg("Localizer"), py::arg("NS"));
	cls_TNaming_Identifier.def("GeneratedIdentification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Identifier::GeneratedIdentification, "None", py::arg("Localizer"), py::arg("NS"));
	cls_TNaming_Identifier.def("Identification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Identifier::Identification, "None", py::arg("Localizer"), py::arg("NS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_Localizer.hxx
	py::class_<TNaming_Localizer, std::unique_ptr<TNaming_Localizer, Deleter<TNaming_Localizer>>> cls_TNaming_Localizer(mod, "TNaming_Localizer", "None");
	cls_TNaming_Localizer.def(py::init<>());
	cls_TNaming_Localizer.def("Init", (void (TNaming_Localizer::*)(const opencascade::handle<TNaming_UsedShapes> &, const Standard_Integer)) &TNaming_Localizer::Init, "None", py::arg("US"), py::arg("CurTrans"));
	cls_TNaming_Localizer.def("SubShapes", (const TopTools_MapOfShape & (TNaming_Localizer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TNaming_Localizer::SubShapes, "None", py::arg("S"), py::arg("Type"));
	cls_TNaming_Localizer.def("Ancestors", (const TopTools_IndexedDataMapOfShapeListOfShape & (TNaming_Localizer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TNaming_Localizer::Ancestors, "None", py::arg("S"), py::arg("Type"));
	cls_TNaming_Localizer.def("FindFeaturesInAncestors", (void (TNaming_Localizer::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_MapOfShape &)) &TNaming_Localizer::FindFeaturesInAncestors, "None", py::arg("S"), py::arg("In"), py::arg("AncInFeatures"));
	cls_TNaming_Localizer.def("GoBack", (void (TNaming_Localizer::*)(const TopoDS_Shape &, const TDF_Label &, const TNaming_Evolution, TopTools_ListOfShape &, TNaming_ListOfNamedShape &)) &TNaming_Localizer::GoBack, "None", py::arg("S"), py::arg("Lab"), py::arg("Evol"), py::arg("OldS"), py::arg("OldLab"));
	cls_TNaming_Localizer.def("Backward", (void (TNaming_Localizer::*)(const opencascade::handle<TNaming_NamedShape> &, const TopoDS_Shape &, TNaming_MapOfNamedShape &, TopTools_MapOfShape &)) &TNaming_Localizer::Backward, "None", py::arg("NS"), py::arg("S"), py::arg("Primitives"), py::arg("ValidShapes"));
	cls_TNaming_Localizer.def("FindNeighbourg", (void (TNaming_Localizer::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_MapOfShape &)) &TNaming_Localizer::FindNeighbourg, "None", py::arg("Cont"), py::arg("S"), py::arg("Neighbourg"));
	cls_TNaming_Localizer.def_static("IsNew_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Localizer::IsNew, "None", py::arg("S"), py::arg("NS"));
	cls_TNaming_Localizer.def_static("FindGenerator_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TNaming_Localizer::FindGenerator, "None", py::arg("NS"), py::arg("S"), py::arg("theListOfGenerators"));
	cls_TNaming_Localizer.def_static("FindShapeContext_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, const TopoDS_Shape &, TopoDS_Shape &)) &TNaming_Localizer::FindShapeContext, "Finds context of the shape <S>.", py::arg("NS"), py::arg("theS"), py::arg("theSC"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ShapesSet.hxx
	py::class_<TNaming_ShapesSet, std::unique_ptr<TNaming_ShapesSet, Deleter<TNaming_ShapesSet>>> cls_TNaming_ShapesSet(mod, "TNaming_ShapesSet", "None");
	cls_TNaming_ShapesSet.def(py::init<>());
	cls_TNaming_ShapesSet.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_TNaming_ShapesSet.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("Type"));
	cls_TNaming_ShapesSet.def("Clear", (void (TNaming_ShapesSet::*)()) &TNaming_ShapesSet::Clear, "Removes all Shapes");
	cls_TNaming_ShapesSet.def("Add", (Standard_Boolean (TNaming_ShapesSet::*)(const TopoDS_Shape &)) &TNaming_ShapesSet::Add, "Adds the Shape <S>", py::arg("S"));
	cls_TNaming_ShapesSet.def("Contains", (Standard_Boolean (TNaming_ShapesSet::*)(const TopoDS_Shape &) const ) &TNaming_ShapesSet::Contains, "Returns True if <S> is in <me>", py::arg("S"));
	cls_TNaming_ShapesSet.def("Remove", (Standard_Boolean (TNaming_ShapesSet::*)(const TopoDS_Shape &)) &TNaming_ShapesSet::Remove, "Removes <S> in <me>.", py::arg("S"));
	cls_TNaming_ShapesSet.def("Add", (void (TNaming_ShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_ShapesSet::Add, "Adds the shapes contained in <Shapes>.", py::arg("Shapes"));
	cls_TNaming_ShapesSet.def("Filter", (void (TNaming_ShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_ShapesSet::Filter, "Erases in <me> the shapes not contained in <Shapes>", py::arg("Shapes"));
	cls_TNaming_ShapesSet.def("Remove", (void (TNaming_ShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_ShapesSet::Remove, "Removes in <me> the shapes contained in <Shapes>", py::arg("Shapes"));
	cls_TNaming_ShapesSet.def("IsEmpty", (Standard_Boolean (TNaming_ShapesSet::*)() const ) &TNaming_ShapesSet::IsEmpty, "None");
	cls_TNaming_ShapesSet.def("NbShapes", (Standard_Integer (TNaming_ShapesSet::*)() const ) &TNaming_ShapesSet::NbShapes, "None");
	cls_TNaming_ShapesSet.def("ChangeMap", (TopTools_MapOfShape & (TNaming_ShapesSet::*)()) &TNaming_ShapesSet::ChangeMap, "None");
	cls_TNaming_ShapesSet.def("Map", (const TopTools_MapOfShape & (TNaming_ShapesSet::*)() const ) &TNaming_ShapesSet::Map, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_IteratorOnShapesSet.hxx
	py::class_<TNaming_IteratorOnShapesSet, std::unique_ptr<TNaming_IteratorOnShapesSet, Deleter<TNaming_IteratorOnShapesSet>>> cls_TNaming_IteratorOnShapesSet(mod, "TNaming_IteratorOnShapesSet", "None");
	cls_TNaming_IteratorOnShapesSet.def(py::init<>());
	cls_TNaming_IteratorOnShapesSet.def(py::init<const TNaming_ShapesSet &>(), py::arg("S"));
	cls_TNaming_IteratorOnShapesSet.def("Init", (void (TNaming_IteratorOnShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_IteratorOnShapesSet::Init, "Initialize the iteration", py::arg("S"));
	cls_TNaming_IteratorOnShapesSet.def("More", (Standard_Boolean (TNaming_IteratorOnShapesSet::*)() const ) &TNaming_IteratorOnShapesSet::More, "Returns True if there is a current Item in the iteration.");
	cls_TNaming_IteratorOnShapesSet.def("Next", (void (TNaming_IteratorOnShapesSet::*)()) &TNaming_IteratorOnShapesSet::Next, "Move to the next Item");
	cls_TNaming_IteratorOnShapesSet.def("Value", (const TopoDS_Shape & (TNaming_IteratorOnShapesSet::*)() const ) &TNaming_IteratorOnShapesSet::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NamingTool.hxx
	py::class_<TNaming_NamingTool, std::unique_ptr<TNaming_NamingTool, Deleter<TNaming_NamingTool>>> cls_TNaming_NamingTool(mod, "TNaming_NamingTool", "None");
	cls_TNaming_NamingTool.def(py::init<>());
	cls_TNaming_NamingTool.def_static("CurrentShape_", (void (*)(const TDF_LabelMap &, const TDF_LabelMap &, const opencascade::handle<TNaming_NamedShape> &, TopTools_IndexedMapOfShape &)) &TNaming_NamingTool::CurrentShape, "None", py::arg("Valid"), py::arg("Forbiden"), py::arg("NS"), py::arg("MS"));
	cls_TNaming_NamingTool.def_static("CurrentShapeFromShape_", (void (*)(const TDF_LabelMap &, const TDF_LabelMap &, const TDF_Label &, const TopoDS_Shape &, TopTools_IndexedMapOfShape &)) &TNaming_NamingTool::CurrentShapeFromShape, "None", py::arg("Valid"), py::arg("Forbiden"), py::arg("Acces"), py::arg("S"), py::arg("MS"));
	cls_TNaming_NamingTool.def_static("BuildDescendants_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, TDF_LabelMap &)) &TNaming_NamingTool::BuildDescendants, "None", py::arg("NS"), py::arg("Labels"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming.hxx
	py::class_<TNaming, std::unique_ptr<TNaming, Deleter<TNaming>>> cls_TNaming(mod, "TNaming", "A topological attribute can be seen as a hook into the topological structure. To this hook, data can be attached and references defined. It is used for keeping and access to topological objects and their evolution. All topological objects are stored in the one user-protected TNaming_UsedShapes attribute at the root label of the data framework. This attribute contains map with all topological shapes, used in this document. To all other labels TNaming_NamedShape attribute can be added. This attribute contains references (hooks) to shapes from the TNaming_UsedShapes attribute and evolution of these shapes. TNaming_NamedShape attribute contains a set of pairs of hooks: old shape and new shape (see the figure below). It allows not only get the topological shapes by the labels, but also trace evolution of the shapes and correctly resolve dependent shapes by the changed one. If shape is just-created, then the old shape for accorded named shape is an empty shape. If a shape is deleted, then the new shape in this named shape is empty. Different algorithms may dispose sub-shapes of the result shape at the individual label depending on necessity: - If a sub-shape must have some extra attributes (material of each face or color of each edge). In this case a specific sub-shape is placed to the separate label (usually, sub-label of the result shape label) with all attributes of this sub-shape. - If topological naming is needed, a necessary and sufficient (for selected sub-shapes identification) set of sub-shapes is placed to the child labels of the result shape label. As usual, as far as basic solids and closed shells are concerned, all faces of the shape are disposed. Edges and vertices sub-shapes can be identified as intersection of contiguous faces. Modified/generated shapes may be placed to one named shape and identified as this named shape and source named shape that also can be identified with used algorithms. TNaming_NamedShape may contain a few pairs of hooks with the same evolution. In this case topology shape, which belongs to the named shape, is a compound of new shapes. The data model contains both the topology and the hooks, and functions handle both topological entities and hooks. Consider the case of a box function, which creates a solid with six faces and six hooks. Each hook is attached to a face. If you want, you can also have this function create hooks for edges and vertices as well as for faces. For the sake of simplicity though, let's limit the example. Not all functions can define explicit hooks for all topological entities they create, but all topological entities can be turned into hooks when necessary. This is where topological naming is necessary.");
	cls_TNaming.def(py::init<>());
	cls_TNaming.def_static("Substitute_", (void (*)(const TDF_Label &, const TDF_Label &, TopTools_DataMapOfShapeShape &)) &TNaming::Substitute, "Subtituter les shapes sur les structures de source vers cible", py::arg("labelsource"), py::arg("labelcible"), py::arg("mapOldNew"));
	cls_TNaming.def_static("Update_", (void (*)(const TDF_Label &, TopTools_DataMapOfShapeShape &)) &TNaming::Update, "Mise a jour des shapes du label et de ses fils en tenant compte des substitutions decrite par mapOldNew.", py::arg("label"), py::arg("mapOldNew"));
	cls_TNaming.def_static("Displace_", [](const TDF_Label & a0, const TopLoc_Location & a1) -> void { return TNaming::Displace(a0, a1); }, py::arg("label"), py::arg("aLocation"));
	cls_TNaming.def_static("Displace_", (void (*)(const TDF_Label &, const TopLoc_Location &, const Standard_Boolean)) &TNaming::Displace, "Application de la Location sur les shapes du label et de ses sous labels.", py::arg("label"), py::arg("aLocation"), py::arg("WithOld"));
	cls_TNaming.def_static("ChangeShapes_", (void (*)(const TDF_Label &, TopTools_DataMapOfShapeShape &)) &TNaming::ChangeShapes, "Remplace les shapes du label et des sous-labels par des copies.", py::arg("label"), py::arg("M"));
	cls_TNaming.def_static("Transform_", (void (*)(const TDF_Label &, const gp_Trsf &)) &TNaming::Transform, "Application de la transformation sur les shapes du label et de ses sous labels. Warning: le remplacement du shape est fait dans tous les attributs qui le contiennent meme si ceux ci ne sont pas associees a des sous-labels de <Label>.", py::arg("label"), py::arg("aTransformation"));
	cls_TNaming.def_static("Replicate_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, const gp_Trsf &, const TDF_Label &)) &TNaming::Replicate, "Replicates the named shape with the transformation <T> on the label <L> (and sub-labels if necessary) (TNaming_GENERATED is set)", py::arg("NS"), py::arg("T"), py::arg("L"));
	cls_TNaming.def_static("Replicate_", (void (*)(const TopoDS_Shape &, const gp_Trsf &, const TDF_Label &)) &TNaming::Replicate, "Replicates the shape with the transformation <T> on the label <L> (and sub-labels if necessary) (TNaming_GENERATED is set)", py::arg("SH"), py::arg("T"), py::arg("L"));
	cls_TNaming.def_static("MakeShape_", (TopoDS_Shape (*)(const TopTools_MapOfShape &)) &TNaming::MakeShape, "Builds shape from map content", py::arg("MS"));
	cls_TNaming.def_static("FindUniqueContext_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TNaming::FindUniqueContext, "Find unique context of shape <S>", py::arg("S"), py::arg("Context"));
	cls_TNaming.def_static("FindUniqueContextSet_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopoDS_Shape &, opencascade::handle<TopTools_HArray1OfShape> &)) &TNaming::FindUniqueContextSet, "Find unique context of shape <S>,which is pure concatenation of atomic shapes (Compound). The result is concatenation of single contexts", py::arg("S"), py::arg("Context"), py::arg("Arr"));
	cls_TNaming.def_static("SubstituteSShape_", (Standard_Boolean (*)(const TDF_Label &, const TopoDS_Shape &, TopoDS_Shape &)) &TNaming::SubstituteSShape, "Subtitutes shape in source structure", py::arg("accesslabel"), py::arg("From"), py::arg("To"));
	cls_TNaming.def_static("OuterWire_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Wire &)) &TNaming::OuterWire, "Returns True if outer wire is found and the found wire in <theWire>.", py::arg("theFace"), py::arg("theWire"));
	cls_TNaming.def_static("OuterShell_", (Standard_Boolean (*)(const TopoDS_Solid &, TopoDS_Shell &)) &TNaming::OuterShell, "Returns True if outer Shell is found and the found shell in <theShell>. Print of TNaming enumeration =============================", py::arg("theSolid"), py::arg("theShell"));
	cls_TNaming.def_static("IDList_", (void (*)(TDF_IDList &)) &TNaming::IDList, "Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use.", py::arg("anIDList"));
	cls_TNaming.def_static("Print_", (Standard_OStream & (*)(const TNaming_Evolution, Standard_OStream &)) &TNaming::Print, "Prints the evolution <EVOL> as a String on the Stream <S> and returns <S>.", py::arg("EVOL"), py::arg("S"));
	cls_TNaming.def_static("Print_", (Standard_OStream & (*)(const TNaming_NameType, Standard_OStream &)) &TNaming::Print, "Prints the name of name type <NAME> as a String on the Stream <S> and returns <S>.", py::arg("NAME"), py::arg("S"));
	cls_TNaming.def_static("Print_", (Standard_OStream & (*)(const TDF_Label &, Standard_OStream &)) &TNaming::Print, "Prints the content of UsedShapes private attribute as a String Table on the Stream <S> and returns <S>.", py::arg("ACCESS"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_PtrNode.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ListOfNamedShape.hxx
	bind_NCollection_List<opencascade::handle<TNaming_NamedShape> >(mod, "TNaming_ListOfNamedShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ListOfNamedShape.hxx
	bind_NCollection_TListIterator<opencascade::handle<TNaming_NamedShape> >(mod, "TNaming_ListIteratorOfListOfNamedShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_PtrRefShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_DataMapOfShapePtrRefShape.hxx
	bind_NCollection_DataMap<TopoDS_Shape, TNaming_RefShape *, TopTools_ShapeMapHasher>(mod, "TNaming_DataMapOfShapePtrRefShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_DataMapOfShapeShapesSet.hxx
	bind_NCollection_DataMap<TopoDS_Shape, TNaming_ShapesSet, TopTools_ShapeMapHasher>(mod, "TNaming_DataMapOfShapeShapesSet");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ListOfIndexedDataMapOfShapeListOfShape.hxx
	bind_NCollection_List<NCollection_IndexedDataMap<TopoDS_Shape, NCollection_List<TopoDS_Shape>, TopTools_ShapeMapHasher> >(mod, "TNaming_ListOfIndexedDataMapOfShapeListOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ListOfIndexedDataMapOfShapeListOfShape.hxx
	bind_NCollection_TListIterator<NCollection_IndexedDataMap<TopoDS_Shape, NCollection_List<TopoDS_Shape>, TopTools_ShapeMapHasher> >(mod, "TNaming_ListIteratorOfListOfIndexedDataMapOfShapeListOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ListOfMapOfShape.hxx
	bind_NCollection_List<NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher> >(mod, "TNaming_ListOfMapOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_ListOfMapOfShape.hxx
	bind_NCollection_TListIterator<NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher> >(mod, "TNaming_ListIteratorOfListOfMapOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NamedShapeHasher.hxx
	bind_NCollection_DefaultHasher<opencascade::handle<TNaming_NamedShape> >(mod, "TNaming_NamedShapeHasher");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_MapOfNamedShape.hxx
	bind_NCollection_Map<opencascade::handle<TNaming_NamedShape>, NCollection_DefaultHasher<opencascade::handle<TNaming_NamedShape> > >(mod, "TNaming_MapOfNamedShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NCollections.hxx
	bind_NCollection_Map<TopoDS_Shape, NCollection_DefaultHasher<TopoDS_Shape> >(mod, "TNaming_MapOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NCollections.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NCollections.hxx
	bind_NCollection_DataMap<TopoDS_Shape, NCollection_Map<TopoDS_Shape, NCollection_DefaultHasher<TopoDS_Shape> >, NCollection_DefaultHasher<TopoDS_Shape> >(mod, "TNaming_DataMapOfShapeMapOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_NCollections.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TNaming_PtrAttribute.hxx

}
