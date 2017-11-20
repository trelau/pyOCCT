#include <pyOCCT_Common.hpp>

#include <STEPControl_ActorWrite.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <STEPCAFControl_ActorWrite.hxx>
#include <STEPControl_Controller.hxx>
#include <STEPCAFControl_Controller.hxx>
#include <Standard_Transient.hxx>
#include <XSControl_WorkSession.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TDF_Label.hxx>
#include <STEPCAFControl_ExternFile.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <STEPCAFControl_DataMapOfLabelExternFile.hxx>
#include <STEPCAFControl_DataMapOfLabelShape.hxx>
#include <STEPCAFControl_DataMapOfPDExternFile.hxx>
#include <STEPCAFControl_DataMapOfSDRExternFile.hxx>
#include <STEPCAFControl_DataMapOfShapePD.hxx>
#include <STEPCAFControl_DataMapOfShapeSDR.hxx>
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <XCAFDimTolObjects_DimensionModifiersSequence.hxx>
#include <StepShape_LimitsAndFits.hxx>
#include <XCAFDimTolObjects_DimensionFormVariance.hxx>
#include <XCAFDimTolObjects_DimensionGrade.hxx>
#include <XCAFDimTolObjects_DimensionType.hxx>
#include <XCAFDimTolObjects_DatumTargetType.hxx>
#include <XCAFDimTolObjects_DimensionQualifier.hxx>
#include <XCAFDimTolObjects_GeomToleranceTypeValue.hxx>
#include <XCAFDimTolObjects_DimensionModif.hxx>
#include <StepDimTol_GeometricToleranceType.hxx>
#include <XCAFDimTolObjects_GeomToleranceType.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepDimTol_GeometricToleranceModifier.hxx>
#include <XCAFDimTolObjects_GeomToleranceModif.hxx>
#include <StepDimTol_HArray1OfDatumReferenceModifier.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>
#include <StepBasic_Unit.hxx>
#include <StepVisual_TessellatedGeometricSet.hxx>
#include <STEPCAFControl_GDTProperty.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_AsciiString.hxx>
#include <STEPControl_Reader.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <STEPConstruct_Tool.hxx>
#include <XCAFDoc_DataMapOfShapeLabel.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <STEPControl_StepModelType.hxx>
#include <STEPControl_Writer.hxx>
#include <STEPCAFControl_Writer.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(STEPCAFControl, mod) {

	// IMPORT
	py::module::import("OCCT.STEPControl");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.XSControl");
	py::module::import("OCCT.IFSelect");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.XCAFDimTolObjects");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.StepDimTol");
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.StepVisual");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.XCAFDoc");
	py::module::import("OCCT.STEPConstruct");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_ActorWrite.hxx
	py::class_<STEPCAFControl_ActorWrite, opencascade::handle<STEPCAFControl_ActorWrite>, STEPControl_ActorWrite> cls_STEPCAFControl_ActorWrite(mod, "STEPCAFControl_ActorWrite", "Extends ActorWrite from STEPControl by analysis of whether shape is assembly (based on information from DECAF)");
	cls_STEPCAFControl_ActorWrite.def(py::init<>());
	cls_STEPCAFControl_ActorWrite.def("IsAssembly", (Standard_Boolean (STEPCAFControl_ActorWrite::*)(TopoDS_Shape &) const ) &STEPCAFControl_ActorWrite::IsAssembly, "Check whether shape S is assembly Returns True if shape is registered in assemblies map", py::arg("S"));
	cls_STEPCAFControl_ActorWrite.def("SetStdMode", [](STEPCAFControl_ActorWrite &self) -> void { return self.SetStdMode(); });
	cls_STEPCAFControl_ActorWrite.def("SetStdMode", (void (STEPCAFControl_ActorWrite::*)(const Standard_Boolean)) &STEPCAFControl_ActorWrite::SetStdMode, "Set standard mode of work In standard mode Actor (default) behaves exactly as its ancestor, also map is cleared", py::arg("stdmode"));
	cls_STEPCAFControl_ActorWrite.def("ClearMap", (void (STEPCAFControl_ActorWrite::*)()) &STEPCAFControl_ActorWrite::ClearMap, "Clears map of shapes registered as assemblies");
	cls_STEPCAFControl_ActorWrite.def("RegisterAssembly", (void (STEPCAFControl_ActorWrite::*)(const TopoDS_Shape &)) &STEPCAFControl_ActorWrite::RegisterAssembly, "Registers shape to be written as assembly The shape should be TopoDS_Compound (else does nothing)", py::arg("S"));
	cls_STEPCAFControl_ActorWrite.def_static("get_type_name_", (const char * (*)()) &STEPCAFControl_ActorWrite::get_type_name, "None");
	cls_STEPCAFControl_ActorWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPCAFControl_ActorWrite::get_type_descriptor, "None");
	cls_STEPCAFControl_ActorWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPCAFControl_ActorWrite::*)() const ) &STEPCAFControl_ActorWrite::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_Controller.hxx
	py::class_<STEPCAFControl_Controller, opencascade::handle<STEPCAFControl_Controller>, STEPControl_Controller> cls_STEPCAFControl_Controller(mod, "STEPCAFControl_Controller", "Extends Controller from STEPControl in order to provide ActorWrite adapted for writing assemblies from DECAF Note that ActorRead from STEPControl is used for reading (inherited automatically)");
	cls_STEPCAFControl_Controller.def(py::init<>());
	cls_STEPCAFControl_Controller.def_static("Init_", (Standard_Boolean (*)()) &STEPCAFControl_Controller::Init, "Standard Initialisation. It creates a Controller for STEP-XCAF and records it to various names, available to select it later Returns True when done, False if could not be done");
	cls_STEPCAFControl_Controller.def_static("get_type_name_", (const char * (*)()) &STEPCAFControl_Controller::get_type_name, "None");
	cls_STEPCAFControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPCAFControl_Controller::get_type_descriptor, "None");
	cls_STEPCAFControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPCAFControl_Controller::*)() const ) &STEPCAFControl_Controller::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_ExternFile.hxx
	py::class_<STEPCAFControl_ExternFile, opencascade::handle<STEPCAFControl_ExternFile>, Standard_Transient> cls_STEPCAFControl_ExternFile(mod, "STEPCAFControl_ExternFile", "Auxiliary class serving as container for data resulting from translation of external file");
	cls_STEPCAFControl_ExternFile.def(py::init<>());
	cls_STEPCAFControl_ExternFile.def("SetWS", (void (STEPCAFControl_ExternFile::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPCAFControl_ExternFile::SetWS, "None", py::arg("WS"));
	cls_STEPCAFControl_ExternFile.def("GetWS", (opencascade::handle<XSControl_WorkSession> (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::GetWS, "None");
	cls_STEPCAFControl_ExternFile.def("SetLoadStatus", (void (STEPCAFControl_ExternFile::*)(const IFSelect_ReturnStatus)) &STEPCAFControl_ExternFile::SetLoadStatus, "None", py::arg("stat"));
	cls_STEPCAFControl_ExternFile.def("GetLoadStatus", (IFSelect_ReturnStatus (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::GetLoadStatus, "None");
	cls_STEPCAFControl_ExternFile.def("SetTransferStatus", (void (STEPCAFControl_ExternFile::*)(const Standard_Boolean)) &STEPCAFControl_ExternFile::SetTransferStatus, "None", py::arg("isok"));
	cls_STEPCAFControl_ExternFile.def("GetTransferStatus", (Standard_Boolean (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::GetTransferStatus, "None");
	cls_STEPCAFControl_ExternFile.def("SetWriteStatus", (void (STEPCAFControl_ExternFile::*)(const IFSelect_ReturnStatus)) &STEPCAFControl_ExternFile::SetWriteStatus, "None", py::arg("stat"));
	cls_STEPCAFControl_ExternFile.def("GetWriteStatus", (IFSelect_ReturnStatus (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::GetWriteStatus, "None");
	cls_STEPCAFControl_ExternFile.def("SetName", (void (STEPCAFControl_ExternFile::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPCAFControl_ExternFile::SetName, "None", py::arg("name"));
	cls_STEPCAFControl_ExternFile.def("GetName", (opencascade::handle<TCollection_HAsciiString> (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::GetName, "None");
	cls_STEPCAFControl_ExternFile.def("SetLabel", (void (STEPCAFControl_ExternFile::*)(const TDF_Label &)) &STEPCAFControl_ExternFile::SetLabel, "None", py::arg("L"));
	cls_STEPCAFControl_ExternFile.def("GetLabel", (TDF_Label (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::GetLabel, "None");
	cls_STEPCAFControl_ExternFile.def_static("get_type_name_", (const char * (*)()) &STEPCAFControl_ExternFile::get_type_name, "None");
	cls_STEPCAFControl_ExternFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPCAFControl_ExternFile::get_type_descriptor, "None");
	cls_STEPCAFControl_ExternFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPCAFControl_ExternFile::*)() const ) &STEPCAFControl_ExternFile::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_GDTProperty.hxx
	py::class_<STEPCAFControl_GDTProperty, std::unique_ptr<STEPCAFControl_GDTProperty, Deleter<STEPCAFControl_GDTProperty>>> cls_STEPCAFControl_GDTProperty(mod, "STEPCAFControl_GDTProperty", "This class provides tools for access (read) the GDT properties.");
	cls_STEPCAFControl_GDTProperty.def(py::init<>());
	cls_STEPCAFControl_GDTProperty.def_static("GetDimModifiers_", (void (*)(const opencascade::handle<StepRepr_CompoundRepresentationItem> &, XCAFDimTolObjects_DimensionModifiersSequence &)) &STEPCAFControl_GDTProperty::GetDimModifiers, "None", py::arg("theCRI"), py::arg("theModifiers"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDimClassOfTolerance_", [](const opencascade::handle<StepShape_LimitsAndFits> & theLAF, Standard_Boolean & theHolle, XCAFDimTolObjects_DimensionFormVariance & theFV, XCAFDimTolObjects_DimensionGrade & theG){ STEPCAFControl_GDTProperty::GetDimClassOfTolerance(theLAF, theHolle, theFV, theG); return theHolle; }, "None", py::arg("theLAF"), py::arg("theHolle"), py::arg("theFV"), py::arg("theG"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDimType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_DimensionType &)) &STEPCAFControl_GDTProperty::GetDimType, "None", py::arg("theName"), py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDatumTargetType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_DatumTargetType &)) &STEPCAFControl_GDTProperty::GetDatumTargetType, "None", py::arg("theDescription"), py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDimQualifierType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_DimensionQualifier &)) &STEPCAFControl_GDTProperty::GetDimQualifierType, "None", py::arg("theDescription"), py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetTolValueType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_GeomToleranceTypeValue &)) &STEPCAFControl_GDTProperty::GetTolValueType, "None", py::arg("theDescription"), py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetTolValueType_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_GeomToleranceTypeValue &)) &STEPCAFControl_GDTProperty::GetTolValueType, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDimTypeName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DimensionType)) &STEPCAFControl_GDTProperty::GetDimTypeName, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDimQualifierName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DimensionQualifier)) &STEPCAFControl_GDTProperty::GetDimQualifierName, "None", py::arg("theQualifier"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDimModifierName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DimensionModif)) &STEPCAFControl_GDTProperty::GetDimModifierName, "None", py::arg("theModifier"));
	cls_STEPCAFControl_GDTProperty.def_static("GetLimitsAndFits_", (opencascade::handle<StepShape_LimitsAndFits> (*)(Standard_Boolean, XCAFDimTolObjects_DimensionFormVariance, XCAFDimTolObjects_DimensionGrade)) &STEPCAFControl_GDTProperty::GetLimitsAndFits, "None", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDatumTargetName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DatumTargetType)) &STEPCAFControl_GDTProperty::GetDatumTargetName, "None", py::arg("theDatumType"));
	cls_STEPCAFControl_GDTProperty.def_static("IsDimensionalLocation_", (Standard_Boolean (*)(const XCAFDimTolObjects_DimensionType)) &STEPCAFControl_GDTProperty::IsDimensionalLocation, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("IsDimensionalSize_", (Standard_Boolean (*)(const XCAFDimTolObjects_DimensionType)) &STEPCAFControl_GDTProperty::IsDimensionalSize, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetGeomToleranceType_", (StepDimTol_GeometricToleranceType (*)(const XCAFDimTolObjects_GeomToleranceType)) &STEPCAFControl_GDTProperty::GetGeomToleranceType, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetGeomToleranceType_", (XCAFDimTolObjects_GeomToleranceType (*)(const StepDimTol_GeometricToleranceType)) &STEPCAFControl_GDTProperty::GetGeomToleranceType, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetGeomTolerance_", (opencascade::handle<StepDimTol_GeometricTolerance> (*)(const XCAFDimTolObjects_GeomToleranceType)) &STEPCAFControl_GDTProperty::GetGeomTolerance, "None", py::arg("theType"));
	cls_STEPCAFControl_GDTProperty.def_static("GetGeomToleranceModifier_", (StepDimTol_GeometricToleranceModifier (*)(const XCAFDimTolObjects_GeomToleranceModif)) &STEPCAFControl_GDTProperty::GetGeomToleranceModifier, "None", py::arg("theModifier"));
	cls_STEPCAFControl_GDTProperty.def_static("GetDatumRefModifiers_", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> (*)(const XCAFDimTolObjects_DatumModifiersSequence, const XCAFDimTolObjects_DatumModifWithValue, const Standard_Real, const StepBasic_Unit)) &STEPCAFControl_GDTProperty::GetDatumRefModifiers, "None", py::arg("theModifiers"), py::arg("theModifWithVal"), py::arg("theValue"), py::arg("theUnit"));
	cls_STEPCAFControl_GDTProperty.def_static("GetTessellation_", (opencascade::handle<StepVisual_TessellatedGeometricSet> (*)(const TopoDS_Shape)) &STEPCAFControl_GDTProperty::GetTessellation, "None", py::arg("theShape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_Reader.hxx
	py::class_<STEPCAFControl_Reader, std::unique_ptr<STEPCAFControl_Reader, Deleter<STEPCAFControl_Reader>>> cls_STEPCAFControl_Reader(mod, "STEPCAFControl_Reader", "Provides a tool to read STEP file and put it into DECAF document. Besides transfer of shapes (including assemblies) provided by STEPControl, supports also colors and part names");
	cls_STEPCAFControl_Reader.def(py::init<>());
	cls_STEPCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
	cls_STEPCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));
	cls_STEPCAFControl_Reader.def("Init", [](STEPCAFControl_Reader &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.Init(a0); }, py::arg("WS"));
	cls_STEPCAFControl_Reader.def("Init", (void (STEPCAFControl_Reader::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &STEPCAFControl_Reader::Init, "Clears the internal data structures and attaches to a new session Clears the session if it was not yet set for STEP", py::arg("WS"), py::arg("scratch"));
	cls_STEPCAFControl_Reader.def("ReadFile", (IFSelect_ReturnStatus (STEPCAFControl_Reader::*)(const Standard_CString)) &STEPCAFControl_Reader::ReadFile, "Loads a file and returns the read status Provided for use like single-file reader", py::arg("filename"));
	cls_STEPCAFControl_Reader.def("NbRootsForTransfer", (Standard_Integer (STEPCAFControl_Reader::*)()) &STEPCAFControl_Reader::NbRootsForTransfer, "Returns number of roots recognized for transfer Shortcut for Reader().NbRootsForTransfer()");
	cls_STEPCAFControl_Reader.def("TransferOneRoot", (Standard_Boolean (STEPCAFControl_Reader::*)(const Standard_Integer, opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::TransferOneRoot, "Translates currently loaded STEP file into the document Returns True if succeeded, and False in case of fail Provided for use like single-file reader", py::arg("num"), py::arg("doc"));
	cls_STEPCAFControl_Reader.def("Transfer", (Standard_Boolean (STEPCAFControl_Reader::*)(opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::Transfer, "Translates currently loaded STEP file into the document Returns True if succeeded, and False in case of fail Provided for use like single-file reader", py::arg("doc"));
	cls_STEPCAFControl_Reader.def("Perform", (Standard_Boolean (STEPCAFControl_Reader::*)(const TCollection_AsciiString &, opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::Perform, "None", py::arg("filename"), py::arg("doc"));
	cls_STEPCAFControl_Reader.def("Perform", (Standard_Boolean (STEPCAFControl_Reader::*)(const Standard_CString, opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::Perform, "Translate STEP file given by filename into the document Return True if succeeded, and False in case of fail", py::arg("filename"), py::arg("doc"));
	cls_STEPCAFControl_Reader.def("ExternFiles", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<STEPCAFControl_ExternFile> > & (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::ExternFiles, "Returns data on external files Returns Null handle if no external files are read");
	cls_STEPCAFControl_Reader.def("ExternFile", (Standard_Boolean (STEPCAFControl_Reader::*)(const Standard_CString, opencascade::handle<STEPCAFControl_ExternFile> &) const ) &STEPCAFControl_Reader::ExternFile, "Returns data on external file by its name Returns False if no external file with given name is read", py::arg("name"), py::arg("ef"));
	cls_STEPCAFControl_Reader.def("ChangeReader", (STEPControl_Reader & (STEPCAFControl_Reader::*)()) &STEPCAFControl_Reader::ChangeReader, "Returns basic reader");
	cls_STEPCAFControl_Reader.def("Reader", (const STEPControl_Reader & (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::Reader, "Returns basic reader as const");
	cls_STEPCAFControl_Reader.def_static("FindInstance_", (TDF_Label (*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &, const opencascade::handle<XCAFDoc_ShapeTool> &, const STEPConstruct_Tool &, const STEPCAFControl_DataMapOfPDExternFile &, const XCAFDoc_DataMapOfShapeLabel &)) &STEPCAFControl_Reader::FindInstance, "Returns label of instance of an assembly component corresponding to a given NAUO", py::arg("NAUO"), py::arg("STool"), py::arg("Tool"), py::arg("PDRFileMap"), py::arg("ShapeLabelMap"));
	cls_STEPCAFControl_Reader.def("SetColorMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetColorMode, "Set ColorMode for indicate read Colors or not.", py::arg("colormode"));
	cls_STEPCAFControl_Reader.def("GetColorMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetColorMode, "None");
	cls_STEPCAFControl_Reader.def("SetNameMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetNameMode, "Set NameMode for indicate read Name or not.", py::arg("namemode"));
	cls_STEPCAFControl_Reader.def("GetNameMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetNameMode, "None");
	cls_STEPCAFControl_Reader.def("SetLayerMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetLayerMode, "Set LayerMode for indicate read Layers or not.", py::arg("layermode"));
	cls_STEPCAFControl_Reader.def("GetLayerMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetLayerMode, "None");
	cls_STEPCAFControl_Reader.def("SetPropsMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetPropsMode, "PropsMode for indicate read Validation properties or not.", py::arg("propsmode"));
	cls_STEPCAFControl_Reader.def("GetPropsMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetPropsMode, "None");
	cls_STEPCAFControl_Reader.def("SetSHUOMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetSHUOMode, "Set SHUO mode for indicate write SHUO or not.", py::arg("shuomode"));
	cls_STEPCAFControl_Reader.def("GetSHUOMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetSHUOMode, "None");
	cls_STEPCAFControl_Reader.def("SetGDTMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetGDTMode, "Set GDT mode for indicate write GDT or not.", py::arg("gdtmode"));
	cls_STEPCAFControl_Reader.def("GetGDTMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetGDTMode, "None");
	cls_STEPCAFControl_Reader.def("SetMatMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetMatMode, "Set Material mode", py::arg("matmode"));
	cls_STEPCAFControl_Reader.def("GetMatMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetMatMode, "None");
	cls_STEPCAFControl_Reader.def("SetViewMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetViewMode, "Set View mode", py::arg("viewmode"));
	cls_STEPCAFControl_Reader.def("GetViewMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const ) &STEPCAFControl_Reader::GetViewMode, "Get View mode");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_Writer.hxx
	py::class_<STEPCAFControl_Writer, std::unique_ptr<STEPCAFControl_Writer, Deleter<STEPCAFControl_Writer>>> cls_STEPCAFControl_Writer(mod, "STEPCAFControl_Writer", "Provides a tool to write DECAF document to the STEP file. Besides transfer of shapes (including assemblies) provided by STEPControl, supports also colors and part names");
	cls_STEPCAFControl_Writer.def(py::init<>());
	cls_STEPCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
	cls_STEPCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));
	cls_STEPCAFControl_Writer.def("Init", [](STEPCAFControl_Writer &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.Init(a0); }, py::arg("WS"));
	cls_STEPCAFControl_Writer.def("Init", (void (STEPCAFControl_Writer::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &STEPCAFControl_Writer::Init, "Clears the internal data structures and attaches to a new session Clears the session if it was not yet set for STEP", py::arg("WS"), py::arg("scratch"));
	cls_STEPCAFControl_Writer.def("Write", (IFSelect_ReturnStatus (STEPCAFControl_Writer::*)(const Standard_CString)) &STEPCAFControl_Writer::Write, "Writes all the produced models into file In case of multimodel with extern references, filename will be a name of root file, all other files have names of corresponding parts Provided for use like single-file writer", py::arg("filename"));
	cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const opencascade::handle<TDocStd_Document> & a0) -> Standard_Boolean { return self.Transfer(a0); }, py::arg("doc"));
	cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const opencascade::handle<TDocStd_Document> & a0, const STEPControl_StepModelType a1) -> Standard_Boolean { return self.Transfer(a0, a1); }, py::arg("doc"), py::arg("mode"));
	cls_STEPCAFControl_Writer.def("Transfer", (Standard_Boolean (STEPCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const STEPControl_StepModelType, const Standard_CString)) &STEPCAFControl_Writer::Transfer, "Transfers a document (or single label) to a STEP model The mode of translation of shape is AsIs If multi is not null pointer, it switches to multifile mode (with external refs), and string pointed by <multi> gives prefix for names of extern files (can be empty string) Returns True if translation is OK", py::arg("doc"), py::arg("mode"), py::arg("multi"));
	cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const TDF_Label & a0) -> Standard_Boolean { return self.Transfer(a0); }, py::arg("L"));
	cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const TDF_Label & a0, const STEPControl_StepModelType a1) -> Standard_Boolean { return self.Transfer(a0, a1); }, py::arg("L"), py::arg("mode"));
	cls_STEPCAFControl_Writer.def("Transfer", (Standard_Boolean (STEPCAFControl_Writer::*)(const TDF_Label &, const STEPControl_StepModelType, const Standard_CString)) &STEPCAFControl_Writer::Transfer, "Method to transfer part of the document specified by label", py::arg("L"), py::arg("mode"), py::arg("multi"));
	cls_STEPCAFControl_Writer.def("Perform", (Standard_Boolean (STEPCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &)) &STEPCAFControl_Writer::Perform, "None", py::arg("doc"), py::arg("filename"));
	cls_STEPCAFControl_Writer.def("Perform", (Standard_Boolean (STEPCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const Standard_CString)) &STEPCAFControl_Writer::Perform, "Transfers a document and writes it to a STEP file Returns True if translation is OK", py::arg("doc"), py::arg("filename"));
	cls_STEPCAFControl_Writer.def("ExternFiles", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<STEPCAFControl_ExternFile> > & (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::ExternFiles, "Returns data on external files Returns Null handle if no external files are read");
	cls_STEPCAFControl_Writer.def("ExternFile", (Standard_Boolean (STEPCAFControl_Writer::*)(const TDF_Label &, opencascade::handle<STEPCAFControl_ExternFile> &) const ) &STEPCAFControl_Writer::ExternFile, "Returns data on external file by its original label Returns False if no external file with given name is read", py::arg("L"), py::arg("ef"));
	cls_STEPCAFControl_Writer.def("ExternFile", (Standard_Boolean (STEPCAFControl_Writer::*)(const Standard_CString, opencascade::handle<STEPCAFControl_ExternFile> &) const ) &STEPCAFControl_Writer::ExternFile, "Returns data on external file by its name Returns False if no external file with given name is read", py::arg("name"), py::arg("ef"));
	cls_STEPCAFControl_Writer.def("ChangeWriter", (STEPControl_Writer & (STEPCAFControl_Writer::*)()) &STEPCAFControl_Writer::ChangeWriter, "Returns basic reader for root file");
	cls_STEPCAFControl_Writer.def("Writer", (const STEPControl_Writer & (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::Writer, "Returns basic reader as const");
	cls_STEPCAFControl_Writer.def("SetColorMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetColorMode, "Set ColorMode for indicate write Colors or not.", py::arg("colormode"));
	cls_STEPCAFControl_Writer.def("GetColorMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetColorMode, "None");
	cls_STEPCAFControl_Writer.def("SetNameMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetNameMode, "Set NameMode for indicate write Name or not.", py::arg("namemode"));
	cls_STEPCAFControl_Writer.def("GetNameMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetNameMode, "None");
	cls_STEPCAFControl_Writer.def("SetLayerMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetLayerMode, "Set LayerMode for indicate write Layers or not.", py::arg("layermode"));
	cls_STEPCAFControl_Writer.def("GetLayerMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetLayerMode, "None");
	cls_STEPCAFControl_Writer.def("SetPropsMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetPropsMode, "PropsMode for indicate write Validation properties or not.", py::arg("propsmode"));
	cls_STEPCAFControl_Writer.def("GetPropsMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetPropsMode, "None");
	cls_STEPCAFControl_Writer.def("SetSHUOMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetSHUOMode, "Set SHUO mode for indicate write SHUO or not.", py::arg("shuomode"));
	cls_STEPCAFControl_Writer.def("GetSHUOMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetSHUOMode, "None");
	cls_STEPCAFControl_Writer.def("SetDimTolMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetDimTolMode, "Set dimtolmode for indicate write D&GTs or not.", py::arg("dimtolmode"));
	cls_STEPCAFControl_Writer.def("GetDimTolMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetDimTolMode, "None");
	cls_STEPCAFControl_Writer.def("SetMaterialMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetMaterialMode, "Set dimtolmode for indicate write D&GTs or not.", py::arg("matmode"));
	cls_STEPCAFControl_Writer.def("GetMaterialMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const ) &STEPCAFControl_Writer::GetMaterialMode, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_DataMapOfLabelExternFile.hxx
	bind_NCollection_DataMap<TDF_Label, opencascade::handle<STEPCAFControl_ExternFile>, TDF_LabelMapHasher>(mod, "STEPCAFControl_DataMapOfLabelExternFile");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_DataMapOfLabelShape.hxx
	bind_NCollection_DataMap<TDF_Label, TopoDS_Shape, TDF_LabelMapHasher>(mod, "STEPCAFControl_DataMapOfLabelShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_DataMapOfPDExternFile.hxx
	bind_NCollection_DataMap<opencascade::handle<StepBasic_ProductDefinition>, opencascade::handle<STEPCAFControl_ExternFile>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "STEPCAFControl_DataMapOfPDExternFile");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_DataMapOfSDRExternFile.hxx
	bind_NCollection_DataMap<opencascade::handle<StepShape_ShapeDefinitionRepresentation>, opencascade::handle<STEPCAFControl_ExternFile>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "STEPCAFControl_DataMapOfSDRExternFile");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_DataMapOfShapePD.hxx
	bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<StepBasic_ProductDefinition>, TopTools_ShapeMapHasher>(mod, "STEPCAFControl_DataMapOfShapePD");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPCAFControl_DataMapOfShapeSDR.hxx
	bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<StepShape_ShapeDefinitionRepresentation>, TopTools_ShapeMapHasher>(mod, "STEPCAFControl_DataMapOfShapeSDR");

	/* FIXME

	*/


}
