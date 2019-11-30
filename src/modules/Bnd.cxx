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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <gp_Trsf.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <Standard_OStream.hxx>
#include <Standard_ConstructionError.hxx>
#include <Bnd_Range.hxx>
#include <NCollection_List.hxx>
#include <NCollection_Array1.hxx>
#include <Bnd_Array1OfBox.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Bnd_Array1OfBox2d.hxx>
#include <gp_XYZ.hxx>
#include <Bnd_Sphere.hxx>
#include <Bnd_Array1OfSphere.hxx>
#include <gp_XY.hxx>
#include <Bnd_B2d.hxx>
#include <gp_Ax2d.hxx>
#include <Bnd_B2f.hxx>
#include <Bnd_B3d.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax3.hxx>
#include <Bnd_B3f.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <Standard_Type.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <Bnd_HArray1OfBox2d.hxx>
#include <TColStd_HArray1OfListOfInteger.hxx>
#include <Bnd_BoundSortBox2d.hxx>
#include <Bnd_HArray1OfSphere.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Bnd_OBB.hxx>
#include <NCollection_Sequence.hxx>
#include <Bnd_SeqOfBox.hxx>
#include <BVH_Box.hxx>
#include <BVH_Types.hxx>
#include <Bnd_Tools.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(Bnd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BVH");

// CLASS: BND_BOX
py::class_<Bnd_Box> cls_Bnd_Box(mod, "Bnd_Box", "Describes a bounding box in 3D space. A bounding box is parallel to the axes of the coordinates system. If it is finite, it is defined by the three intervals: - [ Xmin,Xmax ], - [ Ymin,Ymax ], - [ Zmin,Zmax ]. A bounding box may be infinite (i.e. open) in one or more directions. It is said to be: - OpenXmin if it is infinite on the negative side of the 'X Direction'; - OpenXmax if it is infinite on the positive side of the 'X Direction'; - OpenYmin if it is infinite on the negative side of the 'Y Direction'; - OpenYmax if it is infinite on the positive side of the 'Y Direction'; - OpenZmin if it is infinite on the negative side of the 'Z Direction'; - OpenZmax if it is infinite on the positive side of the 'Z Direction'; - WholeSpace if it is infinite in all six directions. In this case, any point of the space is inside the box; - Void if it is empty. In this case, there is no point included in the box. A bounding box is defined by: - six bounds (Xmin, Xmax, Ymin, Ymax, Zmin and Zmax) which limit the bounding box if it is finite, - eight flags (OpenXmin, OpenXmax, OpenYmin, OpenYmax, OpenZmin, OpenZmax, WholeSpace and Void) which describe the bounding box if it is infinite or empty, and - a gap, which is included on both sides in any direction when consulting the finite bounds of the box.");

// Constructors
cls_Bnd_Box.def(py::init<>());
cls_Bnd_Box.def(py::init<const gp_Pnt, const gp_Pnt>(), py::arg("theMin"), py::arg("theMax"));

