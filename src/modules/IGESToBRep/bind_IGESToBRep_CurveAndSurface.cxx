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
#include <Standard.hxx>
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Message_Msg.hxx>
#include <Geom_Surface.hxx>

void bind_IGESToBRep_CurveAndSurface(py::module &mod){

py::class_<IGESToBRep_CurveAndSurface, std::unique_ptr<IGESToBRep_CurveAndSurface>> cls_IGESToBRep_CurveAndSurface(mod, "IGESToBRep_CurveAndSurface", "Provides methods to transfer CurveAndSurface from IGES to CASCADE.");

// Constructors
cls_IGESToBRep_CurveAndSurface.def(py::init<>());
cls_IGESToBRep_CurveAndSurface.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
cls_IGESToBRep_CurveAndSurface.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));

// Fields

// Methods
// cls_IGESToBRep_CurveAndSurface.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_CurveAndSurface::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_CurveAndSurface.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_CurveAndSurface::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_CurveAndSurface.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_CurveAndSurface::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_CurveAndSurface.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_CurveAndSurface::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_CurveAndSurface.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_CurveAndSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_CurveAndSurface.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_CurveAndSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_CurveAndSurface.def("Init", (void (IGESToBRep_CurveAndSurface::*)()) &IGESToBRep_CurveAndSurface::Init, "Initializes the field of the tool CurveAndSurface with default creating values.");
cls_IGESToBRep_CurveAndSurface.def("SetEpsilon", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetEpsilon, "Changes the value of 'myEps'", py::arg("eps"));
cls_IGESToBRep_CurveAndSurface.def("GetEpsilon", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetEpsilon, "Returns the value of 'myEps'");
cls_IGESToBRep_CurveAndSurface.def("SetEpsCoeff", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetEpsCoeff, "Changes the value of 'myEpsCoeff'", py::arg("eps"));
cls_IGESToBRep_CurveAndSurface.def("GetEpsCoeff", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetEpsCoeff, "Returns the value of 'myEpsCoeff'");
cls_IGESToBRep_CurveAndSurface.def("SetEpsGeom", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetEpsGeom, "Changes the value of 'myEpsGeom'", py::arg("eps"));
cls_IGESToBRep_CurveAndSurface.def("GetEpsGeom", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetEpsGeom, "Returns the value of 'myEpsGeom'");
cls_IGESToBRep_CurveAndSurface.def("SetMinTol", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetMinTol, "Changes the value of 'myMinTol'", py::arg("mintol"));
cls_IGESToBRep_CurveAndSurface.def("SetMaxTol", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetMaxTol, "Changes the value of 'myMaxTol'", py::arg("maxtol"));
cls_IGESToBRep_CurveAndSurface.def("UpdateMinMaxTol", (void (IGESToBRep_CurveAndSurface::*)()) &IGESToBRep_CurveAndSurface::UpdateMinMaxTol, "Sets values of 'myMinTol' and 'myMaxTol' as follows myMaxTol = Max ('read.maxprecision.val', myEpsGeom * myUnitFactor) myMinTol = Precision::Confusion() Remark: This method is automatically invoked each time the values of 'myEpsGeom' or 'myUnitFactor' are changed");
cls_IGESToBRep_CurveAndSurface.def("GetMinTol", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetMinTol, "Returns the value of 'myMinTol'");
cls_IGESToBRep_CurveAndSurface.def("GetMaxTol", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetMaxTol, "Returns the value of 'myMaxTol'");
cls_IGESToBRep_CurveAndSurface.def("SetModeApprox", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Boolean)) &IGESToBRep_CurveAndSurface::SetModeApprox, "Changes the value of 'myModeApprox'", py::arg("mode"));
cls_IGESToBRep_CurveAndSurface.def("GetModeApprox", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetModeApprox, "Returns the value of 'myModeApprox'");
cls_IGESToBRep_CurveAndSurface.def("SetModeTransfer", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Boolean)) &IGESToBRep_CurveAndSurface::SetModeTransfer, "Changes the value of 'myModeIsTopo'", py::arg("mode"));
cls_IGESToBRep_CurveAndSurface.def("GetModeTransfer", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetModeTransfer, "Returns the value of 'myModeIsTopo'");
cls_IGESToBRep_CurveAndSurface.def("SetOptimized", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Boolean)) &IGESToBRep_CurveAndSurface::SetOptimized, "Changes the value of 'myContIsOpti'", py::arg("optimized"));
cls_IGESToBRep_CurveAndSurface.def("GetOptimized", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetOptimized, "Returns the value of 'myContIsOpti'");
cls_IGESToBRep_CurveAndSurface.def("GetUnitFactor", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetUnitFactor, "Returns the value of ' myUnitFactor'");
cls_IGESToBRep_CurveAndSurface.def("SetSurfaceCurve", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Integer)) &IGESToBRep_CurveAndSurface::SetSurfaceCurve, "Changes the value of 'mySurfaceCurve'", py::arg("ival"));
cls_IGESToBRep_CurveAndSurface.def("GetSurfaceCurve", (Standard_Integer (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetSurfaceCurve, "Returns the value of ' mySurfaceCurve' 0 = value in file , 2 = kepp 2d and compute 3d 3 = keep 3d and compute 2d");
cls_IGESToBRep_CurveAndSurface.def("SetModel", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESModel> &)) &IGESToBRep_CurveAndSurface::SetModel, "Set the value of 'myModel'", py::arg("model"));
cls_IGESToBRep_CurveAndSurface.def("GetModel", (opencascade::handle<IGESData_IGESModel> (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetModel, "Returns the value of 'myModel'");
cls_IGESToBRep_CurveAndSurface.def("SetContinuity", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Integer)) &IGESToBRep_CurveAndSurface::SetContinuity, "Changes the value of 'myContinuity' if continuity = 0 do nothing else if continuity = 1 try C1 if continuity = 2 try C2", py::arg("continuity"));
cls_IGESToBRep_CurveAndSurface.def("GetContinuity", (Standard_Integer (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetContinuity, "Returns the value of 'myContinuity'");
cls_IGESToBRep_CurveAndSurface.def("SetTransferProcess", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<Transfer_TransientProcess> &)) &IGESToBRep_CurveAndSurface::SetTransferProcess, "Set the value of 'myMsgReg'", py::arg("TP"));
cls_IGESToBRep_CurveAndSurface.def("GetTransferProcess", (opencascade::handle<Transfer_TransientProcess> (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::GetTransferProcess, "Returns the value of 'myMsgReg'");
cls_IGESToBRep_CurveAndSurface.def("TransferCurveAndSurface", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_CurveAndSurface::TransferCurveAndSurface, "Returns the result of the transfert of any IGES Curve or Surface Entity. If the transfer has failed, this member return a NullEntity.", py::arg("start"));
cls_IGESToBRep_CurveAndSurface.def("TransferGeometry", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_CurveAndSurface::TransferGeometry, "Returns the result of the transfert the geometry of any IGESEntity. If the transfer has failed, this member return a NullEntity.", py::arg("start"));
cls_IGESToBRep_CurveAndSurface.def("SendFail", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Message_Msg &)) &IGESToBRep_CurveAndSurface::SendFail, "Records a new Fail message", py::arg("start"), py::arg("amsg"));
cls_IGESToBRep_CurveAndSurface.def("SendWarning", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Message_Msg &)) &IGESToBRep_CurveAndSurface::SendWarning, "Records a new Warning message", py::arg("start"), py::arg("amsg"));
cls_IGESToBRep_CurveAndSurface.def("SendMsg", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Message_Msg &)) &IGESToBRep_CurveAndSurface::SendMsg, "Records a new Information message from the definition of a Msg (Original+Value)", py::arg("start"), py::arg("amsg"));
cls_IGESToBRep_CurveAndSurface.def("HasShapeResult", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESToBRep_CurveAndSurface::HasShapeResult, "Returns True if start was already treated and has a result in 'myMap' else returns False.", py::arg("start"));
cls_IGESToBRep_CurveAndSurface.def("GetShapeResult", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESToBRep_CurveAndSurface::GetShapeResult, "Returns the result of the transfer of the IGESEntity 'start' contained in 'myMap' . (if HasShapeResult is True).", py::arg("start"));
cls_IGESToBRep_CurveAndSurface.def("SetShapeResult", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Shape &)) &IGESToBRep_CurveAndSurface::SetShapeResult, "set in 'myMap' the result of the transfer of the IGESEntity 'start'.", py::arg("start"), py::arg("result"));
cls_IGESToBRep_CurveAndSurface.def("NbShapeResult", (Standard_Integer (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESToBRep_CurveAndSurface::NbShapeResult, "Returns the number of shapes results contained in 'myMap' for the IGESEntity start ( type VertexList or EdgeList).", py::arg("start"));
cls_IGESToBRep_CurveAndSurface.def("GetShapeResult", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer) const) &IGESToBRep_CurveAndSurface::GetShapeResult, "Returns the numth result of the IGESEntity start (type VertexList or EdgeList) in 'myMap'. (if NbShapeResult is not null).", py::arg("start"), py::arg("num"));
cls_IGESToBRep_CurveAndSurface.def("AddShapeResult", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Shape &)) &IGESToBRep_CurveAndSurface::AddShapeResult, "set in 'myMap' the result of the transfer of the entity of the IGESEntity start ( type VertexList or EdgeList).", py::arg("start"), py::arg("result"));
cls_IGESToBRep_CurveAndSurface.def("SetSurface", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<Geom_Surface> &)) &IGESToBRep_CurveAndSurface::SetSurface, "None", py::arg("theSurface"));
cls_IGESToBRep_CurveAndSurface.def("Surface", (opencascade::handle<Geom_Surface> (IGESToBRep_CurveAndSurface::*)() const) &IGESToBRep_CurveAndSurface::Surface, "None");
cls_IGESToBRep_CurveAndSurface.def("GetUVResolution", (Standard_Real (IGESToBRep_CurveAndSurface::*)()) &IGESToBRep_CurveAndSurface::GetUVResolution, "None");

// Enums

}