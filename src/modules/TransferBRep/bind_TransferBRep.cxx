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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_Transient.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopAbs_Orientation.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TransferBRep_ShapeMapper.hxx>
#include <TransferBRep_HSequenceOfTransferResultInfo.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Message_Printer.hxx>
#include <Message_Msg.hxx>
#include <TransferBRep_TransferResultInfo.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TransferBRep_Reader.hxx>
#include <TransferBRep_ShapeInfo.hxx>
#include <TransferBRep_BinderOfShape.hxx>
#include <TransferBRep_ShapeBinder.hxx>
#include <TransferBRep_ShapeListBinder.hxx>
#include <TransferBRep_OrientedShapeMapper.hxx>
#include <TransferBRep.hxx>

void bind_TransferBRep(py::module &mod){

py::class_<TransferBRep, std::unique_ptr<TransferBRep, Deleter<TransferBRep>>> cls_TransferBRep(mod, "TransferBRep", "This package gathers services to simply read files and convert them to Shapes from CasCade. IE. it can be used in conjunction with purely CasCade software");

// Constructors

// Fields

// Methods
// cls_TransferBRep.def_static("operator new_", (void * (*)(size_t)) &TransferBRep::operator new, "None", py::arg("theSize"));
// cls_TransferBRep.def_static("operator delete_", (void (*)(void *)) &TransferBRep::operator delete, "None", py::arg("theAddress"));
// cls_TransferBRep.def_static("operator new[]_", (void * (*)(size_t)) &TransferBRep::operator new[], "None", py::arg("theSize"));
// cls_TransferBRep.def_static("operator delete[]_", (void (*)(void *)) &TransferBRep::operator delete[], "None", py::arg("theAddress"));
// cls_TransferBRep.def_static("operator new_", (void * (*)(size_t, void *)) &TransferBRep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TransferBRep.def_static("operator delete_", (void (*)(void *, void *)) &TransferBRep::operator delete, "None", py::arg(""), py::arg(""));
cls_TransferBRep.def_static("ShapeResult_", (TopoDS_Shape (*)(const opencascade::handle<Transfer_Binder> &)) &TransferBRep::ShapeResult, "Get the Shape recorded in a Binder If the Binder brings a multiple result, search for the Shape", py::arg("binder"));
cls_TransferBRep.def_static("ShapeResult_", (TopoDS_Shape (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &)) &TransferBRep::ShapeResult, "Get the Shape recorded in a TransientProcess as result of the Transfer of an entity. I.E. in the binder bound to that Entity If no result or result not a single Shape, returns a Null Shape", py::arg("TP"), py::arg("ent"));
cls_TransferBRep.def_static("SetShapeResult_", (void (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &, const TopoDS_Shape &)) &TransferBRep::SetShapeResult, "Sets a Shape as a result for a starting entity <ent> (reverse of ShapeResult) It simply creates a ShapeBinder then binds it to the entity", py::arg("TP"), py::arg("ent"), py::arg("result"));
cls_TransferBRep.def_static("Shapes_", [](const opencascade::handle<Transfer_TransientProcess> & a0) -> opencascade::handle<TopTools_HSequenceOfShape> { return TransferBRep::Shapes(a0); });
cls_TransferBRep.def_static("Shapes_", (opencascade::handle<TopTools_HSequenceOfShape> (*)(const opencascade::handle<Transfer_TransientProcess> &, const Standard_Boolean)) &TransferBRep::Shapes, "Gets the Shapes recorded in a TransientProcess as result of a Transfer, considers roots only or all results according <rootsonly>, returns them as a HSequence", py::arg("TP"), py::arg("rootsonly"));
cls_TransferBRep.def_static("Shapes_", (opencascade::handle<TopTools_HSequenceOfShape> (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<TColStd_HSequenceOfTransient> &)) &TransferBRep::Shapes, "Gets the Shapes recorded in a TransientProcess as result of a Transfer, for a given list of starting entities, returns the shapes as a HSequence", py::arg("TP"), py::arg("list"));
cls_TransferBRep.def_static("ShapeState_", (TopAbs_Orientation (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::ShapeState, "Returns a Status regarding a Shape in a FinderProcess - FORWARD means bound with SAME Orientation - REVERSED means bound with REVERSE Orientation - EXTERNAL means NOT BOUND - INTERNAL is not used", py::arg("FP"), py::arg("shape"));
cls_TransferBRep.def_static("ResultFromShape_", (opencascade::handle<Transfer_Binder> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::ResultFromShape, "Returns the result (as a Binder) attached to a given Shape Null if none", py::arg("FP"), py::arg("shape"));
cls_TransferBRep.def_static("TransientFromShape_", (opencascade::handle<Standard_Transient> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::TransientFromShape, "Returns the result as pure Transient attached to a Shape first one if multiple result", py::arg("FP"), py::arg("shape"));
cls_TransferBRep.def_static("SetTransientFromShape_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &)) &TransferBRep::SetTransientFromShape, "Binds a Transient Result to a Shape in a FinderProcess (as first result if multiple : does not add it to existing one)", py::arg("FP"), py::arg("shape"), py::arg("result"));
cls_TransferBRep.def_static("ShapeMapper_", (opencascade::handle<TransferBRep_ShapeMapper> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &TransferBRep::ShapeMapper, "Returns a ShapeMapper for a given Shape (location included) Either <shape> is already mapped, then its Mapper is returned Or it is not, then a new one is created then returned, BUT it is not mapped here (use Bind or FindElseBind to do this)", py::arg("FP"), py::arg("shape"));
cls_TransferBRep.def_static("TransferResultInfo_", (void (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<TColStd_HSequenceOfTransient> &, opencascade::handle<TransferBRep_HSequenceOfTransferResultInfo> &)) &TransferBRep::TransferResultInfo, "Fills sequence of TransferResultInfo for each type of entity given in the EntityTypes (entity are given as objects). Method IsKind applied to the entities in TP is used to compare with entities in EntityTypes. TopAbs_ShapeEnum).", py::arg("TP"), py::arg("EntityTypes"), py::arg("InfoSeq"));
cls_TransferBRep.def_static("TransferResultInfo_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<TColStd_HSequenceOfInteger> &, opencascade::handle<TransferBRep_HSequenceOfTransferResultInfo> &)) &TransferBRep::TransferResultInfo, "Fills sequence of TransferResultInfo for each type of shape given in the ShapeTypes (which are in fact considered as TopAbs_ShapeEnum). The Finders in the FP are considered as ShapeMappers.", py::arg("FP"), py::arg("ShapeTypes"), py::arg("InfoSeq"));
cls_TransferBRep.def_static("PrintResultInfo_", [](const opencascade::handle<Message_Printer> & a0, const Message_Msg & a1, const opencascade::handle<TransferBRep_TransferResultInfo> & a2) -> void { return TransferBRep::PrintResultInfo(a0, a1, a2); });
cls_TransferBRep.def_static("PrintResultInfo_", (void (*)(const opencascade::handle<Message_Printer> &, const Message_Msg &, const opencascade::handle<TransferBRep_TransferResultInfo> &, const Standard_Boolean)) &TransferBRep::PrintResultInfo, "Prints the results of transfer to given priner with given header.", py::arg("Printer"), py::arg("Header"), py::arg("ResultInfo"), py::arg("printEmpty"));
// cls_TransferBRep.def_static("BRepCheck_", [](const TopoDS_Shape & a0) -> Interface_CheckIterator { return TransferBRep::BRepCheck(a0); });
// cls_TransferBRep.def_static("BRepCheck_", (Interface_CheckIterator (*)(const TopoDS_Shape &, const Standard_Integer)) &TransferBRep::BRepCheck, "Performs a heavy check by calling the Analyser from BRepCheck This tool computes a lot of informations about integrity of a Shape. This method uses it and converts its internal result to a classic check-list. <lev> allows to get more informations : 0 : BRepCheck only 1(D) + Curves/Surfaces not C0 ; 2 + SameParameter on Edges Warning : entities to which checks are bound are the Shapes themselves, embedded in ShapeMapper", py::arg("shape"), py::arg("lev"));
cls_TransferBRep.def_static("ResultCheckList_", (Interface_CheckIterator (*)(const Interface_CheckIterator &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &)) &TransferBRep::ResultCheckList, "Takes a starting CheckIterator which brings checks bound with starting objects (Shapes, Transient from an Imagine appli ...) and converts it to a CheckIterator in which checks are bound with results in an InterfaceModel Mapping is recorded in the FinderProcess Starting objects for which no individual result is recorded remain in their state", py::arg("chl"), py::arg("FP"), py::arg("model"));
cls_TransferBRep.def_static("Checked_", [](const Interface_CheckIterator & a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return TransferBRep::Checked(a0); });
cls_TransferBRep.def_static("Checked_", (opencascade::handle<TColStd_HSequenceOfTransient> (*)(const Interface_CheckIterator &, const Standard_Boolean)) &TransferBRep::Checked, "Returns the list of objects to which a non-empty Check is bound in a check-list. Objects are transients, they can then be either Imagine objects entities for an Interface Norm. <alsoshapes> commands Shapes to be returned too (as ShapeMapper), see also CheckedShapes", py::arg("chl"), py::arg("alsoshapes"));
cls_TransferBRep.def_static("CheckedShapes_", (opencascade::handle<TopTools_HSequenceOfShape> (*)(const Interface_CheckIterator &)) &TransferBRep::CheckedShapes, "Returns the list of shapes to which a non-empty Check is bound in a check-list", py::arg("chl"));
cls_TransferBRep.def_static("CheckObject_", (Interface_CheckIterator (*)(const Interface_CheckIterator &, const opencascade::handle<Standard_Transient> &)) &TransferBRep::CheckObject, "Returns the check-list bound to a given object, generally none (if OK) or one check. <obj> can be, either a true Transient object or entity, or a ShapeMapper, in that case the Shape is considered", py::arg("chl"), py::arg("obj"));

// Enums

}