// Methods
// cls_Bnd_Box.def_static("operator new_", (void * (*)(size_t)) &Bnd_Box::operator new, "None", py::arg("theSize"));
// cls_Bnd_Box.def_static("operator delete_", (void (*)(void *)) &Bnd_Box::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_Box.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_Box::operator new[], "None", py::arg("theSize"));
// cls_Bnd_Box.def_static("operator delete[]_", (void (*)(void *)) &Bnd_Box::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_Box.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_Box::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_Box.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_Box::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_Box.def("SetWhole", (void (Bnd_Box::*)()) &Bnd_Box::SetWhole, "Sets this bounding box so that it covers the whole of 3D space. It is infinitely long in all directions.");
cls_Bnd_Box.def("SetVoid", (void (Bnd_Box::*)()) &Bnd_Box::SetVoid, "Sets this bounding box so that it is empty. All points are outside a void box.");
cls_Bnd_Box.def("Set", (void (Bnd_Box::*)(const gp_Pnt &)) &Bnd_Box::Set, "Sets this bounding box so that it bounds - the point P. This involves first setting this bounding box to be void and then adding the point P.", py::arg("P"));
cls_Bnd_Box.def("Set", (void (Bnd_Box::*)(const gp_Pnt &, const gp_Dir &)) &Bnd_Box::Set, "Sets this bounding box so that it bounds the half-line defined by point P and direction D, i.e. all points M defined by M=P+u*D, where u is greater than or equal to 0, are inside the bounding volume. This involves first setting this box to be void and then adding the half-line.", py::arg("P"), py::arg("D"));
cls_Bnd_Box.def("Update", (void (Bnd_Box::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box::Update, "Enlarges this bounding box, if required, so that it contains at least: - interval [ aXmin,aXmax ] in the 'X Direction', - interval [ aYmin,aYmax ] in the 'Y Direction', - interval [ aZmin,aZmax ] in the 'Z Direction';", py::arg("aXmin"), py::arg("aYmin"), py::arg("aZmin"), py::arg("aXmax"), py::arg("aYmax"), py::arg("aZmax"));
cls_Bnd_Box.def("Update", (void (Bnd_Box::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box::Update, "Adds a point of coordinates (X,Y,Z) to this bounding box.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Bnd_Box.def("GetGap", (Standard_Real (Bnd_Box::*)() const) &Bnd_Box::GetGap, "Returns the gap of this bounding box.");
cls_Bnd_Box.def("SetGap", (void (Bnd_Box::*)(const Standard_Real)) &Bnd_Box::SetGap, "Set the gap of this bounding box to abs(Tol).", py::arg("Tol"));
cls_Bnd_Box.def("Enlarge", (void (Bnd_Box::*)(const Standard_Real)) &Bnd_Box::Enlarge, "Enlarges the box with a tolerance value. (minvalues-Abs(<tol>) and maxvalues+Abs(<tol>)) This means that the minimum values of its X, Y and Z intervals of definition, when they are finite, are reduced by the absolute value of Tol, while the maximum values are increased by the same amount.", py::arg("Tol"));
cls_Bnd_Box.def("Get", [](Bnd_Box &self, Standard_Real & theXmin, Standard_Real & theYmin, Standard_Real & theZmin, Standard_Real & theXmax, Standard_Real & theYmax, Standard_Real & theZmax){ self.Get(theXmin, theYmin, theZmin, theXmax, theYmax, theZmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(theXmin, theYmin, theZmin, theXmax, theYmax, theZmax); }, "Returns the bounds of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()", py::arg("theXmin"), py::arg("theYmin"), py::arg("theZmin"), py::arg("theXmax"), py::arg("theYmax"), py::arg("theZmax"));
cls_Bnd_Box.def("CornerMin", (gp_Pnt (Bnd_Box::*)() const) &Bnd_Box::CornerMin, "Returns the lower corner of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()");
cls_Bnd_Box.def("CornerMax", (gp_Pnt (Bnd_Box::*)() const) &Bnd_Box::CornerMax, "Returns the upper corner of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()");
cls_Bnd_Box.def("OpenXmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenXmin, "The Box will be infinitely long in the Xmin direction.");
cls_Bnd_Box.def("OpenXmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenXmax, "The Box will be infinitely long in the Xmax direction.");
cls_Bnd_Box.def("OpenYmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenYmin, "The Box will be infinitely long in the Ymin direction.");
cls_Bnd_Box.def("OpenYmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenYmax, "The Box will be infinitely long in the Ymax direction.");
cls_Bnd_Box.def("OpenZmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenZmin, "The Box will be infinitely long in the Zmin direction.");
cls_Bnd_Box.def("OpenZmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenZmax, "The Box will be infinitely long in the Zmax direction.");
cls_Bnd_Box.def("IsOpen", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpen, "Returns true if this bounding box has at least one open direction.");
cls_Bnd_Box.def("IsOpenXmin", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenXmin, "Returns true if this bounding box is open in the Xmin direction.");
cls_Bnd_Box.def("IsOpenXmax", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenXmax, "Returns true if this bounding box is open in the Xmax direction.");
cls_Bnd_Box.def("IsOpenYmin", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenYmin, "Returns true if this bounding box is open in the Ymix direction.");
cls_Bnd_Box.def("IsOpenYmax", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenYmax, "Returns true if this bounding box is open in the Ymax direction.");
cls_Bnd_Box.def("IsOpenZmin", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenZmin, "Returns true if this bounding box is open in the Zmin direction.");
cls_Bnd_Box.def("IsOpenZmax", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsOpenZmax, "Returns true if this bounding box is open in the Zmax direction.");
cls_Bnd_Box.def("IsWhole", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsWhole, "Returns true if this bounding box is infinite in all 6 directions (WholeSpace flag).");
cls_Bnd_Box.def("IsVoid", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::IsVoid, "Returns true if this bounding box is empty (Void flag).");
cls_Bnd_Box.def("IsXThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsXThin, "true if xmax-xmin < tol.", py::arg("tol"));
cls_Bnd_Box.def("IsYThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsYThin, "true if ymax-ymin < tol.", py::arg("tol"));
cls_Bnd_Box.def("IsZThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsZThin, "true if zmax-zmin < tol.", py::arg("tol"));
cls_Bnd_Box.def("IsThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const) &Bnd_Box::IsThin, "Returns true if IsXThin, IsYThin and IsZThin are all true, i.e. if the box is thin in all three dimensions.", py::arg("tol"));
cls_Bnd_Box.def("Transformed", (Bnd_Box (Bnd_Box::*)(const gp_Trsf &) const) &Bnd_Box::Transformed, "Returns a bounding box which is the result of applying the transformation T to this bounding box. Warning Applying a geometric transformation (for example, a rotation) to a bounding box generally increases its dimensions. This is not optimal for algorithms which use it.", py::arg("T"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const Bnd_Box &)) &Bnd_Box::Add, "Adds the box <Other> to <me>.", py::arg("Other"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Pnt &)) &Bnd_Box::Add, "Adds a Pnt to the box.", py::arg("P"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Pnt &, const gp_Dir &)) &Bnd_Box::Add, "Extends <me> from the Pnt <P> in the direction <D>.", py::arg("P"), py::arg("D"));
cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Dir &)) &Bnd_Box::Add, "Extends the Box in the given Direction, i.e. adds an half-line. The box may become infinite in 1,2 or 3 directions.", py::arg("D"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pnt &) const) &Bnd_Box::IsOut, "Returns True if the Pnt is out the box.", py::arg("P"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Lin &) const) &Bnd_Box::IsOut, "Returns False if the line intersects the box.", py::arg("L"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pln &) const) &Bnd_Box::IsOut, "Returns False if the plane intersects the box.", py::arg("P"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const Bnd_Box &) const) &Bnd_Box::IsOut, "Returns False if the <Box> intersects or is inside <me>.", py::arg("Other"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const Bnd_Box &, const gp_Trsf &) const) &Bnd_Box::IsOut, "Returns False if the transformed <Box> intersects or is inside <me>.", py::arg("Other"), py::arg("T"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Trsf &, const Bnd_Box &, const gp_Trsf &) const) &Bnd_Box::IsOut, "Returns False if the transformed <Box> intersects or is inside the transformed box <me>.", py::arg("T1"), py::arg("Other"), py::arg("T2"));
cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pnt &, const gp_Pnt &, const gp_Dir &) const) &Bnd_Box::IsOut, "Returns False if the flat band lying between two parallel lines represented by their reference points <P1>, <P2> and direction <D> intersects the box.", py::arg("P1"), py::arg("P2"), py::arg("D"));
cls_Bnd_Box.def("Distance", (Standard_Real (Bnd_Box::*)(const Bnd_Box &) const) &Bnd_Box::Distance, "Computes the minimum distance between two boxes.", py::arg("Other"));
cls_Bnd_Box.def("Dump", (void (Bnd_Box::*)() const) &Bnd_Box::Dump, "None");
cls_Bnd_Box.def("SquareExtent", (Standard_Real (Bnd_Box::*)() const) &Bnd_Box::SquareExtent, "Computes the squared diagonal of me.");
cls_Bnd_Box.def("FinitePart", (Bnd_Box (Bnd_Box::*)() const) &Bnd_Box::FinitePart, "Returns a finite part of an infinite bounding box (returns self if this is already finite box). This can be a Void box in case if its sides has been defined as infinite (Open) without adding any finite points. WARNING! This method relies on Open flags, the infinite points added using Add() method will be returned as is.");
cls_Bnd_Box.def("HasFinitePart", (Standard_Boolean (Bnd_Box::*)() const) &Bnd_Box::HasFinitePart, "Returns TRUE if this box has finite part.");
cls_Bnd_Box.def("DumpJson", [](Bnd_Box &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_Bnd_Box.def("DumpJson", (void (Bnd_Box::*)(Standard_OStream &, const Standard_Integer) const) &Bnd_Box::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));

// CLASS: BND_RANGE
py::class_<Bnd_Range> cls_Bnd_Range(mod, "Bnd_Range", "This class describes a range in 1D space restricted by two real values. A range can be void indicating there is no point included in the range.");

// Constructors
cls_Bnd_Range.def(py::init<>());
cls_Bnd_Range.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theMin"), py::arg("theMax"));

// Methods
cls_Bnd_Range.def("Common", (void (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Common, "Replaces <this> with common-part of <this> and theOther", py::arg("theOther"));
cls_Bnd_Range.def("Union", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Union, "Joins *this and theOther to one interval. Replaces *this to the result. Returns false if the operation cannot be done (e.g. input arguments are empty or separated).", py::arg("theOther"));
cls_Bnd_Range.def("Split", [](Bnd_Range &self, const Standard_Real a0, NCollection_List<Bnd_Range> & a1) -> void { return self.Split(a0, a1); });
cls_Bnd_Range.def("Split", (void (Bnd_Range::*)(const Standard_Real, NCollection_List<Bnd_Range> &, const Standard_Real) const) &Bnd_Range::Split, "Splits <this> to several sub-ranges by theVal value (e.g. range [3, 15] will be split by theVal==5 to the two ranges: [3, 5] and [5, 15]). New ranges will be pushed to theList (theList must be initialized correctly before calling this method). If thePeriod != 0.0 then at least one boundary of new ranges (if <*this> intersects theVal+k*thePeriod) will be equal to theVal+thePeriod*k, where k is an integer number (k = 0, +/-1, +/-2, ...). (let thePeriod in above example be 4 ==> we will obtain four ranges: [3, 5], [5, 9], [9, 13] and [13, 15].", py::arg("theVal"), py::arg("theList"), py::arg("thePeriod"));
cls_Bnd_Range.def("IsIntersected", [](Bnd_Range &self, const Standard_Real a0) -> Standard_Integer { return self.IsIntersected(a0); });
cls_Bnd_Range.def("IsIntersected", (Standard_Integer (Bnd_Range::*)(const Standard_Real, const Standard_Real) const) &Bnd_Range::IsIntersected, "Checks if <this> intersects values like theVal+k*thePeriod, where k is an integer number (k = 0, +/-1, +/-2, ...). Returns: 0 - if <this> does not intersect the theVal+k*thePeriod. 1 - if <this> intersects theVal+k*thePeriod. 2 - if myFirst or/and myLast are equal to theVal+k*thePeriod.", py::arg("theVal"), py::arg("thePeriod"));
cls_Bnd_Range.def("Add", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Add, "Extends <this> to include theParameter", py::arg("theParameter"));
cls_Bnd_Range.def("Add", (void (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Add, "Extends this range to include both ranges.", py::arg("theRange"));
cls_Bnd_Range.def("GetMin", [](Bnd_Range &self, Standard_Real & thePar){ Standard_Boolean rv = self.GetMin(thePar); return std::tuple<Standard_Boolean, Standard_Real &>(rv, thePar); }, "Obtain MIN boundary of <this>. If <this> is VOID the method returns false.", py::arg("thePar"));
cls_Bnd_Range.def("GetMax", [](Bnd_Range &self, Standard_Real & thePar){ Standard_Boolean rv = self.GetMax(thePar); return std::tuple<Standard_Boolean, Standard_Real &>(rv, thePar); }, "Obtain MAX boundary of <this>. If <this> is VOID the method returns false.", py::arg("thePar"));
cls_Bnd_Range.def("GetBounds", [](Bnd_Range &self, Standard_Real & theFirstPar, Standard_Real & theLastPar){ Standard_Boolean rv = self.GetBounds(theFirstPar, theLastPar); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirstPar, theLastPar); }, "Obtain first and last boundary of <this>. If <this> is VOID the method returns false.", py::arg("theFirstPar"), py::arg("theLastPar"));
cls_Bnd_Range.def("GetIntermediatePoint", [](Bnd_Range &self, const Standard_Real theLambda, Standard_Real & theParameter){ Standard_Boolean rv = self.GetIntermediatePoint(theLambda, theParameter); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Obtain theParameter satisfied to the equation (theParameter-MIN)/(MAX-MIN) == theLambda. * theLambda == 0 --> MIN boundary will be returned; * theLambda == 0.5 --> Middle point will be returned; * theLambda == 1 --> MAX boundary will be returned; * theLambda < 0 --> the value less than MIN will be returned; * theLambda > 1 --> the value greater than MAX will be returned. If <this> is VOID the method returns false.", py::arg("theLambda"), py::arg("theParameter"));
cls_Bnd_Range.def("Delta", (Standard_Real (Bnd_Range::*)() const) &Bnd_Range::Delta, "Returns range value (MAX-MIN). Returns negative value for VOID range.");
cls_Bnd_Range.def("IsVoid", (Standard_Boolean (Bnd_Range::*)() const) &Bnd_Range::IsVoid, "Is <this> initialized.");
cls_Bnd_Range.def("SetVoid", (void (Bnd_Range::*)()) &Bnd_Range::SetVoid, "Initializes <this> by default parameters. Makes <this> VOID.");
cls_Bnd_Range.def("Enlarge", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Enlarge, "Extends this to the given value (in both side)", py::arg("theDelta"));
cls_Bnd_Range.def("Shifted", (Bnd_Range (Bnd_Range::*)(const Standard_Real) const) &Bnd_Range::Shifted, "Returns the copy of <*this> shifted by theVal", py::arg("theVal"));
cls_Bnd_Range.def("Shift", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Shift, "Shifts <*this> by theVal", py::arg("theVal"));
cls_Bnd_Range.def("TrimFrom", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::TrimFrom, "Trims the First value in range by the given lower limit. Marks range as Void if the given Lower value is greater than range Max.", py::arg("theValLower"));
cls_Bnd_Range.def("TrimTo", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::TrimTo, "Trim the Last value in range by the given Upper limit. Marks range as Void if the given Upper value is smaller than range Max.", py::arg("theValUpper"));
cls_Bnd_Range.def("IsOut", (Standard_Boolean (Bnd_Range::*)(Standard_Real) const) &Bnd_Range::IsOut, "Returns True if the value is out of this range.", py::arg("theValue"));
cls_Bnd_Range.def("IsOut", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &) const) &Bnd_Range::IsOut, "Returns True if the given range is out of this range.", py::arg("theRange"));
cls_Bnd_Range.def("__eq__", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &) const) &Bnd_Range::operator==, py::is_operator(), "Returns TRUE if theOther is equal to <*this>", py::arg("theOther"));
cls_Bnd_Range.def("DumpJson", [](Bnd_Range &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_Bnd_Range.def("DumpJson", (void (Bnd_Range::*)(Standard_OStream &, const Standard_Integer) const) &Bnd_Range::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));

// TYPEDEF: BND_ARRAY1OFBOX
bind_NCollection_Array1<Bnd_Box>(mod, "Bnd_Array1OfBox", py::module_local(false));

// CLASS: BND_BOX2D
py::class_<Bnd_Box2d> cls_Bnd_Box2d(mod, "Bnd_Box2d", "Describes a bounding box in 2D space. A bounding box is parallel to the axes of the coordinates system. If it is finite, it is defined by the two intervals: - [ Xmin,Xmax ], and - [ Ymin,Ymax ]. A bounding box may be infinite (i.e. open) in one or more directions. It is said to be: - OpenXmin if it is infinite on the negative side of the 'X Direction'; - OpenXmax if it is infinite on the positive side of the 'X Direction'; - OpenYmin if it is infinite on the negative side of the 'Y Direction'; - OpenYmax if it is infinite on the positive side of the 'Y Direction'; - WholeSpace if it is infinite in all four directions. In this case, any point of the space is inside the box; - Void if it is empty. In this case, there is no point included in the box. A bounding box is defined by four bounds (Xmin, Xmax, Ymin and Ymax) which limit the bounding box if it is finite, six flags (OpenXmin, OpenXmax, OpenYmin, OpenYmax, WholeSpace and Void) which describe the bounding box if it is infinite or empty, and - a gap, which is included on both sides in any direction when consulting the finite bounds of the box.");

// Constructors
cls_Bnd_Box2d.def(py::init<>());

// Methods
// cls_Bnd_Box2d.def_static("operator new_", (void * (*)(size_t)) &Bnd_Box2d::operator new, "None", py::arg("theSize"));
// cls_Bnd_Box2d.def_static("operator delete_", (void (*)(void *)) &Bnd_Box2d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_Box2d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_Box2d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_Box2d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_Box2d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_Box2d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_Box2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_Box2d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_Box2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_Box2d.def("SetWhole", (void (Bnd_Box2d::*)()) &Bnd_Box2d::SetWhole, "Sets this bounding box so that it covers the whole 2D space, i.e. it is infinite in all directions.");
cls_Bnd_Box2d.def("SetVoid", (void (Bnd_Box2d::*)()) &Bnd_Box2d::SetVoid, "Sets this 2D bounding box so that it is empty. All points are outside a void box.");
cls_Bnd_Box2d.def("Set", (void (Bnd_Box2d::*)(const gp_Pnt2d &)) &Bnd_Box2d::Set, "Sets this 2D bounding box so that it bounds the point P. This involves first setting this bounding box to be void and then adding the point PThe rectangle bounds the point <P>.", py::arg("thePnt"));
cls_Bnd_Box2d.def("Set", (void (Bnd_Box2d::*)(const gp_Pnt2d &, const gp_Dir2d &)) &Bnd_Box2d::Set, "Sets this 2D bounding box so that it bounds the half-line defined by point P and direction D, i.e. all points M defined by M=P+u*D, where u is greater than or equal to 0, are inside the bounding area. This involves first setting this 2D box to be void and then adding the half-line.", py::arg("thePnt"), py::arg("theDir"));
cls_Bnd_Box2d.def("Update", (void (Bnd_Box2d::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box2d::Update, "Enlarges this 2D bounding box, if required, so that it contains at least: - interval [ aXmin,aXmax ] in the 'X Direction', - interval [ aYmin,aYmax ] in the 'Y Direction'", py::arg("aXmin"), py::arg("aYmin"), py::arg("aXmax"), py::arg("aYmax"));
cls_Bnd_Box2d.def("Update", (void (Bnd_Box2d::*)(const Standard_Real, const Standard_Real)) &Bnd_Box2d::Update, "Adds a point of coordinates (X,Y) to this bounding box.", py::arg("X"), py::arg("Y"));
cls_Bnd_Box2d.def("GetGap", (Standard_Real (Bnd_Box2d::*)() const) &Bnd_Box2d::GetGap, "Returns the gap of this 2D bounding box.");
cls_Bnd_Box2d.def("SetGap", (void (Bnd_Box2d::*)(const Standard_Real)) &Bnd_Box2d::SetGap, "Set the gap of this 2D bounding box to abs(Tol).", py::arg("Tol"));
cls_Bnd_Box2d.def("Enlarge", (void (Bnd_Box2d::*)(const Standard_Real)) &Bnd_Box2d::Enlarge, "Enlarges the box with a tolerance value. This means that the minimum values of its X and Y intervals of definition, when they are finite, are reduced by the absolute value of Tol, while the maximum values are increased by the same amount.", py::arg("theTol"));
cls_Bnd_Box2d.def("Get", [](Bnd_Box2d &self, Standard_Real & aXmin, Standard_Real & aYmin, Standard_Real & aXmax, Standard_Real & aYmax){ self.Get(aXmin, aYmin, aXmax, aYmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(aXmin, aYmin, aXmax, aYmax); }, "Returns the bounds of this 2D bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). if IsVoid()", py::arg("aXmin"), py::arg("aYmin"), py::arg("aXmax"), py::arg("aYmax"));
cls_Bnd_Box2d.def("OpenXmin", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenXmin, "The Box will be infinitely long in the Xmin direction.");
cls_Bnd_Box2d.def("OpenXmax", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenXmax, "The Box will be infinitely long in the Xmax direction.");
cls_Bnd_Box2d.def("OpenYmin", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenYmin, "The Box will be infinitely long in the Ymin direction.");
cls_Bnd_Box2d.def("OpenYmax", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenYmax, "The Box will be infinitely long in the Ymax direction.");
cls_Bnd_Box2d.def("IsOpenXmin", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenXmin, "Returns true if this bounding box is open in the Xmin direction.");
cls_Bnd_Box2d.def("IsOpenXmax", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenXmax, "Returns true if this bounding box is open in the Xmax direction.");
cls_Bnd_Box2d.def("IsOpenYmin", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenYmin, "Returns true if this bounding box is open in the Ymin direction.");
cls_Bnd_Box2d.def("IsOpenYmax", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsOpenYmax, "Returns true if this bounding box is open in the Ymax direction.");
cls_Bnd_Box2d.def("IsWhole", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsWhole, "Returns true if this bounding box is infinite in all 4 directions (Whole Space flag).");
cls_Bnd_Box2d.def("IsVoid", (Standard_Boolean (Bnd_Box2d::*)() const) &Bnd_Box2d::IsVoid, "Returns true if this 2D bounding box is empty (Void flag).");
cls_Bnd_Box2d.def("Transformed", (Bnd_Box2d (Bnd_Box2d::*)(const gp_Trsf2d &) const) &Bnd_Box2d::Transformed, "Returns a bounding box which is the result of applying the transformation T to this bounding box. Warning Applying a geometric transformation (for example, a rotation) to a bounding box generally increases its dimensions. This is not optimal for algorithms which use it.", py::arg("T"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const Bnd_Box2d &)) &Bnd_Box2d::Add, "Adds the 2d box <Other> to <me>.", py::arg("Other"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Pnt2d &)) &Bnd_Box2d::Add, "Adds the 2d point.", py::arg("thePnt"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Pnt2d &, const gp_Dir2d &)) &Bnd_Box2d::Add, "Extends bounding box from thePnt in the direction theDir.", py::arg("thePnt"), py::arg("theDir"));
cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Dir2d &)) &Bnd_Box2d::Add, "Extends the Box in the given Direction, i.e. adds a half-line. The box may become infinite in 1 or 2 directions.", py::arg("D"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const gp_Pnt2d &) const) &Bnd_Box2d::IsOut, "Returns True if the 2d pnt <P> is out <me>.", py::arg("P"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const Bnd_Box2d &) const) &Bnd_Box2d::IsOut, "Returns True if <Box2d> is out <me>.", py::arg("Other"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const Bnd_Box2d &, const gp_Trsf2d &) const) &Bnd_Box2d::IsOut, "Returns True if transformed <Box2d> is out <me>.", py::arg("theOther"), py::arg("theTrsf"));
cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const gp_Trsf2d &, const Bnd_Box2d &, const gp_Trsf2d &) const) &Bnd_Box2d::IsOut, "Compares a transformed bounding with a transformed bounding. The default implementation is to make a copy of <me> and <Other>, to transform them and to test.", py::arg("T1"), py::arg("Other"), py::arg("T2"));
cls_Bnd_Box2d.def("Dump", (void (Bnd_Box2d::*)() const) &Bnd_Box2d::Dump, "None");
cls_Bnd_Box2d.def("SquareExtent", (Standard_Real (Bnd_Box2d::*)() const) &Bnd_Box2d::SquareExtent, "Computes the squared diagonal of me.");

