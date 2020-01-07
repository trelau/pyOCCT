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
#include <gp_XYZ.hxx>
#include <HLRAlgo_PolyMask.hxx>
#include <Standard.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Standard_Transient.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Std.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <HLRAlgo_WiresBlock.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <HLRAlgo.hxx>
#include <HLRAlgo_PolyHidingData.hxx>
#include <NCollection_Array1.hxx>
#include <HLRAlgo_Array1OfPHDat.hxx>
#include <gp_XY.hxx>
#include <HLRAlgo_PolyInternalNode.hxx>
#include <HLRAlgo_Array1OfPINod.hxx>
#include <HLRAlgo_PolyInternalSegment.hxx>
#include <HLRAlgo_Array1OfPISeg.hxx>
#include <HLRAlgo_TriangleData.hxx>
#include <HLRAlgo_Array1OfTData.hxx>
#include <HLRAlgo_BiPoint.hxx>
#include <TopAbs_State.hxx>
#include <HLRAlgo_Coincidence.hxx>
#include <HLRAlgo_EdgeStatus.hxx>
#include <HLRAlgo_EdgeIterator.hxx>
#include <Intrv_Intervals.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <HLRAlgo_HArray1OfPHDat.hxx>
#include <HLRAlgo_HArray1OfPINod.hxx>
#include <HLRAlgo_HArray1OfPISeg.hxx>
#include <HLRAlgo_HArray1OfTData.hxx>
#include <HLRAlgo_Intersection.hxx>
#include <HLRAlgo_Interference.hxx>
#include <NCollection_List.hxx>
#include <HLRAlgo_InterferenceList.hxx>
#include <HLRAlgo_ListOfBPoint.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <HLRAlgo_PolyData.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <HLRAlgo_PolyAlgo.hxx>
#include <HLRAlgo_PolyInternalData.hxx>
#include <HLRAlgo_PolyShellData.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(HLRAlgo, mod) {

py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Intrv");
py::module::import("OCCT.TColgp");

// ENUM: HLRALGO_POLYMASK
py::enum_<HLRAlgo_PolyMask>(mod, "HLRAlgo_PolyMask", "None")
	.value("HLRAlgo_PolyMask_EMskOutLin1", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskOutLin1)
	.value("HLRAlgo_PolyMask_EMskOutLin2", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskOutLin2)
	.value("HLRAlgo_PolyMask_EMskOutLin3", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskOutLin3)
	.value("HLRAlgo_PolyMask_EMskGrALin1", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskGrALin1)
	.value("HLRAlgo_PolyMask_EMskGrALin2", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskGrALin2)
	.value("HLRAlgo_PolyMask_EMskGrALin3", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskGrALin3)
	.value("HLRAlgo_PolyMask_FMskBack", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskBack)
	.value("HLRAlgo_PolyMask_FMskSide", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskSide)
	.value("HLRAlgo_PolyMask_FMskHiding", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskHiding)
	.value("HLRAlgo_PolyMask_FMskFlat", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskFlat)
	.value("HLRAlgo_PolyMask_FMskOnOutL", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskOnOutL)
	.value("HLRAlgo_PolyMask_FMskOrBack", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskOrBack)
	.value("HLRAlgo_PolyMask_FMskFrBack", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskFrBack)
	.export_values();


// CLASS: HLRALGO_PROJECTOR
py::class_<HLRAlgo_Projector> cls_HLRAlgo_Projector(mod, "HLRAlgo_Projector", "Implements a projector object. To transform and project Points and Planes. This object is designed to be used in the removal of hidden lines and is returned by the Prs3d_Projector::Projector function. You define the projection of the selected shape by calling one of the following functions: - HLRBRep_Algo::Projector, or - HLRBRep_PolyAlgo::Projector The choice depends on the algorithm, which you are using. The parameters of the view are defined at the time of construction of a Prs3d_Projector object.");

// Constructors
cls_HLRAlgo_Projector.def(py::init<>());
cls_HLRAlgo_Projector.def(py::init<const gp_Ax2 &>(), py::arg("CS"));
cls_HLRAlgo_Projector.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("CS"), py::arg("Focus"));
cls_HLRAlgo_Projector.def(py::init<const gp_Trsf &, const Standard_Boolean, const Standard_Real>(), py::arg("T"), py::arg("Persp"), py::arg("Focus"));
cls_HLRAlgo_Projector.def(py::init<const gp_Trsf &, const Standard_Boolean, const Standard_Real, const gp_Vec2d &, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("T"), py::arg("Persp"), py::arg("Focus"), py::arg("v1"), py::arg("v2"), py::arg("v3"));

