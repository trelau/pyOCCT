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

#include <TransferBRep_BinderOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TransferBRep_ShapeBinder.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TransferBRep_TransferResultInfo.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TransferBRep_SequenceOfTransferResultInfo.hxx>
#include <TransferBRep_HSequenceOfTransferResultInfo.hxx>
#include <Transfer_Finder.hxx>
#include <TransferBRep_ShapeMapper.hxx>
#include <Interface_Protocol.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_CheckIterator.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TransferBRep_Reader.hxx>
#include <TransferBRep_ShapeInfo.hxx>
#include <Transfer_Binder.hxx>
#include <TransferBRep_ShapeListBinder.hxx>
#include <TransferBRep_OrientedShapeMapper.hxx>
#include <TopAbs_Orientation.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Message_Printer.hxx>
#include <Message_Msg.hxx>
#include <TransferBRep.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TransferBRep, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Transfer");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Message");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_BinderOfShape.hxx
	py::class_<TransferBRep_BinderOfShape, opencascade::handle<TransferBRep_BinderOfShape>, Transfer_Binder> cls_TransferBRep_BinderOfShape(mod, "TransferBRep_BinderOfShape", "Allows direct binding between a starting Object and the Result of its transfer when it is Unique. The Result itself is defined as a formal parameter <Shape from TopoDS> Warning : While it is possible to instantiate BinderOfShape with any Type for the Result, it is not advisable to instantiate it with Transient Classes, because such Results are directly known and managed by TransferProcess & Co, through SimpleBinderOfTransient : this class looks like instantiation of BinderOfShape, but its method ResultType is adapted (reads DynamicType of the Result)");
	cls_TransferBRep_BinderOfShape.def(py::init<>());
	cls_TransferBRep_BinderOfShape.def(py::init<const TopoDS_Shape &>(), py::arg("res"));
	cls_TransferBRep_BinderOfShape.def("ResultType", (opencascade::handle<Standard_Type> (TransferBRep_BinderOfShape::*)() const ) &TransferBRep_BinderOfShape::ResultType, "Returns the Type permitted for the Result, i.e. the Type of the Parameter Class <Shape from TopoDS> (statically defined)");
	cls_TransferBRep_BinderOfShape.def("ResultTypeName", (Standard_CString (TransferBRep_BinderOfShape::*)() const ) &TransferBRep_BinderOfShape::ResultTypeName, "Returns the Type Name computed for the Result (dynamic)");
	cls_TransferBRep_BinderOfShape.def("SetResult", (void (TransferBRep_BinderOfShape::*)(const TopoDS_Shape &)) &TransferBRep_BinderOfShape::SetResult, "Defines the Result", py::arg("res"));
	cls_TransferBRep_BinderOfShape.def("Result", (const TopoDS_Shape & (TransferBRep_BinderOfShape::*)() const ) &TransferBRep_BinderOfShape::Result, "Returns the defined Result, if there is one");
	cls_TransferBRep_BinderOfShape.def("CResult", (TopoDS_Shape & (TransferBRep_BinderOfShape::*)()) &TransferBRep_BinderOfShape::CResult, "Returns the defined Result, if there is one, and allows to change it (avoids Result + SetResult). Admits that Result can be not yet defined Warning : a call to CResult causes Result to be known as defined");
	cls_TransferBRep_BinderOfShape.def_static("get_type_name_", (const char * (*)()) &TransferBRep_BinderOfShape::get_type_name, "None");
	cls_TransferBRep_BinderOfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_BinderOfShape::get_type_descriptor, "None");
	cls_TransferBRep_BinderOfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_BinderOfShape::*)() const ) &TransferBRep_BinderOfShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_TransferResultInfo.hxx
	py::class_<TransferBRep_TransferResultInfo, opencascade::handle<TransferBRep_TransferResultInfo>, Standard_Transient> cls_TransferBRep_TransferResultInfo(mod, "TransferBRep_TransferResultInfo", "Data structure for storing information on transfer result. At the moment it dispatches information for the following types: - result, - result + warning(s), - result + fail(s), - result + warning(s) + fail(s) - no result, - no result + warning(s), - no result + fail(s), - no result + warning(s) + fail(s),");
	cls_TransferBRep_TransferResultInfo.def(py::init<>());
	cls_TransferBRep_TransferResultInfo.def("Clear", (void (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::Clear, "Resets all the fields.");
	cls_TransferBRep_TransferResultInfo.def("Result", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::Result, "None");
	cls_TransferBRep_TransferResultInfo.def("ResultWarning", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::ResultWarning, "None");
	cls_TransferBRep_TransferResultInfo.def("ResultFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::ResultFail, "None");
	cls_TransferBRep_TransferResultInfo.def("ResultWarningFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::ResultWarningFail, "None");
	cls_TransferBRep_TransferResultInfo.def("NoResult", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResult, "None");
	cls_TransferBRep_TransferResultInfo.def("NoResultWarning", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResultWarning, "None");
	cls_TransferBRep_TransferResultInfo.def("NoResultFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResultFail, "None");
	cls_TransferBRep_TransferResultInfo.def("NoResultWarningFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResultWarningFail, "None");
	cls_TransferBRep_TransferResultInfo.def_static("get_type_name_", (const char * (*)()) &TransferBRep_TransferResultInfo::get_type_name, "None");
	cls_TransferBRep_TransferResultInfo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_TransferResultInfo::get_type_descriptor, "None");
	cls_TransferBRep_TransferResultInfo.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_TransferResultInfo::*)() const ) &TransferBRep_TransferResultInfo::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_SequenceOfTransferResultInfo.hxx
	bind_NCollection_Sequence<opencascade::handle<TransferBRep_TransferResultInfo> >(mod, "TransferBRep_SequenceOfTransferResultInfo");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_ShapeMapper.hxx
	py::class_<TransferBRep_ShapeMapper, opencascade::handle<TransferBRep_ShapeMapper>, Transfer_Finder> cls_TransferBRep_ShapeMapper(mod, "TransferBRep_ShapeMapper", "None");
	cls_TransferBRep_ShapeMapper.def(py::init<const TopoDS_Shape &>(), py::arg("akey"));
	cls_TransferBRep_ShapeMapper.def("Value", (const TopoDS_Shape & (TransferBRep_ShapeMapper::*)() const ) &TransferBRep_ShapeMapper::Value, "Returns the contained value");
	cls_TransferBRep_ShapeMapper.def("Equates", (Standard_Boolean (TransferBRep_ShapeMapper::*)(const opencascade::handle<Transfer_Finder> &) const ) &TransferBRep_ShapeMapper::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
	cls_TransferBRep_ShapeMapper.def("ValueType", (opencascade::handle<Standard_Type> (TransferBRep_ShapeMapper::*)() const ) &TransferBRep_ShapeMapper::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
	cls_TransferBRep_ShapeMapper.def("ValueTypeName", (Standard_CString (TransferBRep_ShapeMapper::*)() const ) &TransferBRep_ShapeMapper::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
	cls_TransferBRep_ShapeMapper.def_static("get_type_name_", (const char * (*)()) &TransferBRep_ShapeMapper::get_type_name, "None");
	cls_TransferBRep_ShapeMapper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_ShapeMapper::get_type_descriptor, "None");
	cls_TransferBRep_ShapeMapper.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_ShapeMapper::*)() const ) &TransferBRep_ShapeMapper::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_Reader.hxx
	py::class_<TransferBRep_Reader, std::unique_ptr<TransferBRep_Reader, Deleter<TransferBRep_Reader>>> cls_TransferBRep_Reader(mod, "TransferBRep_Reader", "This class offers a simple, easy to call, way of transferring data from interface files to Shapes from CasCade It must be specialized according to each norm/protocol, by : - defining how to read a file (specific method with protocol) - definig transfer, by providing an Actor");
	cls_TransferBRep_Reader.def(py::init<>());
	cls_TransferBRep_Reader.def("SetProtocol", (void (TransferBRep_Reader::*)(const opencascade::handle<Interface_Protocol> &)) &TransferBRep_Reader::SetProtocol, "Records the protocol to be used for read and transfer roots", py::arg("protocol"));
	cls_TransferBRep_Reader.def("Protocol", (opencascade::handle<Interface_Protocol> (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::Protocol, "Returns the recorded Protocol");
	cls_TransferBRep_Reader.def("SetActor", (void (TransferBRep_Reader::*)(const opencascade::handle<Transfer_ActorOfTransientProcess> &)) &TransferBRep_Reader::SetActor, "Records the actor to be used for transfers", py::arg("actor"));
	cls_TransferBRep_Reader.def("Actor", (opencascade::handle<Transfer_ActorOfTransientProcess> (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::Actor, "Returns the recorded Actor");
	cls_TransferBRep_Reader.def("SetFileStatus", (void (TransferBRep_Reader::*)(const Standard_Integer)) &TransferBRep_Reader::SetFileStatus, "Sets File Status to be interpreted as follows : = 0 OK < 0 file not found > 0 read error, no Model could be created", py::arg("status"));
	cls_TransferBRep_Reader.def("FileStatus", (Standard_Integer (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::FileStatus, "Returns the File Status");
	cls_TransferBRep_Reader.def("FileNotFound", (Standard_Boolean (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::FileNotFound, "Returns True if FileStatus is for FileNotFound");
	cls_TransferBRep_Reader.def("SyntaxError", (Standard_Boolean (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::SyntaxError, "Returns True if FileStatus is for Error during read (major error; for local error, see CheckModel)");
	cls_TransferBRep_Reader.def("SetModel", (void (TransferBRep_Reader::*)(const opencascade::handle<Interface_InterfaceModel> &)) &TransferBRep_Reader::SetModel, "Specifies a Model to work on Also clears the result and Done status", py::arg("model"));
	cls_TransferBRep_Reader.def("Model", (opencascade::handle<Interface_InterfaceModel> (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::Model, "Returns the Model to be worked on");
	cls_TransferBRep_Reader.def("Clear", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::Clear, "clears the result and Done status. But not the Model.");
	cls_TransferBRep_Reader.def("CheckStatusModel", (Standard_Boolean (TransferBRep_Reader::*)(const Standard_Boolean) const ) &TransferBRep_Reader::CheckStatusModel, "Checks the Model. Returns True if there is NO FAIL at all (regardless Warnings) If <withprint> is True, also sends Checks on standard output", py::arg("withprint"));
	cls_TransferBRep_Reader.def("CheckListModel", (Interface_CheckIterator (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::CheckListModel, "Checks the Model (complete : syntax + semantic) and returns the produced Check List");
	cls_TransferBRep_Reader.def("ModeNewTransfer", (Standard_Boolean & (TransferBRep_Reader::*)()) &TransferBRep_Reader::ModeNewTransfer, "Returns (by Reference, hence can be changed) the Mode for new Transfer : True (D) means that each new Transfer produces a new TransferProcess. Else keeps the original one but each Transfer clears its (former results are not kept)");
	cls_TransferBRep_Reader.def("BeginTransfer", (Standard_Boolean (TransferBRep_Reader::*)()) &TransferBRep_Reader::BeginTransfer, "Initializes the Reader for a Transfer (one,roots, or list) Also calls PrepareTransfer Returns True when done, False if could not be done");
	cls_TransferBRep_Reader.def("EndTransfer", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::EndTransfer, "Ebds a Transfer (one, roots or list) by recording its result");
	cls_TransferBRep_Reader.def("PrepareTransfer", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::PrepareTransfer, "Prepares the Transfer. Also can act on the Actor or change the TransientProcess if required. Should not set the Actor into the TransientProcess, it is done by caller. The provided default does nothing.");
	cls_TransferBRep_Reader.def("TransferRoots", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::TransferRoots, "Transfers all Root Entities which are recognized as Geom-Topol The result will be a list of Shapes. This method calls user redefinable PrepareTransfer Remark : former result is cleared");
	cls_TransferBRep_Reader.def("Transfer", (Standard_Boolean (TransferBRep_Reader::*)(const Standard_Integer)) &TransferBRep_Reader::Transfer, "Transfers an Entity given its rank in the Model (Root or not) Returns True if it is recognized as Geom-Topol. (But it can have failed : see IsDone)", py::arg("num"));
	cls_TransferBRep_Reader.def("TransferList", (void (TransferBRep_Reader::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &TransferBRep_Reader::TransferList, "Transfers a list of Entities (only the ones also in the Model) Remark : former result is cleared", py::arg("list"));
	cls_TransferBRep_Reader.def("IsDone", (Standard_Boolean (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::IsDone, "Returns True if the LAST Transfer/TransferRoots was a success");
	cls_TransferBRep_Reader.def("NbShapes", (Standard_Integer (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::NbShapes, "Returns the count of produced Shapes (roots)");
	cls_TransferBRep_Reader.def("Shapes", (opencascade::handle<TopTools_HSequenceOfShape> (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::Shapes, "Returns the complete list of produced Shapes");
	cls_TransferBRep_Reader.def("Shape", [](TransferBRep_Reader &self) -> const TopoDS_Shape & { return self.Shape(); });
	cls_TransferBRep_Reader.def("Shape", (const TopoDS_Shape & (TransferBRep_Reader::*)(const Standard_Integer) const ) &TransferBRep_Reader::Shape, "Returns a Shape given its rank, by default the first one", py::arg("num"));
	cls_TransferBRep_Reader.def("ShapeResult", (TopoDS_Shape (TransferBRep_Reader::*)(const opencascade::handle<Standard_Transient> &) const ) &TransferBRep_Reader::ShapeResult, "Returns a Shape produced from a given entity (if it was individually transferred or if an intermediate result is known). If no Shape is bound with <ent>, returns a Null Shape Warning : Runs on the last call to Transfer,TransferRoots,TransferList", py::arg("ent"));
	cls_TransferBRep_Reader.def("OneShape", (TopoDS_Shape (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::OneShape, "Returns a unique Shape for the result : - a void Shape (type = SHAPE) if result is empty - a simple Shape if result has only one : returns this one - a Compound if result has more than one Shape");
	cls_TransferBRep_Reader.def("NbTransients", (Standard_Integer (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::NbTransients, "Returns the count of produced Transient Results (roots)");
	cls_TransferBRep_Reader.def("Transients", (opencascade::handle<TColStd_HSequenceOfTransient> (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::Transients, "Returns the complete list of produced Transient Results");
	cls_TransferBRep_Reader.def("Transient", [](TransferBRep_Reader &self) -> opencascade::handle<Standard_Transient> { return self.Transient(); });
	cls_TransferBRep_Reader.def("Transient", (opencascade::handle<Standard_Transient> (TransferBRep_Reader::*)(const Standard_Integer) const ) &TransferBRep_Reader::Transient, "Returns a Transient Root Result, given its rank (by default the first one)", py::arg("num"));
	cls_TransferBRep_Reader.def("CheckStatusResult", (Standard_Boolean (TransferBRep_Reader::*)(const Standard_Boolean) const ) &TransferBRep_Reader::CheckStatusResult, "Checks the Result of last Transfer (individual or roots, no cumulation on several transfers). Returns True if NO fail occured during Transfer (queries the TransientProcess)", py::arg("withprints"));
	cls_TransferBRep_Reader.def("CheckListResult", (Interface_CheckIterator (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::CheckListResult, "Checks the Result of last Transfer (individual or roots, no cumulation on several transfers) and returns the produced list");
	cls_TransferBRep_Reader.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (TransferBRep_Reader::*)() const ) &TransferBRep_Reader::TransientProcess, "Returns the TransientProcess. It records informations about the very last transfer done. Null if no transfer yet done. Can be used for queries more accurate than the default ones.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_ShapeInfo.hxx
	py::class_<TransferBRep_ShapeInfo, std::unique_ptr<TransferBRep_ShapeInfo, Deleter<TransferBRep_ShapeInfo>>> cls_TransferBRep_ShapeInfo(mod, "TransferBRep_ShapeInfo", "Gives informations on an object, see template DataInfo This class is for Shape");
	cls_TransferBRep_ShapeInfo.def(py::init<>());
	cls_TransferBRep_ShapeInfo.def_static("Type_", (opencascade::handle<Standard_Type> (*)(const TopoDS_Shape &)) &TransferBRep_ShapeInfo::Type, "Returns the Type attached to an object Here, TShape (Shape has no Dynamic Type)", py::arg("ent"));
	cls_TransferBRep_ShapeInfo.def_static("TypeName_", (Standard_CString (*)(const TopoDS_Shape &)) &TransferBRep_ShapeInfo::TypeName, "Returns Type Name (string) Here, the true name of the Type of a Shape", py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_ShapeBinder.hxx
	py::class_<TransferBRep_ShapeBinder, opencascade::handle<TransferBRep_ShapeBinder>, TransferBRep_BinderOfShape> cls_TransferBRep_ShapeBinder(mod, "TransferBRep_ShapeBinder", "A ShapeBinder is a BinderOfShape with some additional services to cast the Result under various kinds of Shapes");
	cls_TransferBRep_ShapeBinder.def(py::init<>());
	cls_TransferBRep_ShapeBinder.def(py::init<const TopoDS_Shape &>(), py::arg("res"));
	cls_TransferBRep_ShapeBinder.def("ShapeType", (TopAbs_ShapeEnum (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::ShapeType, "Returns the Type of the Shape Result (under TopAbs form)");
	cls_TransferBRep_ShapeBinder.def("Vertex", (TopoDS_Vertex (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Vertex, "None");
	cls_TransferBRep_ShapeBinder.def("Edge", (TopoDS_Edge (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Edge, "None");
	cls_TransferBRep_ShapeBinder.def("Wire", (TopoDS_Wire (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Wire, "None");
	cls_TransferBRep_ShapeBinder.def("Face", (TopoDS_Face (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Face, "None");
	cls_TransferBRep_ShapeBinder.def("Shell", (TopoDS_Shell (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Shell, "None");
	cls_TransferBRep_ShapeBinder.def("Solid", (TopoDS_Solid (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Solid, "None");
	cls_TransferBRep_ShapeBinder.def("CompSolid", (TopoDS_CompSolid (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::CompSolid, "None");
	cls_TransferBRep_ShapeBinder.def("Compound", (TopoDS_Compound (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::Compound, "None");
	cls_TransferBRep_ShapeBinder.def_static("get_type_name_", (const char * (*)()) &TransferBRep_ShapeBinder::get_type_name, "None");
	cls_TransferBRep_ShapeBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_ShapeBinder::get_type_descriptor, "None");
	cls_TransferBRep_ShapeBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_ShapeBinder::*)() const ) &TransferBRep_ShapeBinder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_ShapeListBinder.hxx
	py::class_<TransferBRep_ShapeListBinder, opencascade::handle<TransferBRep_ShapeListBinder>, Transfer_Binder> cls_TransferBRep_ShapeListBinder(mod, "TransferBRep_ShapeListBinder", "This binder binds several (a list of) shapes with a starting entity, when this entity itself corresponds to a simple list of shapes. Each part is not seen as a sub-result of an independant componant, but as an item of a built-in list");
	cls_TransferBRep_ShapeListBinder.def(py::init<>());
	cls_TransferBRep_ShapeListBinder.def(py::init<const opencascade::handle<TopTools_HSequenceOfShape> &>(), py::arg("list"));
	cls_TransferBRep_ShapeListBinder.def("IsMultiple", (Standard_Boolean (TransferBRep_ShapeListBinder::*)() const ) &TransferBRep_ShapeListBinder::IsMultiple, "None");
	cls_TransferBRep_ShapeListBinder.def("ResultType", (opencascade::handle<Standard_Type> (TransferBRep_ShapeListBinder::*)() const ) &TransferBRep_ShapeListBinder::ResultType, "None");
	cls_TransferBRep_ShapeListBinder.def("ResultTypeName", (Standard_CString (TransferBRep_ShapeListBinder::*)() const ) &TransferBRep_ShapeListBinder::ResultTypeName, "None");
	cls_TransferBRep_ShapeListBinder.def("AddResult", (void (TransferBRep_ShapeListBinder::*)(const TopoDS_Shape &)) &TransferBRep_ShapeListBinder::AddResult, "Adds an item to the result list", py::arg("res"));
	cls_TransferBRep_ShapeListBinder.def("Result", (opencascade::handle<TopTools_HSequenceOfShape> (TransferBRep_ShapeListBinder::*)() const ) &TransferBRep_ShapeListBinder::Result, "None");
	cls_TransferBRep_ShapeListBinder.def("SetResult", (void (TransferBRep_ShapeListBinder::*)(const Standard_Integer, const TopoDS_Shape &)) &TransferBRep_ShapeListBinder::SetResult, "Changes an already defined sub-result", py::arg("num"), py::arg("res"));
	cls_TransferBRep_ShapeListBinder.def("NbShapes", (Standard_Integer (TransferBRep_ShapeListBinder::*)() const ) &TransferBRep_ShapeListBinder::NbShapes, "None");
	cls_TransferBRep_ShapeListBinder.def("Shape", (const TopoDS_Shape & (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Shape, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("ShapeType", (TopAbs_ShapeEnum (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::ShapeType, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Vertex", (TopoDS_Vertex (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Vertex, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Edge", (TopoDS_Edge (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Edge, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Wire", (TopoDS_Wire (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Wire, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Face", (TopoDS_Face (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Face, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Shell", (TopoDS_Shell (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Shell, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Solid", (TopoDS_Solid (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Solid, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("CompSolid", (TopoDS_CompSolid (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::CompSolid, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def("Compound", (TopoDS_Compound (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const ) &TransferBRep_ShapeListBinder::Compound, "None", py::arg("num"));
	cls_TransferBRep_ShapeListBinder.def_static("get_type_name_", (const char * (*)()) &TransferBRep_ShapeListBinder::get_type_name, "None");
	cls_TransferBRep_ShapeListBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_ShapeListBinder::get_type_descriptor, "None");
	cls_TransferBRep_ShapeListBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_ShapeListBinder::*)() const ) &TransferBRep_ShapeListBinder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_OrientedShapeMapper.hxx
	py::class_<TransferBRep_OrientedShapeMapper, opencascade::handle<TransferBRep_OrientedShapeMapper>, Transfer_Finder> cls_TransferBRep_OrientedShapeMapper(mod, "TransferBRep_OrientedShapeMapper", "None");
	cls_TransferBRep_OrientedShapeMapper.def(py::init<const TopoDS_Shape &>(), py::arg("akey"));
	cls_TransferBRep_OrientedShapeMapper.def("Value", (const TopoDS_Shape & (TransferBRep_OrientedShapeMapper::*)() const ) &TransferBRep_OrientedShapeMapper::Value, "Returns the contained value");
	cls_TransferBRep_OrientedShapeMapper.def("Equates", (Standard_Boolean (TransferBRep_OrientedShapeMapper::*)(const opencascade::handle<Transfer_Finder> &) const ) &TransferBRep_OrientedShapeMapper::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
	cls_TransferBRep_OrientedShapeMapper.def("ValueType", (opencascade::handle<Standard_Type> (TransferBRep_OrientedShapeMapper::*)() const ) &TransferBRep_OrientedShapeMapper::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
	cls_TransferBRep_OrientedShapeMapper.def("ValueTypeName", (Standard_CString (TransferBRep_OrientedShapeMapper::*)() const ) &TransferBRep_OrientedShapeMapper::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
	cls_TransferBRep_OrientedShapeMapper.def_static("get_type_name_", (const char * (*)()) &TransferBRep_OrientedShapeMapper::get_type_name, "None");
	cls_TransferBRep_OrientedShapeMapper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_OrientedShapeMapper::get_type_descriptor, "None");
	cls_TransferBRep_OrientedShapeMapper.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_OrientedShapeMapper::*)() const ) &TransferBRep_OrientedShapeMapper::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep.hxx
	py::class_<TransferBRep, std::unique_ptr<TransferBRep, Deleter<TransferBRep>>> cls_TransferBRep(mod, "TransferBRep", "This package gathers services to simply read files and convert them to Shapes from CasCade. IE. it can be used in conjunction with purely CasCade software");
	cls_TransferBRep.def(py::init<>());
	cls_TransferBRep.def_static("ShapeResult_", (TopoDS_Shape (*)(const opencascade::handle<Transfer_Binder> &)) &TransferBRep::ShapeResult, "Get the Shape recorded in a Binder If the Binder brings a multiple result, search for the Shape", py::arg("binder"));
	cls_TransferBRep.def_static("ShapeResult_", (TopoDS_Shape (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &)) &TransferBRep::ShapeResult, "Get the Shape recorded in a TransientProcess as result of the Transfer of an entity. I.E. in the binder bound to that Entity If no result or result not a single Shape, returns a Null Shape", py::arg("TP"), py::arg("ent"));
	cls_TransferBRep.def_static("SetShapeResult_", (void (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &, const TopoDS_Shape &)) &TransferBRep::SetShapeResult, "Sets a Shape as a result for a starting entity <ent> (reverse of ShapeResult) It simply creates a ShapeBinder then binds it to the entity", py::arg("TP"), py::arg("ent"), py::arg("result"));
	cls_TransferBRep.def_static("Shapes_", [](const opencascade::handle<Transfer_TransientProcess> & a0) -> opencascade::handle<TopTools_HSequenceOfShape> { return TransferBRep::Shapes(a0); }, py::arg("TP"));
	cls_TransferBRep.def_static("Shapes_", (opencascade::handle<TopTools_HSequenceOfShape> (*)(const opencascade::handle<Transfer_TransientProcess> &, const Standard_Boolean)) &TransferBRep::Shapes, "Gets the Shapes recorded in a TransientProcess as result of a Transfer, considers roots only or all results according <rootsonly>, returns them as a HSequence", py::arg("TP"), py::arg("rootsonly"));
	cls_TransferBRep.def_static("Shapes_", (opencascade::handle<TopTools_HSequenceOfShape> (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<TColStd_HSequenceOfTransient> &)) &TransferBRep::Shapes, "Gets the Shapes recorded in a TransientProcess as result of a Transfer, for a given list of starting entities, returns the shapes as a HSequence", py::arg("TP"), py::arg("list"));
	cls_TransferBRep.def_static("ShapeState_", (TopAbs_Orientation (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::ShapeState, "Returns a Status regarding a Shape in a FinderProcess - FORWARD means bound with SAME Orientation - REVERSED means bound with REVERSE Orientation - EXTERNAL means NOT BOUND - INTERNAL is not used", py::arg("FP"), py::arg("shape"));
	cls_TransferBRep.def_static("ResultFromShape_", (opencascade::handle<Transfer_Binder> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::ResultFromShape, "Returns the result (as a Binder) attached to a given Shape Null if none", py::arg("FP"), py::arg("shape"));
	cls_TransferBRep.def_static("TransientFromShape_", (opencascade::handle<Standard_Transient> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::TransientFromShape, "Returns the result as pure Transient attached to a Shape first one if multiple result", py::arg("FP"), py::arg("shape"));
	cls_TransferBRep.def_static("SetTransientFromShape_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &)) &TransferBRep::SetTransientFromShape, "Binds a Transient Result to a Shape in a FinderProcess (as first result if multiple : does not add it to existing one)", py::arg("FP"), py::arg("shape"), py::arg("result"));
	cls_TransferBRep.def_static("ShapeMapper_", (opencascade::handle<TransferBRep_ShapeMapper> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::ShapeMapper, "Returns a ShapeMapper for a given Shape (location included) Either <shape> is already mapped, then its Mapper is returned Or it is not, then a new one is created then returned, BUT it is not mapped here (use Bind or FindElseBind to do this)", py::arg("FP"), py::arg("shape"));
	cls_TransferBRep.def_static("TransferResultInfo_", (void (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<TColStd_HSequenceOfTransient> &, opencascade::handle<TransferBRep_HSequenceOfTransferResultInfo> &)) &TransferBRep::TransferResultInfo, "Fills sequence of TransferResultInfo for each type of entity given in the EntityTypes (entity are given as objects). Method IsKind applied to the entities in TP is used to compare with entities in EntityTypes. TopAbs_ShapeEnum).", py::arg("TP"), py::arg("EntityTypes"), py::arg("InfoSeq"));
	cls_TransferBRep.def_static("TransferResultInfo_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<TColStd_HSequenceOfInteger> &, opencascade::handle<TransferBRep_HSequenceOfTransferResultInfo> &)) &TransferBRep::TransferResultInfo, "Fills sequence of TransferResultInfo for each type of shape given in the ShapeTypes (which are in fact considered as TopAbs_ShapeEnum). The Finders in the FP are considered as ShapeMappers.", py::arg("FP"), py::arg("ShapeTypes"), py::arg("InfoSeq"));
	cls_TransferBRep.def_static("PrintResultInfo_", [](const opencascade::handle<Message_Printer> & a0, const Message_Msg & a1, const opencascade::handle<TransferBRep_TransferResultInfo> & a2) -> void { return TransferBRep::PrintResultInfo(a0, a1, a2); }, py::arg("Printer"), py::arg("Header"), py::arg("ResultInfo"));
	cls_TransferBRep.def_static("PrintResultInfo_", (void (*)(const opencascade::handle<Message_Printer> &, const Message_Msg &, const opencascade::handle<TransferBRep_TransferResultInfo> &, const Standard_Boolean)) &TransferBRep::PrintResultInfo, "Prints the results of transfer to given priner with given header.", py::arg("Printer"), py::arg("Header"), py::arg("ResultInfo"), py::arg("printEmpty"));
	// cls_TransferBRep.def_static("BRepCheck_", [](const TopoDS_Shape & a0) -> Interface_CheckIterator { return TransferBRep::BRepCheck(a0); }, py::arg("shape"));
	// cls_TransferBRep.def_static("BRepCheck_", (Interface_CheckIterator (*)(const TopoDS_Shape &, const Standard_Integer)) &TransferBRep::BRepCheck, "Performs a heavy check by calling the Analyser from BRepCheck This tool computes a lot of informations about integrity of a Shape. This method uses it and converts its internal result to a classic check-list. <lev> allows to get more informations : 0 : BRepCheck only 1(D) + Curves/Surfaces not C0 ; 2 + SameParameter on Edges Warning : entities to which checks are bound are the Shapes themselves, embedded in ShapeMapper", py::arg("shape"), py::arg("lev"));
	cls_TransferBRep.def_static("ResultCheckList_", (Interface_CheckIterator (*)(const Interface_CheckIterator &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &)) &TransferBRep::ResultCheckList, "Takes a starting CheckIterator which brings checks bound with starting objects (Shapes, Transient from an Imagine appli ...) and converts it to a CheckIterator in which checks are bound with results in an InterfaceModel Mapping is recorded in the FinderProcess Starting objects for which no individual result is recorded remain in their state", py::arg("chl"), py::arg("FP"), py::arg("model"));
	cls_TransferBRep.def_static("Checked_", [](const Interface_CheckIterator & a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return TransferBRep::Checked(a0); }, py::arg("chl"));
	cls_TransferBRep.def_static("Checked_", (opencascade::handle<TColStd_HSequenceOfTransient> (*)(const Interface_CheckIterator &, const Standard_Boolean)) &TransferBRep::Checked, "Returns the list of objects to which a non-empty Check is bound in a check-list. Objects are transients, they can then be either Imagine objects entities for an Interface Norm. <alsoshapes> commands Shapes to be returned too (as ShapeMapper), see also CheckedShapes", py::arg("chl"), py::arg("alsoshapes"));
	cls_TransferBRep.def_static("CheckedShapes_", (opencascade::handle<TopTools_HSequenceOfShape> (*)(const Interface_CheckIterator &)) &TransferBRep::CheckedShapes, "Returns the list of shapes to which a non-empty Check is bound in a check-list", py::arg("chl"));
	cls_TransferBRep.def_static("CheckObject_", (Interface_CheckIterator (*)(const Interface_CheckIterator &, const opencascade::handle<Standard_Transient> &)) &TransferBRep::CheckObject, "Returns the check-list bound to a given object, generally none (if OK) or one check. <obj> can be, either a true Transient object or entity, or a ShapeMapper, in that case the Shape is considered", py::arg("chl"), py::arg("obj"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TransferBRep_HSequenceOfTransferResultInfo.hxx
	py::class_<TransferBRep_HSequenceOfTransferResultInfo, opencascade::handle<TransferBRep_HSequenceOfTransferResultInfo>, TransferBRep_SequenceOfTransferResultInfo, Standard_Transient> cls_TransferBRep_HSequenceOfTransferResultInfo(mod, "TransferBRep_HSequenceOfTransferResultInfo", "None");
	cls_TransferBRep_HSequenceOfTransferResultInfo.def(py::init<>());
	cls_TransferBRep_HSequenceOfTransferResultInfo.def(py::init<const TransferBRep_SequenceOfTransferResultInfo &>(), py::arg("theOther"));
	cls_TransferBRep_HSequenceOfTransferResultInfo.def("Sequence", (const TransferBRep_SequenceOfTransferResultInfo & (TransferBRep_HSequenceOfTransferResultInfo::*)() const ) &TransferBRep_HSequenceOfTransferResultInfo::Sequence, "None");
	cls_TransferBRep_HSequenceOfTransferResultInfo.def("Append", (void (TransferBRep_HSequenceOfTransferResultInfo::*)(const TransferBRep_SequenceOfTransferResultInfo::value_type &)) &TransferBRep_HSequenceOfTransferResultInfo::Append, "None", py::arg("theItem"));
	cls_TransferBRep_HSequenceOfTransferResultInfo.def("Append", (void (TransferBRep_HSequenceOfTransferResultInfo::*)(TransferBRep_SequenceOfTransferResultInfo &)) &TransferBRep_HSequenceOfTransferResultInfo::Append, "None", py::arg("theSequence"));
	cls_TransferBRep_HSequenceOfTransferResultInfo.def("ChangeSequence", (TransferBRep_SequenceOfTransferResultInfo & (TransferBRep_HSequenceOfTransferResultInfo::*)()) &TransferBRep_HSequenceOfTransferResultInfo::ChangeSequence, "None");
	cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("get_type_name_", (const char * (*)()) &TransferBRep_HSequenceOfTransferResultInfo::get_type_name, "None");
	cls_TransferBRep_HSequenceOfTransferResultInfo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_HSequenceOfTransferResultInfo::get_type_descriptor, "None");
	cls_TransferBRep_HSequenceOfTransferResultInfo.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_HSequenceOfTransferResultInfo::*)() const ) &TransferBRep_HSequenceOfTransferResultInfo::DynamicType, "None");


}