// TYPEDEF: BND_ARRAY1OFBOX2D
bind_NCollection_Array1<Bnd_Box2d>(mod, "Bnd_Array1OfBox2d", py::module_local(false));

// CLASS: BND_SPHERE
py::class_<Bnd_Sphere> cls_Bnd_Sphere(mod, "Bnd_Sphere", "This class represents a bounding sphere of a geometric entity (triangle, segment of line or whatever else).");

// Constructors
cls_Bnd_Sphere.def(py::init<>());
cls_Bnd_Sphere.def(py::init<const gp_XYZ &, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theCntr"), py::arg("theRad"), py::arg("theU"), py::arg("theV"));

// Methods
// cls_Bnd_Sphere.def_static("operator new_", (void * (*)(size_t)) &Bnd_Sphere::operator new, "None", py::arg("theSize"));
// cls_Bnd_Sphere.def_static("operator delete_", (void (*)(void *)) &Bnd_Sphere::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_Sphere.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_Sphere::operator new[], "None", py::arg("theSize"));
// cls_Bnd_Sphere.def_static("operator delete[]_", (void (*)(void *)) &Bnd_Sphere::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_Sphere.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_Sphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_Sphere.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_Sphere::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_Sphere.def("U", (Standard_Integer (Bnd_Sphere::*)() const) &Bnd_Sphere::U, "Returns the U parameter on shape");
cls_Bnd_Sphere.def("V", (Standard_Integer (Bnd_Sphere::*)() const) &Bnd_Sphere::V, "Returns the V parameter on shape");
cls_Bnd_Sphere.def("IsValid", (Standard_Boolean (Bnd_Sphere::*)() const) &Bnd_Sphere::IsValid, "Returns validity status, indicating that this sphere corresponds to a real entity");
cls_Bnd_Sphere.def("SetValid", (void (Bnd_Sphere::*)(const Standard_Boolean)) &Bnd_Sphere::SetValid, "None", py::arg("isValid"));
cls_Bnd_Sphere.def("Center", (const gp_XYZ & (Bnd_Sphere::*)() const) &Bnd_Sphere::Center, "Returns center of sphere object");
cls_Bnd_Sphere.def("Radius", (Standard_Real (Bnd_Sphere::*)() const) &Bnd_Sphere::Radius, "Returns the radius value");
cls_Bnd_Sphere.def("Distances", [](Bnd_Sphere &self, const gp_XYZ & theXYZ, Standard_Real & theMin, Standard_Real & theMax){ self.Distances(theXYZ, theMin, theMax); return std::tuple<Standard_Real &, Standard_Real &>(theMin, theMax); }, "Calculate and return minimal and maximal distance to sphere. NOTE: This function is tightly optimized; any modifications may affect performance!", py::arg("theXYZ"), py::arg("theMin"), py::arg("theMax"));
cls_Bnd_Sphere.def("SquareDistances", [](Bnd_Sphere &self, const gp_XYZ & theXYZ, Standard_Real & theMin, Standard_Real & theMax){ self.SquareDistances(theXYZ, theMin, theMax); return std::tuple<Standard_Real &, Standard_Real &>(theMin, theMax); }, "Calculate and return minimal and maximal distance to sphere. NOTE: This function is tightly optimized; any modifications may affect performance!", py::arg("theXYZ"), py::arg("theMin"), py::arg("theMax"));
cls_Bnd_Sphere.def("Project", [](Bnd_Sphere &self, const gp_XYZ & theNode, gp_XYZ & theProjNode, Standard_Real & theDist, Standard_Boolean & theInside){ Standard_Boolean rv = self.Project(theNode, theProjNode, theDist, theInside); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &>(rv, theDist, theInside); }, "Projects a point on entity. Returns true if success", py::arg("theNode"), py::arg("theProjNode"), py::arg("theDist"), py::arg("theInside"));
cls_Bnd_Sphere.def("Distance", (Standard_Real (Bnd_Sphere::*)(const gp_XYZ &) const) &Bnd_Sphere::Distance, "None", py::arg("theNode"));
cls_Bnd_Sphere.def("SquareDistance", (Standard_Real (Bnd_Sphere::*)(const gp_XYZ &) const) &Bnd_Sphere::SquareDistance, "None", py::arg("theNode"));
cls_Bnd_Sphere.def("Add", (void (Bnd_Sphere::*)(const Bnd_Sphere &)) &Bnd_Sphere::Add, "None", py::arg("theOther"));
cls_Bnd_Sphere.def("IsOut", (Standard_Boolean (Bnd_Sphere::*)(const Bnd_Sphere &) const) &Bnd_Sphere::IsOut, "None", py::arg("theOther"));
cls_Bnd_Sphere.def("IsOut", [](Bnd_Sphere &self, const gp_XYZ & thePnt, Standard_Real & theMaxDist){ Standard_Boolean rv = self.IsOut(thePnt, theMaxDist); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theMaxDist); }, "None", py::arg("thePnt"), py::arg("theMaxDist"));
cls_Bnd_Sphere.def("SquareExtent", (Standard_Real (Bnd_Sphere::*)() const) &Bnd_Sphere::SquareExtent, "None");

