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
#include <TopOpeBRepBuild_WireEdgeSet.hxx>
#include <TopOpeBRepBuild_GTopo.hxx>
#include <TopOpeBRepBuild_Builder.hxx>
#include <TopOpeBRepBuild_LoopEnum.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepBuild_BlockIterator.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Std.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <NCollection_List.hxx>
#include <TopOpeBRepBuild_ListOfLoop.hxx>
#include <TopOpeBRepBuild_ListOfListOfLoop.hxx>
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <TopOpeBRepBuild_LoopClassifier.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRepBuild_AreaBuilder.hxx>
#include <TopOpeBRepBuild_PaveSet.hxx>
#include <TopOpeBRepBuild_PaveClassifier.hxx>
#include <TopOpeBRepBuild_Area1dBuilder.hxx>
#include <TopOpeBRepBuild_Area2dBuilder.hxx>
#include <TopOpeBRepBuild_Area3dBuilder.hxx>
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <TopOpeBRepBuild_EdgeBuilder.hxx>
#include <TopOpeBRepBuild_FaceBuilder.hxx>
#include <TopOpeBRepBuild_SolidBuilder.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepBuild_ShellFaceSet.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>
#include <TopOpeBRepDS_PointIterator.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <TopTools_HArray1OfListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopOpeBRepDS_DataMapOfShapeState.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <TopOpeBRepBuild_Builder1.hxx>
#include <TopOpeBRepBuild_PBuilder.hxx>
#include <TopOpeBRepBuild_PGTopo.hxx>
#include <TopOpeBRepBuild_PWireEdgeSet.hxx>
#include <TopOpeBRepTool_Plos.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepBuild_BuilderON.hxx>
#include <TopOpeBRepBuild_CompositeClassifier.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Wire.hxx>
#include <Bnd_Box2d.hxx>
#include <TopOpeBRepBuild_CorrectFace2d.hxx>
#include <TopOpeBRepBuild_ShapeListOfShape.hxx>
#include <TopOpeBRepBuild_ListOfShapeListOfShape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopOpeBRepBuild_DataMapOfShapeListOfShapeListOfShape.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopOpeBRepBuild_Pave.hxx>
#include <TopOpeBRepBuild_ListOfPave.hxx>
#include <TopOpeBRepBuild_SolidAreaBuilder.hxx>
#include <TopOpeBRepBuild_FaceAreaBuilder.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <TopOpeBRepBuild_FuseFace.hxx>
#include <TopOpeBRepBuild_GIter.hxx>
#include <TopOpeBRepBuild_GTool.hxx>
#include <TopOpeBRepBuild_VertexInfo.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopOpeBRepBuild_IndexedDataMapOfShapeVertexInfo.hxx>
#include <TopoDS_Shell.hxx>
#include <BRep_Builder.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>
#include <TopOpeBRepBuild_ShellFaceClassifier.hxx>
#include <TopOpeBRepBuild_ShellToSolid.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfShapeWithState.hxx>
#include <gp_Vec.hxx>
#include <TopOpeBRepBuild_Tools.hxx>
#include <TopOpeBRepBuild_Tools2d.hxx>
#include <BRepClass_Edge.hxx>
#include <BRepClass_FacePassiveClassifier.hxx>
#include <TopOpeBRepBuild_WireEdgeClassifier.hxx>
#include <TopOpeBRepBuild_WireToFace.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(TopOpeBRepBuild, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopOpeBRepDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopOpeBRepTool");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.BRep");
py::module::import("OCCT.BRepClass");

// ENUM: TOPOPEBREPBUILD_LOOPENUM
py::enum_<TopOpeBRepBuild_LoopEnum>(mod, "TopOpeBRepBuild_LoopEnum", "None")
	.value("TopOpeBRepBuild_ANYLOOP", TopOpeBRepBuild_LoopEnum::TopOpeBRepBuild_ANYLOOP)
	.value("TopOpeBRepBuild_BOUNDARY", TopOpeBRepBuild_LoopEnum::TopOpeBRepBuild_BOUNDARY)
	.value("TopOpeBRepBuild_BLOCK", TopOpeBRepBuild_LoopEnum::TopOpeBRepBuild_BLOCK)
	.export_values();


// CLASS: TOPOPEBREPBUILD_BLOCKITERATOR
py::class_<TopOpeBRepBuild_BlockIterator> cls_TopOpeBRepBuild_BlockIterator(mod, "TopOpeBRepBuild_BlockIterator", "Iterator on the elements of a block.");

// Constructors
cls_TopOpeBRepBuild_BlockIterator.def(py::init<>());
cls_TopOpeBRepBuild_BlockIterator.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Lower"), py::arg("Upper"));

// Methods
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_BlockIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_BlockIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_BlockIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_BlockIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_BlockIterator.def("Initialize", (void (TopOpeBRepBuild_BlockIterator::*)()) &TopOpeBRepBuild_BlockIterator::Initialize, "None");
cls_TopOpeBRepBuild_BlockIterator.def("More", (Standard_Boolean (TopOpeBRepBuild_BlockIterator::*)() const) &TopOpeBRepBuild_BlockIterator::More, "None");
cls_TopOpeBRepBuild_BlockIterator.def("Next", (void (TopOpeBRepBuild_BlockIterator::*)()) &TopOpeBRepBuild_BlockIterator::Next, "None");
cls_TopOpeBRepBuild_BlockIterator.def("Value", (Standard_Integer (TopOpeBRepBuild_BlockIterator::*)() const) &TopOpeBRepBuild_BlockIterator::Value, "None");
cls_TopOpeBRepBuild_BlockIterator.def("Extent", (Standard_Integer (TopOpeBRepBuild_BlockIterator::*)() const) &TopOpeBRepBuild_BlockIterator::Extent, "None");

// CLASS: TOPOPEBREPBUILD_LOOP
py::class_<TopOpeBRepBuild_Loop, opencascade::handle<TopOpeBRepBuild_Loop>, Standard_Transient> cls_TopOpeBRepBuild_Loop(mod, "TopOpeBRepBuild_Loop", "a Loop is an existing shape (Shell,Wire) or a set of shapes (Faces,Edges) which are connex. a set of connex shape is represented by a BlockIterator");

// Constructors
cls_TopOpeBRepBuild_Loop.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopOpeBRepBuild_Loop.def(py::init<const TopOpeBRepBuild_BlockIterator &>(), py::arg("BI"));

// Methods
cls_TopOpeBRepBuild_Loop.def("IsShape", (Standard_Boolean (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::IsShape, "None");
cls_TopOpeBRepBuild_Loop.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::Shape, "None");
cls_TopOpeBRepBuild_Loop.def("BlockIterator", (const TopOpeBRepBuild_BlockIterator & (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::BlockIterator, "None");
cls_TopOpeBRepBuild_Loop.def("Dump", (void (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::Dump, "None");
cls_TopOpeBRepBuild_Loop.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepBuild_Loop::get_type_name, "None");
cls_TopOpeBRepBuild_Loop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepBuild_Loop::get_type_descriptor, "None");
cls_TopOpeBRepBuild_Loop.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepBuild_Loop::*)() const) &TopOpeBRepBuild_Loop::DynamicType, "None");

