#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <gp_Trsf.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Trsf2d.hxx>
#include <NCollection_Array1.hxx>
#include <Bnd_Array1OfBox.hxx>
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
#include <Standard_Type.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <Bnd_HArray1OfBox2d.hxx>
#include <Bnd_BoundSortBox2d.hxx>
#include <Bnd_HArray1OfSphere.hxx>
#include <Bnd_Range.hxx>
#include <ApproxInt_KnotTools.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <Bnd_SeqOfBox.hxx>

PYBIND11_MODULE(Bnd, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.ApproxInt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_Box.hxx
	py::class_<Bnd_Box, std::unique_ptr<Bnd_Box, Deleter<Bnd_Box>>> cls_Bnd_Box(mod, "Bnd_Box", "Describes a bounding box in 3D space. A bounding box is parallel to the axes of the coordinates system. If it is finite, it is defined by the three intervals: - [ Xmin,Xmax ], - [ Ymin,Ymax ], - [ Zmin,Zmax ]. A bounding box may be infinite (i.e. open) in one or more directions. It is said to be: - OpenXmin if it is infinite on the negative side of the 'X Direction'; - OpenXmax if it is infinite on the positive side of the 'X Direction'; - OpenYmin if it is infinite on the negative side of the 'Y Direction'; - OpenYmax if it is infinite on the positive side of the 'Y Direction'; - OpenZmin if it is infinite on the negative side of the 'Z Direction'; - OpenZmax if it is infinite on the positive side of the 'Z Direction'; - WholeSpace if it is infinite in all six directions. In this case, any point of the space is inside the box; - Void if it is empty. In this case, there is no point included in the box. A bounding box is defined by: - six bounds (Xmin, Xmax, Ymin, Ymax, Zmin and Zmax) which limit the bounding box if it is finite, - eight flags (OpenXmin, OpenXmax, OpenYmin, OpenYmax, OpenZmin, OpenZmax, WholeSpace and Void) which describe the bounding box if it is infinite or empty, and - a gap, which is included on both sides in any direction when consulting the finite bounds of the box.");
	cls_Bnd_Box.def(py::init<>());
	cls_Bnd_Box.def("SetWhole", (void (Bnd_Box::*)()) &Bnd_Box::SetWhole, "Sets this bounding box so that it covers the whole of 3D space. It is infinitely long in all directions.");
	cls_Bnd_Box.def("SetVoid", (void (Bnd_Box::*)()) &Bnd_Box::SetVoid, "Sets this bounding box so that it is empty. All points are outside a void box.");
	cls_Bnd_Box.def("Set", (void (Bnd_Box::*)(const gp_Pnt &)) &Bnd_Box::Set, "Sets this bounding box so that it bounds - the point P. This involves first setting this bounding box to be void and then adding the point P.", py::arg("P"));
	cls_Bnd_Box.def("Set", (void (Bnd_Box::*)(const gp_Pnt &, const gp_Dir &)) &Bnd_Box::Set, "Sets this bounding box so that it bounds the half-line defined by point P and direction D, i.e. all points M defined by M=P+u*D, where u is greater than or equal to 0, are inside the bounding volume. This involves first setting this box to be void and then adding the half-line.", py::arg("P"), py::arg("D"));
	cls_Bnd_Box.def("Update", (void (Bnd_Box::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box::Update, "Enlarges this bounding box, if required, so that it contains at least: - interval [ aXmin,aXmax ] in the 'X Direction', - interval [ aYmin,aYmax ] in the 'Y Direction', - interval [ aZmin,aZmax ] in the 'Z Direction';", py::arg("aXmin"), py::arg("aYmin"), py::arg("aZmin"), py::arg("aXmax"), py::arg("aYmax"), py::arg("aZmax"));
	cls_Bnd_Box.def("Update", (void (Bnd_Box::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box::Update, "Adds a point of coordinates (X,Y,Z) to this bounding box.", py::arg("X"), py::arg("Y"), py::arg("Z"));
	cls_Bnd_Box.def("GetGap", (Standard_Real (Bnd_Box::*)() const ) &Bnd_Box::GetGap, "Returns the gap of this bounding box.");
	cls_Bnd_Box.def("SetGap", (void (Bnd_Box::*)(const Standard_Real)) &Bnd_Box::SetGap, "Set the gap of this bounding box to abs(Tol).", py::arg("Tol"));
	cls_Bnd_Box.def("Enlarge", (void (Bnd_Box::*)(const Standard_Real)) &Bnd_Box::Enlarge, "Enlarges the box with a tolerance value. (minvalues-Abs(<tol>) and maxvalues+Abs(<tol>)) This means that the minimum values of its X, Y and Z intervals of definition, when they are finite, are reduced by the absolute value of Tol, while the maximum values are increased by the same amount.", py::arg("Tol"));
	cls_Bnd_Box.def("Get", (void (Bnd_Box::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &Bnd_Box::Get, "Returns the bounds of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()", py::arg("theXmin"), py::arg("theYmin"), py::arg("theZmin"), py::arg("theXmax"), py::arg("theYmax"), py::arg("theZmax"));
	cls_Bnd_Box.def("CornerMin", (gp_Pnt (Bnd_Box::*)() const ) &Bnd_Box::CornerMin, "Returns the lower corner of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()");
	cls_Bnd_Box.def("CornerMax", (gp_Pnt (Bnd_Box::*)() const ) &Bnd_Box::CornerMax, "Returns the upper corner of this bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). Standard_ConstructionError exception will be thrown if the box is void. if IsVoid()");
	cls_Bnd_Box.def("OpenXmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenXmin, "The Box will be infinitely long in the Xmin direction.");
	cls_Bnd_Box.def("OpenXmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenXmax, "The Box will be infinitely long in the Xmax direction.");
	cls_Bnd_Box.def("OpenYmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenYmin, "The Box will be infinitely long in the Ymin direction.");
	cls_Bnd_Box.def("OpenYmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenYmax, "The Box will be infinitely long in the Ymax direction.");
	cls_Bnd_Box.def("OpenZmin", (void (Bnd_Box::*)()) &Bnd_Box::OpenZmin, "The Box will be infinitely long in the Zmin direction.");
	cls_Bnd_Box.def("OpenZmax", (void (Bnd_Box::*)()) &Bnd_Box::OpenZmax, "The Box will be infinitely long in the Zmax direction.");
	cls_Bnd_Box.def("IsOpenXmin", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsOpenXmin, "Returns true if this bounding box is open in the Xmin direction.");
	cls_Bnd_Box.def("IsOpenXmax", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsOpenXmax, "Returns true if this bounding box is open in the Xmax direction.");
	cls_Bnd_Box.def("IsOpenYmin", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsOpenYmin, "Returns true if this bounding box is open in the Ymix direction.");
	cls_Bnd_Box.def("IsOpenYmax", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsOpenYmax, "Returns true if this bounding box is open in the Ymax direction.");
	cls_Bnd_Box.def("IsOpenZmin", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsOpenZmin, "Returns true if this bounding box is open in the Zmin direction.");
	cls_Bnd_Box.def("IsOpenZmax", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsOpenZmax, "Returns true if this bounding box is open in the Zmax direction.");
	cls_Bnd_Box.def("IsWhole", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsWhole, "Returns true if this bounding box is infinite in all 6 directions (WholeSpace flag).");
	cls_Bnd_Box.def("IsVoid", (Standard_Boolean (Bnd_Box::*)() const ) &Bnd_Box::IsVoid, "Returns true if this bounding box is empty (Void flag).");
	cls_Bnd_Box.def("IsXThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const ) &Bnd_Box::IsXThin, "true if xmax-xmin < tol.", py::arg("tol"));
	cls_Bnd_Box.def("IsYThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const ) &Bnd_Box::IsYThin, "true if ymax-ymin < tol.", py::arg("tol"));
	cls_Bnd_Box.def("IsZThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const ) &Bnd_Box::IsZThin, "true if zmax-zmin < tol.", py::arg("tol"));
	cls_Bnd_Box.def("IsThin", (Standard_Boolean (Bnd_Box::*)(const Standard_Real) const ) &Bnd_Box::IsThin, "Returns true if IsXThin, IsYThin and IsZThin are all true, i.e. if the box is thin in all three dimensions.", py::arg("tol"));
	cls_Bnd_Box.def("Transformed", (Bnd_Box (Bnd_Box::*)(const gp_Trsf &) const ) &Bnd_Box::Transformed, "Returns a bounding box which is the result of applying the transformation T to this bounding box. Warning Applying a geometric transformation (for example, a rotation) to a bounding box generally increases its dimensions. This is not optimal for algorithms which use it.", py::arg("T"));
	cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const Bnd_Box &)) &Bnd_Box::Add, "Adds the box <Other> to <me>.", py::arg("Other"));
	cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Pnt &)) &Bnd_Box::Add, "Adds a Pnt to the box.", py::arg("P"));
	cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Pnt &, const gp_Dir &)) &Bnd_Box::Add, "Extends <me> from the Pnt <P> in the direction <D>.", py::arg("P"), py::arg("D"));
	cls_Bnd_Box.def("Add", (void (Bnd_Box::*)(const gp_Dir &)) &Bnd_Box::Add, "Extends the Box in the given Direction, i.e. adds an half-line. The box may become infinite in 1,2 or 3 directions.", py::arg("D"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pnt &) const ) &Bnd_Box::IsOut, "Returns True if the Pnt is out the box.", py::arg("P"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Lin &) const ) &Bnd_Box::IsOut, "Returns False if the line intersects the box.", py::arg("L"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pln &) const ) &Bnd_Box::IsOut, "Returns False if the plane intersects the box.", py::arg("P"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const Bnd_Box &) const ) &Bnd_Box::IsOut, "Returns False if the <Box> intersects or is inside <me>.", py::arg("Other"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const Bnd_Box &, const gp_Trsf &) const ) &Bnd_Box::IsOut, "Returns False if the transformed <Box> intersects or is inside <me>.", py::arg("Other"), py::arg("T"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Trsf &, const Bnd_Box &, const gp_Trsf &) const ) &Bnd_Box::IsOut, "Returns False if the transformed <Box> intersects or is inside the transformed box <me>.", py::arg("T1"), py::arg("Other"), py::arg("T2"));
	cls_Bnd_Box.def("IsOut", (Standard_Boolean (Bnd_Box::*)(const gp_Pnt &, const gp_Pnt &, const gp_Dir &) const ) &Bnd_Box::IsOut, "Returns False if the flat band lying between two parallel lines represented by their reference points <P1>, <P2> and direction <D> intersects the box.", py::arg("P1"), py::arg("P2"), py::arg("D"));
	cls_Bnd_Box.def("Distance", (Standard_Real (Bnd_Box::*)(const Bnd_Box &) const ) &Bnd_Box::Distance, "Computes the minimum distance between two boxes.", py::arg("Other"));
	// FIXME cls_Bnd_Box.def("Dump", (void (Bnd_Box::*)() const ) &Bnd_Box::Dump, "None");
	cls_Bnd_Box.def("SquareExtent", (Standard_Real (Bnd_Box::*)() const ) &Bnd_Box::SquareExtent, "Computes the squared diagonal of me.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_Box2d.hxx
	py::class_<Bnd_Box2d, std::unique_ptr<Bnd_Box2d, Deleter<Bnd_Box2d>>> cls_Bnd_Box2d(mod, "Bnd_Box2d", "Describes a bounding box in 2D space. A bounding box is parallel to the axes of the coordinates system. If it is finite, it is defined by the two intervals: - [ Xmin,Xmax ], and - [ Ymin,Ymax ]. A bounding box may be infinite (i.e. open) in one or more directions. It is said to be: - OpenXmin if it is infinite on the negative side of the 'X Direction'; - OpenXmax if it is infinite on the positive side of the 'X Direction'; - OpenYmin if it is infinite on the negative side of the 'Y Direction'; - OpenYmax if it is infinite on the positive side of the 'Y Direction'; - WholeSpace if it is infinite in all four directions. In this case, any point of the space is inside the box; - Void if it is empty. In this case, there is no point included in the box. A bounding box is defined by four bounds (Xmin, Xmax, Ymin and Ymax) which limit the bounding box if it is finite, six flags (OpenXmin, OpenXmax, OpenYmin, OpenYmax, WholeSpace and Void) which describe the bounding box if it is infinite or empty, and - a gap, which is included on both sides in any direction when consulting the finite bounds of the box.");
	cls_Bnd_Box2d.def(py::init<>());
	cls_Bnd_Box2d.def("SetWhole", (void (Bnd_Box2d::*)()) &Bnd_Box2d::SetWhole, "Sets this bounding box so that it covers the whole 2D space, i.e. it is infinite in all directions.");
	cls_Bnd_Box2d.def("SetVoid", (void (Bnd_Box2d::*)()) &Bnd_Box2d::SetVoid, "Sets this 2D bounding box so that it is empty. All points are outside a void box.");
	cls_Bnd_Box2d.def("Set", (void (Bnd_Box2d::*)(const gp_Pnt2d &)) &Bnd_Box2d::Set, "Sets this 2D bounding box so that it bounds the point P. This involves first setting this bounding box to be void and then adding the point PThe rectangle bounds the point <P>.", py::arg("thePnt"));
	cls_Bnd_Box2d.def("Set", (void (Bnd_Box2d::*)(const gp_Pnt2d &, const gp_Dir2d &)) &Bnd_Box2d::Set, "Sets this 2D bounding box so that it bounds the half-line defined by point P and direction D, i.e. all points M defined by M=P+u*D, where u is greater than or equal to 0, are inside the bounding area. This involves first setting this 2D box to be void and then adding the half-line.", py::arg("thePnt"), py::arg("theDir"));
	cls_Bnd_Box2d.def("Update", (void (Bnd_Box2d::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Bnd_Box2d::Update, "Enlarges this 2D bounding box, if required, so that it contains at least: - interval [ aXmin,aXmax ] in the 'X Direction', - interval [ aYmin,aYmax ] in the 'Y Direction'", py::arg("aXmin"), py::arg("aYmin"), py::arg("aXmax"), py::arg("aYmax"));
	cls_Bnd_Box2d.def("Update", (void (Bnd_Box2d::*)(const Standard_Real, const Standard_Real)) &Bnd_Box2d::Update, "Adds a point of coordinates (X,Y) to this bounding box.", py::arg("X"), py::arg("Y"));
	cls_Bnd_Box2d.def("GetGap", (Standard_Real (Bnd_Box2d::*)() const ) &Bnd_Box2d::GetGap, "Returns the gap of this 2D bounding box.");
	cls_Bnd_Box2d.def("SetGap", (void (Bnd_Box2d::*)(const Standard_Real)) &Bnd_Box2d::SetGap, "Set the gap of this 2D bounding box to abs(Tol).", py::arg("Tol"));
	cls_Bnd_Box2d.def("Enlarge", (void (Bnd_Box2d::*)(const Standard_Real)) &Bnd_Box2d::Enlarge, "Enlarges the box with a tolerance value. This means that the minimum values of its X and Y intervals of definition, when they are finite, are reduced by the absolute value of Tol, while the maximum values are increased by the same amount.", py::arg("theTol"));
	cls_Bnd_Box2d.def("Get", (void (Bnd_Box2d::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &Bnd_Box2d::Get, "Returns the bounds of this 2D bounding box. The gap is included. If this bounding box is infinite (i.e. 'open'), returned values may be equal to +/- Precision::Infinite(). if IsVoid()", py::arg("aXmin"), py::arg("aYmin"), py::arg("aXmax"), py::arg("aYmax"));
	cls_Bnd_Box2d.def("OpenXmin", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenXmin, "The Box will be infinitely long in the Xmin direction.");
	cls_Bnd_Box2d.def("OpenXmax", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenXmax, "The Box will be infinitely long in the Xmax direction.");
	cls_Bnd_Box2d.def("OpenYmin", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenYmin, "The Box will be infinitely long in the Ymin direction.");
	cls_Bnd_Box2d.def("OpenYmax", (void (Bnd_Box2d::*)()) &Bnd_Box2d::OpenYmax, "The Box will be infinitely long in the Ymax direction.");
	cls_Bnd_Box2d.def("IsOpenXmin", (Standard_Boolean (Bnd_Box2d::*)() const ) &Bnd_Box2d::IsOpenXmin, "Returns true if this bounding box is open in the Xmin direction.");
	cls_Bnd_Box2d.def("IsOpenXmax", (Standard_Boolean (Bnd_Box2d::*)() const ) &Bnd_Box2d::IsOpenXmax, "Returns true if this bounding box is open in the Xmax direction.");
	cls_Bnd_Box2d.def("IsOpenYmin", (Standard_Boolean (Bnd_Box2d::*)() const ) &Bnd_Box2d::IsOpenYmin, "Returns true if this bounding box is open in the Ymin direction.");
	cls_Bnd_Box2d.def("IsOpenYmax", (Standard_Boolean (Bnd_Box2d::*)() const ) &Bnd_Box2d::IsOpenYmax, "Returns true if this bounding box is open in the Ymax direction.");
	cls_Bnd_Box2d.def("IsWhole", (Standard_Boolean (Bnd_Box2d::*)() const ) &Bnd_Box2d::IsWhole, "Returns true if this bounding box is infinite in all 4 directions (Whole Space flag).");
	cls_Bnd_Box2d.def("IsVoid", (Standard_Boolean (Bnd_Box2d::*)() const ) &Bnd_Box2d::IsVoid, "Returns true if this 2D bounding box is empty (Void flag).");
	cls_Bnd_Box2d.def("Transformed", (Bnd_Box2d (Bnd_Box2d::*)(const gp_Trsf2d &) const ) &Bnd_Box2d::Transformed, "Returns a bounding box which is the result of applying the transformation T to this bounding box. Warning Applying a geometric transformation (for example, a rotation) to a bounding box generally increases its dimensions. This is not optimal for algorithms which use it.", py::arg("T"));
	cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const Bnd_Box2d &)) &Bnd_Box2d::Add, "Adds the 2d box <Other> to <me>.", py::arg("Other"));
	cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Pnt2d &)) &Bnd_Box2d::Add, "Adds the 2d point.", py::arg("thePnt"));
	cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Pnt2d &, const gp_Dir2d &)) &Bnd_Box2d::Add, "Extends bounding box from thePnt in the direction theDir.", py::arg("thePnt"), py::arg("theDir"));
	cls_Bnd_Box2d.def("Add", (void (Bnd_Box2d::*)(const gp_Dir2d &)) &Bnd_Box2d::Add, "Extends the Box in the given Direction, i.e. adds a half-line. The box may become infinite in 1 or 2 directions.", py::arg("D"));
	cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const gp_Pnt2d &) const ) &Bnd_Box2d::IsOut, "Returns True if the 2d pnt <P> is out <me>.", py::arg("P"));
	cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const Bnd_Box2d &) const ) &Bnd_Box2d::IsOut, "Returns True if <Box2d> is out <me>.", py::arg("Other"));
	cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const Bnd_Box2d &, const gp_Trsf2d &) const ) &Bnd_Box2d::IsOut, "Returns True if transformed <Box2d> is out <me>.", py::arg("theOther"), py::arg("theTrsf"));
	cls_Bnd_Box2d.def("IsOut", (Standard_Boolean (Bnd_Box2d::*)(const gp_Trsf2d &, const Bnd_Box2d &, const gp_Trsf2d &) const ) &Bnd_Box2d::IsOut, "Compares a transformed bounding with a transformed bounding. The default implementation is to make a copy of <me> and <Other>, to transform them and to test.", py::arg("T1"), py::arg("Other"), py::arg("T2"));
	// FIXME cls_Bnd_Box2d.def("Dump", (void (Bnd_Box2d::*)() const ) &Bnd_Box2d::Dump, "None");
	cls_Bnd_Box2d.def("SquareExtent", (Standard_Real (Bnd_Box2d::*)() const ) &Bnd_Box2d::SquareExtent, "Computes the squared diagonal of me.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_Sphere.hxx
	py::class_<Bnd_Sphere, std::unique_ptr<Bnd_Sphere, Deleter<Bnd_Sphere>>> cls_Bnd_Sphere(mod, "Bnd_Sphere", "This class represents a bounding sphere of a geometric entity (triangle, segment of line or whatever else).");
	cls_Bnd_Sphere.def(py::init<>());
	cls_Bnd_Sphere.def(py::init<const gp_XYZ &, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theCntr"), py::arg("theRad"), py::arg("theU"), py::arg("theV"));
	cls_Bnd_Sphere.def("U", (Standard_Integer (Bnd_Sphere::*)() const ) &Bnd_Sphere::U, "Returns the U parameter on shape");
	cls_Bnd_Sphere.def("V", (Standard_Integer (Bnd_Sphere::*)() const ) &Bnd_Sphere::V, "Returns the V parameter on shape");
	cls_Bnd_Sphere.def("IsValid", (Standard_Boolean (Bnd_Sphere::*)() const ) &Bnd_Sphere::IsValid, "Returns validity status, indicating that this sphere corresponds to a real entity");
	cls_Bnd_Sphere.def("SetValid", (void (Bnd_Sphere::*)(const Standard_Boolean)) &Bnd_Sphere::SetValid, "None", py::arg("isValid"));
	cls_Bnd_Sphere.def("Center", (const gp_XYZ & (Bnd_Sphere::*)() const ) &Bnd_Sphere::Center, "Returns center of sphere object");
	cls_Bnd_Sphere.def("Radius", (Standard_Real (Bnd_Sphere::*)() const ) &Bnd_Sphere::Radius, "Returns the radius value");
	cls_Bnd_Sphere.def("Distances", (void (Bnd_Sphere::*)(const gp_XYZ &, Standard_Real &, Standard_Real &) const ) &Bnd_Sphere::Distances, "Calculate and return minimal and maximal distance to sphere. NOTE: This function is tightly optimized; any modifications may affect performance!", py::arg("theXYZ"), py::arg("theMin"), py::arg("theMax"));
	cls_Bnd_Sphere.def("SquareDistances", (void (Bnd_Sphere::*)(const gp_XYZ &, Standard_Real &, Standard_Real &) const ) &Bnd_Sphere::SquareDistances, "Calculate and return minimal and maximal distance to sphere. NOTE: This function is tightly optimized; any modifications may affect performance!", py::arg("theXYZ"), py::arg("theMin"), py::arg("theMax"));
	cls_Bnd_Sphere.def("Project", (Standard_Boolean (Bnd_Sphere::*)(const gp_XYZ &, gp_XYZ &, Standard_Real &, Standard_Boolean &) const ) &Bnd_Sphere::Project, "Projects a point on entity. Returns true if success", py::arg("theNode"), py::arg("theProjNode"), py::arg("theDist"), py::arg("theInside"));
	cls_Bnd_Sphere.def("Distance", (Standard_Real (Bnd_Sphere::*)(const gp_XYZ &) const ) &Bnd_Sphere::Distance, "None", py::arg("theNode"));
	cls_Bnd_Sphere.def("SquareDistance", (Standard_Real (Bnd_Sphere::*)(const gp_XYZ &) const ) &Bnd_Sphere::SquareDistance, "None", py::arg("theNode"));
	cls_Bnd_Sphere.def("Add", (void (Bnd_Sphere::*)(const Bnd_Sphere &)) &Bnd_Sphere::Add, "None", py::arg("theOther"));
	cls_Bnd_Sphere.def("IsOut", (Standard_Boolean (Bnd_Sphere::*)(const Bnd_Sphere &) const ) &Bnd_Sphere::IsOut, "None", py::arg("theOther"));
	cls_Bnd_Sphere.def("IsOut", (Standard_Boolean (Bnd_Sphere::*)(const gp_XYZ &, Standard_Real &) const ) &Bnd_Sphere::IsOut, "None", py::arg("thePnt"), py::arg("theMaxDist"));
	cls_Bnd_Sphere.def("SquareExtent", (Standard_Real (Bnd_Sphere::*)() const ) &Bnd_Sphere::SquareExtent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_B2d.hxx
	py::class_<Bnd_B2d, std::unique_ptr<Bnd_B2d, Deleter<Bnd_B2d>>> cls_Bnd_B2d(mod, "Bnd_B2d", "None");
	cls_Bnd_B2d.def(py::init<>());
	cls_Bnd_B2d.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("theCenter"), py::arg("theHSize"));
	cls_Bnd_B2d.def("IsVoid", (Standard_Boolean (Bnd_B2d::*)() const ) &Bnd_B2d::IsVoid, "Returns True if the box is void (non-initialized).");
	cls_Bnd_B2d.def("Clear", (void (Bnd_B2d::*)()) &Bnd_B2d::Clear, "Reset the box data.");
	cls_Bnd_B2d.def("Add", (void (Bnd_B2d::*)(const gp_XY &)) &Bnd_B2d::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B2d.def("Add", (void (Bnd_B2d::*)(const gp_Pnt2d &)) &Bnd_B2d::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B2d.def("Add", (void (Bnd_B2d::*)(const Bnd_B2d &)) &Bnd_B2d::Add, "Update the box by another box.", py::arg("theBox"));
	cls_Bnd_B2d.def("CornerMin", (gp_XY (Bnd_B2d::*)() const ) &Bnd_B2d::CornerMin, "Query a box corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B2d.def("CornerMax", (gp_XY (Bnd_B2d::*)() const ) &Bnd_B2d::CornerMax, "Query a box corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B2d.def("SquareExtent", (Standard_Real (Bnd_B2d::*)() const ) &Bnd_B2d::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
	cls_Bnd_B2d.def("Enlarge", (void (Bnd_B2d::*)(const Standard_Real)) &Bnd_B2d::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
	cls_Bnd_B2d.def("Limit", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &)) &Bnd_B2d::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
	cls_Bnd_B2d.def("Transformed", (Bnd_B2d (Bnd_B2d::*)(const gp_Trsf2d &) const ) &Bnd_B2d::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
	cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_XY &) const ) &Bnd_B2d::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
	cls_Bnd_B2d.def("IsOut", [](Bnd_B2d &self, const gp_XY & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); }, py::arg("theCenter"), py::arg("theRadius"));
	cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_XY &, const Standard_Real, const Standard_Boolean) const ) &Bnd_B2d::IsOut, "Check a circle for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theCenter"), py::arg("theRadius"), py::arg("isCircleHollow"));
	cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &) const ) &Bnd_B2d::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
	cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &, const gp_Trsf2d &) const ) &Bnd_B2d::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
	cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_Ax2d &) const ) &Bnd_B2d::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection.", py::arg("theLine"));
	cls_Bnd_B2d.def("IsOut", (Standard_Boolean (Bnd_B2d::*)(const gp_XY &, const gp_XY &) const ) &Bnd_B2d::IsOut, "Check the Segment defined by the couple of input points for the intersection with the current box. Returns True if there is no intersection.", py::arg("theP0"), py::arg("theP1"));
	cls_Bnd_B2d.def("IsIn", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &) const ) &Bnd_B2d::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
	cls_Bnd_B2d.def("IsIn", (Standard_Boolean (Bnd_B2d::*)(const Bnd_B2d &, const gp_Trsf2d &) const ) &Bnd_B2d::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
	cls_Bnd_B2d.def("SetCenter", (void (Bnd_B2d::*)(const gp_XY &)) &Bnd_B2d::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
	cls_Bnd_B2d.def("SetHSize", (void (Bnd_B2d::*)(const gp_XY &)) &Bnd_B2d::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_B2f.hxx
	py::class_<Bnd_B2f, std::unique_ptr<Bnd_B2f, Deleter<Bnd_B2f>>> cls_Bnd_B2f(mod, "Bnd_B2f", "None");
	cls_Bnd_B2f.def(py::init<>());
	cls_Bnd_B2f.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("theCenter"), py::arg("theHSize"));
	cls_Bnd_B2f.def("IsVoid", (Standard_Boolean (Bnd_B2f::*)() const ) &Bnd_B2f::IsVoid, "Returns True if the box is void (non-initialized).");
	cls_Bnd_B2f.def("Clear", (void (Bnd_B2f::*)()) &Bnd_B2f::Clear, "Reset the box data.");
	cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const gp_Pnt2d &)) &Bnd_B2f::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B2f.def("Add", (void (Bnd_B2f::*)(const Bnd_B2f &)) &Bnd_B2f::Add, "Update the box by another box.", py::arg("theBox"));
	cls_Bnd_B2f.def("CornerMin", (gp_XY (Bnd_B2f::*)() const ) &Bnd_B2f::CornerMin, "Query a box corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B2f.def("CornerMax", (gp_XY (Bnd_B2f::*)() const ) &Bnd_B2f::CornerMax, "Query a box corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B2f.def("SquareExtent", (Standard_Real (Bnd_B2f::*)() const ) &Bnd_B2f::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
	cls_Bnd_B2f.def("Enlarge", (void (Bnd_B2f::*)(const Standard_Real)) &Bnd_B2f::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
	cls_Bnd_B2f.def("Limit", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &)) &Bnd_B2f::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
	cls_Bnd_B2f.def("Transformed", (Bnd_B2f (Bnd_B2f::*)(const gp_Trsf2d &) const ) &Bnd_B2f::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
	cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &) const ) &Bnd_B2f::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
	cls_Bnd_B2f.def("IsOut", [](Bnd_B2f &self, const gp_XY & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); }, py::arg("theCenter"), py::arg("theRadius"));
	cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &, const Standard_Real, const Standard_Boolean) const ) &Bnd_B2f::IsOut, "Check a circle for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theCenter"), py::arg("theRadius"), py::arg("isCircleHollow"));
	cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &) const ) &Bnd_B2f::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
	cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &, const gp_Trsf2d &) const ) &Bnd_B2f::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
	cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_Ax2d &) const ) &Bnd_B2f::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection.", py::arg("theLine"));
	cls_Bnd_B2f.def("IsOut", (Standard_Boolean (Bnd_B2f::*)(const gp_XY &, const gp_XY &) const ) &Bnd_B2f::IsOut, "Check the Segment defined by the couple of input points for the intersection with the current box. Returns True if there is no intersection.", py::arg("theP0"), py::arg("theP1"));
	cls_Bnd_B2f.def("IsIn", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &) const ) &Bnd_B2f::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
	cls_Bnd_B2f.def("IsIn", (Standard_Boolean (Bnd_B2f::*)(const Bnd_B2f &, const gp_Trsf2d &) const ) &Bnd_B2f::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
	cls_Bnd_B2f.def("SetCenter", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
	cls_Bnd_B2f.def("SetHSize", (void (Bnd_B2f::*)(const gp_XY &)) &Bnd_B2f::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_B3d.hxx
	py::class_<Bnd_B3d, std::unique_ptr<Bnd_B3d, Deleter<Bnd_B3d>>> cls_Bnd_B3d(mod, "Bnd_B3d", "None");
	cls_Bnd_B3d.def(py::init<>());
	cls_Bnd_B3d.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("theCenter"), py::arg("theHSize"));
	cls_Bnd_B3d.def("IsVoid", (Standard_Boolean (Bnd_B3d::*)() const ) &Bnd_B3d::IsVoid, "Returns True if the box is void (non-initialized).");
	cls_Bnd_B3d.def("Clear", (void (Bnd_B3d::*)()) &Bnd_B3d::Clear, "Reset the box data.");
	cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const gp_Pnt &)) &Bnd_B3d::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B3d.def("Add", (void (Bnd_B3d::*)(const Bnd_B3d &)) &Bnd_B3d::Add, "Update the box by another box.", py::arg("theBox"));
	cls_Bnd_B3d.def("CornerMin", (gp_XYZ (Bnd_B3d::*)() const ) &Bnd_B3d::CornerMin, "Query the lower corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B3d.def("CornerMax", (gp_XYZ (Bnd_B3d::*)() const ) &Bnd_B3d::CornerMax, "Query the upper corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B3d.def("SquareExtent", (Standard_Real (Bnd_B3d::*)() const ) &Bnd_B3d::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
	cls_Bnd_B3d.def("Enlarge", (void (Bnd_B3d::*)(const Standard_Real)) &Bnd_B3d::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
	cls_Bnd_B3d.def("Limit", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &)) &Bnd_B3d::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
	cls_Bnd_B3d.def("Transformed", (Bnd_B3d (Bnd_B3d::*)(const gp_Trsf &) const ) &Bnd_B3d::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
	cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_XYZ &) const ) &Bnd_B3d::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
	cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_XYZ & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); }, py::arg("theCenter"), py::arg("theRadius"));
	cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_XYZ &, const Standard_Real, const Standard_Boolean) const ) &Bnd_B3d::IsOut, "Check a sphere for the intersection with the current box. Returns True if there is no intersection between boxes. If the parameter 'IsSphereHollow' is True, then the intersection is not reported for a box that is completely inside the sphere (otherwise this method would report an intersection).", py::arg("theCenter"), py::arg("theRadius"), py::arg("isSphereHollow"));
	cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &) const ) &Bnd_B3d::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
	cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &, const gp_Trsf &) const ) &Bnd_B3d::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
	cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_Ax1 & a0) -> Standard_Boolean { return self.IsOut(a0); }, py::arg("theLine"));
	cls_Bnd_B3d.def("IsOut", [](Bnd_B3d &self, const gp_Ax1 & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.IsOut(a0, a1); }, py::arg("theLine"), py::arg("isRay"));
	cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_Ax1 &, const Standard_Boolean, const Standard_Real) const ) &Bnd_B3d::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection. isRay==True means intersection check with the positive half-line theOverthickness is the addition to the size of the current box (may be negative). If positive, it can be treated as the thickness of the line 'theLine' or the radius of the cylinder along 'theLine'", py::arg("theLine"), py::arg("isRay"), py::arg("theOverthickness"));
	cls_Bnd_B3d.def("IsOut", (Standard_Boolean (Bnd_B3d::*)(const gp_Ax3 &) const ) &Bnd_B3d::IsOut, "Check the given Plane for the intersection with the current box. Returns True if there is no intersection.", py::arg("thePlane"));
	cls_Bnd_B3d.def("IsIn", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &) const ) &Bnd_B3d::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
	cls_Bnd_B3d.def("IsIn", (Standard_Boolean (Bnd_B3d::*)(const Bnd_B3d &, const gp_Trsf &) const ) &Bnd_B3d::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
	cls_Bnd_B3d.def("SetCenter", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
	cls_Bnd_B3d.def("SetHSize", (void (Bnd_B3d::*)(const gp_XYZ &)) &Bnd_B3d::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_B3f.hxx
	py::class_<Bnd_B3f, std::unique_ptr<Bnd_B3f, Deleter<Bnd_B3f>>> cls_Bnd_B3f(mod, "Bnd_B3f", "None");
	cls_Bnd_B3f.def(py::init<>());
	cls_Bnd_B3f.def(py::init<const gp_XYZ &, const gp_XYZ &>(), py::arg("theCenter"), py::arg("theHSize"));
	cls_Bnd_B3f.def("IsVoid", (Standard_Boolean (Bnd_B3f::*)() const ) &Bnd_B3f::IsVoid, "Returns True if the box is void (non-initialized).");
	cls_Bnd_B3f.def("Clear", (void (Bnd_B3f::*)()) &Bnd_B3f::Clear, "Reset the box data.");
	cls_Bnd_B3f.def("Add", (void (Bnd_B3f::*)(const gp_XYZ &)) &Bnd_B3f::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B3f.def("Add", (void (Bnd_B3f::*)(const gp_Pnt &)) &Bnd_B3f::Add, "Update the box by a point.", py::arg("thePnt"));
	cls_Bnd_B3f.def("Add", (void (Bnd_B3f::*)(const Bnd_B3f &)) &Bnd_B3f::Add, "Update the box by another box.", py::arg("theBox"));
	cls_Bnd_B3f.def("CornerMin", (gp_XYZ (Bnd_B3f::*)() const ) &Bnd_B3f::CornerMin, "Query the lower corner: (Center - HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B3f.def("CornerMax", (gp_XYZ (Bnd_B3f::*)() const ) &Bnd_B3f::CornerMax, "Query the upper corner: (Center + HSize). You must make sure that the box is NOT VOID (see IsVoid()), otherwise the method returns irrelevant result.");
	cls_Bnd_B3f.def("SquareExtent", (Standard_Real (Bnd_B3f::*)() const ) &Bnd_B3f::SquareExtent, "Query the square diagonal. If the box is VOID (see method IsVoid()) then a very big real value is returned.");
	cls_Bnd_B3f.def("Enlarge", (void (Bnd_B3f::*)(const Standard_Real)) &Bnd_B3f::Enlarge, "Extend the Box by the absolute value of theDiff.", py::arg("theDiff"));
	cls_Bnd_B3f.def("Limit", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &)) &Bnd_B3f::Limit, "Limit the Box by the internals of theOtherBox. Returns True if the limitation takes place, otherwise False indicating that the boxes do not intersect.", py::arg("theOtherBox"));
	cls_Bnd_B3f.def("Transformed", (Bnd_B3f (Bnd_B3f::*)(const gp_Trsf &) const ) &Bnd_B3f::Transformed, "Transform the bounding box with the given transformation. The resulting box will be larger if theTrsf contains rotation.", py::arg("theTrsf"));
	cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_XYZ &) const ) &Bnd_B3f::IsOut, "Check the given point for the inclusion in the Box. Returns True if the point is outside.", py::arg("thePnt"));
	cls_Bnd_B3f.def("IsOut", [](Bnd_B3f &self, const gp_XYZ & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsOut(a0, a1); }, py::arg("theCenter"), py::arg("theRadius"));
	cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_XYZ &, const Standard_Real, const Standard_Boolean) const ) &Bnd_B3f::IsOut, "Check a sphere for the intersection with the current box. Returns True if there is no intersection between boxes. If the parameter 'IsSphereHollow' is True, then the intersection is not reported for a box that is completely inside the sphere (otherwise this method would report an intersection).", py::arg("theCenter"), py::arg("theRadius"), py::arg("isSphereHollow"));
	cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &) const ) &Bnd_B3f::IsOut, "Check the given box for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"));
	cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &, const gp_Trsf &) const ) &Bnd_B3f::IsOut, "Check the given box oriented by the given transformation for the intersection with the current box. Returns True if there is no intersection between boxes.", py::arg("theOtherBox"), py::arg("theTrsf"));
	cls_Bnd_B3f.def("IsOut", [](Bnd_B3f &self, const gp_Ax1 & a0) -> Standard_Boolean { return self.IsOut(a0); }, py::arg("theLine"));
	cls_Bnd_B3f.def("IsOut", [](Bnd_B3f &self, const gp_Ax1 & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.IsOut(a0, a1); }, py::arg("theLine"), py::arg("isRay"));
	cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_Ax1 &, const Standard_Boolean, const Standard_Real) const ) &Bnd_B3f::IsOut, "Check the given Line for the intersection with the current box. Returns True if there is no intersection. isRay==True means intersection check with the positive half-line theOverthickness is the addition to the size of the current box (may be negative). If positive, it can be treated as the thickness of the line 'theLine' or the radius of the cylinder along 'theLine'", py::arg("theLine"), py::arg("isRay"), py::arg("theOverthickness"));
	cls_Bnd_B3f.def("IsOut", (Standard_Boolean (Bnd_B3f::*)(const gp_Ax3 &) const ) &Bnd_B3f::IsOut, "Check the given Plane for the intersection with the current box. Returns True if there is no intersection.", py::arg("thePlane"));
	cls_Bnd_B3f.def("IsIn", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &) const ) &Bnd_B3f::IsIn, "Check that the box 'this' is inside the given box 'theBox'. Returns True if 'this' box is fully inside 'theBox'.", py::arg("theBox"));
	cls_Bnd_B3f.def("IsIn", (Standard_Boolean (Bnd_B3f::*)(const Bnd_B3f &, const gp_Trsf &) const ) &Bnd_B3f::IsIn, "Check that the box 'this' is inside the given box 'theBox' transformed by 'theTrsf'. Returns True if 'this' box is fully inside the transformed 'theBox'.", py::arg("theBox"), py::arg("theTrsf"));
	cls_Bnd_B3f.def("SetCenter", (void (Bnd_B3f::*)(const gp_XYZ &)) &Bnd_B3f::SetCenter, "Set the Center coordinates", py::arg("theCenter"));
	cls_Bnd_B3f.def("SetHSize", (void (Bnd_B3f::*)(const gp_XYZ &)) &Bnd_B3f::SetHSize, "Set the HSize (half-diagonal) coordinates. All components of theHSize must be non-negative.", py::arg("theHSize"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Bnd_Array1OfBox, std::unique_ptr<Bnd_Array1OfBox, Deleter<Bnd_Array1OfBox>>> cls_Bnd_Array1OfBox(mod, "Bnd_Array1OfBox", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Bnd_Array1OfBox.def(py::init<>());
	cls_Bnd_Array1OfBox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_Array1OfBox.def(py::init([] (const Bnd_Array1OfBox &other) {return new Bnd_Array1OfBox(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Bnd_Array1OfBox.def(py::init<Bnd_Array1OfBox &&>(), py::arg("theOther"));
	cls_Bnd_Array1OfBox.def(py::init<const Bnd_Box &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_Array1OfBox.def("begin", (Bnd_Array1OfBox::iterator (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Bnd_Array1OfBox.def("end", (Bnd_Array1OfBox::iterator (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Bnd_Array1OfBox.def("cbegin", (Bnd_Array1OfBox::const_iterator (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Bnd_Array1OfBox.def("cend", (Bnd_Array1OfBox::const_iterator (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Bnd_Array1OfBox.def("Init", (void (Bnd_Array1OfBox::*)(const Bnd_Box &)) &Bnd_Array1OfBox::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Bnd_Array1OfBox.def("Size", (Standard_Integer (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::Size, "Size query");
	cls_Bnd_Array1OfBox.def("Length", (Standard_Integer (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::Length, "Length query (the same)");
	cls_Bnd_Array1OfBox.def("IsEmpty", (Standard_Boolean (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::IsEmpty, "Return TRUE if array has zero length.");
	cls_Bnd_Array1OfBox.def("Lower", (Standard_Integer (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::Lower, "Lower bound");
	cls_Bnd_Array1OfBox.def("Upper", (Standard_Integer (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::Upper, "Upper bound");
	cls_Bnd_Array1OfBox.def("IsDeletable", (Standard_Boolean (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::IsDeletable, "myDeletable flag");
	cls_Bnd_Array1OfBox.def("IsAllocated", (Standard_Boolean (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Bnd_Array1OfBox.def("Assign", (Bnd_Array1OfBox & (Bnd_Array1OfBox::*)(const Bnd_Array1OfBox &)) &Bnd_Array1OfBox::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Bnd_Array1OfBox.def("Move", (Bnd_Array1OfBox & (Bnd_Array1OfBox::*)(Bnd_Array1OfBox &&)) &Bnd_Array1OfBox::Move, "Move assignment", py::arg("theOther"));
	cls_Bnd_Array1OfBox.def("assign", (Bnd_Array1OfBox & (Bnd_Array1OfBox::*)(const Bnd_Array1OfBox &)) &Bnd_Array1OfBox::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Bnd_Array1OfBox.def("assign", (Bnd_Array1OfBox & (Bnd_Array1OfBox::*)(Bnd_Array1OfBox &&)) &Bnd_Array1OfBox::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Bnd_Array1OfBox.def("First", (const Bnd_Box & (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::First, "Returns first element");
	cls_Bnd_Array1OfBox.def("ChangeFirst", (Bnd_Box & (Bnd_Array1OfBox::*)()) &Bnd_Array1OfBox::ChangeFirst, "Returns first element");
	cls_Bnd_Array1OfBox.def("Last", (const Bnd_Box & (Bnd_Array1OfBox::*)() const ) &Bnd_Array1OfBox::Last, "Returns last element");
	cls_Bnd_Array1OfBox.def("ChangeLast", (Bnd_Box & (Bnd_Array1OfBox::*)()) &Bnd_Array1OfBox::ChangeLast, "Returns last element");
	cls_Bnd_Array1OfBox.def("Value", (const Bnd_Box & (Bnd_Array1OfBox::*)(const Standard_Integer) const ) &Bnd_Array1OfBox::Value, "Constant value access", py::arg("theIndex"));
	cls_Bnd_Array1OfBox.def("__call__", (const Bnd_Box & (Bnd_Array1OfBox::*)(const Standard_Integer) const ) &Bnd_Array1OfBox::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Bnd_Array1OfBox.def("ChangeValue", (Bnd_Box & (Bnd_Array1OfBox::*)(const Standard_Integer)) &Bnd_Array1OfBox::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Bnd_Array1OfBox.def("__call__", (Bnd_Box & (Bnd_Array1OfBox::*)(const Standard_Integer)) &Bnd_Array1OfBox::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Bnd_Array1OfBox.def("SetValue", (void (Bnd_Array1OfBox::*)(const Standard_Integer, const Bnd_Box &)) &Bnd_Array1OfBox::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Bnd_Array1OfBox.def("Resize", (void (Bnd_Array1OfBox::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Bnd_Array1OfBox::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Bnd_Array1OfBox.def("__iter__", [](const Bnd_Array1OfBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_BoundSortBox.hxx
	py::class_<Bnd_BoundSortBox, std::unique_ptr<Bnd_BoundSortBox, Deleter<Bnd_BoundSortBox>>> cls_Bnd_BoundSortBox(mod, "Bnd_BoundSortBox", "A tool to compare a bounding box or a plane with a set of bounding boxes. It sorts the set of bounding boxes to give the list of boxes which intersect the element being compared. The boxes being sorted generally bound a set of shapes, while the box being compared bounds a shape to be compared. The resulting list of intersecting boxes therefore gives the list of items which potentially intersect the shape to be compared.");
	cls_Bnd_BoundSortBox.def(py::init<>());
	cls_Bnd_BoundSortBox.def("Initialize", (void (Bnd_BoundSortBox::*)(const Bnd_Box &, const opencascade::handle<Bnd_HArray1OfBox> &)) &Bnd_BoundSortBox::Initialize, "Initializes this comparison algorithm with - the set of bounding boxes SetOfBox.", py::arg("CompleteBox"), py::arg("SetOfBox"));
	cls_Bnd_BoundSortBox.def("Initialize", (void (Bnd_BoundSortBox::*)(const opencascade::handle<Bnd_HArray1OfBox> &)) &Bnd_BoundSortBox::Initialize, "Initializes this comparison algorithm with - the set of bounding boxes SetOfBox, where CompleteBox is given as the global bounding box of SetOfBox.", py::arg("SetOfBox"));
	cls_Bnd_BoundSortBox.def("Initialize", (void (Bnd_BoundSortBox::*)(const Bnd_Box &, const Standard_Integer)) &Bnd_BoundSortBox::Initialize, "Initializes this comparison algorithm, giving it only - the maximum number nbComponents of the bounding boxes to be managed. Use the Add function to define the array of bounding boxes to be sorted by this algorithm.", py::arg("CompleteBox"), py::arg("nbComponents"));
	cls_Bnd_BoundSortBox.def("Add", (void (Bnd_BoundSortBox::*)(const Bnd_Box &, const Standard_Integer)) &Bnd_BoundSortBox::Add, "Adds the bounding box theBox at position boxIndex in the array of boxes to be sorted by this comparison algorithm. This function is used only in conjunction with the third syntax described in the synopsis of Initialize.", py::arg("theBox"), py::arg("boxIndex"));
	cls_Bnd_BoundSortBox.def("Compare", (const TColStd_ListOfInteger & (Bnd_BoundSortBox::*)(const Bnd_Box &)) &Bnd_BoundSortBox::Compare, "Compares the bounding box theBox, with the set of bounding boxes to be sorted by this comparison algorithm, and returns the list of intersecting bounding boxes as a list of indexes on the array of bounding boxes used by this algorithm.", py::arg("theBox"));
	cls_Bnd_BoundSortBox.def("Compare", (const TColStd_ListOfInteger & (Bnd_BoundSortBox::*)(const gp_Pln &)) &Bnd_BoundSortBox::Compare, "Compares the plane P with the set of bounding boxes to be sorted by this comparison algorithm, and returns the list of intersecting bounding boxes as a list of indexes on the array of bounding boxes used by this algorithm.", py::arg("P"));
	// FIXME cls_Bnd_BoundSortBox.def("Dump", (void (Bnd_BoundSortBox::*)() const ) &Bnd_BoundSortBox::Dump, "None");
	cls_Bnd_BoundSortBox.def("Destroy", (void (Bnd_BoundSortBox::*)()) &Bnd_BoundSortBox::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Bnd_Array1OfBox2d, std::unique_ptr<Bnd_Array1OfBox2d, Deleter<Bnd_Array1OfBox2d>>> cls_Bnd_Array1OfBox2d(mod, "Bnd_Array1OfBox2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Bnd_Array1OfBox2d.def(py::init<>());
	cls_Bnd_Array1OfBox2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_Array1OfBox2d.def(py::init([] (const Bnd_Array1OfBox2d &other) {return new Bnd_Array1OfBox2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Bnd_Array1OfBox2d.def(py::init<Bnd_Array1OfBox2d &&>(), py::arg("theOther"));
	cls_Bnd_Array1OfBox2d.def(py::init<const Bnd_Box2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_Array1OfBox2d.def("begin", (Bnd_Array1OfBox2d::iterator (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Bnd_Array1OfBox2d.def("end", (Bnd_Array1OfBox2d::iterator (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Bnd_Array1OfBox2d.def("cbegin", (Bnd_Array1OfBox2d::const_iterator (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Bnd_Array1OfBox2d.def("cend", (Bnd_Array1OfBox2d::const_iterator (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Bnd_Array1OfBox2d.def("Init", (void (Bnd_Array1OfBox2d::*)(const Bnd_Box2d &)) &Bnd_Array1OfBox2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Bnd_Array1OfBox2d.def("Size", (Standard_Integer (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::Size, "Size query");
	cls_Bnd_Array1OfBox2d.def("Length", (Standard_Integer (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::Length, "Length query (the same)");
	cls_Bnd_Array1OfBox2d.def("IsEmpty", (Standard_Boolean (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_Bnd_Array1OfBox2d.def("Lower", (Standard_Integer (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::Lower, "Lower bound");
	cls_Bnd_Array1OfBox2d.def("Upper", (Standard_Integer (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::Upper, "Upper bound");
	cls_Bnd_Array1OfBox2d.def("IsDeletable", (Standard_Boolean (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::IsDeletable, "myDeletable flag");
	cls_Bnd_Array1OfBox2d.def("IsAllocated", (Standard_Boolean (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Bnd_Array1OfBox2d.def("Assign", (Bnd_Array1OfBox2d & (Bnd_Array1OfBox2d::*)(const Bnd_Array1OfBox2d &)) &Bnd_Array1OfBox2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Bnd_Array1OfBox2d.def("Move", (Bnd_Array1OfBox2d & (Bnd_Array1OfBox2d::*)(Bnd_Array1OfBox2d &&)) &Bnd_Array1OfBox2d::Move, "Move assignment", py::arg("theOther"));
	cls_Bnd_Array1OfBox2d.def("assign", (Bnd_Array1OfBox2d & (Bnd_Array1OfBox2d::*)(const Bnd_Array1OfBox2d &)) &Bnd_Array1OfBox2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Bnd_Array1OfBox2d.def("assign", (Bnd_Array1OfBox2d & (Bnd_Array1OfBox2d::*)(Bnd_Array1OfBox2d &&)) &Bnd_Array1OfBox2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Bnd_Array1OfBox2d.def("First", (const Bnd_Box2d & (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::First, "Returns first element");
	cls_Bnd_Array1OfBox2d.def("ChangeFirst", (Bnd_Box2d & (Bnd_Array1OfBox2d::*)()) &Bnd_Array1OfBox2d::ChangeFirst, "Returns first element");
	cls_Bnd_Array1OfBox2d.def("Last", (const Bnd_Box2d & (Bnd_Array1OfBox2d::*)() const ) &Bnd_Array1OfBox2d::Last, "Returns last element");
	cls_Bnd_Array1OfBox2d.def("ChangeLast", (Bnd_Box2d & (Bnd_Array1OfBox2d::*)()) &Bnd_Array1OfBox2d::ChangeLast, "Returns last element");
	cls_Bnd_Array1OfBox2d.def("Value", (const Bnd_Box2d & (Bnd_Array1OfBox2d::*)(const Standard_Integer) const ) &Bnd_Array1OfBox2d::Value, "Constant value access", py::arg("theIndex"));
	cls_Bnd_Array1OfBox2d.def("__call__", (const Bnd_Box2d & (Bnd_Array1OfBox2d::*)(const Standard_Integer) const ) &Bnd_Array1OfBox2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Bnd_Array1OfBox2d.def("ChangeValue", (Bnd_Box2d & (Bnd_Array1OfBox2d::*)(const Standard_Integer)) &Bnd_Array1OfBox2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Bnd_Array1OfBox2d.def("__call__", (Bnd_Box2d & (Bnd_Array1OfBox2d::*)(const Standard_Integer)) &Bnd_Array1OfBox2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Bnd_Array1OfBox2d.def("SetValue", (void (Bnd_Array1OfBox2d::*)(const Standard_Integer, const Bnd_Box2d &)) &Bnd_Array1OfBox2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Bnd_Array1OfBox2d.def("Resize", (void (Bnd_Array1OfBox2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Bnd_Array1OfBox2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Bnd_Array1OfBox2d.def("__iter__", [](const Bnd_Array1OfBox2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_BoundSortBox2d.hxx
	py::class_<Bnd_BoundSortBox2d, std::unique_ptr<Bnd_BoundSortBox2d, Deleter<Bnd_BoundSortBox2d>>> cls_Bnd_BoundSortBox2d(mod, "Bnd_BoundSortBox2d", "A tool to compare a 2D bounding box with a set of 2D bounding boxes. It sorts the set of bounding boxes to give the list of boxes which intersect the element being compared. The boxes being sorted generally bound a set of shapes, while the box being compared bounds a shape to be compared. The resulting list of intersecting boxes therefore gives the list of items which potentially intersect the shape to be compared.");
	cls_Bnd_BoundSortBox2d.def(py::init<>());
	cls_Bnd_BoundSortBox2d.def("Initialize", (void (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &, const opencascade::handle<Bnd_HArray1OfBox2d> &)) &Bnd_BoundSortBox2d::Initialize, "Initializes this comparison algorithm with - the set of 2D bounding boxes SetOfBox", py::arg("CompleteBox"), py::arg("SetOfBox"));
	cls_Bnd_BoundSortBox2d.def("Initialize", (void (Bnd_BoundSortBox2d::*)(const opencascade::handle<Bnd_HArray1OfBox2d> &)) &Bnd_BoundSortBox2d::Initialize, "Initializes this comparison algorithm with - the set of 2D bounding boxes SetOfBox, where CompleteBox is given as the global bounding box of SetOfBox.", py::arg("SetOfBox"));
	cls_Bnd_BoundSortBox2d.def("Initialize", (void (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &, const Standard_Integer)) &Bnd_BoundSortBox2d::Initialize, "Initializes this comparison algorithm, giving it only - the maximum number nbComponents, and - the global bounding box CompleteBox, of the 2D bounding boxes to be managed. Use the Add function to define the array of bounding boxes to be sorted by this algorithm.", py::arg("CompleteBox"), py::arg("nbComponents"));
	cls_Bnd_BoundSortBox2d.def("Add", (void (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &, const Standard_Integer)) &Bnd_BoundSortBox2d::Add, "Adds the 2D bounding box theBox at position boxIndex in the array of boxes to be sorted by this comparison algorithm. This function is used only in conjunction with the third syntax described in the synopsis of Initialize. Exceptions - Standard_OutOfRange if boxIndex is not in the range [ 1,nbComponents ] where nbComponents is the maximum number of bounding boxes declared for this comparison algorithm at initialization. - Standard_MultiplyDefined if a box still exists at position boxIndex in the array of boxes to be sorted by this comparison algorithm.", py::arg("theBox"), py::arg("boxIndex"));
	cls_Bnd_BoundSortBox2d.def("Compare", (const TColStd_ListOfInteger & (Bnd_BoundSortBox2d::*)(const Bnd_Box2d &)) &Bnd_BoundSortBox2d::Compare, "Compares the 2D bounding box theBox with the set of bounding boxes to be sorted by this comparison algorithm, and returns the list of intersecting bounding boxes as a list of indexes on the array of bounding boxes used by this algorithm.", py::arg("theBox"));
	// FIXME cls_Bnd_BoundSortBox2d.def("Dump", (void (Bnd_BoundSortBox2d::*)() const ) &Bnd_BoundSortBox2d::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Bnd_Array1OfSphere, std::unique_ptr<Bnd_Array1OfSphere, Deleter<Bnd_Array1OfSphere>>> cls_Bnd_Array1OfSphere(mod, "Bnd_Array1OfSphere", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Bnd_Array1OfSphere.def(py::init<>());
	cls_Bnd_Array1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_Array1OfSphere.def(py::init([] (const Bnd_Array1OfSphere &other) {return new Bnd_Array1OfSphere(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Bnd_Array1OfSphere.def(py::init<Bnd_Array1OfSphere &&>(), py::arg("theOther"));
	cls_Bnd_Array1OfSphere.def(py::init<const Bnd_Sphere &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_Array1OfSphere.def("begin", (Bnd_Array1OfSphere::iterator (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Bnd_Array1OfSphere.def("end", (Bnd_Array1OfSphere::iterator (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Bnd_Array1OfSphere.def("cbegin", (Bnd_Array1OfSphere::const_iterator (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Bnd_Array1OfSphere.def("cend", (Bnd_Array1OfSphere::const_iterator (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Bnd_Array1OfSphere.def("Init", (void (Bnd_Array1OfSphere::*)(const Bnd_Sphere &)) &Bnd_Array1OfSphere::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Bnd_Array1OfSphere.def("Size", (Standard_Integer (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::Size, "Size query");
	cls_Bnd_Array1OfSphere.def("Length", (Standard_Integer (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::Length, "Length query (the same)");
	cls_Bnd_Array1OfSphere.def("IsEmpty", (Standard_Boolean (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::IsEmpty, "Return TRUE if array has zero length.");
	cls_Bnd_Array1OfSphere.def("Lower", (Standard_Integer (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::Lower, "Lower bound");
	cls_Bnd_Array1OfSphere.def("Upper", (Standard_Integer (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::Upper, "Upper bound");
	cls_Bnd_Array1OfSphere.def("IsDeletable", (Standard_Boolean (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::IsDeletable, "myDeletable flag");
	cls_Bnd_Array1OfSphere.def("IsAllocated", (Standard_Boolean (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Bnd_Array1OfSphere.def("Assign", (Bnd_Array1OfSphere & (Bnd_Array1OfSphere::*)(const Bnd_Array1OfSphere &)) &Bnd_Array1OfSphere::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Bnd_Array1OfSphere.def("Move", (Bnd_Array1OfSphere & (Bnd_Array1OfSphere::*)(Bnd_Array1OfSphere &&)) &Bnd_Array1OfSphere::Move, "Move assignment", py::arg("theOther"));
	cls_Bnd_Array1OfSphere.def("assign", (Bnd_Array1OfSphere & (Bnd_Array1OfSphere::*)(const Bnd_Array1OfSphere &)) &Bnd_Array1OfSphere::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Bnd_Array1OfSphere.def("assign", (Bnd_Array1OfSphere & (Bnd_Array1OfSphere::*)(Bnd_Array1OfSphere &&)) &Bnd_Array1OfSphere::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Bnd_Array1OfSphere.def("First", (const Bnd_Sphere & (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::First, "Returns first element");
	cls_Bnd_Array1OfSphere.def("ChangeFirst", (Bnd_Sphere & (Bnd_Array1OfSphere::*)()) &Bnd_Array1OfSphere::ChangeFirst, "Returns first element");
	cls_Bnd_Array1OfSphere.def("Last", (const Bnd_Sphere & (Bnd_Array1OfSphere::*)() const ) &Bnd_Array1OfSphere::Last, "Returns last element");
	cls_Bnd_Array1OfSphere.def("ChangeLast", (Bnd_Sphere & (Bnd_Array1OfSphere::*)()) &Bnd_Array1OfSphere::ChangeLast, "Returns last element");
	cls_Bnd_Array1OfSphere.def("Value", (const Bnd_Sphere & (Bnd_Array1OfSphere::*)(const Standard_Integer) const ) &Bnd_Array1OfSphere::Value, "Constant value access", py::arg("theIndex"));
	cls_Bnd_Array1OfSphere.def("__call__", (const Bnd_Sphere & (Bnd_Array1OfSphere::*)(const Standard_Integer) const ) &Bnd_Array1OfSphere::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Bnd_Array1OfSphere.def("ChangeValue", (Bnd_Sphere & (Bnd_Array1OfSphere::*)(const Standard_Integer)) &Bnd_Array1OfSphere::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Bnd_Array1OfSphere.def("__call__", (Bnd_Sphere & (Bnd_Array1OfSphere::*)(const Standard_Integer)) &Bnd_Array1OfSphere::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Bnd_Array1OfSphere.def("SetValue", (void (Bnd_Array1OfSphere::*)(const Standard_Integer, const Bnd_Sphere &)) &Bnd_Array1OfSphere::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Bnd_Array1OfSphere.def("Resize", (void (Bnd_Array1OfSphere::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Bnd_Array1OfSphere::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Bnd_Array1OfSphere.def("__iter__", [](const Bnd_Array1OfSphere &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_Range.hxx
	py::class_<Bnd_Range, std::unique_ptr<Bnd_Range, Deleter<Bnd_Range>>> cls_Bnd_Range(mod, "Bnd_Range", "This class describes a range in 1D space restricted by two real values. A range can be void indicating there is no point included in the range.");
	cls_Bnd_Range.def(py::init<>());
	cls_Bnd_Range.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theMin"), py::arg("theMax"));
	cls_Bnd_Range.def("Common", (void (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Common, "Replaces <this> with common-part of <this> and theOther", py::arg("theOther"));
	cls_Bnd_Range.def("Union", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Union, "Joins *this and theOther to one interval. Replaces *this to the result. Returns false if the operation cannot be done (e.g. input arguments are empty or separated).", py::arg("theOther"));
	cls_Bnd_Range.def("Split", [](Bnd_Range &self, const Standard_Real a0, NCollection_List<Bnd_Range> & a1) -> void { return self.Split(a0, a1); }, py::arg("theVal"), py::arg("theList"));
	cls_Bnd_Range.def("Split", (void (Bnd_Range::*)(const Standard_Real, NCollection_List<Bnd_Range> &, const Standard_Real) const ) &Bnd_Range::Split, "Splits <this> to several sub-ranges by theVal value (e.g. range [3, 15] will be split by theVal==5 to the two ranges: [3, 5] and [5, 15]). New ranges will be pushed to theList (theList must be initialized correctly before calling this method). If thePeriod != 0.0 then at least one boundary of new ranges (if <*this> intersects theVal+k*thePeriod) will be equal to theVal+thePeriod*k, where k is an integer number (k = 0, +/-1, +/-2, ...). (let thePeriod in above example be 4 ==> we will obtain four ranges: [3, 5], [5, 9], [9, 13] and [13, 15].", py::arg("theVal"), py::arg("theList"), py::arg("thePeriod"));
	cls_Bnd_Range.def("IsIntersected", [](Bnd_Range &self, const Standard_Real a0) -> Standard_Integer { return self.IsIntersected(a0); }, py::arg("theVal"));
	cls_Bnd_Range.def("IsIntersected", (Standard_Integer (Bnd_Range::*)(const Standard_Real, const Standard_Real) const ) &Bnd_Range::IsIntersected, "Checks if <this> intersects values like theVal+k*thePeriod, where k is an integer number (k = 0, +/-1, +/-2, ...). Returns: 0 - if <this> does not intersect the theVal+k*thePeriod. 1 - if <this> intersects theVal+k*thePeriod. 2 - if myFirst or/and myLast are equal to theVal+k*thePeriod.", py::arg("theVal"), py::arg("thePeriod"));
	cls_Bnd_Range.def("Add", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Add, "Extends <this> to include theParameter", py::arg("theParameter"));
	cls_Bnd_Range.def("GetMin", (Standard_Boolean (Bnd_Range::*)(Standard_Real &) const ) &Bnd_Range::GetMin, "Obtain MIN boundary of <this>. If <this> is VOID the method returns false.", py::arg("thePar"));
	cls_Bnd_Range.def("GetMAX", (Standard_Boolean (Bnd_Range::*)(Standard_Real &) const ) &Bnd_Range::GetMAX, "Obtain MAX boundary of <this>. If <this> is VOID the method returns false.", py::arg("thePar"));
	cls_Bnd_Range.def("GetBounds", (Standard_Boolean (Bnd_Range::*)(Standard_Real &, Standard_Real &) const ) &Bnd_Range::GetBounds, "Obtain first and last boundary of <this>. If <this> is VOID the method returns false.", py::arg("theFirstPar"), py::arg("theLastPar"));
	cls_Bnd_Range.def("Delta", (Standard_Real (Bnd_Range::*)() const ) &Bnd_Range::Delta, "Returns range value (MAX-MIN). Returns negative value for VOID range.");
	cls_Bnd_Range.def("IsVoid", (Standard_Boolean (Bnd_Range::*)() const ) &Bnd_Range::IsVoid, "Is <this> initialized.");
	cls_Bnd_Range.def("SetVoid", (void (Bnd_Range::*)()) &Bnd_Range::SetVoid, "Initializes <this> by default parameters. Makes <this> VOID.");
	cls_Bnd_Range.def("Enlarge", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Enlarge, "Extends this to the given value (in both side)", py::arg("theDelta"));
	cls_Bnd_Range.def("Shifted", (Bnd_Range (Bnd_Range::*)(const Standard_Real) const ) &Bnd_Range::Shifted, "Returns the copy of <*this> shifted by theVal", py::arg("theVal"));
	cls_Bnd_Range.def("Shift", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Shift, "Shifts <*this> by theVal", py::arg("theVal"));
	cls_Bnd_Range.def("__eq__", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &) const ) &Bnd_Range::operator==, py::is_operator(), "Returns TRUE if theOther is equal to <*this>", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_HArray1OfBox.hxx
	py::class_<Bnd_HArray1OfBox, opencascade::handle<Bnd_HArray1OfBox>, Bnd_Array1OfBox, Standard_Transient> cls_Bnd_HArray1OfBox(mod, "Bnd_HArray1OfBox", "None");
	cls_Bnd_HArray1OfBox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_HArray1OfBox.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfBox::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Bnd_HArray1OfBox.def(py::init<const Bnd_Array1OfBox &>(), py::arg("theOther"));
	cls_Bnd_HArray1OfBox.def("Array1", (const Bnd_Array1OfBox & (Bnd_HArray1OfBox::*)() const ) &Bnd_HArray1OfBox::Array1, "None");
	cls_Bnd_HArray1OfBox.def("ChangeArray1", (Bnd_Array1OfBox & (Bnd_HArray1OfBox::*)()) &Bnd_HArray1OfBox::ChangeArray1, "None");
	cls_Bnd_HArray1OfBox.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfBox::get_type_name, "None");
	cls_Bnd_HArray1OfBox.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfBox::get_type_descriptor, "None");
	cls_Bnd_HArray1OfBox.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfBox::*)() const ) &Bnd_HArray1OfBox::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_HArray1OfBox2d.hxx
	py::class_<Bnd_HArray1OfBox2d, opencascade::handle<Bnd_HArray1OfBox2d>, Bnd_Array1OfBox2d, Standard_Transient> cls_Bnd_HArray1OfBox2d(mod, "Bnd_HArray1OfBox2d", "None");
	cls_Bnd_HArray1OfBox2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_HArray1OfBox2d.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfBox2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Bnd_HArray1OfBox2d.def(py::init<const Bnd_Array1OfBox2d &>(), py::arg("theOther"));
	cls_Bnd_HArray1OfBox2d.def("Array1", (const Bnd_Array1OfBox2d & (Bnd_HArray1OfBox2d::*)() const ) &Bnd_HArray1OfBox2d::Array1, "None");
	cls_Bnd_HArray1OfBox2d.def("ChangeArray1", (Bnd_Array1OfBox2d & (Bnd_HArray1OfBox2d::*)()) &Bnd_HArray1OfBox2d::ChangeArray1, "None");
	cls_Bnd_HArray1OfBox2d.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfBox2d::get_type_name, "None");
	cls_Bnd_HArray1OfBox2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfBox2d::get_type_descriptor, "None");
	cls_Bnd_HArray1OfBox2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfBox2d::*)() const ) &Bnd_HArray1OfBox2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bnd_HArray1OfSphere.hxx
	py::class_<Bnd_HArray1OfSphere, opencascade::handle<Bnd_HArray1OfSphere>, Bnd_Array1OfSphere, Standard_Transient> cls_Bnd_HArray1OfSphere(mod, "Bnd_HArray1OfSphere", "None");
	cls_Bnd_HArray1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Bnd_HArray1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfSphere::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Bnd_HArray1OfSphere.def(py::init<const Bnd_Array1OfSphere &>(), py::arg("theOther"));
	cls_Bnd_HArray1OfSphere.def("Array1", (const Bnd_Array1OfSphere & (Bnd_HArray1OfSphere::*)() const ) &Bnd_HArray1OfSphere::Array1, "None");
	cls_Bnd_HArray1OfSphere.def("ChangeArray1", (Bnd_Array1OfSphere & (Bnd_HArray1OfSphere::*)()) &Bnd_HArray1OfSphere::ChangeArray1, "None");
	cls_Bnd_HArray1OfSphere.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfSphere::get_type_name, "None");
	cls_Bnd_HArray1OfSphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfSphere::get_type_descriptor, "None");
	cls_Bnd_HArray1OfSphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfSphere::*)() const ) &Bnd_HArray1OfSphere::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Bnd_SeqOfBox, std::unique_ptr<Bnd_SeqOfBox, Deleter<Bnd_SeqOfBox>>, NCollection_BaseSequence> cls_Bnd_SeqOfBox(mod, "Bnd_SeqOfBox", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Bnd_SeqOfBox.def(py::init<>());
	cls_Bnd_SeqOfBox.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Bnd_SeqOfBox.def(py::init([] (const Bnd_SeqOfBox &other) {return new Bnd_SeqOfBox(other);}), "Copy constructor", py::arg("other"));
	cls_Bnd_SeqOfBox.def("begin", (Bnd_SeqOfBox::iterator (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Bnd_SeqOfBox.def("end", (Bnd_SeqOfBox::iterator (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Bnd_SeqOfBox.def("cbegin", (Bnd_SeqOfBox::const_iterator (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Bnd_SeqOfBox.def("cend", (Bnd_SeqOfBox::const_iterator (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Bnd_SeqOfBox.def("Size", (Standard_Integer (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::Size, "Number of items");
	cls_Bnd_SeqOfBox.def("Length", (Standard_Integer (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::Length, "Number of items");
	cls_Bnd_SeqOfBox.def("Lower", (Standard_Integer (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::Lower, "Method for consistency with other collections.");
	cls_Bnd_SeqOfBox.def("Upper", (Standard_Integer (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::Upper, "Method for consistency with other collections.");
	cls_Bnd_SeqOfBox.def("IsEmpty", (Standard_Boolean (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::IsEmpty, "Empty query");
	cls_Bnd_SeqOfBox.def("Reverse", (void (Bnd_SeqOfBox::*)()) &Bnd_SeqOfBox::Reverse, "Reverse sequence");
	cls_Bnd_SeqOfBox.def("Exchange", (void (Bnd_SeqOfBox::*)(const Standard_Integer, const Standard_Integer)) &Bnd_SeqOfBox::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Bnd_SeqOfBox.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_SeqOfBox::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Bnd_SeqOfBox.def("Clear", [](Bnd_SeqOfBox &self) -> void { return self.Clear(); });
	cls_Bnd_SeqOfBox.def("Clear", (void (Bnd_SeqOfBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_SeqOfBox::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Bnd_SeqOfBox.def("Assign", (Bnd_SeqOfBox & (Bnd_SeqOfBox::*)(const Bnd_SeqOfBox &)) &Bnd_SeqOfBox::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Bnd_SeqOfBox.def("assign", (Bnd_SeqOfBox & (Bnd_SeqOfBox::*)(const Bnd_SeqOfBox &)) &Bnd_SeqOfBox::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Bnd_SeqOfBox.def("Remove", (void (Bnd_SeqOfBox::*)(Bnd_SeqOfBox::Iterator &)) &Bnd_SeqOfBox::Remove, "Remove one item", py::arg("thePosition"));
	cls_Bnd_SeqOfBox.def("Remove", (void (Bnd_SeqOfBox::*)(const Standard_Integer)) &Bnd_SeqOfBox::Remove, "Remove one item", py::arg("theIndex"));
	cls_Bnd_SeqOfBox.def("Remove", (void (Bnd_SeqOfBox::*)(const Standard_Integer, const Standard_Integer)) &Bnd_SeqOfBox::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Bnd_SeqOfBox.def("Append", (void (Bnd_SeqOfBox::*)(const Bnd_Box &)) &Bnd_SeqOfBox::Append, "Append one item", py::arg("theItem"));
	cls_Bnd_SeqOfBox.def("Append", (void (Bnd_SeqOfBox::*)(Bnd_SeqOfBox &)) &Bnd_SeqOfBox::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Bnd_SeqOfBox.def("Prepend", (void (Bnd_SeqOfBox::*)(const Bnd_Box &)) &Bnd_SeqOfBox::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Bnd_SeqOfBox.def("Prepend", (void (Bnd_SeqOfBox::*)(Bnd_SeqOfBox &)) &Bnd_SeqOfBox::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Bnd_SeqOfBox.def("InsertBefore", (void (Bnd_SeqOfBox::*)(const Standard_Integer, const Bnd_Box &)) &Bnd_SeqOfBox::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Bnd_SeqOfBox.def("InsertBefore", (void (Bnd_SeqOfBox::*)(const Standard_Integer, Bnd_SeqOfBox &)) &Bnd_SeqOfBox::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Bnd_SeqOfBox.def("InsertAfter", (void (Bnd_SeqOfBox::*)(Bnd_SeqOfBox::Iterator &, const Bnd_Box &)) &Bnd_SeqOfBox::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Bnd_SeqOfBox.def("InsertAfter", (void (Bnd_SeqOfBox::*)(const Standard_Integer, Bnd_SeqOfBox &)) &Bnd_SeqOfBox::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Bnd_SeqOfBox.def("InsertAfter", (void (Bnd_SeqOfBox::*)(const Standard_Integer, const Bnd_Box &)) &Bnd_SeqOfBox::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Bnd_SeqOfBox.def("Split", (void (Bnd_SeqOfBox::*)(const Standard_Integer, Bnd_SeqOfBox &)) &Bnd_SeqOfBox::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Bnd_SeqOfBox.def("First", (const Bnd_Box & (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::First, "First item access");
	cls_Bnd_SeqOfBox.def("ChangeFirst", (Bnd_Box & (Bnd_SeqOfBox::*)()) &Bnd_SeqOfBox::ChangeFirst, "First item access");
	cls_Bnd_SeqOfBox.def("Last", (const Bnd_Box & (Bnd_SeqOfBox::*)() const ) &Bnd_SeqOfBox::Last, "Last item access");
	cls_Bnd_SeqOfBox.def("ChangeLast", (Bnd_Box & (Bnd_SeqOfBox::*)()) &Bnd_SeqOfBox::ChangeLast, "Last item access");
	cls_Bnd_SeqOfBox.def("Value", (const Bnd_Box & (Bnd_SeqOfBox::*)(const Standard_Integer) const ) &Bnd_SeqOfBox::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Bnd_SeqOfBox.def("__call__", (const Bnd_Box & (Bnd_SeqOfBox::*)(const Standard_Integer) const ) &Bnd_SeqOfBox::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Bnd_SeqOfBox.def("ChangeValue", (Bnd_Box & (Bnd_SeqOfBox::*)(const Standard_Integer)) &Bnd_SeqOfBox::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Bnd_SeqOfBox.def("__call__", (Bnd_Box & (Bnd_SeqOfBox::*)(const Standard_Integer)) &Bnd_SeqOfBox::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Bnd_SeqOfBox.def("SetValue", (void (Bnd_SeqOfBox::*)(const Standard_Integer, const Bnd_Box &)) &Bnd_SeqOfBox::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Bnd_SeqOfBox.def("__iter__", [](const Bnd_SeqOfBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
