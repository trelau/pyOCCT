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

#include <XSControl_Reader.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESModel.hxx>
#include <IFSelect_PrintFail.hxx>
#include <IFSelect_PrintCount.hxx>
#include <IGESControl_Reader.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Transient.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Standard_OStream.hxx>
#include <IGESControl_Writer.hxx>
#include <Transfer_ActorOfFinderProcess.hxx>
#include <Transfer_Finder.hxx>
#include <Transfer_Binder.hxx>
#include <Standard_Type.hxx>
#include <IGESControl_ActorWrite.hxx>
#include <IGESToBRep_AlgoContainer.hxx>
#include <IGESControl_AlgoContainer.hxx>
#include <XSControl_Controller.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IGESControl_Controller.hxx>
#include <IGESToBRep_IGESBoundary.hxx>
#include <IGESToBRep_CurveAndSurface.hxx>
#include <IGESControl_IGESBoundary.hxx>
#include <IGESToBRep_ToolContainer.hxx>
#include <IGESControl_ToolContainer.hxx>

PYBIND11_MODULE(IGESControl, mod) {

	// IMPORT
	py::module::import("OCCT.XSControl");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.IFSelect");
	py::module::import("OCCT.Transfer");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.IGESToBRep");
	py::module::import("OCCT.Interface");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_Reader.hxx
	py::class_<IGESControl_Reader, std::unique_ptr<IGESControl_Reader, Deleter<IGESControl_Reader>>, XSControl_Reader> cls_IGESControl_Reader(mod, "IGESControl_Reader", "Reads IGES files, checks them and translates their contents into Open CASCADE models. The IGES data can be that of a whole model or that of a specific list of entities in the model. As in XSControl_Reader, you specify the list using a selection. For translation of iges files it is possible to use the following sequence: To change parameters of translation class Interface_Static should be used before the beginning of translation (see IGES Parameters and General Parameters) Creation of reader IGESControl_Reader reader; To load a file in a model use method: reader.ReadFile('filename.igs') To check a loading file use method Check: reader.Check(failsonly); where failsonly is equal to Standard_True or Standard_False; To print the results of load: reader.PrintCheckLoad(failsonly,mode) where mode is equal to the value of enumeration IFSelect_PrintCount To transfer entities from a model the following methods can be used: for the whole model reader.TransferRoots(onlyvisible); where onlyvisible is equal to Standard_True or Standard_False; To transfer a list of entities: reader.TransferList(list); To transfer one entity reader.TransferEntity(ent) or reader.Transfer(num); To obtain a result the following method can be used: reader.IsDone() reader.NbShapes() and reader.Shape(num); or reader.OneShape(); To print the results of transfer use method: reader.PrintTransferInfo(failwarn,mode); where printfail is equal to the value of enumeration IFSelect_PrintFail, mode see above. Gets correspondence between an IGES entity and a result shape obtained therefrom. reader.TransientProcess(); TopoDS_Shape shape = TransferBRep::ShapeResult(reader.TransientProcess(),ent);");
	cls_IGESControl_Reader.def(py::init<>());
	cls_IGESControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
	cls_IGESControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));
	cls_IGESControl_Reader.def("SetReadVisible", (void (IGESControl_Reader::*)(const Standard_Boolean)) &IGESControl_Reader::SetReadVisible, "Set the transion of ALL Roots (if theReadOnlyVisible is False) or of Visible Roots (if theReadOnlyVisible is True)", py::arg("ReadRoot"));
	cls_IGESControl_Reader.def("GetReadVisible", (Standard_Boolean (IGESControl_Reader::*)() const ) &IGESControl_Reader::GetReadVisible, "None");
	cls_IGESControl_Reader.def("IGESModel", (opencascade::handle<IGESData_IGESModel> (IGESControl_Reader::*)() const ) &IGESControl_Reader::IGESModel, "Returns the model as a IGESModel. It can then be consulted (header, product)");
	cls_IGESControl_Reader.def("NbRootsForTransfer", (Standard_Integer (IGESControl_Reader::*)()) &IGESControl_Reader::NbRootsForTransfer, "Determines the list of root entities from Model which are candidate for a transfer to a Shape (type of entities is PRODUCT) <theReadOnlyVisible> is taken into account to define roots");
	cls_IGESControl_Reader.def("PrintTransferInfo", (void (IGESControl_Reader::*)(const IFSelect_PrintFail, const IFSelect_PrintCount) const ) &IGESControl_Reader::PrintTransferInfo, "Prints Statistics and check list for Transfer", py::arg("failwarn"), py::arg("mode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_Writer.hxx
	py::class_<IGESControl_Writer, std::unique_ptr<IGESControl_Writer, Deleter<IGESControl_Writer>>> cls_IGESControl_Writer(mod, "IGESControl_Writer", "This class creates and writes IGES files from CAS.CADE models. An IGES file can be written to an existing IGES file or to a new one. The translation can be performed in one or several operations. Each translation operation outputs a distinct root entity in the IGES file. To write an IGES file it is possible to use the following sequence: To modify the IGES file header or to change translation parameters it is necessary to use class Interface_Static (see IGESParameters and GeneralParameters).");
	cls_IGESControl_Writer.def(py::init<>());
	cls_IGESControl_Writer.def(py::init<const Standard_CString>(), py::arg("unit"));
	cls_IGESControl_Writer.def(py::init<const Standard_CString, const Standard_Integer>(), py::arg("unit"), py::arg("modecr"));
	cls_IGESControl_Writer.def(py::init<const opencascade::handle<IGESData_IGESModel> &>(), py::arg("model"));
	cls_IGESControl_Writer.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const Standard_Integer>(), py::arg("model"), py::arg("modecr"));
	cls_IGESControl_Writer.def("Model", (const opencascade::handle<IGESData_IGESModel> & (IGESControl_Writer::*)() const ) &IGESControl_Writer::Model, "Returns the IGES model to be written in output.");
	cls_IGESControl_Writer.def("TransferProcess", (const opencascade::handle<Transfer_FinderProcess> & (IGESControl_Writer::*)() const ) &IGESControl_Writer::TransferProcess, "None");
	cls_IGESControl_Writer.def("SetTransferProcess", (void (IGESControl_Writer::*)(const opencascade::handle<Transfer_FinderProcess> &)) &IGESControl_Writer::SetTransferProcess, "Returns/Sets the TransferProcess : it contains final results and if some, check messages", py::arg("TP"));
	cls_IGESControl_Writer.def("AddShape", (Standard_Boolean (IGESControl_Writer::*)(const TopoDS_Shape &)) &IGESControl_Writer::AddShape, "Translates a Shape to IGES Entities and adds them to the model Returns True if done, False if Shape not suitable for IGES or null", py::arg("sh"));
	cls_IGESControl_Writer.def("AddGeom", (Standard_Boolean (IGESControl_Writer::*)(const opencascade::handle<Standard_Transient> &)) &IGESControl_Writer::AddGeom, "Translates a Geometry (Surface or Curve) to IGES Entities and adds them to the model Returns True if done, False if geom is neither a Surface or a Curve suitable for IGES or is null", py::arg("geom"));
	cls_IGESControl_Writer.def("AddEntity", (Standard_Boolean (IGESControl_Writer::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESControl_Writer::AddEntity, "Adds an IGES entity (and the ones it references) to the model", py::arg("ent"));
	cls_IGESControl_Writer.def("ComputeModel", (void (IGESControl_Writer::*)()) &IGESControl_Writer::ComputeModel, "Computes the entities found in the model, which is ready to be written. This contrasts with the default computation of headers only.");
	cls_IGESControl_Writer.def("Write", [](IGESControl_Writer &self, Standard_OStream & a0) -> Standard_Boolean { return self.Write(a0); }, py::arg("S"));
	cls_IGESControl_Writer.def("Write", (Standard_Boolean (IGESControl_Writer::*)(Standard_OStream &, const Standard_Boolean)) &IGESControl_Writer::Write, "Computes then writes the model to an OStream Returns True when done, false in case of error", py::arg("S"), py::arg("fnes"));
	cls_IGESControl_Writer.def("Write", [](IGESControl_Writer &self, const Standard_CString a0) -> Standard_Boolean { return self.Write(a0); }, py::arg("file"));
	cls_IGESControl_Writer.def("Write", (Standard_Boolean (IGESControl_Writer::*)(const Standard_CString, const Standard_Boolean)) &IGESControl_Writer::Write, "Prepares and writes an IGES model either to an OStream, S or to a file name,CString. Returns True if the operation was performed correctly and False if an error occurred (for instance, if the processor could not create the file).", py::arg("file"), py::arg("fnes"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_ActorWrite.hxx
	py::class_<IGESControl_ActorWrite, opencascade::handle<IGESControl_ActorWrite>, Transfer_ActorOfFinderProcess> cls_IGESControl_ActorWrite(mod, "IGESControl_ActorWrite", "Actor to write Shape to IGES");
	cls_IGESControl_ActorWrite.def(py::init<>());
	cls_IGESControl_ActorWrite.def("Recognize", (Standard_Boolean (IGESControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &)) &IGESControl_ActorWrite::Recognize, "Recognizes a ShapeMapper", py::arg("start"));
	cls_IGESControl_ActorWrite.def("Transfer", (opencascade::handle<Transfer_Binder> (IGESControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_FinderProcess> &)) &IGESControl_ActorWrite::Transfer, "Transfers Shape to IGES Entities", py::arg("start"), py::arg("FP"));
	cls_IGESControl_ActorWrite.def_static("get_type_name_", (const char * (*)()) &IGESControl_ActorWrite::get_type_name, "None");
	cls_IGESControl_ActorWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_ActorWrite::get_type_descriptor, "None");
	cls_IGESControl_ActorWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_ActorWrite::*)() const ) &IGESControl_ActorWrite::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_AlgoContainer.hxx
	py::class_<IGESControl_AlgoContainer, opencascade::handle<IGESControl_AlgoContainer>, IGESToBRep_AlgoContainer> cls_IGESControl_AlgoContainer(mod, "IGESControl_AlgoContainer", "None");
	cls_IGESControl_AlgoContainer.def(py::init<>());
	cls_IGESControl_AlgoContainer.def_static("get_type_name_", (const char * (*)()) &IGESControl_AlgoContainer::get_type_name, "None");
	cls_IGESControl_AlgoContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_AlgoContainer::get_type_descriptor, "None");
	cls_IGESControl_AlgoContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_AlgoContainer::*)() const ) &IGESControl_AlgoContainer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_Controller.hxx
	py::class_<IGESControl_Controller, opencascade::handle<IGESControl_Controller>, XSControl_Controller> cls_IGESControl_Controller(mod, "IGESControl_Controller", "Controller for IGES-5.1");
	cls_IGESControl_Controller.def(py::init<>());
	cls_IGESControl_Controller.def(py::init<const Standard_Boolean>(), py::arg("modefnes"));
	cls_IGESControl_Controller.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (IGESControl_Controller::*)() const ) &IGESControl_Controller::NewModel, "Creates a new empty Model ready to receive data of the Norm. It is taken from IGES Template Model");
	cls_IGESControl_Controller.def("ActorRead", (opencascade::handle<Transfer_ActorOfTransientProcess> (IGESControl_Controller::*)(const opencascade::handle<Interface_InterfaceModel> &) const ) &IGESControl_Controller::ActorRead, "Returns the Actor for Read attached to the pair (norm,appli) It is an Actor from IGESToBRep, adapted from an IGESModel : Unit, tolerances", py::arg("model"));
	cls_IGESControl_Controller.def("TransferWriteShape", [](IGESControl_Controller &self, const TopoDS_Shape & a0, const opencascade::handle<Transfer_FinderProcess> & a1, const opencascade::handle<Interface_InterfaceModel> & a2) -> IFSelect_ReturnStatus { return self.TransferWriteShape(a0, a1, a2); }, py::arg("shape"), py::arg("FP"), py::arg("model"));
	cls_IGESControl_Controller.def("TransferWriteShape", (IFSelect_ReturnStatus (IGESControl_Controller::*)(const TopoDS_Shape &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer) const ) &IGESControl_Controller::TransferWriteShape, "Takes one Shape and transfers it to the InterfaceModel (already created by NewModel for instance) <modetrans> is to be interpreted by each kind of XstepAdaptor Returns a status : 0 OK 1 No result 2 Fail -1 bad modeshape -2 bad model (requires an IGESModel) modeshape : 0 groupe of face (version < 5.1) 1 BREP-version 5.1 of IGES", py::arg("shape"), py::arg("FP"), py::arg("model"), py::arg("modetrans"));
	cls_IGESControl_Controller.def_static("Init_", (Standard_Boolean (*)()) &IGESControl_Controller::Init, "Standard Initialisation. It creates a Controller for IGES and records it to various names, available to select it later Returns True when done, False if could not be done Also, it creates and records an Adaptor for FNES");
	cls_IGESControl_Controller.def("Customise", (void (IGESControl_Controller::*)(opencascade::handle<XSControl_WorkSession> &)) &IGESControl_Controller::Customise, "None", py::arg("WS"));
	cls_IGESControl_Controller.def_static("get_type_name_", (const char * (*)()) &IGESControl_Controller::get_type_name, "None");
	cls_IGESControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_Controller::get_type_descriptor, "None");
	cls_IGESControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_Controller::*)() const ) &IGESControl_Controller::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_IGESBoundary.hxx
	py::class_<IGESControl_IGESBoundary, opencascade::handle<IGESControl_IGESBoundary>, IGESToBRep_IGESBoundary> cls_IGESControl_IGESBoundary(mod, "IGESControl_IGESBoundary", "Translates IGES boundary entity (types 141, 142 and 508) in Advanced Data Exchange. Redefines translation and treatment methods from inherited open class IGESToBRep_IGESBoundary.");
	cls_IGESControl_IGESBoundary.def(py::init<>());
	cls_IGESControl_IGESBoundary.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESControl_IGESBoundary.def("Check", (void (IGESControl_IGESBoundary::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IGESControl_IGESBoundary::Check, "Checks result of translation of IGES boundary entities (types 141, 142 or 508). Checks consistency of 2D and 3D representations and keeps only one if they are inconsistent. Checks the closure of resulting wire and if it is not closed, checks 2D and 3D representation and updates the resulting wire to contain only closed representation.", py::arg("result"), py::arg("checkclosure"), py::arg("okCurve3d"), py::arg("okCurve2d"));
	cls_IGESControl_IGESBoundary.def_static("get_type_name_", (const char * (*)()) &IGESControl_IGESBoundary::get_type_name, "None");
	cls_IGESControl_IGESBoundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_IGESBoundary::get_type_descriptor, "None");
	cls_IGESControl_IGESBoundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_IGESBoundary::*)() const ) &IGESControl_IGESBoundary::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESControl_ToolContainer.hxx
	py::class_<IGESControl_ToolContainer, opencascade::handle<IGESControl_ToolContainer>, IGESToBRep_ToolContainer> cls_IGESControl_ToolContainer(mod, "IGESControl_ToolContainer", "None");
	cls_IGESControl_ToolContainer.def(py::init<>());
	cls_IGESControl_ToolContainer.def("IGESBoundary", (opencascade::handle<IGESToBRep_IGESBoundary> (IGESControl_ToolContainer::*)() const ) &IGESControl_ToolContainer::IGESBoundary, "Returns IGESControl_IGESBoundary");
	cls_IGESControl_ToolContainer.def_static("get_type_name_", (const char * (*)()) &IGESControl_ToolContainer::get_type_name, "None");
	cls_IGESControl_ToolContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_ToolContainer::get_type_descriptor, "None");
	cls_IGESControl_ToolContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_ToolContainer::*)() const ) &IGESControl_ToolContainer::DynamicType, "None");


}