// TYPEDEF: TOPOPEBREPBUILD_LISTOFLOOP
bind_NCollection_List<opencascade::handle<TopOpeBRepBuild_Loop> >(mod, "TopOpeBRepBuild_ListOfLoop", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_LISTITERATOROFLISTOFLOOP
bind_NCollection_TListIterator<opencascade::handle<TopOpeBRepBuild_Loop> >(mod, "TopOpeBRepBuild_ListIteratorOfListOfLoop", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_LISTOFLISTOFLOOP
bind_NCollection_List<NCollection_List<opencascade::handle<TopOpeBRepBuild_Loop> > >(mod, "TopOpeBRepBuild_ListOfListOfLoop", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_LISTITERATOROFLISTOFLISTOFLOOP
bind_NCollection_TListIterator<NCollection_List<opencascade::handle<TopOpeBRepBuild_Loop> > >(mod, "TopOpeBRepBuild_ListIteratorOfListOfListOfLoop", py::module_local(false));

// CLASS: TOPOPEBREPBUILD_AREABUILDER
py::class_<TopOpeBRepBuild_AreaBuilder> cls_TopOpeBRepBuild_AreaBuilder(mod, "TopOpeBRepBuild_AreaBuilder", "The AreaBuilder algorithm is used to reconstruct complex topological objects as Faces or Solids. * Loop is the composite topological object of the boundary. Wire for a Face. Shell for a Solid. * LoopSet is a tool describing the object to build. It gives an iteration on Loops. For each Loop it tells if it is on the boundary or if it is an interference. * LoopClassifier is an algorithm used to test if a Loop is inside another Loop. The result of the reconstruction is an iteration on the reconstructed areas. An area is described by a set of Loops. A AreaBuilder is built with : - a LoopSet describing the object to reconstruct. - a LoopClassifier providing the classification algorithm.");

// Constructors
cls_TopOpeBRepBuild_AreaBuilder.def(py::init<>());
cls_TopOpeBRepBuild_AreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_AreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_AreaBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_AreaBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_AreaBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_AreaBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_AreaBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_AreaBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_AreaBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_AreaBuilder.def("InitAreaBuilder", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("InitAreaBuilder", (void (TopOpeBRepBuild_AreaBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_AreaBuilder::InitAreaBuilder, "Sets a AreaBuilder to find the areas on the shapes described by <LS> using the classifier <LC>.", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_AreaBuilder.def("InitArea", (Standard_Integer (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::InitArea, "Initialize iteration on areas.");
cls_TopOpeBRepBuild_AreaBuilder.def("MoreArea", (Standard_Boolean (TopOpeBRepBuild_AreaBuilder::*)() const) &TopOpeBRepBuild_AreaBuilder::MoreArea, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("NextArea", (void (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::NextArea, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("InitLoop", (Standard_Integer (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::InitLoop, "Initialize iteration on loops of current Area.");
cls_TopOpeBRepBuild_AreaBuilder.def("MoreLoop", (Standard_Boolean (TopOpeBRepBuild_AreaBuilder::*)() const) &TopOpeBRepBuild_AreaBuilder::MoreLoop, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("NextLoop", (void (TopOpeBRepBuild_AreaBuilder::*)()) &TopOpeBRepBuild_AreaBuilder::NextLoop, "None");
cls_TopOpeBRepBuild_AreaBuilder.def("Loop", (const opencascade::handle<TopOpeBRepBuild_Loop> & (TopOpeBRepBuild_AreaBuilder::*)() const) &TopOpeBRepBuild_AreaBuilder::Loop, "Returns the current Loop in the current area.");
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_Loop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, const opencascade::handle<TopOpeBRepBuild_Loop> & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_Loop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_Loop_TO_LISTOFLoop", (void (TopOpeBRepBuild_AreaBuilder::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_AreaBuilder::ADD_Loop_TO_LISTOFLoop, "None", py::arg("L"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_AreaBuilder.def("REM_Loop_FROM_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListIteratorOfListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.REM_Loop_FROM_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("REM_Loop_FROM_LISTOFLoop", (void (TopOpeBRepBuild_AreaBuilder::*)(TopOpeBRepBuild_ListIteratorOfListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_AreaBuilder::REM_Loop_FROM_LISTOFLoop, "None", py::arg("ITLOL"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_AreaBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2, const Standard_Address a3) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_AreaBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", (void (TopOpeBRepBuild_AreaBuilder::*)(TopOpeBRepBuild_ListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address, const Standard_Address, const Standard_Address) const) &TopOpeBRepBuild_AreaBuilder::ADD_LISTOFLoop_TO_LISTOFLoop, "None", py::arg("LOL1"), py::arg("LOL2"), py::arg("s"), py::arg("s1"), py::arg("s2"));

// CLASS: TOPOPEBREPBUILD_AREA1DBUILDER
py::class_<TopOpeBRepBuild_Area1dBuilder, TopOpeBRepBuild_AreaBuilder> cls_TopOpeBRepBuild_Area1dBuilder(mod, "TopOpeBRepBuild_Area1dBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_Area1dBuilder.def(py::init<>());
cls_TopOpeBRepBuild_Area1dBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_Area1dBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Area1dBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Area1dBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Area1dBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Area1dBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Area1dBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area1dBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Area1dBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Area1dBuilder.def("InitAreaBuilder", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("InitAreaBuilder", (void (TopOpeBRepBuild_Area1dBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_Area1dBuilder::InitAreaBuilder, "Sets a Area1dBuilder to find the areas of the shapes described by <LS> using the classifier <LC>.", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_Loop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, const opencascade::handle<TopOpeBRepBuild_Loop> & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_Loop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_Loop_TO_LISTOFLoop", (void (TopOpeBRepBuild_Area1dBuilder::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_Area1dBuilder::ADD_Loop_TO_LISTOFLoop, "None", py::arg("L"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_Area1dBuilder.def("REM_Loop_FROM_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListIteratorOfListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.REM_Loop_FROM_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("REM_Loop_FROM_LISTOFLoop", (void (TopOpeBRepBuild_Area1dBuilder::*)(TopOpeBRepBuild_ListIteratorOfListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address) const) &TopOpeBRepBuild_Area1dBuilder::REM_Loop_FROM_LISTOFLoop, "None", py::arg("ITLOL"), py::arg("LOL"), py::arg("s"));
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", [](TopOpeBRepBuild_Area1dBuilder &self, TopOpeBRepBuild_ListOfLoop & a0, TopOpeBRepBuild_ListOfLoop & a1, const Standard_Address a2, const Standard_Address a3) -> void { return self.ADD_LISTOFLoop_TO_LISTOFLoop(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Area1dBuilder.def("ADD_LISTOFLoop_TO_LISTOFLoop", (void (TopOpeBRepBuild_Area1dBuilder::*)(TopOpeBRepBuild_ListOfLoop &, TopOpeBRepBuild_ListOfLoop &, const Standard_Address, const Standard_Address, const Standard_Address) const) &TopOpeBRepBuild_Area1dBuilder::ADD_LISTOFLoop_TO_LISTOFLoop, "None", py::arg("LOL1"), py::arg("LOL2"), py::arg("s"), py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_Area1dBuilder.def_static("DumpList_", (void (*)(const TopOpeBRepBuild_ListOfLoop &)) &TopOpeBRepBuild_Area1dBuilder::DumpList, "None", py::arg("L"));

// CLASS: TOPOPEBREPBUILD_AREA2DBUILDER
py::class_<TopOpeBRepBuild_Area2dBuilder, TopOpeBRepBuild_AreaBuilder> cls_TopOpeBRepBuild_Area2dBuilder(mod, "TopOpeBRepBuild_Area2dBuilder", "The Area2dBuilder algorithm is used to construct Faces from a LoopSet, where the Loop is the composite topological object of the boundary, here wire or block of edges. The LoopSet gives an iteration on Loops. For each Loop it indicates if it is on the boundary (wire) or if it results from an interference (block of edges). The result of the Area2dBuilder is an iteration on areas. An area is described by a set of Loops.");

// Constructors
cls_TopOpeBRepBuild_Area2dBuilder.def(py::init<>());
cls_TopOpeBRepBuild_Area2dBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_Area2dBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_Area2dBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Area2dBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area2dBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Area2dBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area2dBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Area2dBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area2dBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Area2dBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area2dBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Area2dBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area2dBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Area2dBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Area2dBuilder.def("InitAreaBuilder", [](TopOpeBRepBuild_Area2dBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_Area2dBuilder.def("InitAreaBuilder", (void (TopOpeBRepBuild_Area2dBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_Area2dBuilder::InitAreaBuilder, "Sets a Area1dBuilder to find the areas of the shapes described by <LS> using the classifier <LC>.", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// CLASS: TOPOPEBREPBUILD_AREA3DBUILDER
py::class_<TopOpeBRepBuild_Area3dBuilder, TopOpeBRepBuild_AreaBuilder> cls_TopOpeBRepBuild_Area3dBuilder(mod, "TopOpeBRepBuild_Area3dBuilder", "The Area3dBuilder algorithm is used to construct Solids from a LoopSet, where the Loop is the composite topological object of the boundary, here wire or block of edges. The LoopSet gives an iteration on Loops. For each Loop it indicates if it is on the boundary (wire) or if it results from an interference (block of edges). The result of the Area3dBuilder is an iteration on areas. An area is described by a set of Loops.");

// Constructors
cls_TopOpeBRepBuild_Area3dBuilder.def(py::init<>());
cls_TopOpeBRepBuild_Area3dBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_Area3dBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_Area3dBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Area3dBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area3dBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Area3dBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area3dBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Area3dBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Area3dBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Area3dBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area3dBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Area3dBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Area3dBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Area3dBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Area3dBuilder.def("InitAreaBuilder", [](TopOpeBRepBuild_Area3dBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_Area3dBuilder.def("InitAreaBuilder", (void (TopOpeBRepBuild_Area3dBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_Area3dBuilder::InitAreaBuilder, "Sets a Area1dBuilder to find the areas of the shapes described by <LS> using the classifier <LC>.", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// CLASS: TOPOPEBREPBUILD_BLOCKBUILDER
py::class_<TopOpeBRepBuild_BlockBuilder> cls_TopOpeBRepBuild_BlockBuilder(mod, "TopOpeBRepBuild_BlockBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_BlockBuilder.def(py::init<>());
cls_TopOpeBRepBuild_BlockBuilder.def(py::init<TopOpeBRepBuild_ShapeSet &>(), py::arg("SS"));

// Methods
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_BlockBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_BlockBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_BlockBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_BlockBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_BlockBuilder.def("MakeBlock", (void (TopOpeBRepBuild_BlockBuilder::*)(TopOpeBRepBuild_ShapeSet &)) &TopOpeBRepBuild_BlockBuilder::MakeBlock, "None", py::arg("SS"));
cls_TopOpeBRepBuild_BlockBuilder.def("InitBlock", (void (TopOpeBRepBuild_BlockBuilder::*)()) &TopOpeBRepBuild_BlockBuilder::InitBlock, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("MoreBlock", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)() const) &TopOpeBRepBuild_BlockBuilder::MoreBlock, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("NextBlock", (void (TopOpeBRepBuild_BlockBuilder::*)()) &TopOpeBRepBuild_BlockBuilder::NextBlock, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("BlockIterator", (TopOpeBRepBuild_BlockIterator (TopOpeBRepBuild_BlockBuilder::*)() const) &TopOpeBRepBuild_BlockBuilder::BlockIterator, "None");
cls_TopOpeBRepBuild_BlockBuilder.def("Element", (const TopoDS_Shape & (TopOpeBRepBuild_BlockBuilder::*)(const TopOpeBRepBuild_BlockIterator &) const) &TopOpeBRepBuild_BlockBuilder::Element, "Returns the current element of <BI>.", py::arg("BI"));
cls_TopOpeBRepBuild_BlockBuilder.def("Element", (const TopoDS_Shape & (TopOpeBRepBuild_BlockBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_BlockBuilder::Element, "None", py::arg("I"));
cls_TopOpeBRepBuild_BlockBuilder.def("Element", (Standard_Integer (TopOpeBRepBuild_BlockBuilder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_BlockBuilder::Element, "None", py::arg("S"));
cls_TopOpeBRepBuild_BlockBuilder.def("ElementIsValid", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)(const TopOpeBRepBuild_BlockIterator &) const) &TopOpeBRepBuild_BlockBuilder::ElementIsValid, "None", py::arg("BI"));
cls_TopOpeBRepBuild_BlockBuilder.def("ElementIsValid", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_BlockBuilder::ElementIsValid, "None", py::arg("I"));
cls_TopOpeBRepBuild_BlockBuilder.def("AddElement", (Standard_Integer (TopOpeBRepBuild_BlockBuilder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_BlockBuilder::AddElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_BlockBuilder.def("SetValid", (void (TopOpeBRepBuild_BlockBuilder::*)(const TopOpeBRepBuild_BlockIterator &, const Standard_Boolean)) &TopOpeBRepBuild_BlockBuilder::SetValid, "None", py::arg("BI"), py::arg("isvalid"));
cls_TopOpeBRepBuild_BlockBuilder.def("SetValid", (void (TopOpeBRepBuild_BlockBuilder::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepBuild_BlockBuilder::SetValid, "None", py::arg("I"), py::arg("isvalid"));
cls_TopOpeBRepBuild_BlockBuilder.def("CurrentBlockIsRegular", (Standard_Boolean (TopOpeBRepBuild_BlockBuilder::*)()) &TopOpeBRepBuild_BlockBuilder::CurrentBlockIsRegular, "None");

// CLASS: TOPOPEBREPBUILD_BUILDER
py::class_<TopOpeBRepBuild_Builder> cls_TopOpeBRepBuild_Builder(mod, "TopOpeBRepBuild_Builder", "The Builder algorithm constructs topological objects from an existing topology and new geometries attached to the topology. It is used to construct the result of a topological operation; the existing topologies are the parts involved in the topological operation and the new geometries are the intersection lines and points.");

// Constructors
cls_TopOpeBRepBuild_Builder.def(py::init<const TopOpeBRepDS_BuildTool &>(), py::arg("BT"));

// Methods
// cls_TopOpeBRepBuild_Builder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Builder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Builder.def("ChangeBuildTool", (TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::ChangeBuildTool, "None");
cls_TopOpeBRepBuild_Builder.def("BuildTool", (const TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::BuildTool, "None");
cls_TopOpeBRepBuild_Builder.def("Perform", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder::Perform, "Stores the data structure <HDS>, Create shapes from the new geometries.", py::arg("HDS"));
cls_TopOpeBRepBuild_Builder.def("Perform", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::Perform, "Stores the data structure <HDS>, Create shapes from the new geometries, Evaluates if an operation performed on shapes S1,S2 is a particular case.", py::arg("HDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("DataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::DataStructure, "returns the DS handled by this builder");
cls_TopOpeBRepBuild_Builder.def("Clear", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::Clear, "Removes all splits and merges already performed. Does NOT clear the handled DS.");
cls_TopOpeBRepBuild_Builder.def("MergeEdges", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3) -> void { return self.MergeEdges(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Builder.def("MergeEdges", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4) -> void { return self.MergeEdges(a0, a1, a2, a3, a4); });
cls_TopOpeBRepBuild_Builder.def("MergeEdges", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.MergeEdges(a0, a1, a2, a3, a4, a5); });
cls_TopOpeBRepBuild_Builder.def("MergeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopAbs_State, const TopTools_ListOfShape &, const TopAbs_State, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_Builder::MergeEdges, "Merges the two edges <S1> and <S2> keeping the parts in each edge of states <TB1> and <TB2>. Booleans onA, onB, onAB indicate wheter parts of edges found as state ON respectively on first, second, and both shapes must be (or not) built.", py::arg("L1"), py::arg("TB1"), py::arg("L2"), py::arg("TB2"), py::arg("onA"), py::arg("onB"), py::arg("onAB"));
cls_TopOpeBRepBuild_Builder.def("MergeFaces", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3) -> void { return self.MergeFaces(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Builder.def("MergeFaces", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4) -> void { return self.MergeFaces(a0, a1, a2, a3, a4); });
cls_TopOpeBRepBuild_Builder.def("MergeFaces", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0, const TopAbs_State a1, const TopTools_ListOfShape & a2, const TopAbs_State a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.MergeFaces(a0, a1, a2, a3, a4, a5); });
cls_TopOpeBRepBuild_Builder.def("MergeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopAbs_State, const TopTools_ListOfShape &, const TopAbs_State, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_Builder::MergeFaces, "Merges the two faces <S1> and <S2> keeping the parts in each face of states <TB1> and <TB2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"), py::arg("onA"), py::arg("onB"), py::arg("onAB"));
cls_TopOpeBRepBuild_Builder.def("MergeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeSolids, "Merges the two solids <S1> and <S2> keeping the parts in each solid of states <TB1> and <TB2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder.def("MergeShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeShapes, "Merges the two shapes <S1> and <S2> keeping the parts of states <TB1>,<TB2> in <S1>,<S2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder.def("End", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::End, "None");
cls_TopOpeBRepBuild_Builder.def("Classify", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Classify, "None");
cls_TopOpeBRepBuild_Builder.def("ChangeClassify", (void (TopOpeBRepBuild_Builder::*)(const Standard_Boolean)) &TopOpeBRepBuild_Builder::ChangeClassify, "None", py::arg("B"));
cls_TopOpeBRepBuild_Builder.def("MergeSolid", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeSolid, "Merges the solid <S> keeping the parts of state <TB>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("NewVertex", (const TopoDS_Shape & (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::NewVertex, "Returns the vertex created on point <I>.", py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("NewEdges", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::NewEdges, "Returns the edges created on curve <I>.", py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("NewFaces", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::NewFaces, "Returns the faces created on surface <I>.", py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("IsSplit", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::IsSplit, "Returns True if the shape <S> has been split.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("Splits", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::Splits, "Returns the split parts <TB> of shape <S>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("IsMerged", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::IsMerged, "Returns True if the shape <S> has been merged.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("Merged", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::Merged, "Returns the merged parts <TB> of shape <S>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("InitSection", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::InitSection, "None");
cls_TopOpeBRepBuild_Builder.def("SplitSectionEdges", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::SplitSectionEdges, "create parts ON solid of section edges");
cls_TopOpeBRepBuild_Builder.def("SplitSectionEdge", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::SplitSectionEdge, "create parts ON solid of section edges", py::arg("E"));
cls_TopOpeBRepBuild_Builder.def("SectionCurves", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::SectionCurves, "return the section edges built on new curves.", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("SectionEdges", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::SectionEdges, "return the parts of edges found ON the boundary of the two arguments S1,S2 of Perform()", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("FillSecEdgeAncestorMap", (void (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const TopTools_MapOfShape &, TopTools_DataMapOfShapeShape &) const) &TopOpeBRepBuild_Builder::FillSecEdgeAncestorMap, "Fills anAncMap with pairs (edge,ancestor edge) for each split from the map aMapON for the shape object identified by ShapeRank", py::arg("aShapeRank"), py::arg("aMapON"), py::arg("anAncMap"));
cls_TopOpeBRepBuild_Builder.def("Section", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::Section, "return all section edges.", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("Section", (const TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::Section, "None");
cls_TopOpeBRepBuild_Builder.def("BuildVertices", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder::BuildVertices, "update the DS by creating new geometries. create vertices on DS points.", py::arg("DS"));
cls_TopOpeBRepBuild_Builder.def("BuildEdges", (void (TopOpeBRepBuild_Builder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder::BuildEdges, "update the DS by creating new geometries. create shapes from the new geometries.", py::arg("DS"));
cls_TopOpeBRepBuild_Builder.def("MSplit", (const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & (TopOpeBRepBuild_Builder::*)(const TopAbs_State) const) &TopOpeBRepBuild_Builder::MSplit, "None", py::arg("s"));
cls_TopOpeBRepBuild_Builder.def("ChangeMSplit", (TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & (TopOpeBRepBuild_Builder::*)(const TopAbs_State)) &TopOpeBRepBuild_Builder::ChangeMSplit, "None", py::arg("s"));
cls_TopOpeBRepBuild_Builder.def("MakeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_EdgeBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeEdges, "None", py::arg("E"), py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("MakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_FaceBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeFaces, "None", py::arg("F"), py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("MakeSolids", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_SolidBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeSolids, "None", py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("MakeShells", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_SolidBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::MakeShells, "None", py::arg("B"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("ChangeSplit", (TopTools_ListOfShape & (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::ChangeSplit, "Returns a ref.on the list of shapes connected to <S> as <TB> split parts of <S>. Mark <S> as split in <TB> parts.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("Opec12", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opec12, "None");
cls_TopOpeBRepBuild_Builder.def("Opec21", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opec21, "None");
cls_TopOpeBRepBuild_Builder.def("Opecom", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opecom, "None");
cls_TopOpeBRepBuild_Builder.def("Opefus", (Standard_Boolean (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::Opefus, "None");
cls_TopOpeBRepBuild_Builder.def("ShapePosition", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::ShapePosition, "None", py::arg("S"), py::arg("LS"));
cls_TopOpeBRepBuild_Builder.def("KeepShape", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::KeepShape, "None", py::arg("S"), py::arg("LS"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def_static("TopType_", (TopAbs_ShapeEnum (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::TopType, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("Reverse_", (Standard_Boolean (*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_Builder::Reverse, "None", py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepBuild_Builder.def_static("Orient_", (TopAbs_Orientation (*)(const TopAbs_Orientation, const Standard_Boolean)) &TopOpeBRepBuild_Builder::Orient, "None", py::arg("O"), py::arg("R"));
cls_TopOpeBRepBuild_Builder.def("FindSameDomain", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindSameDomain, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("FindSameDomainSameOrientation", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindSameDomainSameOrientation, "None", py::arg("LSO"), py::arg("LDO"));
cls_TopOpeBRepBuild_Builder.def("MapShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::MapShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("ClearMaps", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::ClearMaps, "None");
cls_TopOpeBRepBuild_Builder.def("FindSameRank", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindSameRank, "None", py::arg("L1"), py::arg("R"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("ShapeRank", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::ShapeRank, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("IsShapeOf", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Integer) const) &TopOpeBRepBuild_Builder::IsShapeOf, "None", py::arg("S"), py::arg("I12"));
cls_TopOpeBRepBuild_Builder.def_static("Contains_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::Contains, "None", py::arg("S"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("FindIsKPart", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::FindIsKPart, "None");
cls_TopOpeBRepBuild_Builder.def("IsKPart", (Standard_Integer (TopOpeBRepBuild_Builder::*)() const) &TopOpeBRepBuild_Builder::IsKPart, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPart", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPart, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPart", (void (TopOpeBRepBuild_Builder::*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_Builder::MergeKPart, "None", py::arg("TB1"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder.def("MergeKPartiskole", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartiskole, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartiskoletge", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartiskoletge, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartisdisj", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartisdisj, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartisfafa", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartisfafa, "None");
cls_TopOpeBRepBuild_Builder.def("MergeKPartissoso", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::MergeKPartissoso, "None");
cls_TopOpeBRepBuild_Builder.def("KPiskole", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPiskole, "None");
cls_TopOpeBRepBuild_Builder.def("KPiskoletge", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPiskoletge, "None");
cls_TopOpeBRepBuild_Builder.def("KPisdisj", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPisdisj, "None");
cls_TopOpeBRepBuild_Builder.def("KPisfafa", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPisfafa, "None");
cls_TopOpeBRepBuild_Builder.def("KPissoso", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPissoso, "None");
cls_TopOpeBRepBuild_Builder.def("KPClearMaps", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::KPClearMaps, "None");
cls_TopOpeBRepBuild_Builder.def("KPlhg", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPlhg, "None", py::arg("S"), py::arg("T"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("KPlhg", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum) const) &TopOpeBRepBuild_Builder::KPlhg, "None", py::arg("S"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("KPlhsd", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPlhsd, "None", py::arg("S"), py::arg("T"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("KPlhsd", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum) const) &TopOpeBRepBuild_Builder::KPlhsd, "None", py::arg("S"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("KPclasSS", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclasSS, "None", py::arg("S1"), py::arg("exceptLS1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("KPclasSS", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclasSS, "None", py::arg("S1"), py::arg("exceptS1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("KPclasSS", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclasSS, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("KPiskolesh", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPiskolesh, "None", py::arg("S"), py::arg("LS"), py::arg("LF"));
cls_TopOpeBRepBuild_Builder.def("KPiskoletgesh", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPiskoletgesh, "None", py::arg("S"), py::arg("LS"), py::arg("LF"));
cls_TopOpeBRepBuild_Builder.def("KPSameDomain", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::KPSameDomain, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("KPisdisjsh", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::KPisdisjsh, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("KPisfafash", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::KPisfafash, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("KPissososh", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::KPissososh, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("KPiskoleanalyse", [](TopOpeBRepBuild_Builder &self, const TopAbs_State FT1, const TopAbs_State FT2, const TopAbs_State ST1, const TopAbs_State ST2, Standard_Integer & I, Standard_Integer & I1, Standard_Integer & I2){ self.KPiskoleanalyse(FT1, FT2, ST1, ST2, I, I1, I2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(I, I1, I2); }, "None", py::arg("FT1"), py::arg("FT2"), py::arg("ST1"), py::arg("ST2"), py::arg("I"), py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepBuild_Builder.def("KPiskoletgeanalyse", [](TopOpeBRepBuild_Builder &self, const TopOpeBRepDS_Config Conf, const TopAbs_State ST1, const TopAbs_State ST2, Standard_Integer & I){ self.KPiskoletgeanalyse(Conf, ST1, ST2, I); return I; }, "None", py::arg("Conf"), py::arg("ST1"), py::arg("ST2"), py::arg("I"));
cls_TopOpeBRepBuild_Builder.def("KPisdisjanalyse", [](TopOpeBRepBuild_Builder &self, const TopAbs_State ST1, const TopAbs_State ST2, Standard_Integer & I, Standard_Integer & IC1, Standard_Integer & IC2){ self.KPisdisjanalyse(ST1, ST2, I, IC1, IC2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(I, IC1, IC2); }, "None", py::arg("ST1"), py::arg("ST2"), py::arg("I"), py::arg("IC1"), py::arg("IC2"));
cls_TopOpeBRepBuild_Builder.def_static("KPls_", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::KPls, "None", py::arg("S"), py::arg("T"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def_static("KPls_", (Standard_Integer (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_Builder::KPls, "None", py::arg("S"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("KPclassF", (TopAbs_State (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::KPclassF, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRepBuild_Builder.def("KPclassFF", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopAbs_State &, TopAbs_State &)) &TopOpeBRepBuild_Builder::KPclassFF, "None", py::arg("F1"), py::arg("F2"), py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepBuild_Builder.def("KPiskoleFF", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopAbs_State &, TopAbs_State &)) &TopOpeBRepBuild_Builder::KPiskoleFF, "None", py::arg("F1"), py::arg("F2"), py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepBuild_Builder.def_static("KPContains_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::KPContains, "None", py::arg("S"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def("KPmakeface", (TopoDS_Shape (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State, const TopAbs_State, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_Builder::KPmakeface, "None", py::arg("F1"), py::arg("LF2"), py::arg("T1"), py::arg("T2"), py::arg("R1"), py::arg("R2"));
cls_TopOpeBRepBuild_Builder.def_static("KPreturn_", (Standard_Integer (*)(const Standard_Integer)) &TopOpeBRepBuild_Builder::KPreturn, "None", py::arg("KP"));
cls_TopOpeBRepBuild_Builder.def("SplitEvisoONperiodicF", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::SplitEvisoONperiodicF, "None");
cls_TopOpeBRepBuild_Builder.def("GMergeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GMergeSolids, "None", py::arg("LSO1"), py::arg("LSO2"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillSolidsSFS", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillSolidsSFS, "None", py::arg("LSO1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillSolidSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillSolidSFS, "None", py::arg("SO1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillSurfaceTopologySFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillSurfaceTopologySFS, "None", py::arg("SO1"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillSurfaceTopologySFS", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepDS_SurfaceIterator &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &) const) &TopOpeBRepBuild_Builder::GFillSurfaceTopologySFS, "None", py::arg("IT"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillShellSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillShellSFS, "None", py::arg("SH1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GFillFaceSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GFillFaceSFS, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GSplitFaceSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GSplitFaceSFS, "None", py::arg("F1"), py::arg("LSclass"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GMergeFaceSFS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::GMergeFaceSFS, "None", py::arg("F"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("GSplitFace", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSplitFace, "None", py::arg("F"), py::arg("G"), py::arg("LSclass"));
cls_TopOpeBRepBuild_Builder.def("AddONPatchesSFS", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder::AddONPatchesSFS, "None", py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder.def("FillOnPatches", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopoDS_Shape &, const TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepBuild_Builder::FillOnPatches, "None", py::arg("anEdgesON"), py::arg("aBaseFace"), py::arg("avoidMap"));
cls_TopOpeBRepBuild_Builder.def("FindFacesTouchingEdge", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::FindFacesTouchingEdge, "None", py::arg("aFace"), py::arg("anEdge"), py::arg("aShRank"), py::arg("aFaces"));
cls_TopOpeBRepBuild_Builder.def("GMergeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GMergeFaces, "None", py::arg("LF1"), py::arg("LF2"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillFacesWES", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillFacesWES, "None", py::arg("LF1"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillFacesWESK", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &, const Standard_Integer)) &TopOpeBRepBuild_Builder::GFillFacesWESK, "None", py::arg("LF1"), py::arg("LF2"), py::arg("G"), py::arg("WES"), py::arg("K"));
cls_TopOpeBRepBuild_Builder.def("GFillFacesWESMakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GFillFacesWESMakeFaces, "None", py::arg("LF1"), py::arg("LF2"), py::arg("LSO"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillFaceWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillFaceWES, "None", py::arg("F"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillCurveTopologyWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillCurveTopologyWES, "None", py::arg("F"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillCurveTopologyWES", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepDS_CurveIterator &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &) const) &TopOpeBRepBuild_Builder::GFillCurveTopologyWES, "None", py::arg("IT"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillONPartsWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, const TopTools_ListOfShape &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillONPartsWES, "None", py::arg("F"), py::arg("G"), py::arg("LSclass"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillWireWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillWireWES, "None", py::arg("W"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GFillEdgeWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GFillEdgeWES, "None", py::arg("E"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GSplitEdgeWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GSplitEdgeWES, "None", py::arg("E"), py::arg("LF2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GMergeEdgeWES", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder::GMergeEdgeWES, "None", py::arg("E"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder.def("GSplitEdge", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSplitEdge, "None", py::arg("E"), py::arg("G"), py::arg("LSclass"));
cls_TopOpeBRepBuild_Builder.def("GMergeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GMergeEdges, "None", py::arg("LE1"), py::arg("LE2"), py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFillEdgesPVS", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder::GFillEdgesPVS, "None", py::arg("LE1"), py::arg("LE2"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GFillEdgePVS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder::GFillEdgePVS, "None", py::arg("E"), py::arg("LE2"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GFillPointTopologyPVS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder::GFillPointTopologyPVS, "None", py::arg("E"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GFillPointTopologyPVS", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopOpeBRepDS_PointIterator &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &) const) &TopOpeBRepBuild_Builder::GFillPointTopologyPVS, "None", py::arg("E"), py::arg("IT"), py::arg("G"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder.def("GParamOnReference", [](TopOpeBRepBuild_Builder &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P){ Standard_Boolean rv = self.GParamOnReference(V, E, P); return std::tuple<Standard_Boolean, Standard_Real &>(rv, P); }, "None", py::arg("V"), py::arg("E"), py::arg("P"));
cls_TopOpeBRepBuild_Builder.def("GKeepShape", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepBuild_Builder::GKeepShape, "None", py::arg("S"), py::arg("Lref"), py::arg("T"));
cls_TopOpeBRepBuild_Builder.def("GKeepShape1", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State, TopAbs_State &)) &TopOpeBRepBuild_Builder::GKeepShape1, "return True if S is classified <T> / Lref shapes", py::arg("S"), py::arg("Lref"), py::arg("T"), py::arg("pos"));
cls_TopOpeBRepBuild_Builder.def("GKeepShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopAbs_State, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GKeepShapes, "add to Lou the shapes of Lin classified <T> / Lref shapes. Lou is not cleared. (S is a dummy trace argument)", py::arg("S"), py::arg("Lref"), py::arg("T"), py::arg("Lin"), py::arg("Lou"));
cls_TopOpeBRepBuild_Builder.def("GSFSMakeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_ShellFaceSet &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSFSMakeSolids, "None", py::arg("SOF"), py::arg("SFS"), py::arg("LOSO"));
cls_TopOpeBRepBuild_Builder.def("GSOBUMakeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_SolidBuilder &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GSOBUMakeSolids, "None", py::arg("SOF"), py::arg("SOBU"), py::arg("LOSO"));
cls_TopOpeBRepBuild_Builder.def("GWESMakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_WireEdgeSet &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GWESMakeFaces, "None", py::arg("FF"), py::arg("WES"), py::arg("LOF"));
cls_TopOpeBRepBuild_Builder.def("GFABUMakeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_FaceBuilder &, TopTools_ListOfShape &, TopTools_DataMapOfShapeInteger &)) &TopOpeBRepBuild_Builder::GFABUMakeFaces, "None", py::arg("FF"), py::arg("FABU"), py::arg("LOF"), py::arg("MWisOld"));
cls_TopOpeBRepBuild_Builder.def("RegularizeFaces", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeFaces, "None", py::arg("FF"), py::arg("lnewFace"), py::arg("LOF"));
cls_TopOpeBRepBuild_Builder.def("RegularizeFace", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeFace, "None", py::arg("FF"), py::arg("newFace"), py::arg("LOF"));
cls_TopOpeBRepBuild_Builder.def("RegularizeSolids", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeSolids, "None", py::arg("SS"), py::arg("lnewSolid"), py::arg("LOS"));
cls_TopOpeBRepBuild_Builder.def("RegularizeSolid", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::RegularizeSolid, "None", py::arg("SS"), py::arg("newSolid"), py::arg("LOS"));
cls_TopOpeBRepBuild_Builder.def("GPVSMakeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_PaveSet &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GPVSMakeEdges, "None", py::arg("EF"), py::arg("PVS"), py::arg("LOE"));
cls_TopOpeBRepBuild_Builder.def("GEDBUMakeEdges", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopOpeBRepBuild_EdgeBuilder &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GEDBUMakeEdges, "None", py::arg("EF"), py::arg("EDBU"), py::arg("LOE"));
cls_TopOpeBRepBuild_Builder.def("GToSplit", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_Builder::GToSplit, "None", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_Builder.def("GToMerge", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::GToMerge, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("GTakeCommonOfSame_", (Standard_Boolean (*)(const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GTakeCommonOfSame, "None", py::arg("G"));
cls_TopOpeBRepBuild_Builder.def_static("GTakeCommonOfDiff_", (Standard_Boolean (*)(const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_Builder::GTakeCommonOfDiff, "None", py::arg("G"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDom", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDom, "None", py::arg("S"), py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDom", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDom, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDomSODO", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDomSODO, "None", py::arg("S"), py::arg("LSO"), py::arg("LDO"));
cls_TopOpeBRepBuild_Builder.def("GFindSamDomSODO", (void (TopOpeBRepBuild_Builder::*)(TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSamDomSODO, "None", py::arg("LSO"), py::arg("LDO"));
cls_TopOpeBRepBuild_Builder.def("GMapShapes", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::GMapShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder.def("GClearMaps", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::GClearMaps, "None");
cls_TopOpeBRepBuild_Builder.def("GFindSameRank", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GFindSameRank, "None", py::arg("L1"), py::arg("R"), py::arg("L2"));
cls_TopOpeBRepBuild_Builder.def("GShapeRank", (Standard_Integer (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::GShapeRank, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("GIsShapeOf", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Integer) const) &TopOpeBRepBuild_Builder::GIsShapeOf, "None", py::arg("S"), py::arg("I12"));
cls_TopOpeBRepBuild_Builder.def_static("GContains_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GContains, "None", py::arg("S"), py::arg("L"));
cls_TopOpeBRepBuild_Builder.def_static("GCopyList_", (void (*)(const TopTools_ListOfShape &, const Standard_Integer, const Standard_Integer, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GCopyList, "None", py::arg("Lin"), py::arg("i1"), py::arg("i2"), py::arg("Lou"));
cls_TopOpeBRepBuild_Builder.def_static("GCopyList_", (void (*)(const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder::GCopyList, "None", py::arg("Lin"), py::arg("Lou"));
cls_TopOpeBRepBuild_Builder.def("GdumpLS", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &) const) &TopOpeBRepBuild_Builder::GdumpLS, "None", py::arg("L"));
cls_TopOpeBRepBuild_Builder.def_static("GdumpPNT_", (void (*)(const gp_Pnt &)) &TopOpeBRepBuild_Builder::GdumpPNT, "None", py::arg("P"));
cls_TopOpeBRepBuild_Builder.def_static("GdumpORIPARPNT_", (void (*)(const TopAbs_Orientation, const Standard_Real, const gp_Pnt &)) &TopOpeBRepBuild_Builder::GdumpORIPARPNT, "None", py::arg("o"), py::arg("p"), py::arg("Pnt"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHA", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpSHA(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHA", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSHA, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORI", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpSHAORI(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORI", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSHAORI, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORIGEO", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpSHAORIGEO(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHAORIGEO", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSHAORIGEO, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1) -> void { return self.GdumpSHASTA(a0, a1); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TCollection_AsciiString & a2) -> void { return self.GdumpSHASTA(a0, a1, a2); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", (void (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const TopAbs_State, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_Builder::GdumpSHASTA, "None", py::arg("iS"), py::arg("T"), py::arg("a"), py::arg("b"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0, const TopAbs_State a1) -> void { return self.GdumpSHASTA(a0, a1); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0, const TopAbs_State a1, const TCollection_AsciiString & a2) -> void { return self.GdumpSHASTA(a0, a1, a2); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopAbs_State, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_Builder::GdumpSHASTA, "None", py::arg("S"), py::arg("T"), py::arg("a"), py::arg("b"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TopOpeBRepBuild_ShapeSet & a2) -> void { return self.GdumpSHASTA(a0, a1, a2); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TopOpeBRepBuild_ShapeSet & a2, const TCollection_AsciiString & a3) -> void { return self.GdumpSHASTA(a0, a1, a2, a3); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", [](TopOpeBRepBuild_Builder &self, const Standard_Integer a0, const TopAbs_State a1, const TopOpeBRepBuild_ShapeSet & a2, const TCollection_AsciiString & a3, const TCollection_AsciiString & a4) -> void { return self.GdumpSHASTA(a0, a1, a2, a3, a4); });
cls_TopOpeBRepBuild_Builder.def("GdumpSHASTA", (void (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const TopAbs_State, const TopOpeBRepBuild_ShapeSet &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_Builder::GdumpSHASTA, "None", py::arg("iS"), py::arg("T"), py::arg("SS"), py::arg("a"), py::arg("b"), py::arg("c"));
cls_TopOpeBRepBuild_Builder.def("GdumpEDG", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0) -> void { return self.GdumpEDG(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpEDG", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpEDG, "None", py::arg("S"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpEDGVER", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.GdumpEDGVER(a0, a1); });
cls_TopOpeBRepBuild_Builder.def("GdumpEDGVER", (void (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpEDGVER, "None", py::arg("E"), py::arg("V"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpSAMDOM", [](TopOpeBRepBuild_Builder &self, const TopTools_ListOfShape & a0) -> void { return self.GdumpSAMDOM(a0); });
cls_TopOpeBRepBuild_Builder.def("GdumpSAMDOM", (void (TopOpeBRepBuild_Builder::*)(const TopTools_ListOfShape &, const Standard_Address) const) &TopOpeBRepBuild_Builder::GdumpSAMDOM, "None", py::arg("L"), py::arg("str"));
cls_TopOpeBRepBuild_Builder.def("GdumpEXP", (void (TopOpeBRepBuild_Builder::*)(const TopOpeBRepTool_ShapeExplorer &) const) &TopOpeBRepBuild_Builder::GdumpEXP, "None", py::arg("E"));
cls_TopOpeBRepBuild_Builder.def("GdumpSOBU", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_SolidBuilder &) const) &TopOpeBRepBuild_Builder::GdumpSOBU, "None", py::arg("SB"));
cls_TopOpeBRepBuild_Builder.def("GdumpFABU", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_FaceBuilder &) const) &TopOpeBRepBuild_Builder::GdumpFABU, "None", py::arg("FB"));
cls_TopOpeBRepBuild_Builder.def("GdumpEDBU", (void (TopOpeBRepBuild_Builder::*)(TopOpeBRepBuild_EdgeBuilder &) const) &TopOpeBRepBuild_Builder::GdumpEDBU, "None", py::arg("EB"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const Standard_Integer) const) &TopOpeBRepBuild_Builder::GtraceSPS, "None", py::arg("iS"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const Standard_Integer, const Standard_Integer) const) &TopOpeBRepBuild_Builder::GtraceSPS, "None", py::arg("iS"), py::arg("jS"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", (Standard_Boolean (TopOpeBRepBuild_Builder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_Builder::GtraceSPS, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def("GtraceSPS", [](TopOpeBRepBuild_Builder &self, const TopoDS_Shape & S, Standard_Integer & IS){ Standard_Boolean rv = self.GtraceSPS(S, IS); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IS); }, "None", py::arg("S"), py::arg("IS"));
cls_TopOpeBRepBuild_Builder.def("GdumpSHASETreset", (void (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::GdumpSHASETreset, "None");
cls_TopOpeBRepBuild_Builder.def("GdumpSHASETindex", (Standard_Integer (TopOpeBRepBuild_Builder::*)()) &TopOpeBRepBuild_Builder::GdumpSHASETindex, "None");
cls_TopOpeBRepBuild_Builder.def_static("PrintGeo_", (void (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::PrintGeo, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("PrintSur_", (void (*)(const TopoDS_Face &)) &TopOpeBRepBuild_Builder::PrintSur, "None", py::arg("F"));
cls_TopOpeBRepBuild_Builder.def_static("PrintCur_", (void (*)(const TopoDS_Edge &)) &TopOpeBRepBuild_Builder::PrintCur, "None", py::arg("E"));
cls_TopOpeBRepBuild_Builder.def_static("PrintPnt_", (void (*)(const TopoDS_Vertex &)) &TopOpeBRepBuild_Builder::PrintPnt, "None", py::arg("V"));
cls_TopOpeBRepBuild_Builder.def_static("PrintOri_", (void (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::PrintOri, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("StringState_", (TCollection_AsciiString (*)(const TopAbs_State)) &TopOpeBRepBuild_Builder::StringState, "None", py::arg("S"));
cls_TopOpeBRepBuild_Builder.def_static("GcheckNBOUNDS_", (Standard_Boolean (*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Builder::GcheckNBOUNDS, "None", py::arg("E"));

// CLASS: TOPOPEBREPBUILD_BUILDER1
py::class_<TopOpeBRepBuild_Builder1, TopOpeBRepBuild_Builder> cls_TopOpeBRepBuild_Builder1(mod, "TopOpeBRepBuild_Builder1", "extension of the class TopOpeBRepBuild_Builder dedicated to avoid bugs in 'Rebuilding Result' algorithm for the case of SOLID/SOLID Boolean Operations");

// Constructors
cls_TopOpeBRepBuild_Builder1.def(py::init<const TopOpeBRepDS_BuildTool &>(), py::arg("BT"));

// Methods
// cls_TopOpeBRepBuild_Builder1.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder1::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Builder1::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Builder1::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Builder1::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Builder1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Builder1.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Builder1::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Builder1.def("Clear", (void (TopOpeBRepBuild_Builder1::*)()) &TopOpeBRepBuild_Builder1::Clear, "Removes all splits and merges already performed. Does NOT clear the handled DS (except ShapeWithStatesMaps).");
cls_TopOpeBRepBuild_Builder1.def("Perform", (void (TopOpeBRepBuild_Builder1::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_Builder1::Perform, "None", py::arg("HDS"));
cls_TopOpeBRepBuild_Builder1.def("Perform", (void (TopOpeBRepBuild_Builder1::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Builder1::Perform, "None", py::arg("HDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_Builder1.def("MergeKPart", (void (TopOpeBRepBuild_Builder1::*)()) &TopOpeBRepBuild_Builder1::MergeKPart, "None");
cls_TopOpeBRepBuild_Builder1.def("MergeKPart", (void (TopOpeBRepBuild_Builder1::*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_Builder1::MergeKPart, "None", py::arg("TB1"), py::arg("TB2"));
cls_TopOpeBRepBuild_Builder1.def("GFillSolidSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillSolidSFS, "None", py::arg("SO1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GFillShellSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillShellSFS, "None", py::arg("SH1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GWESMakeFaces", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, TopOpeBRepBuild_WireEdgeSet &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder1::GWESMakeFaces, "None", py::arg("FF"), py::arg("WES"), py::arg("LOF"));
// cls_TopOpeBRepBuild_Builder1.def("GFillSplitsPVS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_PaveSet &)) &TopOpeBRepBuild_Builder1::GFillSplitsPVS, "None", py::arg("anEdge"), py::arg("G1"), py::arg("PVS"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceNotSameDomSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillFaceNotSameDomSFS, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceNotSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillFaceNotSameDomWES, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillWireNotSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillWireNotSameDomWES, "None", py::arg("W1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillEdgeNotSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillEdgeNotSameDomWES, "None", py::arg("E1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceSameDomSFS", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_ShellFaceSet &)) &TopOpeBRepBuild_Builder1::GFillFaceSameDomSFS, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("SFS"));
cls_TopOpeBRepBuild_Builder1.def("GFillFaceSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillFaceSameDomWES, "None", py::arg("F1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillWireSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillWireSameDomWES, "None", py::arg("W1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("GFillEdgeSameDomWES", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::GFillEdgeSameDomWES, "None", py::arg("E1"), py::arg("LSO2"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("PerformONParts", (void (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopTools_IndexedMapOfShape &, const TopOpeBRepBuild_GTopo &, TopOpeBRepBuild_WireEdgeSet &)) &TopOpeBRepBuild_Builder1::PerformONParts, "None", py::arg("F"), py::arg("SDfaces"), py::arg("G"), py::arg("WES"));
cls_TopOpeBRepBuild_Builder1.def("PerformPieceIn2D", [](TopOpeBRepBuild_Builder1 &self, const TopoDS_Edge & aPieceToPerform, const TopoDS_Edge & aOriginalEdge, const TopoDS_Face & edgeFace, const TopoDS_Face & toFace, const TopOpeBRepBuild_GTopo & G, Standard_Boolean & keep){ self.PerformPieceIn2D(aPieceToPerform, aOriginalEdge, edgeFace, toFace, G, keep); return keep; }, "None", py::arg("aPieceToPerform"), py::arg("aOriginalEdge"), py::arg("edgeFace"), py::arg("toFace"), py::arg("G"), py::arg("keep"));
cls_TopOpeBRepBuild_Builder1.def("PerformPieceOn2D", (Standard_Integer (TopOpeBRepBuild_Builder1::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder1::PerformPieceOn2D, "None", py::arg("aPieceObj"), py::arg("aFaceObj"), py::arg("aEdgeObj"), py::arg("aListOfPieces"), py::arg("aListOfFaces"), py::arg("aListOfPiecesOut2d"));
cls_TopOpeBRepBuild_Builder1.def("TwoPiecesON", (Standard_Integer (TopOpeBRepBuild_Builder1::*)(const TopTools_SequenceOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Builder1::TwoPiecesON, "None", py::arg("aSeq"), py::arg("aListOfPieces"), py::arg("aListOfFaces"), py::arg("aListOfPiecesOut2d"));
cls_TopOpeBRepBuild_Builder1.def("CorrectResult2d", (Standard_Integer (TopOpeBRepBuild_Builder1::*)(TopoDS_Shape &)) &TopOpeBRepBuild_Builder1::CorrectResult2d, "None", py::arg("aResult"));

// TYPEDEF: TOPOPEBREPBUILD_PBUILDER

// TYPEDEF: TOPOPEBREPBUILD_PGTOPO

// TYPEDEF: TOPOPEBREPBUILD_PWIREEDGESET

// CLASS: TOPOPEBREPBUILD_BUILDERON
py::class_<TopOpeBRepBuild_BuilderON> cls_TopOpeBRepBuild_BuilderON(mod, "TopOpeBRepBuild_BuilderON", "None");

// Constructors
cls_TopOpeBRepBuild_BuilderON.def(py::init<>());
cls_TopOpeBRepBuild_BuilderON.def(py::init<const TopOpeBRepBuild_PBuilder &, const TopoDS_Shape &, const TopOpeBRepBuild_PGTopo &, const TopOpeBRepTool_Plos &, const TopOpeBRepBuild_PWireEdgeSet &>(), py::arg("PB"), py::arg("F"), py::arg("PG"), py::arg("PLSclass"), py::arg("PWES"));

// Methods
// cls_TopOpeBRepBuild_BuilderON.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_BuilderON::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_BuilderON::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_BuilderON::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_BuilderON::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_BuilderON::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_BuilderON.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_BuilderON::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_BuilderON.def("Perform", (void (TopOpeBRepBuild_BuilderON::*)(const TopOpeBRepBuild_PBuilder &, const TopoDS_Shape &, const TopOpeBRepBuild_PGTopo &, const TopOpeBRepTool_Plos &, const TopOpeBRepBuild_PWireEdgeSet &)) &TopOpeBRepBuild_BuilderON::Perform, "None", py::arg("PB"), py::arg("F"), py::arg("PG"), py::arg("PLSclass"), py::arg("PWES"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONCheckI", (Standard_Boolean (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepBuild_BuilderON::GFillONCheckI, "None", py::arg("I"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONPartsWES1", (void (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepBuild_BuilderON::GFillONPartsWES1, "None", py::arg("I"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONPartsWES2", (void (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &TopOpeBRepBuild_BuilderON::GFillONPartsWES2, "None", py::arg("I"), py::arg("EspON"));
cls_TopOpeBRepBuild_BuilderON.def("Perform2d", (void (TopOpeBRepBuild_BuilderON::*)(const TopOpeBRepBuild_PBuilder &, const TopoDS_Shape &, const TopOpeBRepBuild_PGTopo &, const TopOpeBRepTool_Plos &, const TopOpeBRepBuild_PWireEdgeSet &)) &TopOpeBRepBuild_BuilderON::Perform2d, "None", py::arg("PB"), py::arg("F"), py::arg("PG"), py::arg("PLSclass"), py::arg("PWES"));
cls_TopOpeBRepBuild_BuilderON.def("GFillONParts2dWES2", (void (TopOpeBRepBuild_BuilderON::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &)) &TopOpeBRepBuild_BuilderON::GFillONParts2dWES2, "None", py::arg("I"), py::arg("EspON"));

// CLASS: TOPOPEBREPBUILD_LOOPCLASSIFIER
py::class_<TopOpeBRepBuild_LoopClassifier> cls_TopOpeBRepBuild_LoopClassifier(mod, "TopOpeBRepBuild_LoopClassifier", "classify loops in order to build Areas");

// Methods
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_LoopClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_LoopClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_LoopClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_LoopClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_LoopClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_LoopClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_LoopClassifier::Compare, "Returns the state of loop <L1> compared with loop <L2>.", py::arg("L1"), py::arg("L2"));

// CLASS: TOPOPEBREPBUILD_COMPOSITECLASSIFIER
py::class_<TopOpeBRepBuild_CompositeClassifier, TopOpeBRepBuild_LoopClassifier> cls_TopOpeBRepBuild_CompositeClassifier(mod, "TopOpeBRepBuild_CompositeClassifier", "classify composite Loops, i.e, loops that can be either a Shape, or a block of Elements.");

// Methods
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_CompositeClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_CompositeClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_CompositeClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_CompositeClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_CompositeClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_CompositeClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_CompositeClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_CompositeClassifier::Compare, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_CompositeClassifier.def("CompareShapes", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::CompareShapes, "classify shape <B1> with shape <B2>", py::arg("B1"), py::arg("B2"));
cls_TopOpeBRepBuild_CompositeClassifier.def("CompareElementToShape", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::CompareElementToShape, "classify element <E> with shape <B>", py::arg("E"), py::arg("B"));
cls_TopOpeBRepBuild_CompositeClassifier.def("ResetShape", (void (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::ResetShape, "prepare classification involving shape <B> calls ResetElement on first element of <B>", py::arg("B"));
cls_TopOpeBRepBuild_CompositeClassifier.def("ResetElement", (void (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::ResetElement, "prepare classification involving element <E>.", py::arg("E"));
cls_TopOpeBRepBuild_CompositeClassifier.def("CompareElement", (Standard_Boolean (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::CompareElement, "Add element <E> in the set of elements used in classification. Returns FALSE if the element <E> has been already added to the set of elements, otherwise returns TRUE.", py::arg("E"));
cls_TopOpeBRepBuild_CompositeClassifier.def("State", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)()) &TopOpeBRepBuild_CompositeClassifier::State, "Returns state of classification of 2D point, defined by ResetElement, with the current set of elements, defined by Compare.");

// CLASS: TOPOPEBREPBUILD_CORRECTFACE2D
py::class_<TopOpeBRepBuild_CorrectFace2d> cls_TopOpeBRepBuild_CorrectFace2d(mod, "TopOpeBRepBuild_CorrectFace2d", "None");

// Constructors
cls_TopOpeBRepBuild_CorrectFace2d.def(py::init<>());
cls_TopOpeBRepBuild_CorrectFace2d.def(py::init<const TopoDS_Face &, const TopTools_IndexedMapOfOrientedShape &, TopTools_IndexedDataMapOfShapeShape &>(), py::arg("aFace"), py::arg("anAvoidMap"), py::arg("aMap"));

// Methods
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_CorrectFace2d::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_CorrectFace2d::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_CorrectFace2d::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_CorrectFace2d::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_CorrectFace2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_CorrectFace2d::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_CorrectFace2d.def("Face", (const TopoDS_Face & (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::Face, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("Perform", (void (TopOpeBRepBuild_CorrectFace2d::*)()) &TopOpeBRepBuild_CorrectFace2d::Perform, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("IsDone", (Standard_Boolean (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::IsDone, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("ErrorStatus", (Standard_Integer (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::ErrorStatus, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("CorrectedFace", (const TopoDS_Face & (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::CorrectedFace, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("SetMapOfTrans2dInfo", (void (TopOpeBRepBuild_CorrectFace2d::*)(TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_CorrectFace2d::SetMapOfTrans2dInfo, "None", py::arg("aMap"));
cls_TopOpeBRepBuild_CorrectFace2d.def("MapOfTrans2dInfo", (TopTools_IndexedDataMapOfShapeShape & (TopOpeBRepBuild_CorrectFace2d::*)()) &TopOpeBRepBuild_CorrectFace2d::MapOfTrans2dInfo, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def_static("GetP2dFL_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, gp_Pnt2d &, gp_Pnt2d &)) &TopOpeBRepBuild_CorrectFace2d::GetP2dFL, "None", py::arg("aFace"), py::arg("anEdge"), py::arg("P2dF"), py::arg("P2dL"));
cls_TopOpeBRepBuild_CorrectFace2d.def_static("CheckList_", (void (*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepBuild_CorrectFace2d::CheckList, "None", py::arg("aFace"), py::arg("aHeadList"));

// CLASS: TOPOPEBREPBUILD_SHAPELISTOFSHAPE
py::class_<TopOpeBRepBuild_ShapeListOfShape> cls_TopOpeBRepBuild_ShapeListOfShape(mod, "TopOpeBRepBuild_ShapeListOfShape", "represent shape + a list of shape");

// Constructors
cls_TopOpeBRepBuild_ShapeListOfShape.def(py::init<>());
cls_TopOpeBRepBuild_ShapeListOfShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopOpeBRepBuild_ShapeListOfShape.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &>(), py::arg("S"), py::arg("L"));

// Methods
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeListOfShape::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShapeListOfShape::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeListOfShape::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShapeListOfShape::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShapeListOfShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeListOfShape.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShapeListOfShape::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShapeListOfShape.def("List", (const TopTools_ListOfShape & (TopOpeBRepBuild_ShapeListOfShape::*)() const) &TopOpeBRepBuild_ShapeListOfShape::List, "None");
cls_TopOpeBRepBuild_ShapeListOfShape.def("ChangeList", (TopTools_ListOfShape & (TopOpeBRepBuild_ShapeListOfShape::*)()) &TopOpeBRepBuild_ShapeListOfShape::ChangeList, "None");
cls_TopOpeBRepBuild_ShapeListOfShape.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeListOfShape::*)() const) &TopOpeBRepBuild_ShapeListOfShape::Shape, "None");
cls_TopOpeBRepBuild_ShapeListOfShape.def("ChangeShape", (TopoDS_Shape & (TopOpeBRepBuild_ShapeListOfShape::*)()) &TopOpeBRepBuild_ShapeListOfShape::ChangeShape, "None");

// TYPEDEF: TOPOPEBREPBUILD_LISTOFSHAPELISTOFSHAPE
bind_NCollection_List<TopOpeBRepBuild_ShapeListOfShape>(mod, "TopOpeBRepBuild_ListOfShapeListOfShape", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_LISTITERATOROFLISTOFSHAPELISTOFSHAPE
bind_NCollection_TListIterator<TopOpeBRepBuild_ShapeListOfShape>(mod, "TopOpeBRepBuild_ListIteratorOfListOfShapeListOfShape", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_DATAMAPOFSHAPELISTOFSHAPELISTOFSHAPE
bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<TopOpeBRepBuild_ShapeListOfShape>, TopTools_ShapeMapHasher>(mod, "TopOpeBRepBuild_DataMapOfShapeListOfShapeListOfShape", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_DATAMAPITERATOROFDATAMAPOFSHAPELISTOFSHAPELISTOFSHAPE

// CLASS: TOPOPEBREPBUILD_SHAPESET
py::class_<TopOpeBRepBuild_ShapeSet> cls_TopOpeBRepBuild_ShapeSet(mod, "TopOpeBRepBuild_ShapeSet", "Auxiliary class providing an exploration of a set of shapes to build faces or solids. To build faces : shapes are wires, elements are edges. To build solids : shapes are shells, elements are faces. The ShapeSet stores a list of shapes, a list of elements to start reconstructions, and a map to search neighbours. The map stores the connection between elements through subshapes of type <SubShapeType> given in constructor. <SubShapeType> is : - TopAbs_VERTEX to connect edges - TopAbs_EDGE to connect faces");

// Constructors
cls_TopOpeBRepBuild_ShapeSet.def(py::init<const TopAbs_ShapeEnum>(), py::arg("SubShapeType"));
cls_TopOpeBRepBuild_ShapeSet.def(py::init<const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("SubShapeType"), py::arg("checkshape"));

// Methods
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShapeSet.def("AddShape", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::AddShape, "Adds <S> to the list of shapes. (wires or shells).", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("AddStartElement", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::AddStartElement, "(S is a face or edge) Add S to the list of starting shapes used for reconstructions. apply AddElement(S).", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("AddElement", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::AddElement, "for each subshape SE of S of type mySubShapeType - Add subshapes of S to the map of subshapes (mySubShapeMap) - Add S to the list of shape incident to subshapes of S.", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("StartElements", (const TopTools_ListOfShape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::StartElements, "return a reference on myStartShapes");
cls_TopOpeBRepBuild_ShapeSet.def("InitShapes", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::InitShapes, "None");
cls_TopOpeBRepBuild_ShapeSet.def("MoreShapes", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::MoreShapes, "None");
cls_TopOpeBRepBuild_ShapeSet.def("NextShape", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::NextShape, "None");
cls_TopOpeBRepBuild_ShapeSet.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::Shape, "None");
cls_TopOpeBRepBuild_ShapeSet.def("InitStartElements", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::InitStartElements, "None");
cls_TopOpeBRepBuild_ShapeSet.def("MoreStartElements", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::MoreStartElements, "None");
cls_TopOpeBRepBuild_ShapeSet.def("NextStartElement", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::NextStartElement, "None");
cls_TopOpeBRepBuild_ShapeSet.def("StartElement", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::StartElement, "None");
cls_TopOpeBRepBuild_ShapeSet.def("InitNeighbours", (void (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::InitNeighbours, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShapeSet.def("MoreNeighbours", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::MoreNeighbours, "None");
cls_TopOpeBRepBuild_ShapeSet.def("NextNeighbour", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::NextNeighbour, "None");
cls_TopOpeBRepBuild_ShapeSet.def("Neighbour", (const TopoDS_Shape & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::Neighbour, "None");
cls_TopOpeBRepBuild_ShapeSet.def("ChangeStartShapes", (TopTools_ListOfShape & (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::ChangeStartShapes, "None");
cls_TopOpeBRepBuild_ShapeSet.def("FindNeighbours", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::FindNeighbours, "Build the list of neighbour shapes of myCurrentShape (neighbour shapes and myCurrentShapes are of type t) Initialize myIncidentShapesIter on neighbour shapes.");
cls_TopOpeBRepBuild_ShapeSet.def("MakeNeighboursList", (const TopTools_ListOfShape & (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::MakeNeighboursList, "None", py::arg("E"), py::arg("V"));
cls_TopOpeBRepBuild_ShapeSet.def("MaxNumberSubShape", (Standard_Integer (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShapeSet::MaxNumberSubShape, "None", py::arg("Shape"));
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", (void (TopOpeBRepBuild_ShapeSet::*)(const Standard_Boolean)) &TopOpeBRepBuild_ShapeSet::CheckShape, "None", py::arg("checkshape"));
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::CheckShape, "None");
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.CheckShape(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("CheckShape", (Standard_Boolean (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepBuild_ShapeSet::CheckShape, "None", py::arg("S"), py::arg("checkgeom"));
cls_TopOpeBRepBuild_ShapeSet.def("DumpName", (void (TopOpeBRepBuild_ShapeSet::*)(Standard_OStream &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::DumpName, "None", py::arg("OS"), py::arg("str"));
cls_TopOpeBRepBuild_ShapeSet.def("DumpCheck", (void (TopOpeBRepBuild_ShapeSet::*)(Standard_OStream &, const TCollection_AsciiString &, const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepBuild_ShapeSet::DumpCheck, "None", py::arg("OS"), py::arg("str"), py::arg("S"), py::arg("chk"));
cls_TopOpeBRepBuild_ShapeSet.def("DumpSS", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::DumpSS, "None");
cls_TopOpeBRepBuild_ShapeSet.def("DumpBB", (void (TopOpeBRepBuild_ShapeSet::*)()) &TopOpeBRepBuild_ShapeSet::DumpBB, "None");
cls_TopOpeBRepBuild_ShapeSet.def("DEBName", (void (TopOpeBRepBuild_ShapeSet::*)(const TCollection_AsciiString &)) &TopOpeBRepBuild_ShapeSet::DEBName, "None", py::arg("N"));
cls_TopOpeBRepBuild_ShapeSet.def("DEBName", (const TCollection_AsciiString & (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::DEBName, "None");
cls_TopOpeBRepBuild_ShapeSet.def("DEBNumber", (void (TopOpeBRepBuild_ShapeSet::*)(const Standard_Integer)) &TopOpeBRepBuild_ShapeSet::DEBNumber, "None", py::arg("I"));
cls_TopOpeBRepBuild_ShapeSet.def("DEBNumber", (Standard_Integer (TopOpeBRepBuild_ShapeSet::*)() const) &TopOpeBRepBuild_ShapeSet::DEBNumber, "None");
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", [](TopOpeBRepBuild_ShapeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShapeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShapeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShapeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));

// CLASS: TOPOPEBREPBUILD_WIREEDGESET
py::class_<TopOpeBRepBuild_WireEdgeSet, TopOpeBRepBuild_ShapeSet> cls_TopOpeBRepBuild_WireEdgeSet(mod, "TopOpeBRepBuild_WireEdgeSet", "a bound is a wire, a boundelement is an edge. The ShapeSet stores : - a list of wire (bounds), - a list of edge (boundelements) to start reconstructions, - a map of vertex giving the list of edge incident to a vertex.");

// Constructors
cls_TopOpeBRepBuild_WireEdgeSet.def(py::init<const TopoDS_Shape &>(), py::arg("F"));
cls_TopOpeBRepBuild_WireEdgeSet.def(py::init<const TopoDS_Shape &, const Standard_Address>(), py::arg("F"), py::arg("Addr"));

// Methods
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_WireEdgeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_WireEdgeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_WireEdgeSet.def("Face", (const TopoDS_Face & (TopOpeBRepBuild_WireEdgeSet::*)() const) &TopOpeBRepBuild_WireEdgeSet::Face, "value of field myFace");
cls_TopOpeBRepBuild_WireEdgeSet.def("AddShape", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::AddShape, "None", py::arg("S"));
cls_TopOpeBRepBuild_WireEdgeSet.def("AddStartElement", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::AddStartElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_WireEdgeSet.def("AddElement", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::AddElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_WireEdgeSet.def("InitNeighbours", (void (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::InitNeighbours, "None", py::arg("E"));
cls_TopOpeBRepBuild_WireEdgeSet.def("FindNeighbours", (void (TopOpeBRepBuild_WireEdgeSet::*)()) &TopOpeBRepBuild_WireEdgeSet::FindNeighbours, "Build the list of neighbour edges of edge myCurrentShape Initialize iterator of neighbour edges to edge myCurrentShape");
cls_TopOpeBRepBuild_WireEdgeSet.def("MakeNeighboursList", (const TopTools_ListOfShape & (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeSet::MakeNeighboursList, "None", py::arg("E"), py::arg("V"));
cls_TopOpeBRepBuild_WireEdgeSet.def_static("IsUVISO_", [](const TopoDS_Edge & E, const TopoDS_Face & F, Standard_Boolean & uiso, Standard_Boolean & viso){ TopOpeBRepBuild_WireEdgeSet::IsUVISO(E, F, uiso, viso); return std::tuple<Standard_Boolean &, Standard_Boolean &>(uiso, viso); }, "None", py::arg("E"), py::arg("F"), py::arg("uiso"), py::arg("viso"));
cls_TopOpeBRepBuild_WireEdgeSet.def("DumpSS", (void (TopOpeBRepBuild_WireEdgeSet::*)()) &TopOpeBRepBuild_WireEdgeSet::DumpSS, "None");
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", [](TopOpeBRepBuild_WireEdgeSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_WireEdgeSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_WireEdgeSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_WireEdgeSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));

// CLASS: TOPOPEBREPBUILD_SHELLFACESET
py::class_<TopOpeBRepBuild_ShellFaceSet, TopOpeBRepBuild_ShapeSet> cls_TopOpeBRepBuild_ShellFaceSet(mod, "TopOpeBRepBuild_ShellFaceSet", "a bound is a shell, a boundelement is a face. The ShapeSet stores : - a list of shell (bounds), - a list of face (boundelements) to start reconstructions, - a map of edge giving the list of face incident to an edge.");

// Constructors
cls_TopOpeBRepBuild_ShellFaceSet.def(py::init<>());
cls_TopOpeBRepBuild_ShellFaceSet.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def(py::init<const TopoDS_Shape &, const Standard_Address>(), py::arg("S"), py::arg("Addr"));

// Methods
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShellFaceSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShellFaceSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShellFaceSet.def("Solid", (const TopoDS_Solid & (TopOpeBRepBuild_ShellFaceSet::*)() const) &TopOpeBRepBuild_ShellFaceSet::Solid, "None");
cls_TopOpeBRepBuild_ShellFaceSet.def("AddShape", (void (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceSet::AddShape, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def("AddStartElement", (void (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceSet::AddStartElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def("AddElement", (void (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceSet::AddElement, "None", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceSet.def("DumpSS", (void (TopOpeBRepBuild_ShellFaceSet::*)()) &TopOpeBRepBuild_ShellFaceSet::DumpSS, "None");
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SName(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SName(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SName", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SName, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopoDS_Shape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopoDS_Shape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SNameori(a0); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", [](TopOpeBRepBuild_ShellFaceSet &self, const TopTools_ListOfShape & a0, const TCollection_AsciiString & a1) -> TCollection_AsciiString { return self.SNameori(a0, a1); });
cls_TopOpeBRepBuild_ShellFaceSet.def("SNameori", (TCollection_AsciiString (TopOpeBRepBuild_ShellFaceSet::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRepBuild_ShellFaceSet::SNameori, "None", py::arg("S"), py::arg("sb"), py::arg("sa"));

// CLASS: TOPOPEBREPBUILD_GTOPO
py::class_<TopOpeBRepBuild_GTopo> cls_TopOpeBRepBuild_GTopo(mod, "TopOpeBRepBuild_GTopo", "None");

// Constructors
cls_TopOpeBRepBuild_GTopo.def(py::init<>());
cls_TopOpeBRepBuild_GTopo.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, const TopOpeBRepDS_Config, const TopOpeBRepDS_Config>(), py::arg("II"), py::arg(""), py::arg("IO"), py::arg("NI"), py::arg("NN"), py::arg("NO"), py::arg("OI"), py::arg("ON"), py::arg("OO"), py::arg("t1"), py::arg("t2"), py::arg("C1"), py::arg("C2"));

// Methods
// cls_TopOpeBRepBuild_GTopo.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_GTopo::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_GTopo::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_GTopo::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_GTopo::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_GTopo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTopo.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_GTopo::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_GTopo.def("Reset", (void (TopOpeBRepBuild_GTopo::*)()) &TopOpeBRepBuild_GTopo::Reset, "None");
cls_TopOpeBRepBuild_GTopo.def("Set", (void (TopOpeBRepBuild_GTopo::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::Set, "None", py::arg("II"), py::arg(""), py::arg("IO"), py::arg("NI"), py::arg("NN"), py::arg("NO"), py::arg("OI"), py::arg("ON"), py::arg("OO"));
cls_TopOpeBRepBuild_GTopo.def("Type", (void (TopOpeBRepBuild_GTopo::*)(TopAbs_ShapeEnum &, TopAbs_ShapeEnum &) const) &TopOpeBRepBuild_GTopo::Type, "None", py::arg("t1"), py::arg("t2"));
cls_TopOpeBRepBuild_GTopo.def("ChangeType", (void (TopOpeBRepBuild_GTopo::*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTopo::ChangeType, "None", py::arg("t1"), py::arg("t2"));
cls_TopOpeBRepBuild_GTopo.def("Config1", (TopOpeBRepDS_Config (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::Config1, "None");
cls_TopOpeBRepBuild_GTopo.def("Config2", (TopOpeBRepDS_Config (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::Config2, "None");
cls_TopOpeBRepBuild_GTopo.def("ChangeConfig", (void (TopOpeBRepBuild_GTopo::*)(const TopOpeBRepDS_Config, const TopOpeBRepDS_Config)) &TopOpeBRepBuild_GTopo::ChangeConfig, "None", py::arg("C1"), py::arg("C2"));
cls_TopOpeBRepBuild_GTopo.def("Value", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)(const TopAbs_State, const TopAbs_State) const) &TopOpeBRepBuild_GTopo::Value, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTopo.def("Value", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)(const Standard_Integer, const Standard_Integer) const) &TopOpeBRepBuild_GTopo::Value, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepBuild_GTopo.def("Value", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)(const Standard_Integer) const) &TopOpeBRepBuild_GTopo::Value, "None", py::arg("II"));
cls_TopOpeBRepBuild_GTopo.def("ChangeValue", (void (TopOpeBRepBuild_GTopo::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::ChangeValue, "None", py::arg("i1"), py::arg("i2"), py::arg("b"));
cls_TopOpeBRepBuild_GTopo.def("ChangeValue", (void (TopOpeBRepBuild_GTopo::*)(const TopAbs_State, const TopAbs_State, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::ChangeValue, "None", py::arg("s1"), py::arg("s2"), py::arg("b"));
cls_TopOpeBRepBuild_GTopo.def("GIndex", (Standard_Integer (TopOpeBRepBuild_GTopo::*)(const TopAbs_State) const) &TopOpeBRepBuild_GTopo::GIndex, "None", py::arg("S"));
cls_TopOpeBRepBuild_GTopo.def("GState", (TopAbs_State (TopOpeBRepBuild_GTopo::*)(const Standard_Integer) const) &TopOpeBRepBuild_GTopo::GState, "None", py::arg("I"));
cls_TopOpeBRepBuild_GTopo.def("Index", [](TopOpeBRepBuild_GTopo &self, const Standard_Integer II, Standard_Integer & i1, Standard_Integer & i2){ self.Index(II, i1, i2); return std::tuple<Standard_Integer &, Standard_Integer &>(i1, i2); }, "None", py::arg("II"), py::arg("i1"), py::arg("i2"));
cls_TopOpeBRepBuild_GTopo.def("DumpVal", (void (TopOpeBRepBuild_GTopo::*)(Standard_OStream &, const TopAbs_State, const TopAbs_State) const) &TopOpeBRepBuild_GTopo::DumpVal, "None", py::arg("OS"), py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTopo.def("DumpType", (void (TopOpeBRepBuild_GTopo::*)(Standard_OStream &) const) &TopOpeBRepBuild_GTopo::DumpType, "None", py::arg("OS"));
cls_TopOpeBRepBuild_GTopo.def_static("DumpSSB_", (void (*)(Standard_OStream &, const TopAbs_State, const TopAbs_State, const Standard_Boolean)) &TopOpeBRepBuild_GTopo::DumpSSB, "None", py::arg("OS"), py::arg("s1"), py::arg("s2"), py::arg("b"));
cls_TopOpeBRepBuild_GTopo.def("Dump", [](TopOpeBRepBuild_GTopo &self, Standard_OStream & a0) -> void { return self.Dump(a0); });
cls_TopOpeBRepBuild_GTopo.def("Dump", (void (TopOpeBRepBuild_GTopo::*)(Standard_OStream &, const Standard_Address) const) &TopOpeBRepBuild_GTopo::Dump, "None", py::arg("OS"), py::arg("s"));
cls_TopOpeBRepBuild_GTopo.def("StatesON", (void (TopOpeBRepBuild_GTopo::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepBuild_GTopo::StatesON, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTopo.def("IsToReverse1", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::IsToReverse1, "None");
cls_TopOpeBRepBuild_GTopo.def("IsToReverse2", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::IsToReverse2, "None");
cls_TopOpeBRepBuild_GTopo.def("SetReverse", (void (TopOpeBRepBuild_GTopo::*)(const Standard_Boolean)) &TopOpeBRepBuild_GTopo::SetReverse, "None", py::arg("rev"));
cls_TopOpeBRepBuild_GTopo.def("Reverse", (Standard_Boolean (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::Reverse, "None");
cls_TopOpeBRepBuild_GTopo.def("CopyPermuted", (TopOpeBRepBuild_GTopo (TopOpeBRepBuild_GTopo::*)() const) &TopOpeBRepBuild_GTopo::CopyPermuted, "None");

// CLASS: TOPOPEBREPBUILD_PAVECLASSIFIER
py::class_<TopOpeBRepBuild_PaveClassifier, TopOpeBRepBuild_LoopClassifier> cls_TopOpeBRepBuild_PaveClassifier(mod, "TopOpeBRepBuild_PaveClassifier", "This class compares vertices on an edge.");

// Constructors
cls_TopOpeBRepBuild_PaveClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("E"));

// Methods
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_PaveClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_PaveClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_PaveClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_PaveClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_PaveClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_PaveClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_PaveClassifier::Compare, "Returns state of vertex <L1> compared with <L2>.", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_PaveClassifier.def("SetFirstParameter", (void (TopOpeBRepBuild_PaveClassifier::*)(const Standard_Real)) &TopOpeBRepBuild_PaveClassifier::SetFirstParameter, "None", py::arg("P"));
cls_TopOpeBRepBuild_PaveClassifier.def("ClosedVertices", (void (TopOpeBRepBuild_PaveClassifier::*)(const Standard_Boolean)) &TopOpeBRepBuild_PaveClassifier::ClosedVertices, "None", py::arg("B"));
cls_TopOpeBRepBuild_PaveClassifier.def_static("AdjustCase_", [](const Standard_Real p1, const TopAbs_Orientation o, const Standard_Real first, const Standard_Real period, const Standard_Real tol, Standard_Integer & cas){ Standard_Real rv = TopOpeBRepBuild_PaveClassifier::AdjustCase(p1, o, first, period, tol, cas); return std::tuple<Standard_Real, Standard_Integer &>(rv, cas); }, "None", py::arg("p1"), py::arg("o"), py::arg("first"), py::arg("period"), py::arg("tol"), py::arg("cas"));

// CLASS: TOPOPEBREPBUILD_PAVE
py::class_<TopOpeBRepBuild_Pave, opencascade::handle<TopOpeBRepBuild_Pave>, TopOpeBRepBuild_Loop> cls_TopOpeBRepBuild_Pave(mod, "TopOpeBRepBuild_Pave", "None");

// Constructors
cls_TopOpeBRepBuild_Pave.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("V"), py::arg("P"), py::arg("bound"));

// Methods
cls_TopOpeBRepBuild_Pave.def("HasSameDomain", (void (TopOpeBRepBuild_Pave::*)(const Standard_Boolean)) &TopOpeBRepBuild_Pave::HasSameDomain, "None", py::arg("b"));
cls_TopOpeBRepBuild_Pave.def("SameDomain", (void (TopOpeBRepBuild_Pave::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_Pave::SameDomain, "None", py::arg("VSD"));
cls_TopOpeBRepBuild_Pave.def("HasSameDomain", (Standard_Boolean (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::HasSameDomain, "None");
cls_TopOpeBRepBuild_Pave.def("SameDomain", (const TopoDS_Shape & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::SameDomain, "None");
cls_TopOpeBRepBuild_Pave.def("Vertex", (const TopoDS_Shape & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Vertex, "None");
cls_TopOpeBRepBuild_Pave.def("ChangeVertex", (TopoDS_Shape & (TopOpeBRepBuild_Pave::*)()) &TopOpeBRepBuild_Pave::ChangeVertex, "None");
cls_TopOpeBRepBuild_Pave.def("Parameter", (Standard_Real (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Parameter, "None");
cls_TopOpeBRepBuild_Pave.def("Parameter", (void (TopOpeBRepBuild_Pave::*)(const Standard_Real)) &TopOpeBRepBuild_Pave::Parameter, "None", py::arg("Par"));
cls_TopOpeBRepBuild_Pave.def("InterferenceType", (TopOpeBRepDS_Kind & (TopOpeBRepBuild_Pave::*)()) &TopOpeBRepBuild_Pave::InterferenceType, "None");
cls_TopOpeBRepBuild_Pave.def("IsShape", (Standard_Boolean (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::IsShape, "None");
cls_TopOpeBRepBuild_Pave.def("Shape", (const TopoDS_Shape & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Shape, "None");
cls_TopOpeBRepBuild_Pave.def("Dump", (void (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::Dump, "None");
cls_TopOpeBRepBuild_Pave.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepBuild_Pave::get_type_name, "None");
cls_TopOpeBRepBuild_Pave.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepBuild_Pave::get_type_descriptor, "None");
cls_TopOpeBRepBuild_Pave.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepBuild_Pave::*)() const) &TopOpeBRepBuild_Pave::DynamicType, "None");

// TYPEDEF: TOPOPEBREPBUILD_LISTOFPAVE
bind_NCollection_List<opencascade::handle<TopOpeBRepBuild_Pave> >(mod, "TopOpeBRepBuild_ListOfPave", py::module_local(false));

// TYPEDEF: TOPOPEBREPBUILD_LISTITERATOROFLISTOFPAVE
bind_NCollection_TListIterator<opencascade::handle<TopOpeBRepBuild_Pave> >(mod, "TopOpeBRepBuild_ListIteratorOfListOfPave", py::module_local(false));

// CLASS: TOPOPEBREPBUILD_LOOPSET
py::class_<TopOpeBRepBuild_LoopSet> cls_TopOpeBRepBuild_LoopSet(mod, "TopOpeBRepBuild_LoopSet", "None");

// Constructors
cls_TopOpeBRepBuild_LoopSet.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_LoopSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_LoopSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_LoopSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_LoopSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_LoopSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_LoopSet.def("ChangeListOfLoop", (TopOpeBRepBuild_ListOfLoop & (TopOpeBRepBuild_LoopSet::*)()) &TopOpeBRepBuild_LoopSet::ChangeListOfLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("InitLoop", (void (TopOpeBRepBuild_LoopSet::*)()) &TopOpeBRepBuild_LoopSet::InitLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("MoreLoop", (Standard_Boolean (TopOpeBRepBuild_LoopSet::*)() const) &TopOpeBRepBuild_LoopSet::MoreLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("NextLoop", (void (TopOpeBRepBuild_LoopSet::*)()) &TopOpeBRepBuild_LoopSet::NextLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("Loop", (opencascade::handle<TopOpeBRepBuild_Loop> (TopOpeBRepBuild_LoopSet::*)() const) &TopOpeBRepBuild_LoopSet::Loop, "None");

// CLASS: TOPOPEBREPBUILD_PAVESET
py::class_<TopOpeBRepBuild_PaveSet, TopOpeBRepBuild_LoopSet> cls_TopOpeBRepBuild_PaveSet(mod, "TopOpeBRepBuild_PaveSet", "class providing an exploration of a set of vertices to build edges. It is similar to LoopSet from TopOpeBRepBuild where Loop is Pave.");

// Constructors
cls_TopOpeBRepBuild_PaveSet.def(py::init<const TopoDS_Shape &>(), py::arg("E"));

// Methods
// cls_TopOpeBRepBuild_PaveSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_PaveSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_PaveSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_PaveSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_PaveSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_PaveSet.def("RemovePV", (void (TopOpeBRepBuild_PaveSet::*)(const Standard_Boolean)) &TopOpeBRepBuild_PaveSet::RemovePV, "None", py::arg("B"));
cls_TopOpeBRepBuild_PaveSet.def("Append", (void (TopOpeBRepBuild_PaveSet::*)(const opencascade::handle<TopOpeBRepBuild_Pave> &)) &TopOpeBRepBuild_PaveSet::Append, "Add <PV> in the Pave set.", py::arg("PV"));
cls_TopOpeBRepBuild_PaveSet.def("InitLoop", (void (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::InitLoop, "None");
cls_TopOpeBRepBuild_PaveSet.def("MoreLoop", (Standard_Boolean (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::MoreLoop, "None");
cls_TopOpeBRepBuild_PaveSet.def("NextLoop", (void (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::NextLoop, "None");
cls_TopOpeBRepBuild_PaveSet.def("Loop", (opencascade::handle<TopOpeBRepBuild_Loop> (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::Loop, "None");
cls_TopOpeBRepBuild_PaveSet.def("Edge", (const TopoDS_Edge & (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::Edge, "None");
cls_TopOpeBRepBuild_PaveSet.def("HasEqualParameters", (Standard_Boolean (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::HasEqualParameters, "None");
cls_TopOpeBRepBuild_PaveSet.def("EqualParameters", (Standard_Real (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::EqualParameters, "None");
cls_TopOpeBRepBuild_PaveSet.def("ClosedVertices", (Standard_Boolean (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::ClosedVertices, "None");
cls_TopOpeBRepBuild_PaveSet.def_static("SortPave_", (void (*)(const TopOpeBRepBuild_ListOfPave &, TopOpeBRepBuild_ListOfPave &)) &TopOpeBRepBuild_PaveSet::SortPave, "None", py::arg("Lin"), py::arg("Lout"));

// CLASS: TOPOPEBREPBUILD_SOLIDAREABUILDER
py::class_<TopOpeBRepBuild_SolidAreaBuilder, TopOpeBRepBuild_Area3dBuilder> cls_TopOpeBRepBuild_SolidAreaBuilder(mod, "TopOpeBRepBuild_SolidAreaBuilder", "The SolidAreaBuilder algorithm is used to construct Solids from a LoopSet, where the Loop is the composite topological object of the boundary, here wire or block of edges. The LoopSet gives an iteration on Loops. For each Loop it indicates if it is on the boundary (wire) or if it results from an interference (block of edges). The result of the SolidAreaBuilder is an iteration on areas. An area is described by a set of Loops.");

// Constructors
cls_TopOpeBRepBuild_SolidAreaBuilder.def(py::init<>());
cls_TopOpeBRepBuild_SolidAreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_SolidAreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_SolidAreaBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_SolidAreaBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_SolidAreaBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_SolidAreaBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidAreaBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_SolidAreaBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_SolidAreaBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_SolidAreaBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidAreaBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_SolidAreaBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidAreaBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_SolidAreaBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_SolidAreaBuilder.def("InitSolidAreaBuilder", [](TopOpeBRepBuild_SolidAreaBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitSolidAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_SolidAreaBuilder.def("InitSolidAreaBuilder", (void (TopOpeBRepBuild_SolidAreaBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_SolidAreaBuilder::InitSolidAreaBuilder, "None", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// CLASS: TOPOPEBREPBUILD_SOLIDBUILDER
py::class_<TopOpeBRepBuild_SolidBuilder> cls_TopOpeBRepBuild_SolidBuilder(mod, "TopOpeBRepBuild_SolidBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_SolidBuilder.def(py::init<>());
cls_TopOpeBRepBuild_SolidBuilder.def(py::init<TopOpeBRepBuild_ShellFaceSet &>(), py::arg("FS"));
cls_TopOpeBRepBuild_SolidBuilder.def(py::init<TopOpeBRepBuild_ShellFaceSet &, const Standard_Boolean>(), py::arg("FS"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_SolidBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_SolidBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_SolidBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_SolidBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_SolidBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_SolidBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_SolidBuilder.def("InitSolidBuilder", (void (TopOpeBRepBuild_SolidBuilder::*)(TopOpeBRepBuild_ShellFaceSet &, const Standard_Boolean)) &TopOpeBRepBuild_SolidBuilder::InitSolidBuilder, "None", py::arg("FS"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_SolidBuilder.def("InitSolid", (Standard_Integer (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::InitSolid, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("MoreSolid", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::MoreSolid, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("NextSolid", (void (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::NextSolid, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("InitShell", (Standard_Integer (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::InitShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("MoreShell", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::MoreShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("NextShell", (void (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::NextShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("IsOldShell", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::IsOldShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("OldShell", (const TopoDS_Shape & (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::OldShell, "Returns current shell This shell may be : * an old shell OldShell(), which has not been reconstructed; * a new shell made of faces described by ...NewFace() methods.");
cls_TopOpeBRepBuild_SolidBuilder.def("InitFace", (Standard_Integer (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::InitFace, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("MoreFace", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::MoreFace, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("NextFace", (void (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::NextFace, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("Face", (const TopoDS_Shape & (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::Face, "Returns current new face of current new shell.");

// CLASS: TOPOPEBREPBUILD_FACEAREABUILDER
py::class_<TopOpeBRepBuild_FaceAreaBuilder, TopOpeBRepBuild_Area2dBuilder> cls_TopOpeBRepBuild_FaceAreaBuilder(mod, "TopOpeBRepBuild_FaceAreaBuilder", "The FaceAreaBuilder algorithm is used to construct Faces from a LoopSet, where the Loop is the composite topological object of the boundary, here wire or block of edges. The LoopSet gives an iteration on Loops. For each Loop it indicates if it is on the boundary (wire) or if it results from an interference (block of edges). The result of the FaceAreaBuilder is an iteration on areas. An area is described by a set of Loops.");

// Constructors
cls_TopOpeBRepBuild_FaceAreaBuilder.def(py::init<>());
cls_TopOpeBRepBuild_FaceAreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_FaceAreaBuilder.def(py::init<TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_FaceAreaBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_FaceAreaBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FaceAreaBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_FaceAreaBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceAreaBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_FaceAreaBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FaceAreaBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_FaceAreaBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceAreaBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_FaceAreaBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceAreaBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_FaceAreaBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_FaceAreaBuilder.def("InitFaceAreaBuilder", [](TopOpeBRepBuild_FaceAreaBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitFaceAreaBuilder(a0, a1); });
cls_TopOpeBRepBuild_FaceAreaBuilder.def("InitFaceAreaBuilder", (void (TopOpeBRepBuild_FaceAreaBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_FaceAreaBuilder::InitFaceAreaBuilder, "None", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// CLASS: TOPOPEBREPBUILD_FACEBUILDER
py::class_<TopOpeBRepBuild_FaceBuilder> cls_TopOpeBRepBuild_FaceBuilder(mod, "TopOpeBRepBuild_FaceBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_FaceBuilder.def(py::init<>());
cls_TopOpeBRepBuild_FaceBuilder.def(py::init<TopOpeBRepBuild_WireEdgeSet &, const TopoDS_Shape &>(), py::arg("ES"), py::arg("F"));
cls_TopOpeBRepBuild_FaceBuilder.def(py::init<TopOpeBRepBuild_WireEdgeSet &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("ES"), py::arg("F"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_FaceBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_FaceBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_FaceBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_FaceBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_FaceBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_FaceBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_FaceBuilder.def("InitFaceBuilder", (void (TopOpeBRepBuild_FaceBuilder::*)(TopOpeBRepBuild_WireEdgeSet &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepBuild_FaceBuilder::InitFaceBuilder, "None", py::arg("ES"), py::arg("F"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_FaceBuilder.def("DetectUnclosedWire", (void (TopOpeBRepBuild_FaceBuilder::*)(TopTools_IndexedDataMapOfShapeShape &, TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_FaceBuilder::DetectUnclosedWire, "Removes are non 3d-closed wires. Fills up maps <mapVVsameG> and <mapVon1Edge>, in order to correct 3d-closed but unclosed (topologic connexity) wires. modifies myBlockBuilder", py::arg("mapVVsameG"), py::arg("mapVon1Edge"));
cls_TopOpeBRepBuild_FaceBuilder.def("CorrectGclosedWire", (void (TopOpeBRepBuild_FaceBuilder::*)(const TopTools_IndexedDataMapOfShapeShape &, const TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_FaceBuilder::CorrectGclosedWire, "Using the given maps, change the topology of the 3d-closed wires, in order to get closed wires.", py::arg("mapVVref"), py::arg("mapVon1Edge"));
cls_TopOpeBRepBuild_FaceBuilder.def("DetectPseudoInternalEdge", (void (TopOpeBRepBuild_FaceBuilder::*)(TopTools_IndexedMapOfShape &)) &TopOpeBRepBuild_FaceBuilder::DetectPseudoInternalEdge, "Removes edges appearing twice (FORWARD,REVERSED) with a bounding vertex not connected to any other edge. mapE contains edges found. modifies myBlockBuilder.", py::arg("mapE"));
cls_TopOpeBRepBuild_FaceBuilder.def("Face", (const TopoDS_Shape & (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::Face, "return myFace");
cls_TopOpeBRepBuild_FaceBuilder.def("InitFace", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::InitFace, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("MoreFace", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::MoreFace, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("NextFace", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::NextFace, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("InitWire", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::InitWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("MoreWire", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::MoreWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("NextWire", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::NextWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("IsOldWire", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::IsOldWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("OldWire", (const TopoDS_Shape & (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::OldWire, "Returns current wire This wire may be : * an old wire OldWire(), which has not been reconstructed; * a new wire made of edges described by ...NewEdge() methods.");
cls_TopOpeBRepBuild_FaceBuilder.def("FindNextValidElement", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::FindNextValidElement, "Iterates on myBlockIterator until finding a valid element");
cls_TopOpeBRepBuild_FaceBuilder.def("InitEdge", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::InitEdge, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("MoreEdge", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::MoreEdge, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("NextEdge", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::NextEdge, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("Edge", (const TopoDS_Shape & (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::Edge, "Returns current new edge of current new wire.");
cls_TopOpeBRepBuild_FaceBuilder.def("EdgeConnexity", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_FaceBuilder::EdgeConnexity, "None", py::arg("E"));
cls_TopOpeBRepBuild_FaceBuilder.def("AddEdgeWire", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepBuild_FaceBuilder::AddEdgeWire, "None", py::arg("E"), py::arg("W"));

// CLASS: TOPOPEBREPBUILD_EDGEBUILDER
py::class_<TopOpeBRepBuild_EdgeBuilder, TopOpeBRepBuild_Area1dBuilder> cls_TopOpeBRepBuild_EdgeBuilder(mod, "TopOpeBRepBuild_EdgeBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_EdgeBuilder.def(py::init<>());
cls_TopOpeBRepBuild_EdgeBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_EdgeBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Methods
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_EdgeBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_EdgeBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_EdgeBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_EdgeBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_EdgeBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_EdgeBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_EdgeBuilder.def("InitEdgeBuilder", [](TopOpeBRepBuild_EdgeBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitEdgeBuilder(a0, a1); });
cls_TopOpeBRepBuild_EdgeBuilder.def("InitEdgeBuilder", (void (TopOpeBRepBuild_EdgeBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_EdgeBuilder::InitEdgeBuilder, "None", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_EdgeBuilder.def("InitEdge", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::InitEdge, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("MoreEdge", (Standard_Boolean (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::MoreEdge, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("NextEdge", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::NextEdge, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("InitVertex", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::InitVertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("MoreVertex", (Standard_Boolean (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::MoreVertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("NextVertex", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::NextVertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("Vertex", (const TopoDS_Shape & (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::Vertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("Parameter", (Standard_Real (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::Parameter, "None");

// CLASS: TOPOPEBREPBUILD_HBUILDER
py::class_<TopOpeBRepBuild_HBuilder, opencascade::handle<TopOpeBRepBuild_HBuilder>, Standard_Transient> cls_TopOpeBRepBuild_HBuilder(mod, "TopOpeBRepBuild_HBuilder", "The HBuilder algorithm constructs topological objects from an existing topology and new geometries attached to the topology. It is used to construct the result of a topological operation; the existing topologies are the parts involved in the topological operation and the new geometries are the intersection lines and points.");

// Constructors
cls_TopOpeBRepBuild_HBuilder.def(py::init<const TopOpeBRepDS_BuildTool &>(), py::arg("BT"));

// Methods
cls_TopOpeBRepBuild_HBuilder.def("BuildTool", (const TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::BuildTool, "None");
cls_TopOpeBRepBuild_HBuilder.def("Perform", (void (TopOpeBRepBuild_HBuilder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepBuild_HBuilder::Perform, "Stores the data structure <HDS>, Create shapes from the new geometries described in <HDS>.", py::arg("HDS"));
cls_TopOpeBRepBuild_HBuilder.def("Perform", (void (TopOpeBRepBuild_HBuilder::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_HBuilder::Perform, "Same as previous + evaluates if an operation performed on shapes S1,S2 is a particular case.", py::arg("HDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepBuild_HBuilder.def("Clear", (void (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::Clear, "Removes all split and merge already performed. Does NOT clear the handled DS.");
cls_TopOpeBRepBuild_HBuilder.def("DataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::DataStructure, "returns the DS handled by this builder");
cls_TopOpeBRepBuild_HBuilder.def("ChangeBuildTool", (TopOpeBRepDS_BuildTool & (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::ChangeBuildTool, "None");
cls_TopOpeBRepBuild_HBuilder.def("MergeShapes", (void (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeShapes, "Merges the two shapes <S1> and <S2> keeping the parts of states <TB1>,<TB2> in <S1>,<S2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_HBuilder.def("MergeSolids", (void (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State, const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeSolids, "Merges the two solids <S1> and <S2> keeping the parts in each solid of states <TB1> and <TB2>.", py::arg("S1"), py::arg("TB1"), py::arg("S2"), py::arg("TB2"));
cls_TopOpeBRepBuild_HBuilder.def("MergeSolid", (void (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeSolid, "Merges the solid <S> keeping the parts of state <TB>.", py::arg("S"), py::arg("TB"));
cls_TopOpeBRepBuild_HBuilder.def("IsSplit", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::IsSplit, "Returns True if the shape <S> has been split.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("Splits", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::Splits, "Returns the split parts <ToBuild> of shape <S>.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("IsMerged", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::IsMerged, "Returns True if the shape <S> has been merged.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("Merged", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const TopAbs_State) const) &TopOpeBRepBuild_HBuilder::Merged, "Returns the merged parts <ToBuild> of shape <S>.", py::arg("S"), py::arg("ToBuild"));
cls_TopOpeBRepBuild_HBuilder.def("NewVertex", (const TopoDS_Shape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_HBuilder::NewVertex, "Returns the vertex created on point <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("NewEdges", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_HBuilder::NewEdges, "Returns the edges created on curve <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("ChangeNewEdges", (TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer)) &TopOpeBRepBuild_HBuilder::ChangeNewEdges, "Returns the edges created on curve <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("NewFaces", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer) const) &TopOpeBRepBuild_HBuilder::NewFaces, "Returns the faces created on surface <I>.", py::arg("I"));
cls_TopOpeBRepBuild_HBuilder.def("Section", (const TopTools_ListOfShape & (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::Section, "None");
cls_TopOpeBRepBuild_HBuilder.def("InitExtendedSectionDS", [](TopOpeBRepBuild_HBuilder &self) -> void { return self.InitExtendedSectionDS(); });
cls_TopOpeBRepBuild_HBuilder.def("InitExtendedSectionDS", (void (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer)) &TopOpeBRepBuild_HBuilder::InitExtendedSectionDS, "None", py::arg("k"));
cls_TopOpeBRepBuild_HBuilder.def("InitSection", [](TopOpeBRepBuild_HBuilder &self) -> void { return self.InitSection(); });
cls_TopOpeBRepBuild_HBuilder.def("InitSection", (void (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer)) &TopOpeBRepBuild_HBuilder::InitSection, "None", py::arg("k"));
cls_TopOpeBRepBuild_HBuilder.def("MoreSection", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::MoreSection, "None");
cls_TopOpeBRepBuild_HBuilder.def("NextSection", (void (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::NextSection, "None");
cls_TopOpeBRepBuild_HBuilder.def("CurrentSection", (const TopoDS_Shape & (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::CurrentSection, "None");
cls_TopOpeBRepBuild_HBuilder.def("GetDSEdgeFromSectEdge", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepBuild_HBuilder::GetDSEdgeFromSectEdge, "None", py::arg("E"), py::arg("rank"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSFaceFromDSEdge", (TColStd_ListOfInteger & (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepBuild_HBuilder::GetDSFaceFromDSEdge, "None", py::arg("indexEdg"), py::arg("rank"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSCurveFromSectEdge", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_HBuilder::GetDSCurveFromSectEdge, "None", py::arg("SectEdge"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSFaceFromDSCurve", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepBuild_HBuilder::GetDSFaceFromDSCurve, "None", py::arg("indexCur"), py::arg("rank"));
cls_TopOpeBRepBuild_HBuilder.def("GetDSPointFromNewVertex", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_HBuilder::GetDSPointFromNewVertex, "None", py::arg("NewVert"));
cls_TopOpeBRepBuild_HBuilder.def("EdgeCurveAncestors", [](TopOpeBRepBuild_HBuilder &self, const TopoDS_Shape & E, TopoDS_Shape & F1, TopoDS_Shape & F2, Standard_Integer & IC){ Standard_Boolean rv = self.EdgeCurveAncestors(E, F1, F2, IC); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IC); }, "search for the couple of face F1,F2 (from arguments of supra Perform(S1,S2,HDS)) method which intersection gives section edge E built on an intersection curve. returns True if F1,F2 have been valued. returns False if E is not a section edge built on intersection curve IC.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("IC"));
cls_TopOpeBRepBuild_HBuilder.def("EdgeSectionAncestors", (Standard_Boolean (TopOpeBRepBuild_HBuilder::*)(const TopoDS_Shape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepBuild_HBuilder::EdgeSectionAncestors, "search for the couple of face F1,F2 (from arguments of supra Perform(S1,S2,HDS)) method which intersection gives section edge E built on at least one edge . returns True if F1,F2 have been valued. returns False if E is not a section edge built on at least one edge of S1 and/or S2. LE1,LE2 are edges of S1,S2 which common part is edge E. LE1 or LE2 may be empty() but not both.", py::arg("E"), py::arg("LF1"), py::arg("LF2"), py::arg("LE1"), py::arg("LE2"));
cls_TopOpeBRepBuild_HBuilder.def("IsKPart", (Standard_Integer (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::IsKPart, "Returns 0 is standard operation, != 0 if particular case");
cls_TopOpeBRepBuild_HBuilder.def("MergeKPart", (void (TopOpeBRepBuild_HBuilder::*)(const TopAbs_State, const TopAbs_State)) &TopOpeBRepBuild_HBuilder::MergeKPart, "None", py::arg("TB1"), py::arg("TB2"));
cls_TopOpeBRepBuild_HBuilder.def("ChangeBuilder", (TopOpeBRepBuild_Builder & (TopOpeBRepBuild_HBuilder::*)()) &TopOpeBRepBuild_HBuilder::ChangeBuilder, "None");
cls_TopOpeBRepBuild_HBuilder.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepBuild_HBuilder::get_type_name, "None");
cls_TopOpeBRepBuild_HBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepBuild_HBuilder::get_type_descriptor, "None");
cls_TopOpeBRepBuild_HBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepBuild_HBuilder::*)() const) &TopOpeBRepBuild_HBuilder::DynamicType, "None");

// CLASS: TOPOPEBREPBUILD_FUSEFACE
py::class_<TopOpeBRepBuild_FuseFace> cls_TopOpeBRepBuild_FuseFace(mod, "TopOpeBRepBuild_FuseFace", "None");

// Constructors
cls_TopOpeBRepBuild_FuseFace.def(py::init<>());
cls_TopOpeBRepBuild_FuseFace.def(py::init<const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Integer>(), py::arg("LIF"), py::arg("LRF"), py::arg("CXM"));

// Methods
// cls_TopOpeBRepBuild_FuseFace.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_FuseFace::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_FuseFace::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_FuseFace::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_FuseFace::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_FuseFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_FuseFace::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_FuseFace.def("Init", (void (TopOpeBRepBuild_FuseFace::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Integer)) &TopOpeBRepBuild_FuseFace::Init, "None", py::arg("LIF"), py::arg("LRF"), py::arg("CXM"));
cls_TopOpeBRepBuild_FuseFace.def("PerformFace", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::PerformFace, "None");
cls_TopOpeBRepBuild_FuseFace.def("PerformEdge", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::PerformEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("ClearEdge", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::ClearEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("ClearVertex", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::ClearVertex, "None");
cls_TopOpeBRepBuild_FuseFace.def("IsDone", (Standard_Boolean (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::IsDone, "None");
cls_TopOpeBRepBuild_FuseFace.def("IsModified", (Standard_Boolean (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::IsModified, "None");
cls_TopOpeBRepBuild_FuseFace.def("LFuseFace", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LFuseFace, "None");
cls_TopOpeBRepBuild_FuseFace.def("LInternEdge", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LInternEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("LExternEdge", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LExternEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("LModifEdge", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LModifEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("LInternVertex", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LInternVertex, "None");
cls_TopOpeBRepBuild_FuseFace.def("LExternVertex", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LExternVertex, "None");
cls_TopOpeBRepBuild_FuseFace.def("LModifVertex", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LModifVertex, "None");

// CLASS: TOPOPEBREPBUILD_GITER
py::class_<TopOpeBRepBuild_GIter> cls_TopOpeBRepBuild_GIter(mod, "TopOpeBRepBuild_GIter", "None");

// Constructors
cls_TopOpeBRepBuild_GIter.def(py::init<>());
cls_TopOpeBRepBuild_GIter.def(py::init<const TopOpeBRepBuild_GTopo &>(), py::arg("G"));

// Methods
// cls_TopOpeBRepBuild_GIter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_GIter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GIter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_GIter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GIter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_GIter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GIter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_GIter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GIter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_GIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_GIter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_GIter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_GIter.def("Init", (void (TopOpeBRepBuild_GIter::*)()) &TopOpeBRepBuild_GIter::Init, "None");
cls_TopOpeBRepBuild_GIter.def("Init", (void (TopOpeBRepBuild_GIter::*)(const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_GIter::Init, "None", py::arg("G"));
cls_TopOpeBRepBuild_GIter.def("More", (Standard_Boolean (TopOpeBRepBuild_GIter::*)() const) &TopOpeBRepBuild_GIter::More, "None");
cls_TopOpeBRepBuild_GIter.def("Next", (void (TopOpeBRepBuild_GIter::*)()) &TopOpeBRepBuild_GIter::Next, "None");
cls_TopOpeBRepBuild_GIter.def("Current", (void (TopOpeBRepBuild_GIter::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepBuild_GIter::Current, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GIter.def("Dump", (void (TopOpeBRepBuild_GIter::*)(Standard_OStream &) const) &TopOpeBRepBuild_GIter::Dump, "None", py::arg("OS"));

// CLASS: TOPOPEBREPBUILD_GTOOL
py::class_<TopOpeBRepBuild_GTool> cls_TopOpeBRepBuild_GTool(mod, "TopOpeBRepBuild_GTool", "None");

// Constructors
cls_TopOpeBRepBuild_GTool.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_GTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_GTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_GTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_GTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_GTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_GTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_GTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_GTool.def_static("GFusUnsh_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GFusUnsh, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GFusSame_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GFusSame, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GFusDiff_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GFusDiff, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GCutUnsh_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GCutUnsh, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GCutSame_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GCutSame, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GCutDiff_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GCutDiff, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GComUnsh_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GComUnsh, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GComSame_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GComSame, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GComDiff_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GComDiff, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("Dump_", (void (*)(Standard_OStream &)) &TopOpeBRepBuild_GTool::Dump, "None", py::arg("OS"));

// CLASS: TOPOPEBREPBUILD_VERTEXINFO
py::class_<TopOpeBRepBuild_VertexInfo> cls_TopOpeBRepBuild_VertexInfo(mod, "TopOpeBRepBuild_VertexInfo", "None");

// Constructors
cls_TopOpeBRepBuild_VertexInfo.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_VertexInfo::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_VertexInfo::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_VertexInfo::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_VertexInfo::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_VertexInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_VertexInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_VertexInfo.def("SetVertex", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Vertex &)) &TopOpeBRepBuild_VertexInfo::SetVertex, "None", py::arg("aV"));
cls_TopOpeBRepBuild_VertexInfo.def("Vertex", (const TopoDS_Vertex & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::Vertex, "None");
cls_TopOpeBRepBuild_VertexInfo.def("SetSmart", (void (TopOpeBRepBuild_VertexInfo::*)(const Standard_Boolean)) &TopOpeBRepBuild_VertexInfo::SetSmart, "None", py::arg("aFlag"));
cls_TopOpeBRepBuild_VertexInfo.def("Smart", (Standard_Boolean (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::Smart, "None");
cls_TopOpeBRepBuild_VertexInfo.def("NbCases", (Standard_Integer (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::NbCases, "None");
cls_TopOpeBRepBuild_VertexInfo.def("FoundOut", (Standard_Integer (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::FoundOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("AddIn", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::AddIn, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("AddOut", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::AddOut, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("SetCurrentIn", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::SetCurrentIn, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("EdgesIn", (const TopTools_IndexedMapOfOrientedShape & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::EdgesIn, "None");
cls_TopOpeBRepBuild_VertexInfo.def("EdgesOut", (const TopTools_IndexedMapOfOrientedShape & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::EdgesOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("ChangeEdgesOut", (TopTools_IndexedMapOfOrientedShape & (TopOpeBRepBuild_VertexInfo::*)()) &TopOpeBRepBuild_VertexInfo::ChangeEdgesOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("Dump", (void (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::Dump, "None");
cls_TopOpeBRepBuild_VertexInfo.def("CurrentOut", (const TopoDS_Edge & (TopOpeBRepBuild_VertexInfo::*)()) &TopOpeBRepBuild_VertexInfo::CurrentOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("AppendPassed", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::AppendPassed, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("RemovePassed", (void (TopOpeBRepBuild_VertexInfo::*)()) &TopOpeBRepBuild_VertexInfo::RemovePassed, "None");
cls_TopOpeBRepBuild_VertexInfo.def("ListPassed", (const TopTools_ListOfShape & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::ListPassed, "None");
cls_TopOpeBRepBuild_VertexInfo.def("Prepare", (void (TopOpeBRepBuild_VertexInfo::*)(const TopTools_ListOfShape &)) &TopOpeBRepBuild_VertexInfo::Prepare, "None", py::arg("aL"));

// TYPEDEF: TOPOPEBREPBUILD_INDEXEDDATAMAPOFSHAPEVERTEXINFO
bind_NCollection_IndexedDataMap<TopoDS_Shape, TopOpeBRepBuild_VertexInfo, TopTools_ShapeMapHasher>(mod, "TopOpeBRepBuild_IndexedDataMapOfShapeVertexInfo", py::module_local(false));

// CLASS: TOPOPEBREPBUILD_SHELLFACECLASSIFIER
py::class_<TopOpeBRepBuild_ShellFaceClassifier, TopOpeBRepBuild_CompositeClassifier> cls_TopOpeBRepBuild_ShellFaceClassifier(mod, "TopOpeBRepBuild_ShellFaceClassifier", "Classify faces and shells. shapes are Shells, Elements are Faces.");

// Constructors
cls_TopOpeBRepBuild_ShellFaceClassifier.def(py::init<const TopOpeBRepBuild_BlockBuilder &>(), py::arg("BB"));

// Methods
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("Clear", (void (TopOpeBRepBuild_ShellFaceClassifier::*)()) &TopOpeBRepBuild_ShellFaceClassifier::Clear, "None");
cls_TopOpeBRepBuild_ShellFaceClassifier.def("CompareShapes", (TopAbs_State (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::CompareShapes, "classify shell <B1> with shell <B2>", py::arg("B1"), py::arg("B2"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("CompareElementToShape", (TopAbs_State (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::CompareElementToShape, "classify face <F> with shell <S>", py::arg("F"), py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("ResetShape", (void (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::ResetShape, "prepare classification involving shell <S> calls ResetElement on first face of <S>", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("ResetElement", (void (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::ResetElement, "prepare classification involving face <F> define 3D point (later used in Compare()) on first vertex of face <F>.", py::arg("F"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("CompareElement", (Standard_Boolean (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::CompareElement, "Add the face <F> in the set of faces used in 3D point classification. Returns FALSE if the face <F> has been already added to the set of faces, otherwise returns TRUE.", py::arg("F"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("State", (TopAbs_State (TopOpeBRepBuild_ShellFaceClassifier::*)()) &TopOpeBRepBuild_ShellFaceClassifier::State, "Returns state of classification of 3D point, defined by ResetElement, with the current set of faces, defined by Compare.");

// CLASS: TOPOPEBREPBUILD_SHELLTOSOLID
py::class_<TopOpeBRepBuild_ShellToSolid> cls_TopOpeBRepBuild_ShellToSolid(mod, "TopOpeBRepBuild_ShellToSolid", "This class builds solids from a set of shells SSh and a solid F.");

// Constructors
cls_TopOpeBRepBuild_ShellToSolid.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellToSolid::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShellToSolid::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellToSolid::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShellToSolid::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShellToSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShellToSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShellToSolid.def("Init", (void (TopOpeBRepBuild_ShellToSolid::*)()) &TopOpeBRepBuild_ShellToSolid::Init, "None");
cls_TopOpeBRepBuild_ShellToSolid.def("AddShell", (void (TopOpeBRepBuild_ShellToSolid::*)(const TopoDS_Shell &)) &TopOpeBRepBuild_ShellToSolid::AddShell, "None", py::arg("Sh"));
cls_TopOpeBRepBuild_ShellToSolid.def("MakeSolids", (void (TopOpeBRepBuild_ShellToSolid::*)(const TopoDS_Solid &, TopTools_ListOfShape &)) &TopOpeBRepBuild_ShellToSolid::MakeSolids, "None", py::arg("So"), py::arg("LSo"));

// CLASS: TOPOPEBREPBUILD_TOOLS
py::class_<TopOpeBRepBuild_Tools> cls_TopOpeBRepBuild_Tools(mod, "TopOpeBRepBuild_Tools", "Auxiliary methods used in TopOpeBRepBuild_Builder1 class");

// Constructors
cls_TopOpeBRepBuild_Tools.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_Tools.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Tools::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Tools.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Tools::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Tools::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Tools.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Tools::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Tools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Tools::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Tools.def_static("FindState_", (void (*)(const TopoDS_Shape &, const TopAbs_State, const TopAbs_ShapeEnum, const TopTools_IndexedDataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepBuild_Tools::FindState, "None", py::arg("aVertex"), py::arg("aState"), py::arg("aShapeEnum"), py::arg("aMapVertexEdges"), py::arg("aMapProcessedVertices"), py::arg("aMapVs"));
cls_TopOpeBRepBuild_Tools.def_static("PropagateState_", (void (*)(const TopOpeBRepDS_DataMapOfShapeState &, const TopTools_IndexedMapOfShape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopOpeBRepTool_ShapeClassifier &, TopOpeBRepDS_IndexedDataMapOfShapeWithState &, const TopTools_MapOfShape &)) &TopOpeBRepBuild_Tools::PropagateState, "None", py::arg("aSplEdgesState"), py::arg("anEdgesToRestMap"), py::arg("aShapeEnum1"), py::arg("aShapeEnum2"), py::arg("aShapeClassifier"), py::arg("aMapOfShapeWithState"), py::arg("anUnkStateShapes"));
cls_TopOpeBRepBuild_Tools.def_static("FindStateThroughVertex_", (TopAbs_State (*)(const TopoDS_Shape &, TopOpeBRepTool_ShapeClassifier &, TopOpeBRepDS_IndexedDataMapOfShapeWithState &, const TopTools_MapOfShape &)) &TopOpeBRepBuild_Tools::FindStateThroughVertex, "None", py::arg("aShape"), py::arg("aShapeClassifier"), py::arg("aMapOfShapeWithState"), py::arg("anAvoidSubshMap"));
cls_TopOpeBRepBuild_Tools.def_static("PropagateStateForWires_", (void (*)(const TopTools_IndexedMapOfShape &, TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepBuild_Tools::PropagateStateForWires, "None", py::arg("aFacesToRestMap"), py::arg("aMapOfShapeWithState"));
cls_TopOpeBRepBuild_Tools.def_static("SpreadStateToChild_", (void (*)(const TopoDS_Shape &, const TopAbs_State, TopOpeBRepDS_IndexedDataMapOfShapeWithState &)) &TopOpeBRepBuild_Tools::SpreadStateToChild, "None", py::arg("aShape"), py::arg("aState"), py::arg("aMapOfShapeWithState"));
cls_TopOpeBRepBuild_Tools.def_static("FindState1_", (void (*)(const TopoDS_Shape &, const TopAbs_State, const TopTools_IndexedDataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepBuild_Tools::FindState1, "None", py::arg("anEdge"), py::arg("aState"), py::arg("aMapEdgesFaces"), py::arg("aMapProcessedVertices"), py::arg("aMapVs"));
cls_TopOpeBRepBuild_Tools.def_static("FindState2_", (void (*)(const TopoDS_Shape &, const TopAbs_State, const TopTools_IndexedDataMapOfShapeListOfShape &, TopTools_MapOfShape &, TopOpeBRepDS_DataMapOfShapeState &)) &TopOpeBRepBuild_Tools::FindState2, "None", py::arg("anEdge"), py::arg("aState"), py::arg("aMapEdgesFaces"), py::arg("aMapProcessedEdges"), py::arg("aMapVs"));
cls_TopOpeBRepBuild_Tools.def_static("GetAdjacentFace_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopTools_IndexedDataMapOfShapeListOfShape &, TopoDS_Shape &)) &TopOpeBRepBuild_Tools::GetAdjacentFace, "None", py::arg("aFaceObj"), py::arg("anEObj"), py::arg("anEdgeFaceMap"), py::arg("anAdjFaceObj"));
cls_TopOpeBRepBuild_Tools.def_static("GetNormalToFaceOnEdge_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetNormalToFaceOnEdge, "None", py::arg("aFObj"), py::arg("anEdgeObj"), py::arg("aDirNormal"));
cls_TopOpeBRepBuild_Tools.def_static("GetNormalInNearestPoint_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetNormalInNearestPoint, "This function used to compute normal in point which is located near the point with param UV (used for computation of normals where the normal in the point UV equal to zero).", py::arg("aFace"), py::arg("anEdge"), py::arg("aNormal"));
cls_TopOpeBRepBuild_Tools.def_static("GetTangentToEdgeEdge_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetTangentToEdgeEdge, "None", py::arg("aFObj"), py::arg("anEdgeObj"), py::arg("aOriEObj"), py::arg("aTangent"));
cls_TopOpeBRepBuild_Tools.def_static("GetTangentToEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepBuild_Tools::GetTangentToEdge, "None", py::arg("anEdgeObj"), py::arg("aTangent"));
cls_TopOpeBRepBuild_Tools.def_static("UpdatePCurves_", (void (*)(const TopoDS_Wire &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRepBuild_Tools::UpdatePCurves, "Recompute PCurves of the all edges from the wire on the <toFace>", py::arg("aWire"), py::arg("fromFace"), py::arg("toFace"));
cls_TopOpeBRepBuild_Tools.def_static("UpdateEdgeOnPeriodicalFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRepBuild_Tools::UpdateEdgeOnPeriodicalFace, "recompute PCurves of the closing (SIM , with 2 PCurves) edge on the NewFace", py::arg("aEdgeToUpdate"), py::arg("OldFace"), py::arg("NewFace"));
cls_TopOpeBRepBuild_Tools.def_static("UpdateEdgeOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRepBuild_Tools::UpdateEdgeOnFace, "recompute PCurve of the edge on the NewFace", py::arg("aEdgeToUpdate"), py::arg("OldFace"), py::arg("NewFace"));
cls_TopOpeBRepBuild_Tools.def_static("IsDegEdgesTheSame_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_Tools::IsDegEdgesTheSame, "None", py::arg("anE1"), py::arg("anE2"));
cls_TopOpeBRepBuild_Tools.def_static("NormalizeFace_", (void (*)(const TopoDS_Shape &, TopoDS_Shape &)) &TopOpeBRepBuild_Tools::NormalizeFace, "test if <oldFace> does not contain INTERNAL or EXTERNAL edges and remove such edges in case of its presence. The result is stored in <corrFace>", py::arg("oldFace"), py::arg("corrFace"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectFace2d_", (void (*)(const TopoDS_Shape &, TopoDS_Shape &, const TopTools_IndexedMapOfOrientedShape &, TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_Tools::CorrectFace2d, "test if UV representation of <oldFace> is good (i.e. face is closed in 2d). if face is not closed , this method will try to close such face and will return corrected edges in the <aMapOfCorrect2dEdges>. Parameter <aSourceShapes> used to fix the edge (or wires) which should be correct (Corrector used it as a start shapes). NOTE : Parameter corrFace doesn't mean anything. If you want to use this method , rebuild resulting face after by yourself using corrected edges.", py::arg("oldFace"), py::arg("corrFace"), py::arg("aSourceShapes"), py::arg("aMapOfCorrect2dEdges"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectTolerances_", [](const TopoDS_Shape & a0) -> void { return TopOpeBRepBuild_Tools::CorrectTolerances(a0); });
cls_TopOpeBRepBuild_Tools.def_static("CorrectTolerances_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepBuild_Tools::CorrectTolerances, "None", py::arg("aS"), py::arg("aTolMax"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectCurveOnSurface_", [](const TopoDS_Shape & a0) -> void { return TopOpeBRepBuild_Tools::CorrectCurveOnSurface(a0); });
cls_TopOpeBRepBuild_Tools.def_static("CorrectCurveOnSurface_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepBuild_Tools::CorrectCurveOnSurface, "None", py::arg("aS"), py::arg("aTolMax"));
cls_TopOpeBRepBuild_Tools.def_static("CorrectPointOnCurve_", [](const TopoDS_Shape & a0) -> void { return TopOpeBRepBuild_Tools::CorrectPointOnCurve(a0); });
cls_TopOpeBRepBuild_Tools.def_static("CorrectPointOnCurve_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepBuild_Tools::CorrectPointOnCurve, "None", py::arg("aS"), py::arg("aTolMax"));
cls_TopOpeBRepBuild_Tools.def_static("CheckFaceClosed2d_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepBuild_Tools::CheckFaceClosed2d, "Checks if <theFace> has the properly closed in 2D boundary(ies)", py::arg("theFace"));

// CLASS: TOPOPEBREPBUILD_TOOLS2D
py::class_<TopOpeBRepBuild_Tools2d> cls_TopOpeBRepBuild_Tools2d(mod, "TopOpeBRepBuild_Tools2d", "None");

// Constructors
cls_TopOpeBRepBuild_Tools2d.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_Tools2d.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_Tools2d::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Tools2d.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_Tools2d::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools2d.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_Tools2d::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_Tools2d.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_Tools2d::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools2d.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_Tools2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_Tools2d.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_Tools2d::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_Tools2d.def_static("MakeMapOfShapeVertexInfo_", (void (*)(const TopoDS_Wire &, TopOpeBRepBuild_IndexedDataMapOfShapeVertexInfo &)) &TopOpeBRepBuild_Tools2d::MakeMapOfShapeVertexInfo, "None", py::arg("aWire"), py::arg("aMap"));
cls_TopOpeBRepBuild_Tools2d.def_static("DumpMapOfShapeVertexInfo_", (void (*)(const TopOpeBRepBuild_IndexedDataMapOfShapeVertexInfo &)) &TopOpeBRepBuild_Tools2d::DumpMapOfShapeVertexInfo, "None", py::arg("aMap"));
cls_TopOpeBRepBuild_Tools2d.def_static("Path_", (void (*)(const TopoDS_Wire &, TopTools_ListOfShape &)) &TopOpeBRepBuild_Tools2d::Path, "None", py::arg("aWire"), py::arg("aResList"));

// CLASS: TOPOPEBREPBUILD_WIREEDGECLASSIFIER
py::class_<TopOpeBRepBuild_WireEdgeClassifier, TopOpeBRepBuild_CompositeClassifier> cls_TopOpeBRepBuild_WireEdgeClassifier(mod, "TopOpeBRepBuild_WireEdgeClassifier", "Classify edges and wires. shapes are Wires, Element are Edge.");

// Constructors
cls_TopOpeBRepBuild_WireEdgeClassifier.def(py::init<const TopoDS_Shape &, const TopOpeBRepBuild_BlockBuilder &>(), py::arg("F"), py::arg("BB"));

// Methods
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_WireEdgeClassifier::Compare, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("LoopToShape", (TopoDS_Shape (TopOpeBRepBuild_WireEdgeClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_WireEdgeClassifier::LoopToShape, "None", py::arg("L"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("CompareShapes", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::CompareShapes, "classify wire <B1> with wire <B2>", py::arg("B1"), py::arg("B2"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("CompareElementToShape", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::CompareElementToShape, "classify edge <E> with wire <B>", py::arg("E"), py::arg("B"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("ResetShape", (void (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::ResetShape, "prepare classification involving wire <B> calls ResetElement on first edge of <B>", py::arg("B"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("ResetElement", (void (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::ResetElement, "prepare classification involving edge <E> define 2D point (later used in Compare()) on first vertex of edge <E>.", py::arg("E"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("CompareElement", (Standard_Boolean (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::CompareElement, "Add the edge <E> in the set of edges used in 2D point classification.", py::arg("E"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("State", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)()) &TopOpeBRepBuild_WireEdgeClassifier::State, "Returns state of classification of 2D point, defined by ResetElement, with the current set of edges, defined by Compare.");

// CLASS: TOPOPEBREPBUILD_WIRETOFACE
py::class_<TopOpeBRepBuild_WireToFace> cls_TopOpeBRepBuild_WireToFace(mod, "TopOpeBRepBuild_WireToFace", "This class builds faces from a set of wires SW and a face F. The face must have and underlying surface, say S. All of the edges of all of the wires must have a 2d representation on surface S (except if S is planar)");

// Constructors
cls_TopOpeBRepBuild_WireToFace.def(py::init<>());

// Methods
// cls_TopOpeBRepBuild_WireToFace.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_WireToFace::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_WireToFace::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_WireToFace::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_WireToFace::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_WireToFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_WireToFace::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_WireToFace.def("Init", (void (TopOpeBRepBuild_WireToFace::*)()) &TopOpeBRepBuild_WireToFace::Init, "None");
cls_TopOpeBRepBuild_WireToFace.def("AddWire", (void (TopOpeBRepBuild_WireToFace::*)(const TopoDS_Wire &)) &TopOpeBRepBuild_WireToFace::AddWire, "None", py::arg("W"));
cls_TopOpeBRepBuild_WireToFace.def("MakeFaces", (void (TopOpeBRepBuild_WireToFace::*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepBuild_WireToFace::MakeFaces, "None", py::arg("F"), py::arg("LF"));


}