// TYPEDEF: BND_ARRAY1OFSPHERE
bind_NCollection_Array1<Bnd_Sphere>(mod, "Bnd_Array1OfSphere", py::module_local(false));

// CLASS: BND_B2D
py::class_<Bnd_B2d> cls_Bnd_B2d(mod, "Bnd_B2d", "None");

// Constructors
cls_Bnd_B2d.def(py::init<>());
cls_Bnd_B2d.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("theCenter"), py::arg("theHSize"));

// Methods
// cls_Bnd_B2d.def_static("operator new_", (void * (*)(size_t)) &Bnd_B2d::operator new, "None", py::arg("theSize"));
// cls_Bnd_B2d.def_static("operator delete_", (void (*)(void *)) &Bnd_B2d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_B2d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_B2d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_B2d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_B2d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_B2d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_B2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_B2d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_B2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_B2d.def("IsVoid", (Standard_Boolean (Bnd_B2d::*)() const) &Bnd_B2d::IsVoid, "Returns True if the box is void (non-initialized).");
cls_Bnd_B2d.def("Clear", (void (Bnd_B2d::*)()) &Bnd_B2d::Clear, "Reset the box data.");
cls_Bnd_B2d.def("Add", (void (Bnd_B2d::*)(const gp_XY &)) &Bnd_B2d::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B2d.def("Add", (void (Bnd_B2d::*)(const gp_Pnt2d &)) &Bnd_B2d::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B2d.def("Add", (void (Bnd_B2d::*)(const Bnd_B2d &)) &Bnd_B2d::Add, "Update the box by another box.", py::arg("theBox"));
cls_Bnd_B2d.def("CornerMin", (gp_XY (Bnd_B2d::*)() const) &Bnd_B2d::CornerMin, "Query a box corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B2d.def("CornerMax", (gp_XY (Bnd_B2d::*)() const) &Bnd_B2d::CornerMax, "Query a box corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B2d.def("SquareExtent", (Standard_Real (Bnd_B2d::*)() const) &Bnd_B2d::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
cls_Bnd_B2d.def("Enlarge", (void (Bnd_B2d::*)(const Standard_Real)) &Bnd_B2d::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
cls_Bnd_B2d.def("Limit", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &)) &Bnd_B2d::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
cls_Bnd_B2d.def("Transformed", (Bnd_B2d (Bnd_B2d::*)(const gp_Trsf2d &) const) &Bnd_B2d::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_XY &) const) &Bnd_B2d::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
cls_Bnd_B2d.def("IsOut", [](Bnd_B2d &self, const gp_XY & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_XY &, const Standard_Real, const Standard_Boolean) const) &Bnd_B2d::IsOut, "Check a circle for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theCenter"), py::arg("theRadius"), py::arg("isCircleHollow"));
cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &) const) &Bnd_B2d::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &, const gp_Trsf2d &) const) &Bnd_B2d::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_Ax2d &) const) &Bnd_B2d::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection.", py::arg("theLine"));
cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_XY &, const gp_XY &) const) &Bnd_B2d::IsOut, "Check the Segment defined by the couple of input points for the intersection with the current box. Returns True if there is no intersection.", py::arg("theP0"), py::arg("theP1"));
cls_Bnd_B2d.def("IsIn", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &) const) &Bnd_B2d::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
cls_Bnd_B2d.def("IsIn", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &, const gp_Trsf2d &) const) &Bnd_B2d::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
cls_Bnd_B2d.def("SetCenter", (void (Bnd_B2d::*)(const gp_XY &)) &Bnd_B2d::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
cls_Bnd_B2d.def("SetHSize", (void (Bnd_B2d::*)(const gp_XY &)) &Bnd_B2d::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

// CLASS: BND_B2F
py::class_<Bnd_B2f> cls_Bnd_B2f(mod, "Bnd_B2f", "None");

// Constructors
cls_Bnd_B2f.def(py::init<>());
cls_Bnd_B2f.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("theCenter"), py::arg("theHSize"));

// Methods
// cls_Bnd_B2f.def_static("operator new_", (void * (*)(size_t)) &Bnd_B2f::operator new, "None", py::arg("theSize"));
// cls_Bnd_B2f.def_static("operator delete_", (void (*)(void *)) &Bnd_B2f::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_B2f.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_B2f::operator new[], "None", py::arg("theSize"));
// cls_Bnd_B2f.def_static("operator delete[]_", (void (*)(void *)) &Bnd_B2f::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_B2f.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_B2f::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_B2f.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_B2f::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_B2f.def("IsVoid", (Standard_Boolean (Bnd_B2f::*)() const) &Bnd_B2f::IsVoid, "Returns True if the box is void (non-initialized).");
cls_Bnd_B2f.def("Clear", (void (Bnd_B2f::*)()) &Bnd_B2f::Clear, "Reset the box data.");
cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const gp_Pnt2d &)) &Bnd_B2f::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const Bnd_B2f &)) &Bnd_B2f::Add, "Update the box by another box.", py::arg("theBox"));
cls_Bnd_B2f.def("CornerMin", (gp_XY (Bnd_B2f::*)() const) &Bnd_B2f::CornerMin, "Query a box corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B2f.def("CornerMax", (gp_XY (Bnd_B2f::*)() const) &Bnd_B2f::CornerMax, "Query a box corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B2f.def("SquareExtent", (Standard_Real (Bnd_B2f::*)() const) &Bnd_B2f::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
cls_Bnd_B2f.def("Enlarge", (void (Bnd_B2f::*)(const Standard_Real)) &Bnd_B2f::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
cls_Bnd_B2f.def("Limit", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &)) &Bnd_B2f::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
cls_Bnd_B2f.def("Transformed", (Bnd_B2f (Bnd_B2f::*)(const gp_Trsf2d &) const) &Bnd_B2f::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &) const) &Bnd_B2f::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
cls_Bnd_B2f.def("IsOut", [](Bnd_B2f &self, const gp_XY & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &, const Standard_Real, const Standard_Boolean) const) &Bnd_B2f::IsOut, "Check a circle for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theCenter"), py::arg("theRadius"), py::arg("isCircleHollow"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &) const) &Bnd_B2f::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &, const gp_Trsf2d &) const) &Bnd_B2f::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_Ax2d &) const) &Bnd_B2f::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection.", py::arg("theLine"));
cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &, const gp_XY &) const) &Bnd_B2f::IsOut, "Check the Segment defined by the couple of input points for the intersection with the current box. Returns True if there is no intersection.", py::arg("theP0"), py::arg("theP1"));
cls_Bnd_B2f.def("IsIn", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &) const) &Bnd_B2f::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
cls_Bnd_B2f.def("IsIn", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &, const gp_Trsf2d &) const) &Bnd_B2f::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
cls_Bnd_B2f.def("SetCenter", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
cls_Bnd_B2f.def("SetHSize", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

// CLASS: BND_B3D
py::class_<Bnd_B3d> cls_Bnd_B3d(mod, "Bnd_B3d", "None");

// Constructors
cls_Bnd_B3d.def(py::init<>());
cls_Bnd_B3d.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("theCenter"), py::arg("theHSize"));

// Methods
// cls_Bnd_B3d.def_static("operator new_", (void * (*)(size_t)) &Bnd_B3d::operator new, "None", py::arg("theSize"));
// cls_Bnd_B3d.def_static("operator delete_", (void (*)(void *)) &Bnd_B3d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_B3d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_B3d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_B3d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_B3d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_B3d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_B3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_B3d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_B3d::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_B3d.def("IsVoid", (Standard_Boolean (Bnd_B3d::*)() const) &Bnd_B3d::IsVoid, "Returns True if the box is void (non-initialized).");
cls_Bnd_B3d.def("Clear", (void (Bnd_B3d::*)()) &Bnd_B3d::Clear, "Reset the box data.");
cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const gp_Pnt &)) &Bnd_B3d::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const Bnd_B3d &)) &Bnd_B3d::Add, "Update the box by another box.", py::arg("theBox"));
cls_Bnd_B3d.def("CornerMin", (gp_XYZ (Bnd_B3d::*)() const) &Bnd_B3d::CornerMin, "Query the lower corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B3d.def("CornerMax", (gp_XYZ (Bnd_B3d::*)() const) &Bnd_B3d::CornerMax, "Query the upper corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B3d.def("SquareExtent", (Standard_Real (Bnd_B3d::*)() const) &Bnd_B3d::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
cls_Bnd_B3d.def("Enlarge", (void (Bnd_B3d::*)(const Standard_Real)) &Bnd_B3d::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
cls_Bnd_B3d.def("Limit", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &)) &Bnd_B3d::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
cls_Bnd_B3d.def("Transformed", (Bnd_B3d (Bnd_B3d::*)(const gp_Trsf &) const) &Bnd_B3d::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_XYZ &) const) &Bnd_B3d::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_XYZ & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_XYZ &, const Standard_Real, const Standard_Boolean) const) &Bnd_B3d::IsOut, "Check a sphere for the intersection with the current box. Returns True if there is no intersection between boxes. If the parameter 'IsSphereHollow' is True, then the intersection is not reported for a box that is completely inside the sphere (otherwise this method would report an intersection).", py::arg("theCenter"), py::arg("theRadius"), py::arg("isSphereHollow"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &) const) &Bnd_B3d::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &, const gp_Trsf &) const) &Bnd_B3d::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_Ax1 & a0) -> Standard_Boolean { return self.IsOut(a0); });
cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_Ax1 & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_Ax1 &, const Standard_Boolean, const Standard_Real) const) &Bnd_B3d::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection. isRay==True means intersection check with the positive half-line theOverthickness is the addition to the size of the current box (may be negative). If positive, it can be treated as the thickness of the line 'theLine' or the radius of the cylinder along 'theLine'", py::arg("theLine"), py::arg("isRay"), py::arg("theOverthickness"));
cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_Ax3 &) const) &Bnd_B3d::IsOut, "Check the given Plane for the intersection with the current box. Returns True if there is no intersection.", py::arg("thePlane"));
cls_Bnd_B3d.def("IsIn", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &) const) &Bnd_B3d::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
cls_Bnd_B3d.def("IsIn", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &, const gp_Trsf &) const) &Bnd_B3d::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
cls_Bnd_B3d.def("SetCenter", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
cls_Bnd_B3d.def("SetHSize", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

// CLASS: BND_B3F
py::class_<Bnd_B3f> cls_Bnd_B3f(mod, "Bnd_B3f", "None");

// Constructors
cls_Bnd_B3f.def(py::init<>());
cls_Bnd_B3f.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("theCenter"), py::arg("theHSize"));

// Methods
// cls_Bnd_B3f.def_static("operator new_", (void * (*)(size_t)) &Bnd_B3f::operator new, "None", py::arg("theSize"));
// cls_Bnd_B3f.def_static("operator delete_", (void (*)(void *)) &Bnd_B3f::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_B3f.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_B3f::operator new[], "None", py::arg("theSize"));
// cls_Bnd_B3f.def_static("operator delete[]_", (void (*)(void *)) &Bnd_B3f::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_B3f.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_B3f::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_B3f.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_B3f::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_B3f.def("IsVoid", (Standard_Boolean (Bnd_B3f::*)() const) &Bnd_B3f::IsVoid, "Returns True if the box is void (non-initialized).");
cls_Bnd_B3f.def("Clear", (void (Bnd_B3f::*)()) &Bnd_B3f::Clear, "Reset the box data.");
cls_Bnd_B3f.def("Add", (void (Bnd_B3f::*)(const gp_XYZ &)) &Bnd_B3f::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B3f.def("Add", (void (Bnd_B3f::*)(const gp_Pnt &)) &Bnd_B3f::Add, "Update the box by a point.", py::arg("thePnt"));
cls_Bnd_B3f.def("Add", (void (Bnd_B3f::*)(const Bnd_B3f &)) &Bnd_B3f::Add, "Update the box by another box.", py::arg("theBox"));
cls_Bnd_B3f.def("CornerMin", (gp_XYZ (Bnd_B3f::*)() const) &Bnd_B3f::CornerMin, "Query the lower corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B3f.def("CornerMax", (gp_XYZ (Bnd_B3f::*)() const) &Bnd_B3f::CornerMax, "Query the upper corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
cls_Bnd_B3f.def("SquareExtent", (Standard_Real (Bnd_B3f::*)() const) &Bnd_B3f::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
cls_Bnd_B3f.def("Enlarge", (void (Bnd_B3f::*)(const Standard_Real)) &Bnd_B3f::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
cls_Bnd_B3f.def("Limit", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &)) &Bnd_B3f::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
cls_Bnd_B3f.def("Transformed", (Bnd_B3f (Bnd_B3f::*)(const gp_Trsf &) const) &Bnd_B3f::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_XYZ &) const) &Bnd_B3f::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
cls_Bnd_B3f.def("IsOut", [](Bnd_B3f &self, const gp_XYZ & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_XYZ &, const Standard_Real, const Standard_Boolean) const) &Bnd_B3f::IsOut, "Check a sphere for the intersection with the current box. Returns True if there is no intersection between boxes. If the parameter 'IsSphereHollow' is True, then the intersection is not reported for a box that is completely inside the sphere (otherwise this method would report an intersection).", py::arg("theCenter"), py::arg("theRadius"), py::arg("isSphereHollow"));
cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &) const) &Bnd_B3f::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &, const gp_Trsf &) const) &Bnd_B3f::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
cls_Bnd_B3f.def("IsOut", [](Bnd_B3f &self, const gp_Ax1 & a0) -> Standard_Boolean { return self.IsOut(a0); });
cls_Bnd_B3f.def("IsOut", [](Bnd_B3f &self, const gp_Ax1 & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.IsOut(a0, a1); });
cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_Ax1 &, const Standard_Boolean, const Standard_Real) const) &Bnd_B3f::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection. isRay==True means intersection check with the positive half-line theOverthickness is the addition to the size of the current box (may be negative). If positive, it can be treated as the thickness of the line 'theLine' or the radius of the cylinder along 'theLine'", py::arg("theLine"), py::arg("isRay"), py::arg("theOverthickness"));
cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_Ax3 &) const) &Bnd_B3f::IsOut, "Check the given Plane for the intersection with the current box. Returns True if there is no intersection.", py::arg("thePlane"));
cls_Bnd_B3f.def("IsIn", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &) const) &Bnd_B3f::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
cls_Bnd_B3f.def("IsIn", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &, const gp_Trsf &) const) &Bnd_B3f::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
cls_Bnd_B3f.def("SetCenter", (void (Bnd_B3f::*)(const gp_XYZ &)) &Bnd_B3f::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
cls_Bnd_B3f.def("SetHSize", (void (Bnd_B3f::*)(const gp_XYZ &)) &Bnd_B3f::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

// CLASS: BND_HARRAY1OFBOX
py::class_<Bnd_HArray1OfBox, opencascade::handle<Bnd_HArray1OfBox>, Standard_Transient> cls_Bnd_HArray1OfBox(mod, "Bnd_HArray1OfBox", "None", py::multiple_inheritance());

// Constructors
cls_Bnd_HArray1OfBox.def(py::init<>());
cls_Bnd_HArray1OfBox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Bnd_HArray1OfBox.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfBox::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Bnd_HArray1OfBox.def(py::init<const Bnd_Array1OfBox &>(), py::arg("theOther"));

// Methods
// cls_Bnd_HArray1OfBox.def_static("operator new_", (void * (*)(size_t)) &Bnd_HArray1OfBox::operator new, "None", py::arg("theSize"));
// cls_Bnd_HArray1OfBox.def_static("operator delete_", (void (*)(void *)) &Bnd_HArray1OfBox::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfBox.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_HArray1OfBox::operator new[], "None", py::arg("theSize"));
// cls_Bnd_HArray1OfBox.def_static("operator delete[]_", (void (*)(void *)) &Bnd_HArray1OfBox::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfBox.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_HArray1OfBox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_HArray1OfBox.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_HArray1OfBox::operator delete, "None", py::arg(""), py::arg(""));
// cls_Bnd_HArray1OfBox.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfBox::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Bnd_HArray1OfBox.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfBox::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Bnd_HArray1OfBox.def("Array1", (const Bnd_Array1OfBox & (Bnd_HArray1OfBox::*)() const) &Bnd_HArray1OfBox::Array1, "None");
cls_Bnd_HArray1OfBox.def("ChangeArray1", (Bnd_Array1OfBox & (Bnd_HArray1OfBox::*)()) &Bnd_HArray1OfBox::ChangeArray1, "None");
cls_Bnd_HArray1OfBox.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfBox::get_type_name, "None");
cls_Bnd_HArray1OfBox.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfBox::get_type_descriptor, "None");
cls_Bnd_HArray1OfBox.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfBox::*)() const) &Bnd_HArray1OfBox::DynamicType, "None");

