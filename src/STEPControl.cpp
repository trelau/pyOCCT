#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <STEPControl_StepModelType.hxx>
#include <Transfer_ActorOfFinderProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Finder.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_FinderProcess.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Type.hxx>
#include <STEPControl_ActorWrite.hxx>
#include <XSControl_Controller.hxx>
#include <Interface_InterfaceModel.hxx>
#include <XSControl_WorkSession.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <STEPControl_Controller.hxx>
#include <XSControl_Reader.hxx>
#include <StepData_StepModel.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_TransientProcess.hxx>
#include <StepRepr_Representation.hxx>
#include <gp_Trsf.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <STEPControl_ActorRead.hxx>

PYBIND11_MODULE(STEPControl, mod) {

	// IMPORT
	py::module::import("OCCT.Transfer");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.StepGeom");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.XSControl");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.IFSelect");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPControl_StepModelType.hxx
	py::enum_<STEPControl_StepModelType>(mod, "STEPControl_StepModelType", "Gives you the choice of translation mode for an Open CASCADE shape that is being translated to STEP. - STEPControl_AsIs translates an Open CASCADE shape to its highest possible STEP representation. - STEPControl_ManifoldSolidBrep translates an Open CASCADE shape to a STEP manifold_solid_brep or brep_with_voids entity. - STEPControl_FacetedBrep translates an Open CASCADE shape into a STEP faceted_brep entity. - STEPControl_ShellBasedSurfaceModel translates an Open CASCADE shape into a STEP shell_based_surface_model entity. - STEPControl_GeometricCurveSet translates an Open CASCADE shape into a STEP geometric_curve_set entity.")
		.value("STEPControl_AsIs", STEPControl_StepModelType::STEPControl_AsIs)
		.value("STEPControl_ManifoldSolidBrep", STEPControl_StepModelType::STEPControl_ManifoldSolidBrep)
		.value("STEPControl_BrepWithVoids", STEPControl_StepModelType::STEPControl_BrepWithVoids)
		.value("STEPControl_FacetedBrep", STEPControl_StepModelType::STEPControl_FacetedBrep)
		.value("STEPControl_FacetedBrepAndBrepWithVoids", STEPControl_StepModelType::STEPControl_FacetedBrepAndBrepWithVoids)
		.value("STEPControl_ShellBasedSurfaceModel", STEPControl_StepModelType::STEPControl_ShellBasedSurfaceModel)
		.value("STEPControl_GeometricCurveSet", STEPControl_StepModelType::STEPControl_GeometricCurveSet)
		.value("STEPControl_Hybrid", STEPControl_StepModelType::STEPControl_Hybrid)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPControl_ActorWrite.hxx
	py::class_<STEPControl_ActorWrite, opencascade::handle<STEPControl_ActorWrite>, Transfer_ActorOfFinderProcess> cls_STEPControl_ActorWrite(mod, "STEPControl_ActorWrite", "This class performs the transfer of a Shape from TopoDS to AP203 or AP214 (CD2 or DIS)");
	cls_STEPControl_ActorWrite.def(py::init<>());
	cls_STEPControl_ActorWrite.def("Recognize", (Standard_Boolean (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &)) &STEPControl_ActorWrite::Recognize, "None", py::arg("start"));
	cls_STEPControl_ActorWrite.def("Transfer", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_FinderProcess> &)) &STEPControl_ActorWrite::Transfer, "None", py::arg("start"), py::arg("FP"));
	cls_STEPControl_ActorWrite.def("TransferSubShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, opencascade::handle<StepGeom_Axis2Placement3d> & a2, const opencascade::handle<Transfer_FinderProcess> & a3) -> opencascade::handle<Transfer_Binder> { return self.TransferSubShape(a0, a1, a2, a3); }, py::arg("start"), py::arg("SDR"), py::arg("AX1"), py::arg("FP"));
	cls_STEPControl_ActorWrite.def("TransferSubShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, opencascade::handle<StepGeom_Axis2Placement3d> & a2, const opencascade::handle<Transfer_FinderProcess> & a3, const opencascade::handle<TopTools_HSequenceOfShape> & a4) -> opencascade::handle<Transfer_Binder> { return self.TransferSubShape(a0, a1, a2, a3, a4); }, py::arg("start"), py::arg("SDR"), py::arg("AX1"), py::arg("FP"), py::arg("shapeGroup"));
	cls_STEPControl_ActorWrite.def("TransferSubShape", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Boolean)) &STEPControl_ActorWrite::TransferSubShape, "None", py::arg("start"), py::arg("SDR"), py::arg("AX1"), py::arg("FP"), py::arg("shapeGroup"), py::arg("isManifold"));
	cls_STEPControl_ActorWrite.def("TransferShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, const opencascade::handle<Transfer_FinderProcess> & a2) -> opencascade::handle<Transfer_Binder> { return self.TransferShape(a0, a1, a2); }, py::arg("start"), py::arg("SDR"), py::arg("FP"));
	cls_STEPControl_ActorWrite.def("TransferShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, const opencascade::handle<Transfer_FinderProcess> & a2, const opencascade::handle<TopTools_HSequenceOfShape> & a3) -> opencascade::handle<Transfer_Binder> { return self.TransferShape(a0, a1, a2, a3); }, py::arg("start"), py::arg("SDR"), py::arg("FP"), py::arg("shapeGroup"));
	cls_STEPControl_ActorWrite.def("TransferShape", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Boolean)) &STEPControl_ActorWrite::TransferShape, "None", py::arg("start"), py::arg("SDR"), py::arg("FP"), py::arg("shapeGroup"), py::arg("isManifold"));
	cls_STEPControl_ActorWrite.def("TransferCompound", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<Transfer_FinderProcess> &)) &STEPControl_ActorWrite::TransferCompound, "None", py::arg("start"), py::arg("SDR"), py::arg("FP"));
	cls_STEPControl_ActorWrite.def("SetMode", (void (STEPControl_ActorWrite::*)(const STEPControl_StepModelType)) &STEPControl_ActorWrite::SetMode, "None", py::arg("M"));
	cls_STEPControl_ActorWrite.def("Mode", (STEPControl_StepModelType (STEPControl_ActorWrite::*)() const ) &STEPControl_ActorWrite::Mode, "None");
	cls_STEPControl_ActorWrite.def("SetGroupMode", (void (STEPControl_ActorWrite::*)(const Standard_Integer)) &STEPControl_ActorWrite::SetGroupMode, "None", py::arg("mode"));
	cls_STEPControl_ActorWrite.def("GroupMode", (Standard_Integer (STEPControl_ActorWrite::*)() const ) &STEPControl_ActorWrite::GroupMode, "None");
	cls_STEPControl_ActorWrite.def("SetTolerance", (void (STEPControl_ActorWrite::*)(const Standard_Real)) &STEPControl_ActorWrite::SetTolerance, "None", py::arg("Tol"));
	cls_STEPControl_ActorWrite.def("IsAssembly", (Standard_Boolean (STEPControl_ActorWrite::*)(TopoDS_Shape &) const ) &STEPControl_ActorWrite::IsAssembly, "Customizable method to check whether shape S should be written as assembly or not Default implementation uses flag GroupMode and analyses the shape itself NOTE: this method can modify shape", py::arg("S"));
	cls_STEPControl_ActorWrite.def_static("get_type_name_", (const char * (*)()) &STEPControl_ActorWrite::get_type_name, "None");
	cls_STEPControl_ActorWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPControl_ActorWrite::get_type_descriptor, "None");
	cls_STEPControl_ActorWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPControl_ActorWrite::*)() const ) &STEPControl_ActorWrite::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPControl_Controller.hxx
	py::class_<STEPControl_Controller, opencascade::handle<STEPControl_Controller>, XSControl_Controller> cls_STEPControl_Controller(mod, "STEPControl_Controller", "defines basic controller for STEP processor");
	cls_STEPControl_Controller.def(py::init<>());
	cls_STEPControl_Controller.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (STEPControl_Controller::*)() const ) &STEPControl_Controller::NewModel, "Creates a new empty Model ready to receive data of the Norm. It is taken from STEP Template Model");
	cls_STEPControl_Controller.def("Customise", (void (STEPControl_Controller::*)(opencascade::handle<XSControl_WorkSession> &)) &STEPControl_Controller::Customise, "None", py::arg("WS"));
	cls_STEPControl_Controller.def("TransferWriteShape", [](STEPControl_Controller &self, const TopoDS_Shape & a0, const opencascade::handle<Transfer_FinderProcess> & a1, const opencascade::handle<Interface_InterfaceModel> & a2) -> IFSelect_ReturnStatus { return self.TransferWriteShape(a0, a1, a2); }, py::arg("shape"), py::arg("FP"), py::arg("model"));
	cls_STEPControl_Controller.def("TransferWriteShape", (IFSelect_ReturnStatus (STEPControl_Controller::*)(const TopoDS_Shape &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer) const ) &STEPControl_Controller::TransferWriteShape, "Takes one Shape and transfers it to the InterfaceModel (already created by NewModel for instance) <modeshape> is to be interpreted by each kind of XstepAdaptor Returns a status : 0 OK 1 No result 2 Fail -1 bad modeshape -2 bad model (requires a StepModel) modeshape : 1 Facetted BRep, 2 Shell, 3 Manifold Solid", py::arg("shape"), py::arg("FP"), py::arg("model"), py::arg("modetrans"));
	cls_STEPControl_Controller.def_static("Init_", (Standard_Boolean (*)()) &STEPControl_Controller::Init, "Standard Initialisation. It creates a Controller for STEP and records it to various names, available to select it later Returns True when done, False if could not be done");
	cls_STEPControl_Controller.def_static("get_type_name_", (const char * (*)()) &STEPControl_Controller::get_type_name, "None");
	cls_STEPControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPControl_Controller::get_type_descriptor, "None");
	cls_STEPControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPControl_Controller::*)() const ) &STEPControl_Controller::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPControl_Reader.hxx
	py::class_<STEPControl_Reader, std::unique_ptr<STEPControl_Reader, Deleter<STEPControl_Reader>>, XSControl_Reader> cls_STEPControl_Reader(mod, "STEPControl_Reader", "Reads STEP files, checks them and translates their contents into Open CASCADE models. The STEP data can be that of a whole model or that of a specific list of entities in the model. As in XSControl_Reader, you specify the list using a selection. For the translation of iges files it is possible to use next sequence: To change translation parameters class Interface_Static should be used before beginning of translation (see STEP Parameters and General Parameters) Creation of reader - STEPControl_Reader reader; To load s file in a model use method reader.ReadFile('filename.stp') To print load results reader.PrintCheckLoad(failsonly,mode) where mode is equal to the value of enumeration IFSelect_PrintCount For definition number of candidates : Standard_Integer nbroots = reader. NbRootsForTransfer(); To transfer entities from a model the following methods can be used: for the whole model - reader.TransferRoots(); to transfer a list of entities: reader.TransferList(list); to transfer one entity Handle(Standard_Transient) ent = reader.RootForTransfer(num); reader.TransferEntity(ent), or reader.TransferOneRoot(num), or reader.TransferOne(num), or reader.TransferRoot(num) To obtain the result the following method can be used: reader.NbShapes() and reader.Shape(num); or reader.OneShape(); To print the results of transfer use method: reader.PrintCheckTransfer(failwarn,mode); where printfail is equal to the value of enumeration IFSelect_PrintFail, mode see above; or reader.PrintStatsTransfer(); Gets correspondence between a STEP entity and a result shape obtained from it. Handle(XSControl_WorkSession) WS = reader.WS(); if ( WS->TransferReader()->HasResult(ent) ) TopoDS_Shape shape = WS->TransferReader()->ShapeResult(ent);");
	cls_STEPControl_Reader.def(py::init<>());
	cls_STEPControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
	cls_STEPControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));
	cls_STEPControl_Reader.def("StepModel", (opencascade::handle<StepData_StepModel> (STEPControl_Reader::*)() const ) &STEPControl_Reader::StepModel, "Returns the model as a StepModel. It can then be consulted (header, product)");
	cls_STEPControl_Reader.def("TransferRoot", [](STEPControl_Reader &self) -> Standard_Boolean { return self.TransferRoot(); });
	cls_STEPControl_Reader.def("TransferRoot", (Standard_Boolean (STEPControl_Reader::*)(const Standard_Integer)) &STEPControl_Reader::TransferRoot, "Transfers a root given its rank in the list of candidate roots Default is the first one Returns True if a shape has resulted, false else Same as inherited TransferOneRoot, kept for compatibility", py::arg("num"));
	cls_STEPControl_Reader.def("NbRootsForTransfer", (Standard_Integer (STEPControl_Reader::*)()) &STEPControl_Reader::NbRootsForTransfer, "Determines the list of root entities from Model which are candidate for a transfer to a Shape (type of entities is PRODUCT)");
	cls_STEPControl_Reader.def("FileUnits", (void (STEPControl_Reader::*)(TColStd_SequenceOfAsciiString &, TColStd_SequenceOfAsciiString &, TColStd_SequenceOfAsciiString &)) &STEPControl_Reader::FileUnits, "Returns sequence of all unit names for shape representations found in file", py::arg("theUnitLengthNames"), py::arg("theUnitAngleNames"), py::arg("theUnitSolidAngleNames"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPControl_Writer.hxx
	py::class_<STEPControl_Writer, std::unique_ptr<STEPControl_Writer, Deleter<STEPControl_Writer>>> cls_STEPControl_Writer(mod, "STEPControl_Writer", "This class creates and writes STEP files from Open CASCADE models. A STEP file can be written to an existing STEP file or to a new one. Translation can be performed in one or several operations. Each translation operation outputs a distinct root entity in the STEP file.");
	cls_STEPControl_Writer.def(py::init<>());
	cls_STEPControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
	cls_STEPControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));
	cls_STEPControl_Writer.def("SetTolerance", (void (STEPControl_Writer::*)(const Standard_Real)) &STEPControl_Writer::SetTolerance, "Sets a length-measure value that will be written to uncertainty-measure-with-unit when the next shape is translated.", py::arg("Tol"));
	cls_STEPControl_Writer.def("UnsetTolerance", (void (STEPControl_Writer::*)()) &STEPControl_Writer::UnsetTolerance, "Unsets the tolerance formerly forced by SetTolerance");
	cls_STEPControl_Writer.def("SetWS", [](STEPControl_Writer &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.SetWS(a0); }, py::arg("WS"));
	cls_STEPControl_Writer.def("SetWS", (void (STEPControl_Writer::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &STEPControl_Writer::SetWS, "Sets a specific session to <me>", py::arg("WS"), py::arg("scratch"));
	cls_STEPControl_Writer.def("WS", (opencascade::handle<XSControl_WorkSession> (STEPControl_Writer::*)() const ) &STEPControl_Writer::WS, "Returns the session used in <me>");
	cls_STEPControl_Writer.def("Model", [](STEPControl_Writer &self) -> opencascade::handle<StepData_StepModel> { return self.Model(); });
	cls_STEPControl_Writer.def("Model", (opencascade::handle<StepData_StepModel> (STEPControl_Writer::*)(const Standard_Boolean)) &STEPControl_Writer::Model, "Returns the produced model. Produces a new one if not yet done or if <newone> is True This method allows for instance to edit product or header data before writing.", py::arg("newone"));
	cls_STEPControl_Writer.def("Transfer", [](STEPControl_Writer &self, const TopoDS_Shape & a0, const STEPControl_StepModelType a1) -> IFSelect_ReturnStatus { return self.Transfer(a0, a1); }, py::arg("sh"), py::arg("mode"));
	cls_STEPControl_Writer.def("Transfer", (IFSelect_ReturnStatus (STEPControl_Writer::*)(const TopoDS_Shape &, const STEPControl_StepModelType, const Standard_Boolean)) &STEPControl_Writer::Transfer, "Translates shape sh to a STEP entity. mode defines the STEP entity type to be output: - STEPControlStd_AsIs translates a shape to its highest possible STEP representation. - STEPControlStd_ManifoldSolidBrep translates a shape to a STEP manifold_solid_brep or brep_with_voids entity. - STEPControlStd_FacetedBrep translates a shape into a STEP faceted_brep entity. - STEPControlStd_ShellBasedSurfaceModel translates a shape into a STEP shell_based_surface_model entity. - STEPControlStd_GeometricCurveSet translates a shape into a STEP geometric_curve_set entity.", py::arg("sh"), py::arg("mode"), py::arg("compgraph"));
	cls_STEPControl_Writer.def("Write", (IFSelect_ReturnStatus (STEPControl_Writer::*)(const Standard_CString)) &STEPControl_Writer::Write, "Writes a STEP model in the file identified by filename.", py::arg("filename"));
	cls_STEPControl_Writer.def("PrintStatsTransfer", [](STEPControl_Writer &self, const Standard_Integer a0) -> void { return self.PrintStatsTransfer(a0); }, py::arg("what"));
	cls_STEPControl_Writer.def("PrintStatsTransfer", (void (STEPControl_Writer::*)(const Standard_Integer, const Standard_Integer) const ) &STEPControl_Writer::PrintStatsTransfer, "Displays the statistics for the last translation. what defines the kind of statistics that are displayed: - 0 gives general statistics (number of translated roots, number of warnings, number of fail messages), - 1 gives root results, - 2 gives statistics for all checked entities, - 3 gives the list of translated entities, - 4 gives warning and fail messages, - 5 gives fail messages only. mode is used according to the use of what. If what is 0, mode is ignored. If what is 1, 2 or 3, mode defines the following: - 0 lists the numbers of STEP entities in a STEP model, - 1 gives the number, identifier, type and result type for each STEP entity and/or its status (fail, warning, etc.), - 2 gives maximum information for each STEP entity (i.e. checks), - 3 gives the number of entities by the type of a STEP entity, - 4 gives the number of of STEP entities per result type and/or status, - 5 gives the number of pairs (STEP or result type and status), - 6 gives the number of pairs (STEP or result type and status) AND the list of entity numbers in the STEP model.", py::arg("what"), py::arg("mode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPControl_ActorRead.hxx
	py::class_<STEPControl_ActorRead, opencascade::handle<STEPControl_ActorRead>, Transfer_ActorOfTransientProcess> cls_STEPControl_ActorRead(mod, "STEPControl_ActorRead", "This class performs the transfer of an Entity from AP214 and AP203, either Geometric or Topologic.");
	cls_STEPControl_ActorRead.def(py::init<>());
	cls_STEPControl_ActorRead.def("Recognize", (Standard_Boolean (STEPControl_ActorRead::*)(const opencascade::handle<Standard_Transient> &)) &STEPControl_ActorRead::Recognize, "None", py::arg("start"));
	cls_STEPControl_ActorRead.def("Transfer", (opencascade::handle<Transfer_Binder> (STEPControl_ActorRead::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &STEPControl_ActorRead::Transfer, "None", py::arg("start"), py::arg("TP"));
	cls_STEPControl_ActorRead.def("TransferShape", [](STEPControl_ActorRead &self, const opencascade::handle<Standard_Transient> & a0, const opencascade::handle<Transfer_TransientProcess> & a1) -> opencascade::handle<Transfer_Binder> { return self.TransferShape(a0, a1); }, py::arg("start"), py::arg("TP"));
	cls_STEPControl_ActorRead.def("TransferShape", (opencascade::handle<Transfer_Binder> (STEPControl_ActorRead::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &, const Standard_Boolean)) &STEPControl_ActorRead::TransferShape, "None", py::arg("start"), py::arg("TP"), py::arg("isManifold"));
	cls_STEPControl_ActorRead.def("PrepareUnits", (void (STEPControl_ActorRead::*)(const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<Transfer_TransientProcess> &)) &STEPControl_ActorRead::PrepareUnits, "set units and tolerances context by given ShapeRepresentation", py::arg("rep"), py::arg("TP"));
	cls_STEPControl_ActorRead.def("ResetUnits", (void (STEPControl_ActorRead::*)()) &STEPControl_ActorRead::ResetUnits, "reset units and tolerances context to default (mm, radians, read.precision.val, etc.)");
	cls_STEPControl_ActorRead.def("ComputeTransformation", (Standard_Boolean (STEPControl_ActorRead::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<Transfer_TransientProcess> &, gp_Trsf &)) &STEPControl_ActorRead::ComputeTransformation, "Computes transformation defined by two axis placements (in MAPPED_ITEM or ITEM_DEFINED_TRANSFORMATION) taking into account their representation contexts (i.e. units, which may be different) Returns True if transformation is computed and is not an identity.", py::arg("Origin"), py::arg("Target"), py::arg("OrigContext"), py::arg("TargContext"), py::arg("TP"), py::arg("Trsf"));
	cls_STEPControl_ActorRead.def("ComputeSRRWT", (Standard_Boolean (STEPControl_ActorRead::*)(const opencascade::handle<StepRepr_RepresentationRelationship> &, const opencascade::handle<Transfer_TransientProcess> &, gp_Trsf &)) &STEPControl_ActorRead::ComputeSRRWT, "Computes transformation defined by given REPRESENTATION_RELATIONSHIP_WITH_TRANSFORMATION", py::arg("SRR"), py::arg("TP"), py::arg("Trsf"));
	cls_STEPControl_ActorRead.def_static("get_type_name_", (const char * (*)()) &STEPControl_ActorRead::get_type_name, "None");
	cls_STEPControl_ActorRead.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPControl_ActorRead::get_type_descriptor, "None");
	cls_STEPControl_ActorRead.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPControl_ActorRead::*)() const ) &STEPControl_ActorRead::DynamicType, "None");


}
