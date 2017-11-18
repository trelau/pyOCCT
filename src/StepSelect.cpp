#include <pyOCCT_Common.hpp>

#include <IFSelect_Signature.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Type.hxx>
#include <StepSelect_StepType.hxx>
#include <IFSelect_Activator.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <StepSelect_Activator.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <StepData_StepWriter.hxx>
#include <TCollection_AsciiString.hxx>
#include <StepSelect_FileModifier.hxx>
#include <StepSelect_FloatFormat.hxx>
#include <IFSelect_Modifier.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Interface_CopyTool.hxx>
#include <StepData_StepModel.hxx>
#include <StepData_Protocol.hxx>
#include <StepSelect_ModelModifier.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <Interface_EntityIterator.hxx>
#include <Message_Messenger.hxx>
#include <StepSelect_WorkLibrary.hxx>

PYBIND11_MODULE(StepSelect, mod) {

	// IMPORT
	py::module::import("OCCT.IFSelect");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Message");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepSelect_StepType.hxx
	py::class_<StepSelect_StepType, opencascade::handle<StepSelect_StepType>, IFSelect_Signature> cls_StepSelect_StepType(mod, "StepSelect_StepType", "StepType is a Signature specific to Step definitions : it considers the type as defined in STEP Schemas, the same which is used in files. For a Complex Type, if its definition is known, StepType produces the list of basic types, separated by commas, the whole between brackets : '(TYPE1,TYPE2..)'. If its precise definition is not known (simply it is known as Complex, it can be recognised, but the list is produced at Write time only), StepType produces : '(..COMPLEX TYPE..)'");
	cls_StepSelect_StepType.def(py::init<>());
	cls_StepSelect_StepType.def("SetProtocol", (void (StepSelect_StepType::*)(const opencascade::handle<Interface_Protocol> &)) &StepSelect_StepType::SetProtocol, "Sets the StepType signature to work with a Protocol : this initialises the library", py::arg("proto"));
	cls_StepSelect_StepType.def("Value", (Standard_CString (StepSelect_StepType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const ) &StepSelect_StepType::Value, "Returns the Step Type defined from the Protocol (see above). If <ent> is not recognised, produces '..NOT FROM SCHEMA <name>..'", py::arg("ent"), py::arg("model"));
	cls_StepSelect_StepType.def_static("get_type_name_", (const char * (*)()) &StepSelect_StepType::get_type_name, "None");
	cls_StepSelect_StepType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_StepType::get_type_descriptor, "None");
	cls_StepSelect_StepType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_StepType::*)() const ) &StepSelect_StepType::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepSelect_Activator.hxx
	py::class_<StepSelect_Activator, opencascade::handle<StepSelect_Activator>, IFSelect_Activator> cls_StepSelect_Activator(mod, "StepSelect_Activator", "Performs Actions specific to StepSelect, i.e. creation of Step Selections and Counters, plus dumping specific to Step");
	cls_StepSelect_Activator.def(py::init<>());
	cls_StepSelect_Activator.def("Do", (IFSelect_ReturnStatus (StepSelect_Activator::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &StepSelect_Activator::Do, "Executes a Command Line for StepSelect", py::arg("number"), py::arg("pilot"));
	cls_StepSelect_Activator.def("Help", (Standard_CString (StepSelect_Activator::*)(const Standard_Integer) const ) &StepSelect_Activator::Help, "Sends a short help message for StepSelect commands", py::arg("number"));
	cls_StepSelect_Activator.def_static("get_type_name_", (const char * (*)()) &StepSelect_Activator::get_type_name, "None");
	cls_StepSelect_Activator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_Activator::get_type_descriptor, "None");
	cls_StepSelect_Activator.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_Activator::*)() const ) &StepSelect_Activator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepSelect_FileModifier.hxx
	py::class_<StepSelect_FileModifier, opencascade::handle<StepSelect_FileModifier>, IFSelect_GeneralModifier> cls_StepSelect_FileModifier(mod, "StepSelect_FileModifier", "None");
	cls_StepSelect_FileModifier.def("Perform", (void (StepSelect_FileModifier::*)(IFSelect_ContextWrite &, StepData_StepWriter &) const ) &StepSelect_FileModifier::Perform, "Perform the action specific to each class of File Modifier <ctx> is the ContextWrite, which brings : the model, the protocol, the file name, plus the object AppliedModifiers (not used here) and the CheckList Remark that the model has to be casted for specific access", py::arg("ctx"), py::arg("writer"));
	cls_StepSelect_FileModifier.def_static("get_type_name_", (const char * (*)()) &StepSelect_FileModifier::get_type_name, "None");
	cls_StepSelect_FileModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_FileModifier::get_type_descriptor, "None");
	cls_StepSelect_FileModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_FileModifier::*)() const ) &StepSelect_FileModifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepSelect_FloatFormat.hxx
	py::class_<StepSelect_FloatFormat, opencascade::handle<StepSelect_FloatFormat>, StepSelect_FileModifier> cls_StepSelect_FloatFormat(mod, "StepSelect_FloatFormat", "This class gives control out format for floatting values : ZeroSuppress or no, Main Format, Format in Range (for values around 1.), as StepWriter allows to manage it. Formats are given under C-printf form");
	cls_StepSelect_FloatFormat.def(py::init<>());
	cls_StepSelect_FloatFormat.def("SetDefault", [](StepSelect_FloatFormat &self) -> void { return self.SetDefault(); });
	cls_StepSelect_FloatFormat.def("SetDefault", (void (StepSelect_FloatFormat::*)(const Standard_Integer)) &StepSelect_FloatFormat::SetDefault, "Sets FloatFormat to default value (see Create) but if <digits> is given positive, it commands Formats (main and range) to ensure <digits> significant digits to be displayed", py::arg("digits"));
	cls_StepSelect_FloatFormat.def("SetZeroSuppress", (void (StepSelect_FloatFormat::*)(const Standard_Boolean)) &StepSelect_FloatFormat::SetZeroSuppress, "Sets ZeroSuppress mode to a new value", py::arg("mode"));
	cls_StepSelect_FloatFormat.def("SetFormat", [](StepSelect_FloatFormat &self) -> void { return self.SetFormat(); });
	cls_StepSelect_FloatFormat.def("SetFormat", (void (StepSelect_FloatFormat::*)(const Standard_CString)) &StepSelect_FloatFormat::SetFormat, "Sets Main Format to a new value Remark : SetFormat, SetZeroSuppress and SetFormatForRange are independant", py::arg("format"));
	cls_StepSelect_FloatFormat.def("SetFormatForRange", [](StepSelect_FloatFormat &self) -> void { return self.SetFormatForRange(); });
	cls_StepSelect_FloatFormat.def("SetFormatForRange", [](StepSelect_FloatFormat &self, const Standard_CString a0) -> void { return self.SetFormatForRange(a0); }, py::arg("format"));
	cls_StepSelect_FloatFormat.def("SetFormatForRange", [](StepSelect_FloatFormat &self, const Standard_CString a0, const Standard_Real a1) -> void { return self.SetFormatForRange(a0, a1); }, py::arg("format"), py::arg("Rmin"));
	cls_StepSelect_FloatFormat.def("SetFormatForRange", (void (StepSelect_FloatFormat::*)(const Standard_CString, const Standard_Real, const Standard_Real)) &StepSelect_FloatFormat::SetFormatForRange, "Sets Format for Range to a new value with its range of application. To cancel it, give format as '' (empty string) Remark that if the condition (0. < Rmin < Rmax) is not verified, this secondary format will be ignored. Moreover, this secondary format is intended to be used in a range around 1.", py::arg("format"), py::arg("Rmin"), py::arg("Rmax"));
	cls_StepSelect_FloatFormat.def("Format", (void (StepSelect_FloatFormat::*)(Standard_Boolean &, TCollection_AsciiString &, Standard_Boolean &, TCollection_AsciiString &, Standard_Real &, Standard_Real &) const ) &StepSelect_FloatFormat::Format, "Returns all recorded parameters : zerosup : ZeroSuppress status mainform : Main Format (which applies out of the range, or for every real if no range is set) hasrange : True if a FormatInRange is set, False else (following parameters do not apply if it is False) forminrange : Secondary Format (it applies inside the range) rangemin, rangemax : the range in which the secondary format applies", py::arg("zerosup"), py::arg("mainform"), py::arg("hasrange"), py::arg("forminrange"), py::arg("rangemin"), py::arg("rangemax"));
	cls_StepSelect_FloatFormat.def("Perform", (void (StepSelect_FloatFormat::*)(IFSelect_ContextWrite &, StepData_StepWriter &) const ) &StepSelect_FloatFormat::Perform, "Sets the Floatting Formats of StepWriter to the recorded parameters", py::arg("ctx"), py::arg("writer"));
	cls_StepSelect_FloatFormat.def("Label", (TCollection_AsciiString (StepSelect_FloatFormat::*)() const ) &StepSelect_FloatFormat::Label, "Returns specific Label : for instance, 'Float Format [ZeroSuppress] %E [, in range R1-R2 %f]'");
	cls_StepSelect_FloatFormat.def_static("get_type_name_", (const char * (*)()) &StepSelect_FloatFormat::get_type_name, "None");
	cls_StepSelect_FloatFormat.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_FloatFormat::get_type_descriptor, "None");
	cls_StepSelect_FloatFormat.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_FloatFormat::*)() const ) &StepSelect_FloatFormat::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepSelect_ModelModifier.hxx
	py::class_<StepSelect_ModelModifier, opencascade::handle<StepSelect_ModelModifier>, IFSelect_Modifier> cls_StepSelect_ModelModifier(mod, "StepSelect_ModelModifier", "None");
	cls_StepSelect_ModelModifier.def("Perform", (void (StepSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const ) &StepSelect_ModelModifier::Perform, "The inherited Perform does the required cast (and refuses to go further if cast has failed) then calls the instantiated Performing", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
	cls_StepSelect_ModelModifier.def("PerformProtocol", (void (StepSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<StepData_StepModel> &, const opencascade::handle<StepData_Protocol> &, Interface_CopyTool &) const ) &StepSelect_ModelModifier::PerformProtocol, "Specific Perform with Protocol. It is defined to let the Protocol unused and to call Performing without Protocol (most current case). It can be redefined if specific action requires Protocol.", py::arg("ctx"), py::arg("target"), py::arg("proto"), py::arg("TC"));
	cls_StepSelect_ModelModifier.def("Performing", (void (StepSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<StepData_StepModel> &, Interface_CopyTool &) const ) &StepSelect_ModelModifier::Performing, "Specific Perform, without Protocol. If Performing with Protocol is redefined, Performing without Protocol must though be defined to do nothing (not called, but demanded by the linker)", py::arg("ctx"), py::arg("target"), py::arg("TC"));
	cls_StepSelect_ModelModifier.def_static("get_type_name_", (const char * (*)()) &StepSelect_ModelModifier::get_type_name, "None");
	cls_StepSelect_ModelModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_ModelModifier::get_type_descriptor, "None");
	cls_StepSelect_ModelModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_ModelModifier::*)() const ) &StepSelect_ModelModifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepSelect_WorkLibrary.hxx
	py::class_<StepSelect_WorkLibrary, opencascade::handle<StepSelect_WorkLibrary>, IFSelect_WorkLibrary> cls_StepSelect_WorkLibrary(mod, "StepSelect_WorkLibrary", "Performs Read and Write a STEP File with a STEP Model Following the protocols, Copy may be implemented or not");
	cls_StepSelect_WorkLibrary.def(py::init<>());
	cls_StepSelect_WorkLibrary.def(py::init<const Standard_Boolean>(), py::arg("copymode"));
	cls_StepSelect_WorkLibrary.def("SetDumpLabel", (void (StepSelect_WorkLibrary::*)(const Standard_Integer)) &StepSelect_WorkLibrary::SetDumpLabel, "Selects a mode to dump entities 0 (D) : prints numbers, then displays table number/label 1 : prints labels, then displays table label/number 2 : prints labels onky", py::arg("mode"));
	cls_StepSelect_WorkLibrary.def("ReadFile", (Standard_Integer (StepSelect_WorkLibrary::*)(const Standard_CString, opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &) const ) &StepSelect_WorkLibrary::ReadFile, "Reads a STEP File and returns a STEP Model (into <mod>), or lets <mod> 'Null' in case of Error Returns 0 if OK, 1 if Read Error, -1 if File not opened", py::arg("name"), py::arg("model"), py::arg("protocol"));
	cls_StepSelect_WorkLibrary.def("WriteFile", (Standard_Boolean (StepSelect_WorkLibrary::*)(IFSelect_ContextWrite &) const ) &StepSelect_WorkLibrary::WriteFile, "Writes a File from a STEP Model Returns False (and writes no file) if <ctx> does not bring a STEP Model", py::arg("ctx"));
	cls_StepSelect_WorkLibrary.def("CopyModel", (Standard_Boolean (StepSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_InterfaceModel> &, const Interface_EntityIterator &, Interface_CopyTool &) const ) &StepSelect_WorkLibrary::CopyModel, "Performs the copy of entities from an original model to a new one. Works according <copymode> : if True, standard copy is run else nothing is done and returned value is False", py::arg("original"), py::arg("newmodel"), py::arg("list"), py::arg("TC"));
	cls_StepSelect_WorkLibrary.def("DumpEntity", (void (StepSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &StepSelect_WorkLibrary::DumpEntity, "Dumps an entity under STEP form, i.e. as a part of a Step file Works with a StepDumper. Level 0 just displays type; level 1 displays the entity itself and level 2 displays the entity plus its shared ones (one sub-level : immediately shared entities)", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"), py::arg("level"));
	cls_StepSelect_WorkLibrary.def_static("get_type_name_", (const char * (*)()) &StepSelect_WorkLibrary::get_type_name, "None");
	cls_StepSelect_WorkLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_WorkLibrary::get_type_descriptor, "None");
	cls_StepSelect_WorkLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_WorkLibrary::*)() const ) &StepSelect_WorkLibrary::DynamicType, "None");


}