// CLASS: BND_BOUNDSORTBOX
py::class_<Bnd_BoundSortBox> cls_Bnd_BoundSortBox(mod, "Bnd_BoundSortBox", "A tool to compare a bounding box or a plane with a set of bounding boxes. It sorts the set of bounding boxes to give the list of boxes which intersect the element being compared. The boxes being sorted generally bound a set of shapes, while the box being compared bounds a shape to be compared. The resulting list of intersecting boxes therefore gives the list of items which potentially intersect the shape to be compared.");

// Constructors
cls_Bnd_BoundSortBox.def(py::init<>());

// Methods
// cls_Bnd_BoundSortBox.def_static("operator new_", (void * (*)(size_t)) &Bnd_BoundSortBox::operator new, "None", py::arg("theSize"));
// cls_Bnd_BoundSortBox.def_static("operator delete_", (void (*)(void *)) &Bnd_BoundSortBox::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_BoundSortBox.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_BoundSortBox::operator new[], "None", py::arg("theSize"));
// cls_Bnd_BoundSortBox.def_static("operator delete[]_", (void (*)(void *)) &Bnd_BoundSortBox::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_BoundSortBox.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_BoundSortBox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_BoundSortBox.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_BoundSortBox::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_BoundSortBox.def("Initialize", (void (Bnd_BoundSortBox::*)(const Bnd_Box &, const opencascade::handle<Bnd_HArray1OfBox> &)) &Bnd_BoundSortBox::Initialize, "Initializes this comparison algorithm with - the set of bounding boxes SetOfBox.", py::arg("CompleteBox"), py::arg("SetOfBox"));
cls_Bnd_BoundSortBox.def("Initialize", (void (Bnd_BoundSortBox::*)(const opencascade::handle<Bnd_HArray1OfBox> &)) &Bnd_BoundSortBox::Initialize, "Initializes this comparison algorithm with - the set of bounding boxes SetOfBox, where CompleteBox is given as the global bounding box of SetOfBox.", py::arg("SetOfBox"));
cls_Bnd_BoundSortBox.def("Initialize", (void (Bnd_BoundSortBox::*)(const Bnd_Box &, const Standard_Integer)) &Bnd_BoundSortBox::Initialize, "Initializes this comparison algorithm, giving it only - the maximum number nbComponents of the bounding boxes to be managed. Use the Add function to define the array of bounding boxes to be sorted by this algorithm.", py::arg("CompleteBox"), py::arg("nbComponents"));
cls_Bnd_BoundSortBox.def("Add", (void (Bnd_BoundSortBox::*)(const Bnd_Box &, const Standard_Integer)) &Bnd_BoundSortBox::Add, "Adds the bounding box theBox at position boxIndex in the array of boxes to be sorted by this comparison algorithm. This function is used only in conjunction with the third syntax described in the synopsis of Initialize.", py::arg("theBox"), py::arg("boxIndex"));
cls_Bnd_BoundSortBox.def("Compare", (const TColStd_ListOfInteger & (Bnd_BoundSortBox::*)(const Bnd_Box &)) &Bnd_BoundSortBox::Compare, "Compares the bounding box theBox, with the set of bounding boxes to be sorted by this comparison algorithm, and returns the list of intersecting bounding boxes as a list of indexes on the array of bounding boxes used by this algorithm.", py::arg("theBox"));
cls_Bnd_BoundSortBox.def("Compare", (const TColStd_ListOfInteger & (Bnd_BoundSortBox::*)(const gp_Pln &)) &Bnd_BoundSortBox::Compare, "Compares the plane P with the set of bounding boxes to be sorted by this comparison algorithm, and returns the list of intersecting bounding boxes as a list of indexes on the array of bounding boxes used by this algorithm.", py::arg("P"));
cls_Bnd_BoundSortBox.def("Dump", (void (Bnd_BoundSortBox::*)() const) &Bnd_BoundSortBox::Dump, "None");
cls_Bnd_BoundSortBox.def("Destroy", (void (Bnd_BoundSortBox::*)()) &Bnd_BoundSortBox::Destroy, "None");

