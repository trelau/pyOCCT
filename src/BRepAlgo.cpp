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

#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BRepAlgo_Image.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <BRepAlgo_BooleanOperation.hxx>
#include <BRepAlgo_Fuse.hxx>
#include <BRepAlgo_Cut.hxx>
#include <BRepAlgo_Common.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <BRepAlgo_Section.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepAlgo_Loop.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepAlgo_Tool.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepAlgo_FaceRestrictor.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <BRepAlgo_DSAccess.hxx>
#include <BRepAlgo_BooleanOperations.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepAlgo_CheckStatus.hxx>
#include <BRepAlgo_EdgeConnector.hxx>
#include <GeomAbs_Shape.hxx>
#include <Adaptor3d_Curve.hxx>
#include <BRepAlgo_NormalProjection.hxx>
#include <BRepAlgo.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepAlgo_DataMapOfShapeBoolean.hxx>
#include <BRepAlgo_DataMapOfShapeInterference.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepAlgo_SequenceOfSequenceOfInteger.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BRepAlgo, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.BRepBuilderAPI");
	py::module::import("OCCT.TopOpeBRepBuild");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopOpeBRepDS");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_CheckStatus.hxx
	py::enum_<BRepAlgo_CheckStatus>(mod, "BRepAlgo_CheckStatus", "None")
		.value("BRepAlgo_OK", BRepAlgo_CheckStatus::BRepAlgo_OK)
		.value("BRepAlgo_NOK", BRepAlgo_CheckStatus::BRepAlgo_NOK)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Image.hxx
	py::class_<BRepAlgo_Image, std::unique_ptr<BRepAlgo_Image, Deleter<BRepAlgo_Image>>> cls_BRepAlgo_Image(mod, "BRepAlgo_Image", "Stores link between a shape <S> and a shape <NewS> obtained from <S>. <NewS> is an image of <S>.");
	cls_BRepAlgo_Image.def(py::init<>());
	cls_BRepAlgo_Image.def("SetRoot", (void (BRepAlgo_Image::*)(const TopoDS_Shape &)) &BRepAlgo_Image::SetRoot, "None", py::arg("S"));
	cls_BRepAlgo_Image.def("Bind", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_Image::Bind, "Links <NewS> as image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
	cls_BRepAlgo_Image.def("Bind", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepAlgo_Image::Bind, "Links <NewS> as image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
	cls_BRepAlgo_Image.def("Add", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_Image::Add, "Add <NewS> to the image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
	cls_BRepAlgo_Image.def("Add", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepAlgo_Image::Add, "Add <NewS> to the image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
	cls_BRepAlgo_Image.def("Clear", (void (BRepAlgo_Image::*)()) &BRepAlgo_Image::Clear, "None");
	cls_BRepAlgo_Image.def("Remove", (void (BRepAlgo_Image::*)(const TopoDS_Shape &)) &BRepAlgo_Image::Remove, "Remove <S> to set of images.", py::arg("S"));
	cls_BRepAlgo_Image.def("Roots", (const TopTools_ListOfShape & (BRepAlgo_Image::*)() const ) &BRepAlgo_Image::Roots, "None");
	cls_BRepAlgo_Image.def("IsImage", (Standard_Boolean (BRepAlgo_Image::*)(const TopoDS_Shape &) const ) &BRepAlgo_Image::IsImage, "None", py::arg("S"));
	cls_BRepAlgo_Image.def("ImageFrom", (const TopoDS_Shape & (BRepAlgo_Image::*)(const TopoDS_Shape &) const ) &BRepAlgo_Image::ImageFrom, "Returns the generator of <S>", py::arg("S"));
	cls_BRepAlgo_Image.def("Root", (const TopoDS_Shape & (BRepAlgo_Image::*)(const TopoDS_Shape &) const ) &BRepAlgo_Image::Root, "Returns the upper generator of <S>", py::arg("S"));
	cls_BRepAlgo_Image.def("HasImage", (Standard_Boolean (BRepAlgo_Image::*)(const TopoDS_Shape &) const ) &BRepAlgo_Image::HasImage, "None", py::arg("S"));
	cls_BRepAlgo_Image.def("Image", (const TopTools_ListOfShape & (BRepAlgo_Image::*)(const TopoDS_Shape &) const ) &BRepAlgo_Image::Image, "Returns the Image of <S>. Returns <S> in the list if HasImage(S) is false.", py::arg("S"));
	cls_BRepAlgo_Image.def("LastImage", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, TopTools_ListOfShape &) const ) &BRepAlgo_Image::LastImage, "Stores in <L> the images of images of...images of <S>. <L> contains only <S> if HasImage(S) is false.", py::arg("S"), py::arg("L"));
	cls_BRepAlgo_Image.def("Compact", (void (BRepAlgo_Image::*)()) &BRepAlgo_Image::Compact, "Keeps only the link between roots and lastimage.");
	cls_BRepAlgo_Image.def("Filter", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BRepAlgo_Image::Filter, "Deletes in the images the shape of type <ShapeType> which are not in <S>. Warning: Compact() must be call before.", py::arg("S"), py::arg("ShapeType"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_AsDes.hxx
	py::class_<BRepAlgo_AsDes, opencascade::handle<BRepAlgo_AsDes>, Standard_Transient> cls_BRepAlgo_AsDes(mod, "BRepAlgo_AsDes", "SD to store descendants and ascendants of Shapes.");
	cls_BRepAlgo_AsDes.def(py::init<>());
	cls_BRepAlgo_AsDes.def("Clear", (void (BRepAlgo_AsDes::*)()) &BRepAlgo_AsDes::Clear, "None");
	cls_BRepAlgo_AsDes.def("Add", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_AsDes::Add, "Stores <SS> as a futur subshape of <S>.", py::arg("S"), py::arg("SS"));
	cls_BRepAlgo_AsDes.def("Add", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepAlgo_AsDes::Add, "Stores <SS> as futurs SubShapes of <S>.", py::arg("S"), py::arg("SS"));
	cls_BRepAlgo_AsDes.def("HasAscendant", (Standard_Boolean (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const ) &BRepAlgo_AsDes::HasAscendant, "None", py::arg("S"));
	cls_BRepAlgo_AsDes.def("HasDescendant", (Standard_Boolean (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const ) &BRepAlgo_AsDes::HasDescendant, "None", py::arg("S"));
	cls_BRepAlgo_AsDes.def("Ascendant", (const TopTools_ListOfShape & (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const ) &BRepAlgo_AsDes::Ascendant, "Returns the Shape containing <S>.", py::arg("S"));
	cls_BRepAlgo_AsDes.def("Descendant", (const TopTools_ListOfShape & (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const ) &BRepAlgo_AsDes::Descendant, "Returns futur subhapes of <S>.", py::arg("S"));
	cls_BRepAlgo_AsDes.def("ChangeDescendant", (TopTools_ListOfShape & (BRepAlgo_AsDes::*)(const TopoDS_Shape &)) &BRepAlgo_AsDes::ChangeDescendant, "Returns futur subhapes of <S>.", py::arg("S"));
	cls_BRepAlgo_AsDes.def("Replace", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_AsDes::Replace, "Replace <OldS> by <NewS>. <OldS> disapear from <me>.", py::arg("OldS"), py::arg("NewS"));
	cls_BRepAlgo_AsDes.def("Remove", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &)) &BRepAlgo_AsDes::Remove, "Remove <S> from me.", py::arg("S"));
	cls_BRepAlgo_AsDes.def("HasCommonDescendant", (Standard_Boolean (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &) const ) &BRepAlgo_AsDes::HasCommonDescendant, "Returns True if (S1> and <S2> has common Descendants. Stores in <LC> the Commons Descendants.", py::arg("S1"), py::arg("S2"), py::arg("LC"));
	cls_BRepAlgo_AsDes.def_static("get_type_name_", (const char * (*)()) &BRepAlgo_AsDes::get_type_name, "None");
	cls_BRepAlgo_AsDes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAlgo_AsDes::get_type_descriptor, "None");
	cls_BRepAlgo_AsDes.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAlgo_AsDes::*)() const ) &BRepAlgo_AsDes::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_BooleanOperation.hxx
	py::class_<BRepAlgo_BooleanOperation, std::unique_ptr<BRepAlgo_BooleanOperation, Deleter<BRepAlgo_BooleanOperation>>, BRepBuilderAPI_MakeShape> cls_BRepAlgo_BooleanOperation(mod, "BRepAlgo_BooleanOperation", "The abstract class BooleanOperation is the root class of Boolean operations. A BooleanOperation object stores the two shapes in preparation for the Boolean operation specified in one of the classes inheriting from this one. These include: - Common - Cut - Fuse - Section.");
	cls_BRepAlgo_BooleanOperation.def("PerformDS", (void (BRepAlgo_BooleanOperation::*)()) &BRepAlgo_BooleanOperation::PerformDS, "None");
	cls_BRepAlgo_BooleanOperation.def("Perform", (void (BRepAlgo_BooleanOperation::*)(const TopAbs_State, const TopAbs_State)) &BRepAlgo_BooleanOperation::Perform, "None", py::arg("St1"), py::arg("St2"));
	cls_BRepAlgo_BooleanOperation.def("Builder", (opencascade::handle<TopOpeBRepBuild_HBuilder> (BRepAlgo_BooleanOperation::*)() const ) &BRepAlgo_BooleanOperation::Builder, "None");
	cls_BRepAlgo_BooleanOperation.def("Shape1", (const TopoDS_Shape & (BRepAlgo_BooleanOperation::*)() const ) &BRepAlgo_BooleanOperation::Shape1, "Returns the first shape involved in this Boolean operation.");
	cls_BRepAlgo_BooleanOperation.def("Shape2", (const TopoDS_Shape & (BRepAlgo_BooleanOperation::*)() const ) &BRepAlgo_BooleanOperation::Shape2, "Returns the second shape involved in this Boolean operation.");
	cls_BRepAlgo_BooleanOperation.def("Modified", (const TopTools_ListOfShape & (BRepAlgo_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperation::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
	cls_BRepAlgo_BooleanOperation.def("IsDeleted", (Standard_Boolean (BRepAlgo_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperation::IsDeleted, "None", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Fuse.hxx
	py::class_<BRepAlgo_Fuse, std::unique_ptr<BRepAlgo_Fuse, Deleter<BRepAlgo_Fuse>>, BRepAlgo_BooleanOperation> cls_BRepAlgo_Fuse(mod, "BRepAlgo_Fuse", "Describes functions for performing a topological fusion operation (Boolean union). A Fuse object provides the framework for: - defining the construction of a fused shape, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepAlgo_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Cut.hxx
	py::class_<BRepAlgo_Cut, std::unique_ptr<BRepAlgo_Cut, Deleter<BRepAlgo_Cut>>, BRepAlgo_BooleanOperation> cls_BRepAlgo_Cut(mod, "BRepAlgo_Cut", "Describes functions for performing a topological cut operation (Boolean subtraction). A Cut object provides the framework for: - defining the construction of a cut shape, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepAlgo_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Common.hxx
	py::class_<BRepAlgo_Common, std::unique_ptr<BRepAlgo_Common, Deleter<BRepAlgo_Common>>, BRepAlgo_BooleanOperation> cls_BRepAlgo_Common(mod, "BRepAlgo_Common", "Describes functions for performing a topological common operation (Boolean intersection). A Common object provides the framework for: - defining the construction of a common shape, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepAlgo_Common.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Section.hxx
	py::class_<BRepAlgo_Section, std::unique_ptr<BRepAlgo_Section, Deleter<BRepAlgo_Section>>, BRepAlgo_BooleanOperation> cls_BRepAlgo_Section(mod, "BRepAlgo_Section", "Construction of the section lines between two shapes. For this Boolean operation, each face of the first shape is intersected by each face of the second shape. The resulting intersection edges are brought together into a compound object, but not chained or grouped into wires. Computation of the intersection of two Shapes or Surfaces The two parts involved in this Boolean operation may be defined from geometric surfaces: the most common use is the computation of the planar section of a shape. A Section object provides the framework for: - defining the shapes to be intersected, and the computation options, - implementing the construction algorithm, and - consulting the result. Example : giving two shapes S1,S2 accessing faces, let compute the section edges R on S1,S2, performing approximation on new curves, performing PCurve on part 1 but not on part 2 : Standard_Boolean PerformNow = Standard_False; BRepBoolAPI_Section S(S1,S2,PerformNow); S.ComputePCurveOn1(Standard_True); S.Approximation(Standard_True); S.Build(); TopoDS_Shape R = S.Shape(); On Null Shapes of geometries, NotDone() is called.");
	cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Sh1"), py::arg("Sh2"));
	cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sh1"), py::arg("Sh2"), py::arg("PerformNow"));
	cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("Sh"), py::arg("Pl"));
	cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &, const Standard_Boolean>(), py::arg("Sh"), py::arg("Pl"), py::arg("PerformNow"));
	cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sh"), py::arg("Sf"));
	cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sh"), py::arg("Sf"), py::arg("PerformNow"));
	cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &>(), py::arg("Sf"), py::arg("Sh"));
	cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sf"), py::arg("Sh"), py::arg("PerformNow"));
	cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sf1"), py::arg("Sf2"));
	cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sf1"), py::arg("Sf2"), py::arg("PerformNow"));
	cls_BRepAlgo_Section.def("Init1", (void (BRepAlgo_Section::*)(const TopoDS_Shape &)) &BRepAlgo_Section::Init1, "Initializes the first part", py::arg("S1"));
	cls_BRepAlgo_Section.def("Init1", (void (BRepAlgo_Section::*)(const gp_Pln &)) &BRepAlgo_Section::Init1, "Initializes the first part", py::arg("Pl"));
	cls_BRepAlgo_Section.def("Init1", (void (BRepAlgo_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgo_Section::Init1, "Initializes the first part", py::arg("Sf"));
	cls_BRepAlgo_Section.def("Init2", (void (BRepAlgo_Section::*)(const TopoDS_Shape &)) &BRepAlgo_Section::Init2, "initialize second part", py::arg("S2"));
	cls_BRepAlgo_Section.def("Init2", (void (BRepAlgo_Section::*)(const gp_Pln &)) &BRepAlgo_Section::Init2, "Initializes the second part", py::arg("Pl"));
	cls_BRepAlgo_Section.def("Init2", (void (BRepAlgo_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgo_Section::Init2, "This and the above algorithms reinitialize the first and the second parts on which this algorithm is going to perform the intersection computation. This is done with either: the surface Sf, the plane Pl or the shape Sh. You use the function Build to construct the result.", py::arg("Sf"));
	cls_BRepAlgo_Section.def("Approximation", (void (BRepAlgo_Section::*)(const Standard_Boolean)) &BRepAlgo_Section::Approximation, "Defines an option for computation of further intersections. This computation will be performed by the function Build in this framework. By default, the underlying 3D geometry attached to each elementary edge of the result of a computed intersection is: - analytic where possible, provided the corresponding geometry corresponds to a type of analytic curve defined in the Geom package; for example the intersection of a cylindrical shape with a plane gives an ellipse or a circle; - or elsewhere, given as a succession of points grouped together in a BSpline curve of degree 1. If Approx equals true, when further computations are performed in this framework with the function Build, these edges will have an attached 3D geometry which is a BSpline approximation of the computed set of points. Note that as a result, approximations will be computed on edges built only on new intersection lines.", py::arg("B"));
	cls_BRepAlgo_Section.def("ComputePCurveOn1", (void (BRepAlgo_Section::*)(const Standard_Boolean)) &BRepAlgo_Section::ComputePCurveOn1, "Indicates if the Pcurve must be (or not) performed on first part.", py::arg("B"));
	cls_BRepAlgo_Section.def("ComputePCurveOn2", (void (BRepAlgo_Section::*)(const Standard_Boolean)) &BRepAlgo_Section::ComputePCurveOn2, "Define options for the computation of further intersections which will be performed by the function Build in this framework. By default, no parametric 2D curve (pcurve) is defined for the elementary edges of the result. If ComputePCurve1 equals true, further computations performed in this framework with the function Build will attach an additional pcurve in the parametric space of the first shape to the constructed edges. If ComputePCurve2 equals true, the additional pcurve will be attached to the constructed edges in the parametric space of the second shape. These two functions may be used together. Note that as a result, pcurves will only be added onto edges built on new intersection lines.", py::arg("B"));
	cls_BRepAlgo_Section.def("Build", (void (BRepAlgo_Section::*)()) &BRepAlgo_Section::Build, "Performs the computation of the section lines between the two parts defined at the time of construction of this framework or reinitialized with the Init1 and Init2 functions. The constructed shape will be returned by the function Shape. This is a compound object composed of edges. These intersection edges may be built: - on new intersection lines, or - on coincident portions of edges in the two intersected shapes. These intersection edges are independent: they are not chained or grouped into wires. If no intersection edge exists, the result is an empty compound object. The shapes involved in the construction of the section lines can be retrieved with the function Shape1 or Shape2. Note that other objects than TopoDS_Shape shapes given as arguments at the construction time of this framework, or to the Init1 or Init2 function, are converted into faces or shells before performing the computation of the intersection. Parametric 2D curves on intersection edges No parametric 2D curve (pcurve) is defined for the elementary edges of the result. To attach parametric curves like this to the constructed edges you have to use: - the function ComputePCurveOn1 to ask for the additional computation of a pcurve in the parametric space of the first shape, - the function ComputePCurveOn2 to ask for the additional computation of a pcurve in the parametric space of the second shape. This must be done before calling this function. Note that as a result, pcurves are added on edges built on new intersection lines only. Approximation of intersection edges The underlying 3D geometry attached to each elementary edge of the result is: - analytic where possible provided the corresponding geometry corresponds to a type of analytic curve defined in the Geom package; for example, the intersection of a cylindrical shape with a plane gives an ellipse or a circle; or - elsewhere, given as a succession of points grouped together in a BSpline curve of degree 1. If, on computed elementary intersection edges whose underlying geometry is not analytic, you prefer to have an attached 3D geometry which is a BSpline approximation of the computed set of points, you have to use the function Approximation to ask for this computation option before calling this function. You may also have combined these computation options: look at the example given above to illustrate the use of the constructors.");
	cls_BRepAlgo_Section.def("HasAncestorFaceOn1", (Standard_Boolean (BRepAlgo_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &BRepAlgo_Section::HasAncestorFaceOn1, "Identifies the ancestor faces of the new intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn1 gives the ancestor face in the first shape, and These functions return: - true if an ancestor face F is found, or - false if not. An ancestor face is identifiable for the edge E if the three following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm, - the edge E is built on an intersection curve. In other words, E is a new edge built on the intersection curve, not on edges belonging to the intersecting shapes. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true.", py::arg("E"), py::arg("F"));
	cls_BRepAlgo_Section.def("HasAncestorFaceOn2", (Standard_Boolean (BRepAlgo_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const ) &BRepAlgo_Section::HasAncestorFaceOn2, "Identifies the ancestor faces of the new intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn2 gives the ancestor face in the second shape. These functions return: - true if an ancestor face F is found, or - false if not. An ancestor face is identifiable for the edge E if the three following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm, - the edge E is built on an intersection curve. In other words, E is a new edge built on the intersection curve, not on edges belonging to the intersecting shapes. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true.", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Loop.hxx
	py::class_<BRepAlgo_Loop, std::unique_ptr<BRepAlgo_Loop, Deleter<BRepAlgo_Loop>>> cls_BRepAlgo_Loop(mod, "BRepAlgo_Loop", "Builds the loops from a set of edges on a face.");
	cls_BRepAlgo_Loop.def(py::init<>());
	cls_BRepAlgo_Loop.def("Init", (void (BRepAlgo_Loop::*)(const TopoDS_Face &)) &BRepAlgo_Loop::Init, "Init with <F> the set of edges must have pcurves on <F>.", py::arg("F"));
	cls_BRepAlgo_Loop.def("AddEdge", (void (BRepAlgo_Loop::*)(TopoDS_Edge &, const TopTools_ListOfShape &)) &BRepAlgo_Loop::AddEdge, "Add E with <LV>. <E> will be copied and trim by vertices in <LV>.", py::arg("E"), py::arg("LV"));
	cls_BRepAlgo_Loop.def("AddConstEdge", (void (BRepAlgo_Loop::*)(const TopoDS_Edge &)) &BRepAlgo_Loop::AddConstEdge, "Add <E> as const edge, E can be in the result.", py::arg("E"));
	cls_BRepAlgo_Loop.def("AddConstEdges", (void (BRepAlgo_Loop::*)(const TopTools_ListOfShape &)) &BRepAlgo_Loop::AddConstEdges, "Add <LE> as a set of const edges.", py::arg("LE"));
	cls_BRepAlgo_Loop.def("Perform", (void (BRepAlgo_Loop::*)()) &BRepAlgo_Loop::Perform, "Make loops.");
	cls_BRepAlgo_Loop.def("CutEdge", (void (BRepAlgo_Loop::*)(const TopoDS_Edge &, const TopTools_ListOfShape &, TopTools_ListOfShape &) const ) &BRepAlgo_Loop::CutEdge, "Cut the edge <E> in several edges <NE> on the vertices<VonE>.", py::arg("E"), py::arg("VonE"), py::arg("NE"));
	cls_BRepAlgo_Loop.def("NewWires", (const TopTools_ListOfShape & (BRepAlgo_Loop::*)() const ) &BRepAlgo_Loop::NewWires, "Returns the list of wires performed. can be an empty list.");
	cls_BRepAlgo_Loop.def("WiresToFaces", (void (BRepAlgo_Loop::*)()) &BRepAlgo_Loop::WiresToFaces, "Build faces from the wires result.");
	cls_BRepAlgo_Loop.def("NewFaces", (const TopTools_ListOfShape & (BRepAlgo_Loop::*)() const ) &BRepAlgo_Loop::NewFaces, "Returns the list of faces. Warning: The method <WiresToFaces> as to be called before. can be an empty list.");
	cls_BRepAlgo_Loop.def("NewEdges", (const TopTools_ListOfShape & (BRepAlgo_Loop::*)(const TopoDS_Edge &) const ) &BRepAlgo_Loop::NewEdges, "Returns the list of new edges built from an edge <E> it can be an empty list.", py::arg("E"));
	cls_BRepAlgo_Loop.def("GetVerticesForSubstitute", (void (BRepAlgo_Loop::*)(TopTools_DataMapOfShapeShape &) const ) &BRepAlgo_Loop::GetVerticesForSubstitute, "Returns the datamap of vertices with their substitutes.", py::arg("VerVerMap"));
	cls_BRepAlgo_Loop.def("VerticesForSubstitute", (void (BRepAlgo_Loop::*)(TopTools_DataMapOfShapeShape &)) &BRepAlgo_Loop::VerticesForSubstitute, "None", py::arg("VerVerMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_Tool.hxx
	py::class_<BRepAlgo_Tool, std::unique_ptr<BRepAlgo_Tool, Deleter<BRepAlgo_Tool>>> cls_BRepAlgo_Tool(mod, "BRepAlgo_Tool", "None");
	cls_BRepAlgo_Tool.def(py::init<>());
	cls_BRepAlgo_Tool.def_static("Deboucle3D_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopTools_MapOfShape &)) &BRepAlgo_Tool::Deboucle3D, "Remove the non valid part of an offsetshape 1 - Remove all the free boundary and the faces connex to such edges. 2 - Remove all the shapes not valid in the result (according to the side of offseting) in this verion only the first point is implemented.", py::arg("S"), py::arg("Boundary"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_FaceRestrictor.hxx
	py::class_<BRepAlgo_FaceRestrictor, std::unique_ptr<BRepAlgo_FaceRestrictor, Deleter<BRepAlgo_FaceRestrictor>>> cls_BRepAlgo_FaceRestrictor(mod, "BRepAlgo_FaceRestrictor", "Builds all the faces limited with a set of non jointing and planars wires. if <ControlOrientation> is false The Wires must have correct orientations. Sinon orientation des wires de telle sorte que les faces ne soient pas infinies et qu'elles soient disjointes.");
	cls_BRepAlgo_FaceRestrictor.def(py::init<>());
	cls_BRepAlgo_FaceRestrictor.def("Init", [](BRepAlgo_FaceRestrictor &self, const TopoDS_Face & a0) -> void { return self.Init(a0); }, py::arg("F"));
	cls_BRepAlgo_FaceRestrictor.def("Init", [](BRepAlgo_FaceRestrictor &self, const TopoDS_Face & a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); }, py::arg("F"), py::arg("Proj"));
	cls_BRepAlgo_FaceRestrictor.def("Init", (void (BRepAlgo_FaceRestrictor::*)(const TopoDS_Face &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgo_FaceRestrictor::Init, "the surface of <F> will be the the surface of each new faces built. <Proj> is used to update pcurves on edges if necessary. See Add().", py::arg("F"), py::arg("Proj"), py::arg("ControlOrientation"));
	cls_BRepAlgo_FaceRestrictor.def("Add", (void (BRepAlgo_FaceRestrictor::*)(TopoDS_Wire &)) &BRepAlgo_FaceRestrictor::Add, "Add the wire <W> to the set of wires.", py::arg("W"));
	cls_BRepAlgo_FaceRestrictor.def("Clear", (void (BRepAlgo_FaceRestrictor::*)()) &BRepAlgo_FaceRestrictor::Clear, "Removes all the Wires");
	cls_BRepAlgo_FaceRestrictor.def("Perform", (void (BRepAlgo_FaceRestrictor::*)()) &BRepAlgo_FaceRestrictor::Perform, "Evaluate all the faces limited by the set of Wires.");
	cls_BRepAlgo_FaceRestrictor.def("IsDone", (Standard_Boolean (BRepAlgo_FaceRestrictor::*)() const ) &BRepAlgo_FaceRestrictor::IsDone, "None");
	cls_BRepAlgo_FaceRestrictor.def("More", (Standard_Boolean (BRepAlgo_FaceRestrictor::*)() const ) &BRepAlgo_FaceRestrictor::More, "None");
	cls_BRepAlgo_FaceRestrictor.def("Next", (void (BRepAlgo_FaceRestrictor::*)()) &BRepAlgo_FaceRestrictor::Next, "None");
	cls_BRepAlgo_FaceRestrictor.def("Current", (TopoDS_Face (BRepAlgo_FaceRestrictor::*)() const ) &BRepAlgo_FaceRestrictor::Current, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_BooleanOperations.hxx
	py::class_<BRepAlgo_BooleanOperations, std::unique_ptr<BRepAlgo_BooleanOperations, Deleter<BRepAlgo_BooleanOperations>>> cls_BRepAlgo_BooleanOperations(mod, "BRepAlgo_BooleanOperations", "None");
	cls_BRepAlgo_BooleanOperations.def(py::init<>());
	cls_BRepAlgo_BooleanOperations.def("Shapes2d", (void (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::Shapes2d, "S1 is a Shell with ALL faces supported by the SAME S2 is an Edge INCLUDED in that surface with pcurve. this avoids a time-consuming 3D operation, compared to Shapes.", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_BooleanOperations.def("Shapes", (void (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::Shapes, "Defines the arguments.", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_BooleanOperations.def("SetApproxParameters", (void (BRepAlgo_BooleanOperations::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &BRepAlgo_BooleanOperations::SetApproxParameters, "Sets different parameters for the curve approximations : NbPntMax : Maximum number of points to be approximated at the same time in one curve. Tol3D, Tol2D : Tolerances to be reached by the approximation. RelativeTol : The given tolerances are relative.", py::arg("NbPntMax"), py::arg("Tol3D"), py::arg("Tol2D"));
	cls_BRepAlgo_BooleanOperations.def("Define", (void (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &, const TopoDS_Shape &, opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &BRepAlgo_BooleanOperations::Define, "None", py::arg("S1"), py::arg("S2"), py::arg("HDS"));
	cls_BRepAlgo_BooleanOperations.def("Common", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Common, "returns the common part of the shapes.");
	cls_BRepAlgo_BooleanOperations.def("Fus", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Fus, "returns the fuse part of the shapes.");
	cls_BRepAlgo_BooleanOperations.def("Cut", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Cut, "returns the cut part of the shapes.");
	cls_BRepAlgo_BooleanOperations.def("Section", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Section, "returns the intersection of the shapes.");
	cls_BRepAlgo_BooleanOperations.def("Shape", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Shape, "returns the result of the boolean operation.");
	cls_BRepAlgo_BooleanOperations.def("ShapeFrom", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::ShapeFrom, "Returns the shape(s) resulting of the boolean operation issued from the shape <S>.", py::arg("S"));
	cls_BRepAlgo_BooleanOperations.def("Modified", (const TopTools_ListOfShape & (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::Modified, "Returns the list of the descendant shapes of the shape <S>.", py::arg("S"));
	cls_BRepAlgo_BooleanOperations.def("IsDeleted", (Standard_Boolean (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::IsDeleted, "Returns the fact that the shape <S> has been deleted or not by the boolean operation.", py::arg("S"));
	cls_BRepAlgo_BooleanOperations.def("DataStructure", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_BooleanOperations::*)() const ) &BRepAlgo_BooleanOperations::DataStructure, "None");
	cls_BRepAlgo_BooleanOperations.def("ChangeDataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::ChangeDataStructure, "None");
	cls_BRepAlgo_BooleanOperations.def("Builder", (const opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_BooleanOperations::*)() const ) &BRepAlgo_BooleanOperations::Builder, "None");
	cls_BRepAlgo_BooleanOperations.def("ChangeBuilder", (opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::ChangeBuilder, "None");
	cls_BRepAlgo_BooleanOperations.def("DataStructureAccess", (BRepAlgo_DSAccess & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::DataStructureAccess, "returns the member myDSA. It is useful to then access the method GetSectionEdgeSet (wich is a member of DSAccess)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_DSAccess.hxx
	py::class_<BRepAlgo_DSAccess, std::unique_ptr<BRepAlgo_DSAccess, Deleter<BRepAlgo_DSAccess>>> cls_BRepAlgo_DSAccess(mod, "BRepAlgo_DSAccess", "None");
	cls_BRepAlgo_DSAccess.def(py::init<>());
	cls_BRepAlgo_DSAccess.def("Init", (void (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::Init, "Clears the internal data structure, including the");
	cls_BRepAlgo_DSAccess.def("Load", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::Load, "Loads the shape in DS.", py::arg("S"));
	cls_BRepAlgo_DSAccess.def("Load", (void (BRepAlgo_DSAccess::*)(TopoDS_Shape &, TopoDS_Shape &)) &BRepAlgo_DSAccess::Load, "Loads two shapes in the DS without intersecting them.", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_DSAccess.def("Intersect", (void (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::Intersect, "Intersects two shapes at input and loads the DS with their intersection. Clears the TopOpeBRepBuild_HBuilder if necessary");
	cls_BRepAlgo_DSAccess.def("Intersect", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::Intersect, "Intersects the faces contained in two given shapes and loads them in the DS. Clears the TopOpeBRepBuild_HBuilder if necessary", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_DSAccess.def("SameDomain", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::SameDomain, "This method does the same thing as the previous, but faster. There is no intersection face/face 3D. The faces have the same support(surface). No test of tangency (that is why it is faster). Intersects in 2d the faces tangent F1 anf F2.", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_DSAccess.def("GetSectionEdgeSet", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::GetSectionEdgeSet, "returns compounds of Edge connected with section, which contains sections between faces contained in S1 and S2. returns an empty list of Shape if S1 or S2 do not contain face. calls GetSectionEdgeSet() if it has not already been done", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_DSAccess.def("GetSectionEdgeSet", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::GetSectionEdgeSet, "returns all compounds of edges connected with section contained in the DS");
	cls_BRepAlgo_DSAccess.def("IsWire", (Standard_Boolean (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::IsWire, "NYI", py::arg("Compound"));
	cls_BRepAlgo_DSAccess.def("Wire", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::Wire, "NYI", py::arg("Compound"));
	cls_BRepAlgo_DSAccess.def("SectionVertex", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::SectionVertex, "NYI returns the vertex of section, which contains the section between face S1 and edge S2 (returns an empty Shape if S1 is not a face or if S2 is not an edge)", py::arg("S1"), py::arg("S2"));
	cls_BRepAlgo_DSAccess.def("SuppressEdgeSet", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::SuppressEdgeSet, "Invalidates a complete line of section. All Edges connected by Vertex or a Wire. Can be a group of connected Edges, which do not form a standard Wire.", py::arg("Compound"));
	cls_BRepAlgo_DSAccess.def("ChangeEdgeSet", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::ChangeEdgeSet, "Modifies a line of section. <New> -- should be a Group of Edges connected by Vertex. -- Can be a Wire. Can be a group of connected Edges that do not form a standard Wire. <New> should be sub-groupn of <Old>", py::arg("Old"), py::arg("New"));
	cls_BRepAlgo_DSAccess.def("SuppressSectionVertex", (void (BRepAlgo_DSAccess::*)(const TopoDS_Vertex &)) &BRepAlgo_DSAccess::SuppressSectionVertex, "NYI Make invalid a Vertex of section. The Vertex shoud be reconstructed from a point.", py::arg("V"));
	cls_BRepAlgo_DSAccess.def("Merge", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopAbs_State, const TopAbs_State)) &BRepAlgo_DSAccess::Merge, "None", py::arg("state1"), py::arg("state2"));
	cls_BRepAlgo_DSAccess.def("Merge", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopAbs_State)) &BRepAlgo_DSAccess::Merge, "None", py::arg("state1"));
	cls_BRepAlgo_DSAccess.def("Propagate", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopAbs_State, const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::Propagate, "NYI Propagation of a state starting from the shape FromShape = edge or vertex of section, face or Coumpound de section. LoadShape is either S1, or S2 (see the method Load). Propagation from FromShape, on the states <what> of LoadShape. Return a Wire in 2d, a Shell in 3d. Specifications are incomplete, to be redefined for the typologies correpsonding to <FromShape> and the result : exemple : FromShape resultat vertex wire (or edge) edge of section face (or shell) compound of section shell ... ...", py::arg("what"), py::arg("FromShape"), py::arg("LoadShape"));
	cls_BRepAlgo_DSAccess.def("PropagateFromSection", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::PropagateFromSection, "SectionShape est soit un Vertex de section(NYI), soit une Edge de section. Propagation des shapes de section en partant de SectionShape. return un Compound de section.", py::arg("SectionShape"));
	cls_BRepAlgo_DSAccess.def("Modified", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::Modified, "Returns the list of the descendant shapes of the shape <S>.", py::arg("S"));
	// cls_BRepAlgo_DSAccess.def("IsDeleted", (Standard_Boolean (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::IsDeleted, "Returns the fact that the shape <S> has been deleted or not by the boolean operation.", py::arg("S"));
	cls_BRepAlgo_DSAccess.def("Check", (BRepAlgo_CheckStatus (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::Check, "NYI coherence of the internal Data Structure.");
	cls_BRepAlgo_DSAccess.def("DS", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_DSAccess::*)() const ) &BRepAlgo_DSAccess::DS, "None");
	cls_BRepAlgo_DSAccess.def("ChangeDS", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::ChangeDS, "None");
	cls_BRepAlgo_DSAccess.def("Builder", (const opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_DSAccess::*)() const ) &BRepAlgo_DSAccess::Builder, "None");
	cls_BRepAlgo_DSAccess.def("ChangeBuilder", (opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::ChangeBuilder, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_EdgeConnector.hxx
	py::class_<BRepAlgo_EdgeConnector, opencascade::handle<BRepAlgo_EdgeConnector>, Standard_Transient> cls_BRepAlgo_EdgeConnector(mod, "BRepAlgo_EdgeConnector", "Used by DSAccess to reconstruct an EdgeSet of connected edges. The result produced by MakeBlock is a list of non-standard TopoDS_wire, which can present connexions of edge of order > 2 in certain vertex. The method IsWire indicates standard/non-standard character of all wire produced.");
	cls_BRepAlgo_EdgeConnector.def(py::init<>());
	cls_BRepAlgo_EdgeConnector.def("Add", (void (BRepAlgo_EdgeConnector::*)(const TopoDS_Edge &)) &BRepAlgo_EdgeConnector::Add, "None", py::arg("e"));
	cls_BRepAlgo_EdgeConnector.def("Add", (void (BRepAlgo_EdgeConnector::*)(TopTools_ListOfShape &)) &BRepAlgo_EdgeConnector::Add, "None", py::arg("LOEdge"));
	cls_BRepAlgo_EdgeConnector.def("AddStart", (void (BRepAlgo_EdgeConnector::*)(const TopoDS_Shape &)) &BRepAlgo_EdgeConnector::AddStart, "None", py::arg("e"));
	cls_BRepAlgo_EdgeConnector.def("AddStart", (void (BRepAlgo_EdgeConnector::*)(TopTools_ListOfShape &)) &BRepAlgo_EdgeConnector::AddStart, "None", py::arg("LOEdge"));
	cls_BRepAlgo_EdgeConnector.def("ClearStartElement", (void (BRepAlgo_EdgeConnector::*)()) &BRepAlgo_EdgeConnector::ClearStartElement, "None");
	cls_BRepAlgo_EdgeConnector.def("MakeBlock", (TopTools_ListOfShape & (BRepAlgo_EdgeConnector::*)()) &BRepAlgo_EdgeConnector::MakeBlock, "returns a list of wire non standard");
	cls_BRepAlgo_EdgeConnector.def("Done", (void (BRepAlgo_EdgeConnector::*)()) &BRepAlgo_EdgeConnector::Done, "None");
	cls_BRepAlgo_EdgeConnector.def("IsDone", (Standard_Boolean (BRepAlgo_EdgeConnector::*)() const ) &BRepAlgo_EdgeConnector::IsDone, "NYI returns true if proceeded to MakeBlock()");
	cls_BRepAlgo_EdgeConnector.def("IsWire", (Standard_Boolean (BRepAlgo_EdgeConnector::*)(const TopoDS_Shape &)) &BRepAlgo_EdgeConnector::IsWire, "NYI returns true if W is a Wire standard. W must belong to the list returned by MakeBlock.", py::arg("W"));
	cls_BRepAlgo_EdgeConnector.def_static("get_type_name_", (const char * (*)()) &BRepAlgo_EdgeConnector::get_type_name, "None");
	cls_BRepAlgo_EdgeConnector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAlgo_EdgeConnector::get_type_descriptor, "None");
	cls_BRepAlgo_EdgeConnector.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAlgo_EdgeConnector::*)() const ) &BRepAlgo_EdgeConnector::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_NormalProjection.hxx
	py::class_<BRepAlgo_NormalProjection, std::unique_ptr<BRepAlgo_NormalProjection, Deleter<BRepAlgo_NormalProjection>>> cls_BRepAlgo_NormalProjection(mod, "BRepAlgo_NormalProjection", "This class makes the projection of a wire on a shape.");
	cls_BRepAlgo_NormalProjection.def(py::init<>());
	cls_BRepAlgo_NormalProjection.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_BRepAlgo_NormalProjection.def("Init", (void (BRepAlgo_NormalProjection::*)(const TopoDS_Shape &)) &BRepAlgo_NormalProjection::Init, "None", py::arg("S"));
	cls_BRepAlgo_NormalProjection.def("Add", (void (BRepAlgo_NormalProjection::*)(const TopoDS_Shape &)) &BRepAlgo_NormalProjection::Add, "Add an edge or a wire to the list of shape to project", py::arg("ToProj"));
	cls_BRepAlgo_NormalProjection.def("SetParams", (void (BRepAlgo_NormalProjection::*)(const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepAlgo_NormalProjection::SetParams, "Set the parameters used for computation Tol3d is the requiered tolerance between the 3d projected curve and its 2d representation InternalContinuity is the order of constraints used for approximation. MaxDeg and MaxSeg are the maximum degree and the maximum number of segment for BSpline resulting of an approximation.", py::arg("Tol3D"), py::arg("Tol2D"), py::arg("InternalContinuity"), py::arg("MaxDegree"), py::arg("MaxSeg"));
	cls_BRepAlgo_NormalProjection.def("SetDefaultParams", (void (BRepAlgo_NormalProjection::*)()) &BRepAlgo_NormalProjection::SetDefaultParams, "Set the parameters used for computation in their default values");
	cls_BRepAlgo_NormalProjection.def("SetMaxDistance", (void (BRepAlgo_NormalProjection::*)(const Standard_Real)) &BRepAlgo_NormalProjection::SetMaxDistance, "Sets the maximum distance between target shape and shape to project. If this condition is not satisfied then corresponding part of solution is discarded. if MaxDist < 0 then this method does not affect the algorithm", py::arg("MaxDist"));
	cls_BRepAlgo_NormalProjection.def("Compute3d", [](BRepAlgo_NormalProjection &self) -> void { return self.Compute3d(); });
	cls_BRepAlgo_NormalProjection.def("Compute3d", (void (BRepAlgo_NormalProjection::*)(const Standard_Boolean)) &BRepAlgo_NormalProjection::Compute3d, "if With3d = Standard_False the 3dcurve is not computed the initial 3dcurve is kept to build the resulting edges.", py::arg("With3d"));
	cls_BRepAlgo_NormalProjection.def("SetLimit", [](BRepAlgo_NormalProjection &self) -> void { return self.SetLimit(); });
	cls_BRepAlgo_NormalProjection.def("SetLimit", (void (BRepAlgo_NormalProjection::*)(const Standard_Boolean)) &BRepAlgo_NormalProjection::SetLimit, "Manage limitation of projected edges.", py::arg("FaceBoundaries"));
	cls_BRepAlgo_NormalProjection.def("Build", (void (BRepAlgo_NormalProjection::*)()) &BRepAlgo_NormalProjection::Build, "Builds the result as a compound.");
	cls_BRepAlgo_NormalProjection.def("IsDone", (Standard_Boolean (BRepAlgo_NormalProjection::*)() const ) &BRepAlgo_NormalProjection::IsDone, "None");
	cls_BRepAlgo_NormalProjection.def("Projection", (const TopoDS_Shape & (BRepAlgo_NormalProjection::*)() const ) &BRepAlgo_NormalProjection::Projection, "returns the result");
	cls_BRepAlgo_NormalProjection.def("Ancestor", (const TopoDS_Shape & (BRepAlgo_NormalProjection::*)(const TopoDS_Edge &) const ) &BRepAlgo_NormalProjection::Ancestor, "For a resulting edge, returns the corresponding initial edge.", py::arg("E"));
	cls_BRepAlgo_NormalProjection.def("Couple", (const TopoDS_Shape & (BRepAlgo_NormalProjection::*)(const TopoDS_Edge &) const ) &BRepAlgo_NormalProjection::Couple, "For a projected edge, returns the corresponding initial face.", py::arg("E"));
	cls_BRepAlgo_NormalProjection.def("Generated", (const TopTools_ListOfShape & (BRepAlgo_NormalProjection::*)(const TopoDS_Shape &)) &BRepAlgo_NormalProjection::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
	cls_BRepAlgo_NormalProjection.def("IsElementary", (Standard_Boolean (BRepAlgo_NormalProjection::*)(const Adaptor3d_Curve &) const ) &BRepAlgo_NormalProjection::IsElementary, "None", py::arg("C"));
	cls_BRepAlgo_NormalProjection.def("BuildWire", (Standard_Boolean (BRepAlgo_NormalProjection::*)(TopTools_ListOfShape &) const ) &BRepAlgo_NormalProjection::BuildWire, "build the result as a list of wire if possible in -- a first returns a wire only if there is only a wire.", py::arg("Liste"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo.hxx
	py::class_<BRepAlgo, std::unique_ptr<BRepAlgo, Deleter<BRepAlgo>>> cls_BRepAlgo(mod, "BRepAlgo", "The BRepAlgo package provides a full range of services to perform Old Boolean Operations in Open CASCADE. Attention: The New Boolean Operation has replaced the Old Boolean Operations algorithm in the BrepAlgoAPI package in Open CASCADE.");
	cls_BRepAlgo.def(py::init<>());
	cls_BRepAlgo.def_static("ConcatenateWire_", [](const TopoDS_Wire & a0, const GeomAbs_Shape a1) -> TopoDS_Wire { return BRepAlgo::ConcatenateWire(a0, a1); }, py::arg("Wire"), py::arg("Option"));
	cls_BRepAlgo.def_static("ConcatenateWire_", (TopoDS_Wire (*)(const TopoDS_Wire &, const GeomAbs_Shape, const Standard_Real)) &BRepAlgo::ConcatenateWire, "this method makes a wire whose edges are C1 from a Wire whose edges could be G1. It removes a vertex between G1 edges. Option can be G1 or C1.", py::arg("Wire"), py::arg("Option"), py::arg("AngularTolerance"));
	cls_BRepAlgo.def_static("ConcatenateWireC0_", (TopoDS_Edge (*)(const TopoDS_Wire &)) &BRepAlgo::ConcatenateWireC0, "this method makes an edge from a wire. Junction points between edges of wire may be sharp, resulting curve of the resulting edge may be C0.", py::arg("Wire"));
	cls_BRepAlgo.def_static("IsValid_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepAlgo::IsValid, "Checks if the shape is 'correct'. If not, returns <Standard_False>, else returns <Standard_True>.", py::arg("S"));
	cls_BRepAlgo.def_static("IsValid_", [](const TopTools_ListOfShape & a0, const TopoDS_Shape & a1) -> Standard_Boolean { return BRepAlgo::IsValid(a0, a1); }, py::arg("theArgs"), py::arg("theResult"));
	cls_BRepAlgo.def_static("IsValid_", [](const TopTools_ListOfShape & a0, const TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Boolean { return BRepAlgo::IsValid(a0, a1, a2); }, py::arg("theArgs"), py::arg("theResult"), py::arg("closedSolid"));
	cls_BRepAlgo.def_static("IsValid_", (Standard_Boolean (*)(const TopTools_ListOfShape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgo::IsValid, "Checks if the Generated and Modified Faces from the shapes <arguments> in the shape <result> are 'correct'. The args may be empty, then all faces will be checked. If <Closed> is True, only closed shape are valid. If <GeomCtrl> is False the geometry of new vertices and edges are not verified and the auto-intersection of new wires are not searched.", py::arg("theArgs"), py::arg("theResult"), py::arg("closedSolid"), py::arg("GeomCtrl"));
	cls_BRepAlgo.def_static("IsTopologicallyValid_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepAlgo::IsTopologicallyValid, "Checks if the shape is 'correct'. If not, returns <Standard_False>, else returns <Standard_True>. This method differs from the previous one in the fact that no geometric contols (intersection of wires, pcurve validity) are performed.", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_DataMapOfShapeBoolean.hxx
	bind_NCollection_DataMap<TopoDS_Shape, bool, TopTools_ShapeMapHasher>(mod, "BRepAlgo_DataMapOfShapeBoolean");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_DataMapOfShapeInterference.hxx
	bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<TopOpeBRepDS_Interference>, TopTools_ShapeMapHasher>(mod, "BRepAlgo_DataMapOfShapeInterference");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAlgo_SequenceOfSequenceOfInteger.hxx
	bind_NCollection_Sequence<NCollection_Sequence<int> >(mod, "BRepAlgo_SequenceOfSequenceOfInteger");


}
