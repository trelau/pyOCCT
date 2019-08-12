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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_Controller.hxx>
#include <Interface_Protocol.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Transfer_ActorOfFinderProcess.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <XSControl_WorkSession.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <NCollection_Vector.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>

void bind_XSControl_Controller(py::module &mod){

py::class_<XSControl_Controller, opencascade::handle<XSControl_Controller>, Standard_Transient> cls_XSControl_Controller(mod, "XSControl_Controller", "This class allows a general X-STEP engine to run generic functions on any interface norm, in the same way. It includes the transfer operations. I.e. it gathers the already available general modules, the engine has just to know it");

// Fields

// Methods
cls_XSControl_Controller.def("SetNames", (void (XSControl_Controller::*)(const Standard_CString, const Standard_CString)) &XSControl_Controller::SetNames, "Changes names if a name is empty, the formerly set one remains Remark : Does not call Record or AutoRecord", py::arg("theLongName"), py::arg("theShortName"));
cls_XSControl_Controller.def("AutoRecord", (void (XSControl_Controller::*)() const) &XSControl_Controller::AutoRecord, "Records <me> is a general dictionary under Short and Long Names (see method Name)");
cls_XSControl_Controller.def("Record", (void (XSControl_Controller::*)(const Standard_CString) const) &XSControl_Controller::Record, "Records <me> in a general dictionary under a name Error if <name> already used for another one", py::arg("name"));
cls_XSControl_Controller.def_static("Recorded_", (opencascade::handle<XSControl_Controller> (*)(const Standard_CString)) &XSControl_Controller::Recorded, "Returns the Controller attached to a given name Returns a Null Handle if <name> is unknown", py::arg("name"));
cls_XSControl_Controller.def("Name", [](XSControl_Controller &self) -> Standard_CString { return self.Name(); });
cls_XSControl_Controller.def("Name", (Standard_CString (XSControl_Controller::*)(const Standard_Boolean) const) &XSControl_Controller::Name, "Returns a name, as given when initializing : rsc = False (D) : True Name attached to the Norm (long name) rsc = True : Name of the ressource set (i.e. short name)", py::arg("rsc"));
cls_XSControl_Controller.def("Protocol", (const opencascade::handle<Interface_Protocol> & (XSControl_Controller::*)() const) &XSControl_Controller::Protocol, "Returns the Protocol attached to the Norm (from field)");
cls_XSControl_Controller.def("WorkLibrary", (const opencascade::handle<IFSelect_WorkLibrary> & (XSControl_Controller::*)() const) &XSControl_Controller::WorkLibrary, "Returns the WorkLibrary attached to the Norm. Remark that it has to be in phase with the Protocol (read from field)");
cls_XSControl_Controller.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (XSControl_Controller::*)() const) &XSControl_Controller::NewModel, "Creates a new empty Model ready to receive data of the Norm Used to write data from Imagine to an interface file");
cls_XSControl_Controller.def("ActorRead", (opencascade::handle<Transfer_ActorOfTransientProcess> (XSControl_Controller::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &XSControl_Controller::ActorRead, "Returns the Actor for Read attached to the pair (norm,appli) It can be adapted for data of the input Model, as required Can be read from field then adapted with Model as required", py::arg("model"));
cls_XSControl_Controller.def("ActorWrite", (opencascade::handle<Transfer_ActorOfFinderProcess> (XSControl_Controller::*)() const) &XSControl_Controller::ActorWrite, "Returns the Actor for Write attached to the pair (norm,appli) Read from field. Can be redefined");
cls_XSControl_Controller.def("SetModeWrite", [](XSControl_Controller &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetModeWrite(a0, a1); });
cls_XSControl_Controller.def("SetModeWrite", (void (XSControl_Controller::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &XSControl_Controller::SetModeWrite, "Sets mininum and maximum values for modetrans (write) Erases formerly recorded bounds and values Actually only for shape Then, for each value a little help can be attached", py::arg("modemin"), py::arg("modemax"), py::arg("shape"));
cls_XSControl_Controller.def("SetModeWriteHelp", [](XSControl_Controller &self, const Standard_Integer a0, const Standard_CString a1) -> void { return self.SetModeWriteHelp(a0, a1); });
cls_XSControl_Controller.def("SetModeWriteHelp", (void (XSControl_Controller::*)(const Standard_Integer, const Standard_CString, const Standard_Boolean)) &XSControl_Controller::SetModeWriteHelp, "Attaches a short line of help to a value of modetrans (write)", py::arg("modetrans"), py::arg("help"), py::arg("shape"));
cls_XSControl_Controller.def("ModeWriteBounds", [](XSControl_Controller &self, Standard_Integer & modemin, Standard_Integer & modemax, const Standard_Boolean shape){ Standard_Boolean rv = self.ModeWriteBounds(modemin, modemax, shape); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, modemin, modemax); }, "Returns recorded min and max values for modetrans (write) Actually only for shapes Returns True if bounds are set, False else (then, free value)", py::arg("modemin"), py::arg("modemax"), py::arg("shape"));
cls_XSControl_Controller.def("IsModeWrite", [](XSControl_Controller &self, const Standard_Integer a0) -> Standard_Boolean { return self.IsModeWrite(a0); });
cls_XSControl_Controller.def("IsModeWrite", (Standard_Boolean (XSControl_Controller::*)(const Standard_Integer, const Standard_Boolean) const) &XSControl_Controller::IsModeWrite, "Tells if a value of <modetrans> is a good value(within bounds) Actually only for shapes", py::arg("modetrans"), py::arg("shape"));
cls_XSControl_Controller.def("ModeWriteHelp", [](XSControl_Controller &self, const Standard_Integer a0) -> Standard_CString { return self.ModeWriteHelp(a0); });
cls_XSControl_Controller.def("ModeWriteHelp", (Standard_CString (XSControl_Controller::*)(const Standard_Integer, const Standard_Boolean) const) &XSControl_Controller::ModeWriteHelp, "Returns the help line recorded for a value of modetrans empty if help not defined or not within bounds or if values are free", py::arg("modetrans"), py::arg("shape"));
cls_XSControl_Controller.def("RecognizeWriteTransient", [](XSControl_Controller &self, const opencascade::handle<Standard_Transient> & a0) -> Standard_Boolean { return self.RecognizeWriteTransient(a0); });
cls_XSControl_Controller.def("RecognizeWriteTransient", (Standard_Boolean (XSControl_Controller::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_Controller::RecognizeWriteTransient, "Tells if <obj> (an application object) is a valid candidate for a transfer to a Model. By default, asks the ActorWrite if known (through a TransientMapper). Can be redefined", py::arg("obj"), py::arg("modetrans"));
cls_XSControl_Controller.def("TransferWriteTransient", [](XSControl_Controller &self, const opencascade::handle<Standard_Transient> & a0, const opencascade::handle<Transfer_FinderProcess> & a1, const opencascade::handle<Interface_InterfaceModel> & a2) -> IFSelect_ReturnStatus { return self.TransferWriteTransient(a0, a1, a2); });
cls_XSControl_Controller.def("TransferWriteTransient", (IFSelect_ReturnStatus (XSControl_Controller::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer) const) &XSControl_Controller::TransferWriteTransient, "Takes one Transient Object and transfers it to an InterfaceModel (already created, e.g. by NewModel) (result is recorded in the model by AddWithRefs) FP records produced results and checks", py::arg("obj"), py::arg("FP"), py::arg("model"), py::arg("modetrans"));
cls_XSControl_Controller.def("RecognizeWriteShape", [](XSControl_Controller &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.RecognizeWriteShape(a0); });
cls_XSControl_Controller.def("RecognizeWriteShape", (Standard_Boolean (XSControl_Controller::*)(const TopoDS_Shape &, const Standard_Integer) const) &XSControl_Controller::RecognizeWriteShape, "Tells if a shape is valid for a transfer to a model Asks the ActorWrite (through a ShapeMapper)", py::arg("shape"), py::arg("modetrans"));
cls_XSControl_Controller.def("TransferWriteShape", [](XSControl_Controller &self, const TopoDS_Shape & a0, const opencascade::handle<Transfer_FinderProcess> & a1, const opencascade::handle<Interface_InterfaceModel> & a2) -> IFSelect_ReturnStatus { return self.TransferWriteShape(a0, a1, a2); });
cls_XSControl_Controller.def("TransferWriteShape", (IFSelect_ReturnStatus (XSControl_Controller::*)(const TopoDS_Shape &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer) const) &XSControl_Controller::TransferWriteShape, "Takes one Shape and transfers it to an InterfaceModel (already created, e.g. by NewModel) Default uses ActorWrite; can be redefined as necessary Returned value is a status, as follows : Done OK , Void : No Result , Fail : Fail (e.g. exception) Error : bad conditions , bad model or null model", py::arg("shape"), py::arg("FP"), py::arg("model"), py::arg("modetrans"));
cls_XSControl_Controller.def("AddSessionItem", [](XSControl_Controller &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddSessionItem(a0, a1); });
cls_XSControl_Controller.def("AddSessionItem", (void (XSControl_Controller::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_Boolean)) &XSControl_Controller::AddSessionItem, "Records a Session Item, to be added for customisation of the Work Session. It must have a specific name. <setapplied> is used if <item> is a GeneralModifier, to decide If set to true, <item> will be applied to the hook list 'send'. Else, it is not applied to any hook list. Remark : this method is to be called at Create time, the recorded items will be used by Customise Warning : if <name> conflicts, the last recorded item is kept", py::arg("theItem"), py::arg("theName"), py::arg("toApply"));
cls_XSControl_Controller.def("SessionItem", (opencascade::handle<Standard_Transient> (XSControl_Controller::*)(const Standard_CString) const) &XSControl_Controller::SessionItem, "Returns an item given its name to record in a Session If <name> is unknown, returns a Null Handle", py::arg("theName"));
cls_XSControl_Controller.def("Customise", (void (XSControl_Controller::*)(opencascade::handle<XSControl_WorkSession> &)) &XSControl_Controller::Customise, "Customises a WorkSession, by adding to it the recorded items (by AddSessionItem)", py::arg("WS"));
cls_XSControl_Controller.def("AdaptorSession", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (XSControl_Controller::*)() const) &XSControl_Controller::AdaptorSession, "None");
cls_XSControl_Controller.def_static("get_type_name_", (const char * (*)()) &XSControl_Controller::get_type_name, "None");
cls_XSControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_Controller::get_type_descriptor, "None");
cls_XSControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_Controller::*)() const) &XSControl_Controller::DynamicType, "None");

// Enums

}