// CLASS: BND_HARRAY1OFBOX2D
py::class_<Bnd_HArray1OfBox2d, opencascade::handle<Bnd_HArray1OfBox2d>, Standard_Transient> cls_Bnd_HArray1OfBox2d(mod, "Bnd_HArray1OfBox2d", "None", py::multiple_inheritance());

// Constructors
cls_Bnd_HArray1OfBox2d.def(py::init<>());
cls_Bnd_HArray1OfBox2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Bnd_HArray1OfBox2d.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfBox2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Bnd_HArray1OfBox2d.def(py::init<const Bnd_Array1OfBox2d &>(), py::arg("theOther"));

// Methods
// cls_Bnd_HArray1OfBox2d.def_static("operator new_", (void * (*)(size_t)) &Bnd_HArray1OfBox2d::operator new, "None", py::arg("theSize"));
// cls_Bnd_HArray1OfBox2d.def_static("operator delete_", (void (*)(void *)) &Bnd_HArray1OfBox2d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfBox2d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_HArray1OfBox2d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_HArray1OfBox2d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_HArray1OfBox2d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfBox2d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_HArray1OfBox2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_HArray1OfBox2d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_HArray1OfBox2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_Bnd_HArray1OfBox2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfBox2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Bnd_HArray1OfBox2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfBox2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Bnd_HArray1OfBox2d.def("Array1", (const Bnd_Array1OfBox2d & (Bnd_HArray1OfBox2d::*)() const) &Bnd_HArray1OfBox2d::Array1, "None");
cls_Bnd_HArray1OfBox2d.def("ChangeArray1", (Bnd_Array1OfBox2d & (Bnd_HArray1OfBox2d::*)()) &Bnd_HArray1OfBox2d::ChangeArray1, "None");
cls_Bnd_HArray1OfBox2d.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfBox2d::get_type_name, "None");
cls_Bnd_HArray1OfBox2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfBox2d::get_type_descriptor, "None");
cls_Bnd_HArray1OfBox2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfBox2d::*)() const) &Bnd_HArray1OfBox2d::DynamicType, "None");