// Methods
// cls_HLRAlgo_Projector.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Projector::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Projector.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Projector::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Projector.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Projector::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Projector.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Projector::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Projector.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Projector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Projector.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Projector::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Projector.def("Set", (void (HLRAlgo_Projector::*)(const gp_Trsf &, const Standard_Boolean, const Standard_Real)) &HLRAlgo_Projector::Set, "None", py::arg("T"), py::arg("Persp"), py::arg("Focus"));
cls_HLRAlgo_Projector.def("Directions", (void (HLRAlgo_Projector::*)(gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &HLRAlgo_Projector::Directions, "None", py::arg("D1"), py::arg("D2"), py::arg("D3"));
cls_HLRAlgo_Projector.def("Scaled", [](HLRAlgo_Projector &self) -> void { return self.Scaled(); });
cls_HLRAlgo_Projector.def("Scaled", (void (HLRAlgo_Projector::*)(const Standard_Boolean)) &HLRAlgo_Projector::Scaled, "to compute with the given scale and translation.", py::arg("On"));
cls_HLRAlgo_Projector.def("Perspective", (Standard_Boolean (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::Perspective, "Returns True if there is a perspective transformation.");
cls_HLRAlgo_Projector.def("Transformation", (const gp_Trsf & (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::Transformation, "Returns the active transformation.");
cls_HLRAlgo_Projector.def("InvertedTransformation", (const gp_Trsf & (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::InvertedTransformation, "Returns the active inverted transformation.");
cls_HLRAlgo_Projector.def("FullTransformation", (const gp_Trsf & (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::FullTransformation, "Returns the original transformation.");
cls_HLRAlgo_Projector.def("Focus", (Standard_Real (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::Focus, "Returns the focal length.");
cls_HLRAlgo_Projector.def("Transform", (void (HLRAlgo_Projector::*)(gp_Vec &) const) &HLRAlgo_Projector::Transform, "None", py::arg("D"));
cls_HLRAlgo_Projector.def("Transform", (void (HLRAlgo_Projector::*)(gp_Pnt &) const) &HLRAlgo_Projector::Transform, "None", py::arg("Pnt"));
cls_HLRAlgo_Projector.def("Project", (void (HLRAlgo_Projector::*)(const gp_Pnt &, gp_Pnt2d &) const) &HLRAlgo_Projector::Project, "Transform and apply perspective if needed.", py::arg("P"), py::arg("Pout"));
cls_HLRAlgo_Projector.def("Project", [](HLRAlgo_Projector &self, const gp_Pnt & P, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Project(P, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Transform and apply perspective if needed.", py::arg("P"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_HLRAlgo_Projector.def("Project", (void (HLRAlgo_Projector::*)(const gp_Pnt &, const gp_Vec &, gp_Pnt2d &, gp_Vec2d &) const) &HLRAlgo_Projector::Project, "Transform and apply perspective if needed.", py::arg("P"), py::arg("D1"), py::arg("Pout"), py::arg("D1out"));
cls_HLRAlgo_Projector.def("Shoot", (gp_Lin (HLRAlgo_Projector::*)(const Standard_Real, const Standard_Real) const) &HLRAlgo_Projector::Shoot, "return a line going through the eye towards the 2d point <X,Y>.", py::arg("X"), py::arg("Y"));

// CLASS: HLRALGO_EDGESBLOCK
py::class_<HLRAlgo_EdgesBlock, opencascade::handle<HLRAlgo_EdgesBlock>, Standard_Transient> cls_HLRAlgo_EdgesBlock(mod, "HLRAlgo_EdgesBlock", "An EdgesBlock is a set of Edges. It is used by the DataStructure to structure the Edges.");

// Constructors
cls_HLRAlgo_EdgesBlock.def(py::init<const Standard_Integer>(), py::arg("NbEdges"));

// Methods
cls_HLRAlgo_EdgesBlock.def("NbEdges", (Standard_Integer (HLRAlgo_EdgesBlock::*)() const) &HLRAlgo_EdgesBlock::NbEdges, "None");
cls_HLRAlgo_EdgesBlock.def("Edge", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Integer)) &HLRAlgo_EdgesBlock::Edge, "None", py::arg("I"), py::arg("EI"));
cls_HLRAlgo_EdgesBlock.def("Edge", (Standard_Integer (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Edge, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("Orientation", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const TopAbs_Orientation)) &HLRAlgo_EdgesBlock::Orientation, "None", py::arg("I"), py::arg("Or"));
cls_HLRAlgo_EdgesBlock.def("Orientation", (TopAbs_Orientation (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Orientation, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("OutLine", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::OutLine, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("OutLine", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::OutLine, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("Internal", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Internal, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("Internal", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::Internal, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("Double", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Double, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("Double", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::Double, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("IsoLine", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::IsoLine, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("IsoLine", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::IsoLine, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("UpdateMinMax", (void (HLRAlgo_EdgesBlock::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo_EdgesBlock::UpdateMinMax, "None", py::arg("TotMinMax"));
cls_HLRAlgo_EdgesBlock.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRAlgo_EdgesBlock::*)()) &HLRAlgo_EdgesBlock::MinMax, "None");
cls_HLRAlgo_EdgesBlock.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_EdgesBlock::get_type_name, "None");
cls_HLRAlgo_EdgesBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_EdgesBlock::get_type_descriptor, "None");
cls_HLRAlgo_EdgesBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_EdgesBlock::*)() const) &HLRAlgo_EdgesBlock::DynamicType, "None");

// CLASS: HLRALGO_WIRESBLOCK
py::class_<HLRAlgo_WiresBlock, opencascade::handle<HLRAlgo_WiresBlock>, Standard_Transient> cls_HLRAlgo_WiresBlock(mod, "HLRAlgo_WiresBlock", "A WiresBlock is a set of Blocks. It is used by the DataStructure to structure the Edges.");

// Constructors
cls_HLRAlgo_WiresBlock.def(py::init<const Standard_Integer>(), py::arg("NbWires"));

// Methods
cls_HLRAlgo_WiresBlock.def("NbWires", (Standard_Integer (HLRAlgo_WiresBlock::*)() const) &HLRAlgo_WiresBlock::NbWires, "None");
cls_HLRAlgo_WiresBlock.def("Set", (void (HLRAlgo_WiresBlock::*)(const Standard_Integer, const opencascade::handle<HLRAlgo_EdgesBlock> &)) &HLRAlgo_WiresBlock::Set, "None", py::arg("I"), py::arg("W"));
cls_HLRAlgo_WiresBlock.def("Wire", (opencascade::handle<HLRAlgo_EdgesBlock> & (HLRAlgo_WiresBlock::*)(const Standard_Integer)) &HLRAlgo_WiresBlock::Wire, "None", py::arg("I"));
cls_HLRAlgo_WiresBlock.def("UpdateMinMax", (void (HLRAlgo_WiresBlock::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo_WiresBlock::UpdateMinMax, "None", py::arg("theMinMaxes"));
cls_HLRAlgo_WiresBlock.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRAlgo_WiresBlock::*)()) &HLRAlgo_WiresBlock::MinMax, "None");
cls_HLRAlgo_WiresBlock.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_WiresBlock::get_type_name, "None");
cls_HLRAlgo_WiresBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_WiresBlock::get_type_descriptor, "None");
cls_HLRAlgo_WiresBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_WiresBlock::*)() const) &HLRAlgo_WiresBlock::DynamicType, "None");

// CLASS: HLRALGO
py::class_<HLRAlgo> cls_HLRAlgo(mod, "HLRAlgo", "In order to have the precision required in industrial design, drawings need to offer the possibility of removing lines, which are hidden in a given projection. To do this, the Hidden Line Removal component provides two algorithms: HLRBRep_Algo and HLRBRep_PolyAlgo. These algorithms remove or indicate lines hidden by surfaces. For a given projection, they calculate a set of lines characteristic of the object being represented. They are also used in conjunction with extraction utilities, which reconstruct a new, simplified shape from a selection of calculation results. This new shape is made up of edges, which represent the lines of the visualized shape in a plane. This plane is the projection plane. HLRBRep_Algo takes into account the shape itself. HLRBRep_PolyAlgo works with a polyhedral simplification of the shape. When you use HLRBRep_Algo, you obtain an exact result, whereas, when you use HLRBRep_PolyAlgo, you reduce computation time but obtain polygonal segments.");

// Constructors
cls_HLRAlgo.def(py::init<>());

// Methods
// cls_HLRAlgo.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo.def_static("operator delete_", (void (*)(void *)) &HLRAlgo::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo::operator delete, "None", py::arg(""), py::arg(""));
// cls_HLRAlgo.def_static("UpdateMinMax_", (void (*)(const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real [16], Standard_Real [16])) &HLRAlgo::UpdateMinMax, "Iterator on the visible or hidden parts of an EdgeStatus.", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("Min"), py::arg("Max"));
// cls_HLRAlgo.def_static("EnlargeMinMax_", (void (*)(const Standard_Real, Standard_Real [16], Standard_Real [16])) &HLRAlgo::EnlargeMinMax, "None", py::arg("tol"), py::arg("Min"), py::arg("Max"));
// cls_HLRAlgo.def_static("InitMinMax_", (void (*)(const Standard_Real, Standard_Real [16], Standard_Real [16])) &HLRAlgo::InitMinMax, "None", py::arg("Big"), py::arg("Min"), py::arg("Max"));
cls_HLRAlgo.def_static("EncodeMinMax_", (void (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::EncodeMinMax, "None", py::arg("Min"), py::arg("Max"), py::arg("MinMax"));
cls_HLRAlgo.def_static("SizeBox_", (Standard_Real (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::SizeBox, "None", py::arg("Min"), py::arg("Max"));
cls_HLRAlgo.def_static("DecodeMinMax_", (void (*)(const HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::DecodeMinMax, "None", py::arg("MinMax"), py::arg("Min"), py::arg("Max"));
cls_HLRAlgo.def_static("CopyMinMax_", (void (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::CopyMinMax, "None", py::arg("IMin"), py::arg("IMax"), py::arg("OMin"), py::arg("OMax"));
cls_HLRAlgo.def_static("AddMinMax_", (void (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::AddMinMax, "None", py::arg("IMin"), py::arg("IMax"), py::arg("OMin"), py::arg("OMax"));

// CLASS: HLRALGO_POLYHIDINGDATA
py::class_<HLRAlgo_PolyHidingData> cls_HLRAlgo_PolyHidingData(mod, "HLRAlgo_PolyHidingData", "Data structure of a set of Hiding Triangles.");

// Constructors
cls_HLRAlgo_PolyHidingData.def(py::init<>());

// Methods
// cls_HLRAlgo_PolyHidingData.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_PolyHidingData::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_PolyHidingData.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_PolyHidingData::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyHidingData.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_PolyHidingData::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_PolyHidingData.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_PolyHidingData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyHidingData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_PolyHidingData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_PolyHidingData.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_PolyHidingData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_PolyHidingData.def("Set", (void (HLRAlgo_PolyHidingData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRAlgo_PolyHidingData::Set, "None", py::arg("Index"), py::arg("Minim"), py::arg("Maxim"), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_HLRAlgo_PolyHidingData.def("Indices", (HLRAlgo_PolyHidingData::TriangleIndices & (HLRAlgo_PolyHidingData::*)()) &HLRAlgo_PolyHidingData::Indices, "None");
cls_HLRAlgo_PolyHidingData.def("Plane", (HLRAlgo_PolyHidingData::PlaneT & (HLRAlgo_PolyHidingData::*)()) &HLRAlgo_PolyHidingData::Plane, "None");

// TYPEDEF: HLRALGO_ARRAY1OFPHDAT
bind_NCollection_Array1<HLRAlgo_PolyHidingData>(mod, "HLRAlgo_Array1OfPHDat", py::module_local(false));

// CLASS: HLRALGO_POLYINTERNALNODE
py::class_<HLRAlgo_PolyInternalNode, opencascade::handle<HLRAlgo_PolyInternalNode>, Standard_Transient> cls_HLRAlgo_PolyInternalNode(mod, "HLRAlgo_PolyInternalNode", "to Update OutLines.");

// Constructors
cls_HLRAlgo_PolyInternalNode.def(py::init<>());

// Methods
cls_HLRAlgo_PolyInternalNode.def("Indices", (HLRAlgo_PolyInternalNode::NodeIndices & (HLRAlgo_PolyInternalNode::*)()) &HLRAlgo_PolyInternalNode::Indices, "None");
cls_HLRAlgo_PolyInternalNode.def("Data", (HLRAlgo_PolyInternalNode::NodeData & (HLRAlgo_PolyInternalNode::*)()) &HLRAlgo_PolyInternalNode::Data, "None");
cls_HLRAlgo_PolyInternalNode.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyInternalNode::get_type_name, "None");
cls_HLRAlgo_PolyInternalNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyInternalNode::get_type_descriptor, "None");
cls_HLRAlgo_PolyInternalNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyInternalNode::*)() const) &HLRAlgo_PolyInternalNode::DynamicType, "None");

// TYPEDEF: HLRALGO_ARRAY1OFPINOD
bind_NCollection_Array1<opencascade::handle<HLRAlgo_PolyInternalNode> >(mod, "HLRAlgo_Array1OfPINod", py::module_local(false));

// CLASS: HLRALGO_POLYINTERNALSEGMENT
py::class_<HLRAlgo_PolyInternalSegment> cls_HLRAlgo_PolyInternalSegment(mod, "HLRAlgo_PolyInternalSegment", "to Update OutLines.");

// Constructors
cls_HLRAlgo_PolyInternalSegment.def(py::init<>());

// Fields
cls_HLRAlgo_PolyInternalSegment.def_readwrite("LstSg1", &HLRAlgo_PolyInternalSegment::LstSg1, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("LstSg2", &HLRAlgo_PolyInternalSegment::LstSg2, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("NxtSg1", &HLRAlgo_PolyInternalSegment::NxtSg1, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("NxtSg2", &HLRAlgo_PolyInternalSegment::NxtSg2, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("Conex1", &HLRAlgo_PolyInternalSegment::Conex1, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("Conex2", &HLRAlgo_PolyInternalSegment::Conex2, "None");

// Methods
// cls_HLRAlgo_PolyInternalSegment.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_PolyInternalSegment::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_PolyInternalSegment::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_PolyInternalSegment::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_PolyInternalSegment::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_PolyInternalSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_PolyInternalSegment::operator delete, "None", py::arg(""), py::arg(""));

// TYPEDEF: HLRALGO_ARRAY1OFPISEG
bind_NCollection_Array1<HLRAlgo_PolyInternalSegment>(mod, "HLRAlgo_Array1OfPISeg", py::module_local(false));

// CLASS: HLRALGO_TRIANGLEDATA
py::class_<HLRAlgo_TriangleData> cls_HLRAlgo_TriangleData(mod, "HLRAlgo_TriangleData", "Data structure of a triangle.");

// Constructors
cls_HLRAlgo_TriangleData.def(py::init<>());

// Fields
cls_HLRAlgo_TriangleData.def_readwrite("Node1", &HLRAlgo_TriangleData::Node1, "None");
cls_HLRAlgo_TriangleData.def_readwrite("Node2", &HLRAlgo_TriangleData::Node2, "None");
cls_HLRAlgo_TriangleData.def_readwrite("Node3", &HLRAlgo_TriangleData::Node3, "None");
cls_HLRAlgo_TriangleData.def_readwrite("Flags", &HLRAlgo_TriangleData::Flags, "None");

// Methods
// cls_HLRAlgo_TriangleData.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_TriangleData::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_TriangleData.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_TriangleData::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_TriangleData.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_TriangleData::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_TriangleData.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_TriangleData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_TriangleData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_TriangleData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_TriangleData.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_TriangleData::operator delete, "None", py::arg(""), py::arg(""));

// TYPEDEF: HLRALGO_ARRAY1OFTDATA
bind_NCollection_Array1<HLRAlgo_TriangleData>(mod, "HLRAlgo_Array1OfTData", py::module_local(false));

// CLASS: HLRALGO_BIPOINT
py::class_<HLRAlgo_BiPoint> cls_HLRAlgo_BiPoint(mod, "HLRAlgo_BiPoint", "None");

// Constructors
cls_HLRAlgo_BiPoint.def(py::init<>());
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("flag"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("flag"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("i2"), py::arg("i2p1"), py::arg("i2p2"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("i2"), py::arg("i2p1"), py::arg("i2p2"), py::arg("flag"));

// Methods
// cls_HLRAlgo_BiPoint.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_BiPoint::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_BiPoint.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_BiPoint::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_BiPoint.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_BiPoint::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_BiPoint.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_BiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_BiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_BiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_BiPoint.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_BiPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_BiPoint.def("Rg1Line", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::Rg1Line, "None");
cls_HLRAlgo_BiPoint.def("Rg1Line", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::Rg1Line, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("RgNLine", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::RgNLine, "None");
cls_HLRAlgo_BiPoint.def("RgNLine", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::RgNLine, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("OutLine", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::OutLine, "None");
cls_HLRAlgo_BiPoint.def("OutLine", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::OutLine, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("IntLine", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::IntLine, "None");
cls_HLRAlgo_BiPoint.def("IntLine", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::IntLine, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("Hidden", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::Hidden, "None");
cls_HLRAlgo_BiPoint.def("Hidden", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::Hidden, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("Indices", (HLRAlgo_BiPoint::IndicesT & (HLRAlgo_BiPoint::*)()) &HLRAlgo_BiPoint::Indices, "None");
cls_HLRAlgo_BiPoint.def("Points", (HLRAlgo_BiPoint::PointsT & (HLRAlgo_BiPoint::*)()) &HLRAlgo_BiPoint::Points, "None");

// CLASS: HLRALGO_COINCIDENCE
py::class_<HLRAlgo_Coincidence> cls_HLRAlgo_Coincidence(mod, "HLRAlgo_Coincidence", "The Coincidence class is used in an Inteference to store informations on the 'hiding' edge.");

// Constructors
cls_HLRAlgo_Coincidence.def(py::init<>());

// Methods
// cls_HLRAlgo_Coincidence.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Coincidence::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Coincidence.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Coincidence::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Coincidence.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Coincidence::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Coincidence.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Coincidence::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Coincidence.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Coincidence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Coincidence.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Coincidence::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Coincidence.def("Set2D", (void (HLRAlgo_Coincidence::*)(const Standard_Integer, const Standard_Real)) &HLRAlgo_Coincidence::Set2D, "None", py::arg("FE"), py::arg("Param"));
cls_HLRAlgo_Coincidence.def("SetState3D", (void (HLRAlgo_Coincidence::*)(const TopAbs_State, const TopAbs_State)) &HLRAlgo_Coincidence::SetState3D, "None", py::arg("stbef"), py::arg("staft"));
cls_HLRAlgo_Coincidence.def("Value2D", [](HLRAlgo_Coincidence &self, Standard_Integer & FE, Standard_Real & Param){ self.Value2D(FE, Param); return std::tuple<Standard_Integer &, Standard_Real &>(FE, Param); }, "None", py::arg("FE"), py::arg("Param"));
cls_HLRAlgo_Coincidence.def("State3D", (void (HLRAlgo_Coincidence::*)(TopAbs_State &, TopAbs_State &) const) &HLRAlgo_Coincidence::State3D, "None", py::arg("stbef"), py::arg("staft"));

// CLASS: HLRALGO_EDGEITERATOR
py::class_<HLRAlgo_EdgeIterator> cls_HLRAlgo_EdgeIterator(mod, "HLRAlgo_EdgeIterator", "None");

// Constructors
cls_HLRAlgo_EdgeIterator.def(py::init<>());

// Methods
// cls_HLRAlgo_EdgeIterator.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_EdgeIterator::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeIterator.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_EdgeIterator::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeIterator.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_EdgeIterator::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeIterator.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_EdgeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_EdgeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_EdgeIterator.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_EdgeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_EdgeIterator.def("InitHidden", (void (HLRAlgo_EdgeIterator::*)(HLRAlgo_EdgeStatus &)) &HLRAlgo_EdgeIterator::InitHidden, "None", py::arg("status"));
cls_HLRAlgo_EdgeIterator.def("MoreHidden", (Standard_Boolean (HLRAlgo_EdgeIterator::*)() const) &HLRAlgo_EdgeIterator::MoreHidden, "None");
cls_HLRAlgo_EdgeIterator.def("NextHidden", (void (HLRAlgo_EdgeIterator::*)()) &HLRAlgo_EdgeIterator::NextHidden, "None");
cls_HLRAlgo_EdgeIterator.def("Hidden", [](HLRAlgo_EdgeIterator &self, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.Hidden(Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "Returns the bounds and the tolerances of the current Hidden Interval", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRAlgo_EdgeIterator.def("InitVisible", (void (HLRAlgo_EdgeIterator::*)(HLRAlgo_EdgeStatus &)) &HLRAlgo_EdgeIterator::InitVisible, "None", py::arg("status"));
cls_HLRAlgo_EdgeIterator.def("MoreVisible", (Standard_Boolean (HLRAlgo_EdgeIterator::*)() const) &HLRAlgo_EdgeIterator::MoreVisible, "None");
cls_HLRAlgo_EdgeIterator.def("NextVisible", (void (HLRAlgo_EdgeIterator::*)()) &HLRAlgo_EdgeIterator::NextVisible, "None");
cls_HLRAlgo_EdgeIterator.def("Visible", [](HLRAlgo_EdgeIterator &self, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.Visible(Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "Returns the bounds and the tolerances of the current Visible Interval", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));

// CLASS: HLRALGO_EDGESTATUS
py::class_<HLRAlgo_EdgeStatus> cls_HLRAlgo_EdgeStatus(mod, "HLRAlgo_EdgeStatus", "This class describes the Hidden Line status of an Edge. It contains :");

// Constructors
cls_HLRAlgo_EdgeStatus.def(py::init<>());
cls_HLRAlgo_EdgeStatus.def(py::init<const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal>(), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));

// Methods
// cls_HLRAlgo_EdgeStatus.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_EdgeStatus::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeStatus.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_EdgeStatus::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeStatus.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_EdgeStatus::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeStatus.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_EdgeStatus::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeStatus.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_EdgeStatus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_EdgeStatus.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_EdgeStatus::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_EdgeStatus.def("Initialize", (void (HLRAlgo_EdgeStatus::*)(const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal)) &HLRAlgo_EdgeStatus::Initialize, "Initialize an EdgeStatus. Default visible. The Edge is bounded by the interval <Start>, <End> with the tolerances <TolStart>, <TolEnd>.", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRAlgo_EdgeStatus.def("Bounds", [](HLRAlgo_EdgeStatus &self, Standard_Real & theStart, Standard_ShortReal & theTolStart, Standard_Real & theEnd, Standard_ShortReal & theTolEnd){ self.Bounds(theStart, theTolStart, theEnd, theTolEnd); return std::tuple<Standard_Real &, Standard_Real &>(theStart, theEnd); }, "None", py::arg("theStart"), py::arg("theTolStart"), py::arg("theEnd"), py::arg("theTolEnd"));
cls_HLRAlgo_EdgeStatus.def("NbVisiblePart", (Standard_Integer (HLRAlgo_EdgeStatus::*)() const) &HLRAlgo_EdgeStatus::NbVisiblePart, "None");
cls_HLRAlgo_EdgeStatus.def("VisiblePart", [](HLRAlgo_EdgeStatus &self, const Standard_Integer Index, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.VisiblePart(Index, Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "None", py::arg("Index"), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRAlgo_EdgeStatus.def("Hide", (void (HLRAlgo_EdgeStatus::*)(const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal, const Standard_Boolean, const Standard_Boolean)) &HLRAlgo_EdgeStatus::Hide, "Hides the interval <Start>, <End> with the tolerances <TolStart>, <TolEnd>. This interval is subtracted from the visible parts. If the hidden part is on ( or under ) the face the flag <OnFace> is True ( or False ). If the hidden part is on ( or inside ) the boundary of the face the flag <OnBoundary> is True ( or False ).", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"), py::arg("OnFace"), py::arg("OnBoundary"));
cls_HLRAlgo_EdgeStatus.def("HideAll", (void (HLRAlgo_EdgeStatus::*)()) &HLRAlgo_EdgeStatus::HideAll, "Hide the whole Edge.");
cls_HLRAlgo_EdgeStatus.def("ShowAll", (void (HLRAlgo_EdgeStatus::*)()) &HLRAlgo_EdgeStatus::ShowAll, "Show the whole Edge.");
cls_HLRAlgo_EdgeStatus.def("AllHidden", (Standard_Boolean (HLRAlgo_EdgeStatus::*)() const) &HLRAlgo_EdgeStatus::AllHidden, "None");
cls_HLRAlgo_EdgeStatus.def("AllHidden", (void (HLRAlgo_EdgeStatus::*)(const Standard_Boolean)) &HLRAlgo_EdgeStatus::AllHidden, "None", py::arg("B"));
cls_HLRAlgo_EdgeStatus.def("AllVisible", (Standard_Boolean (HLRAlgo_EdgeStatus::*)() const) &HLRAlgo_EdgeStatus::AllVisible, "None");
cls_HLRAlgo_EdgeStatus.def("AllVisible", (void (HLRAlgo_EdgeStatus::*)(const Standard_Boolean)) &HLRAlgo_EdgeStatus::AllVisible, "None", py::arg("B"));

// CLASS: HLRALGO_HARRAY1OFPHDAT
bind_Define_HArray1<HLRAlgo_HArray1OfPHDat, HLRAlgo_Array1OfPHDat>(mod, "HLRAlgo_HArray1OfPHDat");

// CLASS: HLRALGO_HARRAY1OFPINOD
bind_Define_HArray1<HLRAlgo_HArray1OfPINod, HLRAlgo_Array1OfPINod>(mod, "HLRAlgo_HArray1OfPINod");

// CLASS: HLRALGO_HARRAY1OFPISEG
bind_Define_HArray1<HLRAlgo_HArray1OfPISeg, HLRAlgo_Array1OfPISeg>(mod, "HLRAlgo_HArray1OfPISeg");

// CLASS: HLRALGO_HARRAY1OFTDATA
bind_Define_HArray1<HLRAlgo_HArray1OfTData, HLRAlgo_Array1OfTData>(mod, "HLRAlgo_HArray1OfTData");

// CLASS: HLRALGO_INTERSECTION
py::class_<HLRAlgo_Intersection> cls_HLRAlgo_Intersection(mod, "HLRAlgo_Intersection", "Describes an intersection on an edge to hide. Contains a parameter and a state (ON = on the face, OUT = above the face, IN = under the Face)");

// Constructors
cls_HLRAlgo_Intersection.def(py::init<>());
cls_HLRAlgo_Intersection.def(py::init<const TopAbs_Orientation, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_ShortReal, const TopAbs_State>(), py::arg("Ori"), py::arg("Lev"), py::arg("SegInd"), py::arg("Ind"), py::arg("P"), py::arg("Tol"), py::arg("S"));

// Methods
// cls_HLRAlgo_Intersection.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Intersection::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Intersection.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Intersection::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Intersection.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Intersection.def("Orientation", (void (HLRAlgo_Intersection::*)(const TopAbs_Orientation)) &HLRAlgo_Intersection::Orientation, "None", py::arg("Ori"));
cls_HLRAlgo_Intersection.def("Orientation", (TopAbs_Orientation (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Orientation, "None");
cls_HLRAlgo_Intersection.def("Level", (void (HLRAlgo_Intersection::*)(const Standard_Integer)) &HLRAlgo_Intersection::Level, "None", py::arg("Lev"));
cls_HLRAlgo_Intersection.def("Level", (Standard_Integer (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Level, "None");
cls_HLRAlgo_Intersection.def("SegIndex", (void (HLRAlgo_Intersection::*)(const Standard_Integer)) &HLRAlgo_Intersection::SegIndex, "None", py::arg("SegInd"));
cls_HLRAlgo_Intersection.def("SegIndex", (Standard_Integer (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::SegIndex, "None");
cls_HLRAlgo_Intersection.def("Index", (void (HLRAlgo_Intersection::*)(const Standard_Integer)) &HLRAlgo_Intersection::Index, "None", py::arg("Ind"));
cls_HLRAlgo_Intersection.def("Index", (Standard_Integer (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Index, "None");
cls_HLRAlgo_Intersection.def("Parameter", (void (HLRAlgo_Intersection::*)(const Standard_Real)) &HLRAlgo_Intersection::Parameter, "None", py::arg("P"));
cls_HLRAlgo_Intersection.def("Parameter", (Standard_Real (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Parameter, "None");
cls_HLRAlgo_Intersection.def("Tolerance", (void (HLRAlgo_Intersection::*)(const Standard_ShortReal)) &HLRAlgo_Intersection::Tolerance, "None", py::arg("T"));
cls_HLRAlgo_Intersection.def("Tolerance", (Standard_ShortReal (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Tolerance, "None");
cls_HLRAlgo_Intersection.def("State", (void (HLRAlgo_Intersection::*)(const TopAbs_State)) &HLRAlgo_Intersection::State, "None", py::arg("S"));
cls_HLRAlgo_Intersection.def("State", (TopAbs_State (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::State, "None");

// CLASS: HLRALGO_INTERFERENCE
py::class_<HLRAlgo_Interference> cls_HLRAlgo_Interference(mod, "HLRAlgo_Interference", "None");

// Constructors
cls_HLRAlgo_Interference.def(py::init<>());
cls_HLRAlgo_Interference.def(py::init<const HLRAlgo_Intersection &, const HLRAlgo_Coincidence &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation>(), py::arg("Inters"), py::arg("Bound"), py::arg("Orient"), py::arg("Trans"), py::arg("BTrans"));

// Methods
// cls_HLRAlgo_Interference.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Interference::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Interference.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Interference::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Interference.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Interference::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Interference.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Interference::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Interference.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Interference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Interference.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Interference::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Interference.def("Intersection", (void (HLRAlgo_Interference::*)(const HLRAlgo_Intersection &)) &HLRAlgo_Interference::Intersection, "None", py::arg("I"));
cls_HLRAlgo_Interference.def("Boundary", (void (HLRAlgo_Interference::*)(const HLRAlgo_Coincidence &)) &HLRAlgo_Interference::Boundary, "None", py::arg("B"));
cls_HLRAlgo_Interference.def("Orientation", (void (HLRAlgo_Interference::*)(const TopAbs_Orientation)) &HLRAlgo_Interference::Orientation, "None", py::arg("O"));
cls_HLRAlgo_Interference.def("Transition", (void (HLRAlgo_Interference::*)(const TopAbs_Orientation)) &HLRAlgo_Interference::Transition, "None", py::arg("Tr"));
cls_HLRAlgo_Interference.def("BoundaryTransition", (void (HLRAlgo_Interference::*)(const TopAbs_Orientation)) &HLRAlgo_Interference::BoundaryTransition, "None", py::arg("BTr"));
cls_HLRAlgo_Interference.def("Intersection", (const HLRAlgo_Intersection & (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Intersection, "None");
cls_HLRAlgo_Interference.def("ChangeIntersection", (HLRAlgo_Intersection & (HLRAlgo_Interference::*)()) &HLRAlgo_Interference::ChangeIntersection, "None");
cls_HLRAlgo_Interference.def("Boundary", (const HLRAlgo_Coincidence & (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Boundary, "None");
cls_HLRAlgo_Interference.def("ChangeBoundary", (HLRAlgo_Coincidence & (HLRAlgo_Interference::*)()) &HLRAlgo_Interference::ChangeBoundary, "None");
cls_HLRAlgo_Interference.def("Orientation", (TopAbs_Orientation (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Orientation, "None");
cls_HLRAlgo_Interference.def("Transition", (TopAbs_Orientation (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Transition, "None");
cls_HLRAlgo_Interference.def("BoundaryTransition", (TopAbs_Orientation (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::BoundaryTransition, "None");

// TYPEDEF: HLRALGO_INTERFERENCELIST
bind_NCollection_List<HLRAlgo_Interference>(mod, "HLRAlgo_InterferenceList", py::module_local(false));

// TYPEDEF: HLRALGO_LISTITERATOROFINTERFERENCELIST
bind_NCollection_TListIterator<HLRAlgo_Interference>(mod, "HLRAlgo_ListIteratorOfInterferenceList", py::module_local(false));

// TYPEDEF: HLRALGO_LISTOFBPOINT
bind_NCollection_List<HLRAlgo_BiPoint>(mod, "HLRAlgo_ListOfBPoint", py::module_local(false));

// TYPEDEF: HLRALGO_LISTITERATOROFLISTOFBPOINT
bind_NCollection_TListIterator<HLRAlgo_BiPoint>(mod, "HLRAlgo_ListIteratorOfListOfBPoint", py::module_local(false));

// CLASS: HLRALGO_POLYDATA
py::class_<HLRAlgo_PolyData, opencascade::handle<HLRAlgo_PolyData>, Standard_Transient> cls_HLRAlgo_PolyData(mod, "HLRAlgo_PolyData", "Data structure of a set of Triangles.");

// Constructors
cls_HLRAlgo_PolyData.def(py::init<>());

// Methods
cls_HLRAlgo_PolyData.def("HNodes", (void (HLRAlgo_PolyData::*)(const opencascade::handle<TColgp_HArray1OfXYZ> &)) &HLRAlgo_PolyData::HNodes, "None", py::arg("HNodes"));
cls_HLRAlgo_PolyData.def("HTData", (void (HLRAlgo_PolyData::*)(const opencascade::handle<HLRAlgo_HArray1OfTData> &)) &HLRAlgo_PolyData::HTData, "None", py::arg("HTData"));
cls_HLRAlgo_PolyData.def("HPHDat", (void (HLRAlgo_PolyData::*)(const opencascade::handle<HLRAlgo_HArray1OfPHDat> &)) &HLRAlgo_PolyData::HPHDat, "None", py::arg("HPHDat"));
cls_HLRAlgo_PolyData.def("FaceIndex", (void (HLRAlgo_PolyData::*)(const Standard_Integer)) &HLRAlgo_PolyData::FaceIndex, "None", py::arg("I"));
cls_HLRAlgo_PolyData.def("FaceIndex", (Standard_Integer (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::FaceIndex, "None");
cls_HLRAlgo_PolyData.def("Nodes", (TColgp_Array1OfXYZ & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::Nodes, "None");
cls_HLRAlgo_PolyData.def("TData", (HLRAlgo_Array1OfTData & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::TData, "None");
cls_HLRAlgo_PolyData.def("PHDat", (HLRAlgo_Array1OfPHDat & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::PHDat, "None");
cls_HLRAlgo_PolyData.def("UpdateGlobalMinMax", (void (HLRAlgo_PolyData::*)(HLRAlgo_PolyData::Box &)) &HLRAlgo_PolyData::UpdateGlobalMinMax, "None", py::arg("theBox"));
cls_HLRAlgo_PolyData.def("Hiding", (Standard_Boolean (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::Hiding, "None");
cls_HLRAlgo_PolyData.def("HideByPolyData", (void (HLRAlgo_PolyData::*)(const HLRAlgo_BiPoint::PointsT &, HLRAlgo_PolyData::Triangle &, HLRAlgo_BiPoint::IndicesT &, const Standard_Boolean, HLRAlgo_EdgeStatus &)) &HLRAlgo_PolyData::HideByPolyData, "process hiding between <Pt1> and <Pt2>.", py::arg("thePoints"), py::arg("theTriangle"), py::arg("theIndices"), py::arg("HidingShell"), py::arg("status"));
cls_HLRAlgo_PolyData.def("Indices", (HLRAlgo_PolyData::FaceIndices & (HLRAlgo_PolyData::*)()) &HLRAlgo_PolyData::Indices, "None");
cls_HLRAlgo_PolyData.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyData::get_type_name, "None");
cls_HLRAlgo_PolyData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyData::get_type_descriptor, "None");
cls_HLRAlgo_PolyData.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::DynamicType, "None");

// CLASS: HLRALGO_POLYALGO
py::class_<HLRAlgo_PolyAlgo, opencascade::handle<HLRAlgo_PolyAlgo>, Standard_Transient> cls_HLRAlgo_PolyAlgo(mod, "HLRAlgo_PolyAlgo", "to remove Hidden lines on Triangulations.");

// Constructors
cls_HLRAlgo_PolyAlgo.def(py::init<>());

// Methods
cls_HLRAlgo_PolyAlgo.def("Init", (void (HLRAlgo_PolyAlgo::*)(const opencascade::handle<TColStd_HArray1OfTransient> &)) &HLRAlgo_PolyAlgo::Init, "None", py::arg("HShell"));
cls_HLRAlgo_PolyAlgo.def("PolyShell", (TColStd_Array1OfTransient & (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::PolyShell, "None");
cls_HLRAlgo_PolyAlgo.def("Clear", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::Clear, "None");
cls_HLRAlgo_PolyAlgo.def("Update", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::Update, "Prepare all the data to process the algo.");
cls_HLRAlgo_PolyAlgo.def("InitHide", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::InitHide, "None");
cls_HLRAlgo_PolyAlgo.def("MoreHide", (Standard_Boolean (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::MoreHide, "None");
cls_HLRAlgo_PolyAlgo.def("NextHide", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::NextHide, "None");
cls_HLRAlgo_PolyAlgo.def("Hide", [](HLRAlgo_PolyAlgo &self, HLRAlgo_EdgeStatus & status, Standard_Integer & Index, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Hide(status, Index, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Integer &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, Index, reg1, regn, outl, intl); }, "process hiding between <Pt1> and <Pt2>.", py::arg("status"), py::arg("Index"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_PolyAlgo.def("InitShow", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::InitShow, "None");
cls_HLRAlgo_PolyAlgo.def("MoreShow", (Standard_Boolean (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::MoreShow, "None");
cls_HLRAlgo_PolyAlgo.def("NextShow", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::NextShow, "None");
cls_HLRAlgo_PolyAlgo.def("Show", [](HLRAlgo_PolyAlgo &self, Standard_Integer & Index, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Show(Index, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Integer &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, Index, reg1, regn, outl, intl); }, "process hiding between <Pt1> and <Pt2>.", py::arg("Index"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_PolyAlgo.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyAlgo::get_type_name, "None");
cls_HLRAlgo_PolyAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyAlgo::get_type_descriptor, "None");
cls_HLRAlgo_PolyAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::DynamicType, "None");

// CLASS: HLRALGO_POLYINTERNALDATA
py::class_<HLRAlgo_PolyInternalData, opencascade::handle<HLRAlgo_PolyInternalData>, Standard_Transient> cls_HLRAlgo_PolyInternalData(mod, "HLRAlgo_PolyInternalData", "to Update OutLines.");

// Constructors
cls_HLRAlgo_PolyInternalData.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbNod"), py::arg("nbTri"));

// Methods
// cls_HLRAlgo_PolyInternalData.def("UpdateLinks", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPINod *&)) &HLRAlgo_PolyInternalData::UpdateLinks, "None", py::arg("TData"), py::arg("PISeg"), py::arg("PINod"));
// cls_HLRAlgo_PolyInternalData.def("AddNode", (Standard_Integer (HLRAlgo_PolyInternalData::*)(HLRAlgo_PolyInternalNode::NodeData &, HLRAlgo_PolyInternalNode::NodeData &, HLRAlgo_Array1OfPINod *&, HLRAlgo_Array1OfPINod *&, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRAlgo_PolyInternalData::AddNode, "None", py::arg("Nod1RValues"), py::arg("Nod2RValues"), py::arg("PINod1"), py::arg("PINod2"), py::arg("coef1"), py::arg("X3"), py::arg("Y3"), py::arg("Z3"));
// cls_HLRAlgo_PolyInternalData.def("UpdateLinks", (void (HLRAlgo_PolyInternalData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPINod *&, HLRAlgo_Array1OfPINod *&)) &HLRAlgo_PolyInternalData::UpdateLinks, "None", py::arg("ip1"), py::arg("ip2"), py::arg("ip3"), py::arg("TData1"), py::arg("TData2"), py::arg("PISeg1"), py::arg("PISeg2"), py::arg("PINod1"), py::arg("PINod2"));
cls_HLRAlgo_PolyInternalData.def("Dump", (void (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::Dump, "None");
// cls_HLRAlgo_PolyInternalData.def("IncTData", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfTData *&)) &HLRAlgo_PolyInternalData::IncTData, "None", py::arg("TData1"), py::arg("TData2"));
// cls_HLRAlgo_PolyInternalData.def("IncPISeg", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPISeg *&)) &HLRAlgo_PolyInternalData::IncPISeg, "None", py::arg("PISeg1"), py::arg("PISeg2"));
// cls_HLRAlgo_PolyInternalData.def("IncPINod", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfPINod *&, HLRAlgo_Array1OfPINod *&)) &HLRAlgo_PolyInternalData::IncPINod, "None", py::arg("PINod1"), py::arg("PINod2"));
cls_HLRAlgo_PolyInternalData.def("DecTData", (void (HLRAlgo_PolyInternalData::*)()) &HLRAlgo_PolyInternalData::DecTData, "None");
cls_HLRAlgo_PolyInternalData.def("DecPISeg", (void (HLRAlgo_PolyInternalData::*)()) &HLRAlgo_PolyInternalData::DecPISeg, "None");
cls_HLRAlgo_PolyInternalData.def("DecPINod", (void (HLRAlgo_PolyInternalData::*)()) &HLRAlgo_PolyInternalData::DecPINod, "None");
cls_HLRAlgo_PolyInternalData.def("NbTData", (Standard_Integer (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::NbTData, "None");
cls_HLRAlgo_PolyInternalData.def("NbPISeg", (Standard_Integer (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::NbPISeg, "None");
cls_HLRAlgo_PolyInternalData.def("NbPINod", (Standard_Integer (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::NbPINod, "None");
cls_HLRAlgo_PolyInternalData.def("Planar", (Standard_Boolean (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::Planar, "None");
cls_HLRAlgo_PolyInternalData.def("Planar", (void (HLRAlgo_PolyInternalData::*)(const Standard_Boolean)) &HLRAlgo_PolyInternalData::Planar, "None", py::arg("B"));
cls_HLRAlgo_PolyInternalData.def("IntOutL", (Standard_Boolean (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::IntOutL, "None");
cls_HLRAlgo_PolyInternalData.def("IntOutL", (void (HLRAlgo_PolyInternalData::*)(const Standard_Boolean)) &HLRAlgo_PolyInternalData::IntOutL, "None", py::arg("B"));
cls_HLRAlgo_PolyInternalData.def("TData", (HLRAlgo_Array1OfTData & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::TData, "None");
cls_HLRAlgo_PolyInternalData.def("PISeg", (HLRAlgo_Array1OfPISeg & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::PISeg, "None");
cls_HLRAlgo_PolyInternalData.def("PINod", (HLRAlgo_Array1OfPINod & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::PINod, "None");
cls_HLRAlgo_PolyInternalData.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyInternalData::get_type_name, "None");
cls_HLRAlgo_PolyInternalData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyInternalData::get_type_descriptor, "None");
cls_HLRAlgo_PolyInternalData.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::DynamicType, "None");

// CLASS: HLRALGO_POLYSHELLDATA
py::class_<HLRAlgo_PolyShellData, opencascade::handle<HLRAlgo_PolyShellData>, Standard_Transient> cls_HLRAlgo_PolyShellData(mod, "HLRAlgo_PolyShellData", "All the PolyData of a Shell");

// Constructors
cls_HLRAlgo_PolyShellData.def(py::init<const Standard_Integer>(), py::arg("nbFace"));

// Methods
cls_HLRAlgo_PolyShellData.def("UpdateGlobalMinMax", (void (HLRAlgo_PolyShellData::*)(HLRAlgo_PolyData::Box &)) &HLRAlgo_PolyShellData::UpdateGlobalMinMax, "None", py::arg("theBox"));
cls_HLRAlgo_PolyShellData.def("UpdateHiding", (void (HLRAlgo_PolyShellData::*)(const Standard_Integer)) &HLRAlgo_PolyShellData::UpdateHiding, "None", py::arg("nbHiding"));
cls_HLRAlgo_PolyShellData.def("Hiding", (Standard_Boolean (HLRAlgo_PolyShellData::*)() const) &HLRAlgo_PolyShellData::Hiding, "None");
cls_HLRAlgo_PolyShellData.def("PolyData", (TColStd_Array1OfTransient & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::PolyData, "None");
cls_HLRAlgo_PolyShellData.def("HidingPolyData", (TColStd_Array1OfTransient & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::HidingPolyData, "None");
cls_HLRAlgo_PolyShellData.def("Edges", (HLRAlgo_ListOfBPoint & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::Edges, "None");
cls_HLRAlgo_PolyShellData.def("Indices", (HLRAlgo_PolyShellData::ShellIndices & (HLRAlgo_PolyShellData::*)()) &HLRAlgo_PolyShellData::Indices, "None");
cls_HLRAlgo_PolyShellData.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyShellData::get_type_name, "None");
cls_HLRAlgo_PolyShellData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyShellData::get_type_descriptor, "None");
cls_HLRAlgo_PolyShellData.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyShellData::*)() const) &HLRAlgo_PolyShellData::DynamicType, "None");


}