// CLASS: BND_BOUNDSORTBOX2D
py::class_<Bnd_BoundSortBox2d> cls_Bnd_BoundSortBox2d(mod, "Bnd_BoundSortBox2d", "A tool to compare a 2D bounding box with a set of 2D bounding boxes. It sorts the set of bounding boxes to give the list of boxes which intersect the element being compared. The boxes being sorted generally bound a set of shapes, while the box being compared bounds a shape to be compared. The resulting list of intersecting boxes therefore gives the list of items which potentially intersect the shape to be compared.");

// Constructors
cls_Bnd_BoundSortBox2d.def(py::init<>());

// Methods
// cls_Bnd_BoundSortBox2d.def_static("operator new_", (void * (*)(size_t)) &Bnd_BoundSortBox2d::operator new, "None", py::arg("theSize"));
// cls_Bnd_BoundSortBox2d.def_static("operator delete_", (void (*)(void *)) &Bnd_BoundSortBox2d::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_BoundSortBox2d.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_BoundSortBox2d::operator new[], "None", py::arg("theSize"));
// cls_Bnd_BoundSortBox2d.def_static("operator delete[]_", (void (*)(void *)) &Bnd_BoundSortBox2d::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_BoundSortBox2d.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_BoundSortBox2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_BoundSortBox2d.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_BoundSortBox2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_BoundSortBox2d.def("Initialize", (void (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &, const opencascade::handle<Bnd_HArray1OfBox2d> &)) &Bnd_BoundSortBox2d::Initialize, "Initializes this comparison algorithm with - the set of 2D bounding boxes SetOfBox", py::arg("CompleteBox"), py::arg("SetOfBox"));
cls_Bnd_BoundSortBox2d.def("Initialize", (void (Bnd_BoundSortBox2d::*)(const opencascade::handle<Bnd_HArray1OfBox2d> &)) &Bnd_BoundSortBox2d::Initialize, "Initializes this comparison algorithm with - the set of 2D bounding boxes SetOfBox, where CompleteBox is given as the global bounding box of SetOfBox.", py::arg("SetOfBox"));
cls_Bnd_BoundSortBox2d.def("Initialize", (void (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &, const Standard_Integer)) &Bnd_BoundSortBox2d::Initialize, "Initializes this comparison algorithm, giving it only - the maximum number nbComponents, and - the global bounding box CompleteBox, of the 2D bounding boxes to be managed. Use the Add function to define the array of bounding boxes to be sorted by this algorithm.", py::arg("CompleteBox"), py::arg("nbComponents"));
cls_Bnd_BoundSortBox2d.def("Add", (void (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &, const Standard_Integer)) &Bnd_BoundSortBox2d::Add, "Adds the 2D bounding box theBox at position boxIndex in the array of boxes to be sorted by this comparison algorithm. This function is used only in conjunction with the third syntax described in the synopsis of Initialize. Exceptions - Standard_OutOfRange if boxIndex is not in the range [ 1,nbComponents ] where nbComponents is the maximum number of bounding boxes declared for this comparison algorithm at initialization. - Standard_MultiplyDefined if a box still exists at position boxIndex in the array of boxes to be sorted by this comparison algorithm.", py::arg("theBox"), py::arg("boxIndex"));
cls_Bnd_BoundSortBox2d.def("Compare", (const TColStd_ListOfInteger & (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &)) &Bnd_BoundSortBox2d::Compare, "Compares the 2D bounding box theBox with the set of bounding boxes to be sorted by this comparison algorithm, and returns the list of intersecting bounding boxes as a list of indexes on the array of bounding boxes used by this algorithm.", py::arg("theBox"));
cls_Bnd_BoundSortBox2d.def("Dump", (void (Bnd_BoundSortBox2d::*)() const) &Bnd_BoundSortBox2d::Dump, "None");

// CLASS: BND_HARRAY1OFSPHERE
py::class_<Bnd_HArray1OfSphere, opencascade::handle<Bnd_HArray1OfSphere>, Standard_Transient> cls_Bnd_HArray1OfSphere(mod, "Bnd_HArray1OfSphere", "None", py::multiple_inheritance());

// Constructors
cls_Bnd_HArray1OfSphere.def(py::init<>());
cls_Bnd_HArray1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Bnd_HArray1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfSphere::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Bnd_HArray1OfSphere.def(py::init<const Bnd_Array1OfSphere &>(), py::arg("theOther"));

// Methods
// cls_Bnd_HArray1OfSphere.def_static("operator new_", (void * (*)(size_t)) &Bnd_HArray1OfSphere::operator new, "None", py::arg("theSize"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete_", (void (*)(void *)) &Bnd_HArray1OfSphere::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfSphere.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_HArray1OfSphere::operator new[], "None", py::arg("theSize"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete[]_", (void (*)(void *)) &Bnd_HArray1OfSphere::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfSphere.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_HArray1OfSphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_HArray1OfSphere::operator delete, "None", py::arg(""), py::arg(""));
// cls_Bnd_HArray1OfSphere.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfSphere::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfSphere::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Bnd_HArray1OfSphere.def("Array1", (const Bnd_Array1OfSphere & (Bnd_HArray1OfSphere::*)() const) &Bnd_HArray1OfSphere::Array1, "None");
cls_Bnd_HArray1OfSphere.def("ChangeArray1", (Bnd_Array1OfSphere & (Bnd_HArray1OfSphere::*)()) &Bnd_HArray1OfSphere::ChangeArray1, "None");
cls_Bnd_HArray1OfSphere.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfSphere::get_type_name, "None");
cls_Bnd_HArray1OfSphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfSphere::get_type_descriptor, "None");
cls_Bnd_HArray1OfSphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfSphere::*)() const) &Bnd_HArray1OfSphere::DynamicType, "None");

// CLASS: BND_OBB
py::class_<Bnd_OBB> cls_Bnd_OBB(mod, "Bnd_OBB", "The class describes the Oriented Bounding Box (OBB), much tighter enclosing volume for the shape than the Axis Aligned Bounding Box (AABB). The OBB is defined by a center of the box, the axes and the halves of its three dimensions. The OBB can be used more effectively than AABB as a rejection mechanism for non-interfering objects.");

// Constructors
cls_Bnd_OBB.def(py::init<>());
cls_Bnd_OBB.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCenter"), py::arg("theXDirection"), py::arg("theYDirection"), py::arg("theZDirection"), py::arg("theHXSize"), py::arg("theHYSize"), py::arg("theHZSize"));
cls_Bnd_OBB.def(py::init<const Bnd_Box &>(), py::arg("theBox"));

// Methods
// cls_Bnd_OBB.def_static("operator new_", (void * (*)(size_t)) &Bnd_OBB::operator new, "None", py::arg("theSize"));
// cls_Bnd_OBB.def_static("operator delete_", (void (*)(void *)) &Bnd_OBB::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_OBB.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_OBB::operator new[], "None", py::arg("theSize"));
// cls_Bnd_OBB.def_static("operator delete[]_", (void (*)(void *)) &Bnd_OBB::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_OBB.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_OBB::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_OBB.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_OBB::operator delete, "None", py::arg(""), py::arg(""));
cls_Bnd_OBB.def("ReBuild", [](Bnd_OBB &self, const TColgp_Array1OfPnt & a0) -> void { return self.ReBuild(a0); });
cls_Bnd_OBB.def("ReBuild", [](Bnd_OBB &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal * a1) -> void { return self.ReBuild(a0, a1); });
cls_Bnd_OBB.def("ReBuild", (void (Bnd_OBB::*)(const TColgp_Array1OfPnt &, const TColStd_Array1OfReal *, const Standard_Boolean)) &Bnd_OBB::ReBuild, "Creates new OBB covering every point in theListOfPoints. Tolerance of every such point is set by *theListOfTolerances array. If this array is not void (not null-pointer) then the resulted Bnd_OBB will be enlarged using tolerances of points lying on the box surface. <theIsOptimal> flag defines the mode in which the OBB will be built. Constructing Optimal box takes more time, but the resulting box is usually more tight. In case of construction of Optimal OBB more possible axes are checked.", py::arg("theListOfPoints"), py::arg("theListOfTolerances"), py::arg("theIsOptimal"));
cls_Bnd_OBB.def("SetCenter", (void (Bnd_OBB::*)(const gp_Pnt &)) &Bnd_OBB::SetCenter, "Sets the center of OBB", py::arg("theCenter"));
cls_Bnd_OBB.def("SetXComponent", (void (Bnd_OBB::*)(const gp_Dir &, const Standard_Real)) &Bnd_OBB::SetXComponent, "Sets the X component of OBB - direction and size", py::arg("theXDirection"), py::arg("theHXSize"));
cls_Bnd_OBB.def("SetYComponent", (void (Bnd_OBB::*)(const gp_Dir &, const Standard_Real)) &Bnd_OBB::SetYComponent, "Sets the Y component of OBB - direction and size", py::arg("theYDirection"), py::arg("theHYSize"));
cls_Bnd_OBB.def("SetZComponent", (void (Bnd_OBB::*)(const gp_Dir &, const Standard_Real)) &Bnd_OBB::SetZComponent, "Sets the Z component of OBB - direction and size", py::arg("theZDirection"), py::arg("theHZSize"));
cls_Bnd_OBB.def("Position", (gp_Ax3 (Bnd_OBB::*)() const) &Bnd_OBB::Position, "Returns the local coordinates system of this oriented box. So that applying it to axis-aligned box ((-XHSize, -YHSize, -ZHSize), (XHSize, YHSize, ZHSize)) will produce this oriented box.");
cls_Bnd_OBB.def("Center", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::Center, "Returns the center of OBB");
cls_Bnd_OBB.def("XDirection", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::XDirection, "Returns the X Direction of OBB");
cls_Bnd_OBB.def("YDirection", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::YDirection, "Returns the Y Direction of OBB");
cls_Bnd_OBB.def("ZDirection", (const gp_XYZ & (Bnd_OBB::*)() const) &Bnd_OBB::ZDirection, "Returns the Z Direction of OBB");
cls_Bnd_OBB.def("XHSize", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::XHSize, "Returns the X Dimension of OBB");
cls_Bnd_OBB.def("YHSize", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::YHSize, "Returns the Y Dimension of OBB");
cls_Bnd_OBB.def("ZHSize", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::ZHSize, "Returns the Z Dimension of OBB");
cls_Bnd_OBB.def("IsVoid", (Standard_Boolean (Bnd_OBB::*)() const) &Bnd_OBB::IsVoid, "Checks if the box is empty.");
cls_Bnd_OBB.def("SetVoid", (void (Bnd_OBB::*)()) &Bnd_OBB::SetVoid, "Clears this box");
cls_Bnd_OBB.def("SetAABox", (void (Bnd_OBB::*)(const Standard_Boolean &)) &Bnd_OBB::SetAABox, "Sets the flag for axes aligned box", py::arg("theFlag"));
cls_Bnd_OBB.def("IsAABox", (Standard_Boolean (Bnd_OBB::*)() const) &Bnd_OBB::IsAABox, "Returns TRUE if the box is axes aligned");
cls_Bnd_OBB.def("Enlarge", (void (Bnd_OBB::*)(const Standard_Real)) &Bnd_OBB::Enlarge, "Enlarges the box with the given value", py::arg("theGapAdd"));
// cls_Bnd_OBB.def("GetVertex", (Standard_Boolean (Bnd_OBB::*)(gp_Pnt [8]) const) &Bnd_OBB::GetVertex, "Returns the array of vertices in <this>. The local coordinate of the vertex depending on the index of the array are follow: Index == 0: (-XHSize(), -YHSize(), -ZHSize()) Index == 1: ( XHSize(), -YHSize(), -ZHSize()) Index == 2: (-XHSize(), YHSize(), -ZHSize()) Index == 3: ( XHSize(), YHSize(), -ZHSize()) Index == 4: (-XHSize(), -YHSize(), ZHSize()) Index == 5: ( XHSize(), -YHSize(), ZHSize()) Index == 6: (-XHSize(), YHSize(), ZHSize()) Index == 7: ( XHSize(), YHSize(), ZHSize()).", py::arg("theP"));
cls_Bnd_OBB.def("SquareExtent", (Standard_Real (Bnd_OBB::*)() const) &Bnd_OBB::SquareExtent, "Returns square diagonal of this box");
cls_Bnd_OBB.def("IsOut", (Standard_Boolean (Bnd_OBB::*)(const Bnd_OBB &) const) &Bnd_OBB::IsOut, "Check if the box do not interfere the other box.", py::arg("theOther"));
cls_Bnd_OBB.def("IsOut", (Standard_Boolean (Bnd_OBB::*)(const gp_Pnt &) const) &Bnd_OBB::IsOut, "Check if the point is inside of <this>.", py::arg("theP"));
cls_Bnd_OBB.def("IsCompletelyInside", (Standard_Boolean (Bnd_OBB::*)(const Bnd_OBB &) const) &Bnd_OBB::IsCompletelyInside, "Check if the theOther is completely inside *this.", py::arg("theOther"));
cls_Bnd_OBB.def("Add", (void (Bnd_OBB::*)(const Bnd_OBB &)) &Bnd_OBB::Add, "Rebuilds this in order to include all previous objects (which it was created from) and theOther.", py::arg("theOther"));
cls_Bnd_OBB.def("Add", (void (Bnd_OBB::*)(const gp_Pnt &)) &Bnd_OBB::Add, "Rebuilds this in order to include all previous objects (which it was created from) and theP.", py::arg("theP"));
cls_Bnd_OBB.def("DumpJson", [](Bnd_OBB &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_Bnd_OBB.def("DumpJson", (void (Bnd_OBB::*)(Standard_OStream &, const Standard_Integer) const) &Bnd_OBB::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));

// TYPEDEF: BND_SEQOFBOX
bind_NCollection_Sequence<Bnd_Box>(mod, "Bnd_SeqOfBox", py::module_local(false));

// CLASS: BND_TOOLS
py::class_<Bnd_Tools> cls_Bnd_Tools(mod, "Bnd_Tools", "Defines a set of static methods operating with bounding boxes");

// Methods
cls_Bnd_Tools.def_static("Bnd2BVH_", (BVH_Box<Standard_Real, 2> (*)(const Bnd_Box2d &)) &Bnd_Tools::Bnd2BVH, "Converts the given Bnd_Box2d to BVH_Box", py::arg("theBox"));
cls_Bnd_Tools.def_static("Bnd2BVH_", (BVH_Box<Standard_Real, 3> (*)(const Bnd_Box &)) &Bnd_Tools::Bnd2BVH, "Converts the given Bnd_Box to BVH_Box", py::arg("theBox"));


}
