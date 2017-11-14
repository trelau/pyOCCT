#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <TopLoc_ItemLocation.hxx>
#include <TopLoc_SListOfItemLocation.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TopLoc_SListNodeOfItemLocation.hxx>
#include <TopLoc_Datum3D.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <Standard_OStream.hxx>
#include <TopLoc_Location.hxx>
#include <TopLoc_MapLocationHasher.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TopLoc_IndexedMapOfLocation.hxx>
#include <NCollection_Map.hxx>
#include <TopLoc_MapOfLocation.hxx>

PYBIND11_MODULE(TopLoc, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_Location.hxx
	mod.def("HashCode", (Standard_Integer (*)(const TopLoc_Location &, const Standard_Integer)) &HashCode, "None", py::arg("me"), py::arg("Upper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_Datum3D.hxx
	mod.def("ShallowDump", (void (*)(const opencascade::handle<TopLoc_Datum3D> &, Standard_OStream &)) &ShallowDump, "None", py::arg("me"), py::arg("S"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_SListNodeOfItemLocation.hxx
	py::class_<TopLoc_SListNodeOfItemLocation, opencascade::handle<TopLoc_SListNodeOfItemLocation>, Standard_Transient> cls_TopLoc_SListNodeOfItemLocation(mod, "TopLoc_SListNodeOfItemLocation", "None");
	cls_TopLoc_SListNodeOfItemLocation.def(py::init<const TopLoc_ItemLocation &, const TopLoc_SListOfItemLocation &>(), py::arg("I"), py::arg("aTail"));
	cls_TopLoc_SListNodeOfItemLocation.def("Tail", (TopLoc_SListOfItemLocation & (TopLoc_SListNodeOfItemLocation::*)() const ) &TopLoc_SListNodeOfItemLocation::Tail, "None");
	cls_TopLoc_SListNodeOfItemLocation.def("Value", (TopLoc_ItemLocation & (TopLoc_SListNodeOfItemLocation::*)() const ) &TopLoc_SListNodeOfItemLocation::Value, "None");
	cls_TopLoc_SListNodeOfItemLocation.def_static("get_type_name_", (const char * (*)()) &TopLoc_SListNodeOfItemLocation::get_type_name, "None");
	cls_TopLoc_SListNodeOfItemLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopLoc_SListNodeOfItemLocation::get_type_descriptor, "None");
	cls_TopLoc_SListNodeOfItemLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopLoc_SListNodeOfItemLocation::*)() const ) &TopLoc_SListNodeOfItemLocation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_ItemLocation.hxx
	py::class_<TopLoc_ItemLocation, std::unique_ptr<TopLoc_ItemLocation, Deleter<TopLoc_ItemLocation>>> cls_TopLoc_ItemLocation(mod, "TopLoc_ItemLocation", "An ItemLocation is an elementary coordinate system in a Location.");
	cls_TopLoc_ItemLocation.def(py::init<const opencascade::handle<TopLoc_Datum3D> &, const Standard_Integer>(), py::arg("D"), py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_SListOfItemLocation.hxx
	py::class_<TopLoc_SListOfItemLocation, std::unique_ptr<TopLoc_SListOfItemLocation, Deleter<TopLoc_SListOfItemLocation>>> cls_TopLoc_SListOfItemLocation(mod, "TopLoc_SListOfItemLocation", "An SListOfItemLocation is a LISP like list of Items. An SListOfItemLocation is : . Empty. . Or it has a Value and a Tail which is an other SListOfItemLocation.");
	cls_TopLoc_SListOfItemLocation.def(py::init<>());
	cls_TopLoc_SListOfItemLocation.def(py::init<const TopLoc_ItemLocation &, const TopLoc_SListOfItemLocation &>(), py::arg("anItem"), py::arg("aTail"));
	cls_TopLoc_SListOfItemLocation.def(py::init([] (const TopLoc_SListOfItemLocation &other) {return new TopLoc_SListOfItemLocation(other);}), "Copy constructor", py::arg("other"));
	cls_TopLoc_SListOfItemLocation.def("Assign", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(const TopLoc_SListOfItemLocation &)) &TopLoc_SListOfItemLocation::Assign, "Sets a list from an other one. The lists are shared. The list itself is returned.", py::arg("Other"));
	cls_TopLoc_SListOfItemLocation.def("assign", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(const TopLoc_SListOfItemLocation &)) &TopLoc_SListOfItemLocation::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_TopLoc_SListOfItemLocation.def("IsEmpty", (Standard_Boolean (TopLoc_SListOfItemLocation::*)() const ) &TopLoc_SListOfItemLocation::IsEmpty, "None");
	cls_TopLoc_SListOfItemLocation.def("Clear", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::Clear, "Sets the list to be empty.");
	cls_TopLoc_SListOfItemLocation.def("Value", (const TopLoc_ItemLocation & (TopLoc_SListOfItemLocation::*)() const ) &TopLoc_SListOfItemLocation::Value, "Returns the current value of the list. An error is raised if the list is empty.");
	cls_TopLoc_SListOfItemLocation.def("Tail", (const TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)() const ) &TopLoc_SListOfItemLocation::Tail, "Returns the current tail of the list. On an empty list the tail is the list itself.");
	cls_TopLoc_SListOfItemLocation.def("Construct", (void (TopLoc_SListOfItemLocation::*)(const TopLoc_ItemLocation &)) &TopLoc_SListOfItemLocation::Construct, "Replaces the list by a list with <anItem> as Value and the list <me> as tail.", py::arg("anItem"));
	cls_TopLoc_SListOfItemLocation.def("ToTail", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::ToTail, "Replaces the list <me> by its tail.");
	cls_TopLoc_SListOfItemLocation.def("More", (Standard_Boolean (TopLoc_SListOfItemLocation::*)() const ) &TopLoc_SListOfItemLocation::More, "Returns True if the iterator has a current value. This is !IsEmpty()");
	cls_TopLoc_SListOfItemLocation.def("Next", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::Next, "Moves the iterator to the next object in the list. If the iterator is empty it will stay empty. This is ToTail()");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_Datum3D.hxx
	py::class_<TopLoc_Datum3D, opencascade::handle<TopLoc_Datum3D>, Standard_Transient> cls_TopLoc_Datum3D(mod, "TopLoc_Datum3D", "Describes a coordinate transformation, i.e. a change to an elementary 3D coordinate system, or position in 3D space. A Datum3D is always described relative to the default datum. The default datum is described relative to itself: its origin is (0,0,0), and its axes are (1,0,0) (0,1,0) (0,0,1).");
	cls_TopLoc_Datum3D.def(py::init<>());
	cls_TopLoc_Datum3D.def(py::init<const gp_Trsf &>(), py::arg("T"));
	cls_TopLoc_Datum3D.def("Transformation", (const gp_Trsf & (TopLoc_Datum3D::*)() const ) &TopLoc_Datum3D::Transformation, "Returns a gp_Trsf which, when applied to this datum, produces the default datum.");
	cls_TopLoc_Datum3D.def("ShallowDump", (void (TopLoc_Datum3D::*)(Standard_OStream &) const ) &TopLoc_Datum3D::ShallowDump, "Writes the contents of this Datum3D to the stream S.", py::arg("S"));
	cls_TopLoc_Datum3D.def_static("get_type_name_", (const char * (*)()) &TopLoc_Datum3D::get_type_name, "None");
	cls_TopLoc_Datum3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopLoc_Datum3D::get_type_descriptor, "None");
	cls_TopLoc_Datum3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopLoc_Datum3D::*)() const ) &TopLoc_Datum3D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_Location.hxx
	py::class_<TopLoc_Location, std::unique_ptr<TopLoc_Location, Deleter<TopLoc_Location>>> cls_TopLoc_Location(mod, "TopLoc_Location", "A Location is a composite transition. It comprises a series of elementary reference coordinates, i.e. objects of type TopLoc_Datum3D, and the powers to which these objects are raised.");
	cls_TopLoc_Location.def(py::init<>());
	cls_TopLoc_Location.def(py::init<const gp_Trsf &>(), py::arg("T"));
	cls_TopLoc_Location.def(py::init<const opencascade::handle<TopLoc_Datum3D> &>(), py::arg("D"));
	cls_TopLoc_Location.def("IsIdentity", (Standard_Boolean (TopLoc_Location::*)() const ) &TopLoc_Location::IsIdentity, "Returns true if this location is equal to the Identity transformation.");
	cls_TopLoc_Location.def("Identity", (void (TopLoc_Location::*)()) &TopLoc_Location::Identity, "Resets this location to the Identity transformation.");
	cls_TopLoc_Location.def("FirstDatum", (const opencascade::handle<TopLoc_Datum3D> & (TopLoc_Location::*)() const ) &TopLoc_Location::FirstDatum, "Returns the first elementary datum of the Location. Use the NextLocation function recursively to access the other data comprising this location. Exceptions Standard_NoSuchObject if this location is empty.");
	cls_TopLoc_Location.def("FirstPower", (Standard_Integer (TopLoc_Location::*)() const ) &TopLoc_Location::FirstPower, "Returns the power elevation of the first elementary datum. Exceptions Standard_NoSuchObject if this location is empty.");
	cls_TopLoc_Location.def("NextLocation", (const TopLoc_Location & (TopLoc_Location::*)() const ) &TopLoc_Location::NextLocation, "Returns a Location representing <me> without the first datum. We have the relation :");
	cls_TopLoc_Location.def("Transformation", (const gp_Trsf & (TopLoc_Location::*)() const ) &TopLoc_Location::Transformation, "Returns the transformation associated to the coordinate system.");
	cls_TopLoc_Location.def("Inverted", (TopLoc_Location (TopLoc_Location::*)() const ) &TopLoc_Location::Inverted, "Returns the inverse of <me>.");
	cls_TopLoc_Location.def("Multiplied", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::Multiplied, "Returns <me> * <Other>, the elementary datums are concatenated.", py::arg("Other"));
	cls_TopLoc_Location.def("__mul__", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::operator*, py::is_operator(), "None", py::arg("Other"));
	cls_TopLoc_Location.def("Divided", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::Divided, "Returns <me> / <Other>.", py::arg("Other"));
	cls_TopLoc_Location.def("__truediv__", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::operator/, py::is_operator(), "None", py::arg("Other"));
	cls_TopLoc_Location.def("Predivided", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::Predivided, "Returns <Other>.Inverted() * <me>.", py::arg("Other"));
	cls_TopLoc_Location.def("Powered", (TopLoc_Location (TopLoc_Location::*)(const Standard_Integer) const ) &TopLoc_Location::Powered, "Returns me at the power <pwr>. If <pwr> is zero returns Identity. <pwr> can be lower than zero (usual meaning for powers).", py::arg("pwr"));
	// FIXME cls_TopLoc_Location.def("HashCode", (Standard_Integer (TopLoc_Location::*)(const Standard_Integer) const ) &TopLoc_Location::HashCode, "Returns a hashed value for this local coordinate system. This value is used, with map tables, to store and retrieve the object easily, and is in the range [ 1..Upper ].", py::arg("Upper"));
	cls_TopLoc_Location.def("IsEqual", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::IsEqual, "Returns true if this location and the location Other have the same elementary data, i.e. contain the same series of TopLoc_Datum3D and respective powers. This method is an alias for operator ==.", py::arg("Other"));
	cls_TopLoc_Location.def("__eq__", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::operator==, py::is_operator(), "None", py::arg("Other"));
	cls_TopLoc_Location.def("IsDifferent", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::IsDifferent, "Returns true if this location and the location Other do not have the same elementary data, i.e. do not contain the same series of TopLoc_Datum3D and respective powers. This method is an alias for operator !=.", py::arg("Other"));
	cls_TopLoc_Location.def("__ne__", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const ) &TopLoc_Location::operator!=, py::is_operator(), "None", py::arg("Other"));
	cls_TopLoc_Location.def("ShallowDump", (void (TopLoc_Location::*)(Standard_OStream &) const ) &TopLoc_Location::ShallowDump, "Prints the contents of <me> on the stream .", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<TopLoc_MapLocationHasher, std::unique_ptr<TopLoc_MapLocationHasher, Deleter<TopLoc_MapLocationHasher>>> cls_TopLoc_MapLocationHasher(mod, "TopLoc_MapLocationHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_TopLoc_MapLocationHasher.def(py::init<>());
	cls_TopLoc_MapLocationHasher.def_static("HashCode_", (Standard_Integer (*)(const TopLoc_Location &, const Standard_Integer)) &TopLoc_MapLocationHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_TopLoc_MapLocationHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TopLoc_Location &, const TopLoc_Location &)) &TopLoc_MapLocationHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<TopLoc_IndexedMapOfLocation, std::unique_ptr<TopLoc_IndexedMapOfLocation, Deleter<TopLoc_IndexedMapOfLocation>>, NCollection_BaseMap> cls_TopLoc_IndexedMapOfLocation(mod, "TopLoc_IndexedMapOfLocation", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_TopLoc_IndexedMapOfLocation.def(py::init<>());
	cls_TopLoc_IndexedMapOfLocation.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopLoc_IndexedMapOfLocation.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopLoc_IndexedMapOfLocation.def(py::init([] (const TopLoc_IndexedMapOfLocation &other) {return new TopLoc_IndexedMapOfLocation(other);}), "Copy constructor", py::arg("other"));
	cls_TopLoc_IndexedMapOfLocation.def("cbegin", (TopLoc_IndexedMapOfLocation::const_iterator (TopLoc_IndexedMapOfLocation::*)() const ) &TopLoc_IndexedMapOfLocation::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopLoc_IndexedMapOfLocation.def("cend", (TopLoc_IndexedMapOfLocation::const_iterator (TopLoc_IndexedMapOfLocation::*)() const ) &TopLoc_IndexedMapOfLocation::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopLoc_IndexedMapOfLocation.def("Exchange", (void (TopLoc_IndexedMapOfLocation::*)(TopLoc_IndexedMapOfLocation &)) &TopLoc_IndexedMapOfLocation::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopLoc_IndexedMapOfLocation.def("Assign", (TopLoc_IndexedMapOfLocation & (TopLoc_IndexedMapOfLocation::*)(const TopLoc_IndexedMapOfLocation &)) &TopLoc_IndexedMapOfLocation::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopLoc_IndexedMapOfLocation.def("assign", (TopLoc_IndexedMapOfLocation & (TopLoc_IndexedMapOfLocation::*)(const TopLoc_IndexedMapOfLocation &)) &TopLoc_IndexedMapOfLocation::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopLoc_IndexedMapOfLocation.def("ReSize", (void (TopLoc_IndexedMapOfLocation::*)(const Standard_Integer)) &TopLoc_IndexedMapOfLocation::ReSize, "ReSize", py::arg("N"));
	cls_TopLoc_IndexedMapOfLocation.def("Add", (Standard_Integer (TopLoc_IndexedMapOfLocation::*)(const TopLoc_Location &)) &TopLoc_IndexedMapOfLocation::Add, "Add", py::arg("theKey1"));
	cls_TopLoc_IndexedMapOfLocation.def("Contains", (Standard_Boolean (TopLoc_IndexedMapOfLocation::*)(const TopLoc_Location &) const ) &TopLoc_IndexedMapOfLocation::Contains, "Contains", py::arg("theKey1"));
	cls_TopLoc_IndexedMapOfLocation.def("Substitute", (void (TopLoc_IndexedMapOfLocation::*)(const Standard_Integer, const TopLoc_Location &)) &TopLoc_IndexedMapOfLocation::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_TopLoc_IndexedMapOfLocation.def("Swap", (void (TopLoc_IndexedMapOfLocation::*)(const Standard_Integer, const Standard_Integer)) &TopLoc_IndexedMapOfLocation::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TopLoc_IndexedMapOfLocation.def("RemoveLast", (void (TopLoc_IndexedMapOfLocation::*)()) &TopLoc_IndexedMapOfLocation::RemoveLast, "RemoveLast");
	cls_TopLoc_IndexedMapOfLocation.def("RemoveFromIndex", (void (TopLoc_IndexedMapOfLocation::*)(const Standard_Integer)) &TopLoc_IndexedMapOfLocation::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TopLoc_IndexedMapOfLocation.def("RemoveKey", (Standard_Boolean (TopLoc_IndexedMapOfLocation::*)(const TopLoc_Location &)) &TopLoc_IndexedMapOfLocation::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TopLoc_IndexedMapOfLocation.def("FindKey", (const TopLoc_Location & (TopLoc_IndexedMapOfLocation::*)(const Standard_Integer) const ) &TopLoc_IndexedMapOfLocation::FindKey, "FindKey", py::arg("theKey2"));
	cls_TopLoc_IndexedMapOfLocation.def("__call__", (const TopLoc_Location & (TopLoc_IndexedMapOfLocation::*)(const Standard_Integer) const ) &TopLoc_IndexedMapOfLocation::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TopLoc_IndexedMapOfLocation.def("FindIndex", (Standard_Integer (TopLoc_IndexedMapOfLocation::*)(const TopLoc_Location &) const ) &TopLoc_IndexedMapOfLocation::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TopLoc_IndexedMapOfLocation.def("Clear", [](TopLoc_IndexedMapOfLocation &self) -> void { return self.Clear(); });
	cls_TopLoc_IndexedMapOfLocation.def("Clear", (void (TopLoc_IndexedMapOfLocation::*)(const Standard_Boolean)) &TopLoc_IndexedMapOfLocation::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopLoc_IndexedMapOfLocation.def("Clear", (void (TopLoc_IndexedMapOfLocation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopLoc_IndexedMapOfLocation::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopLoc_IndexedMapOfLocation.def("Size", (Standard_Integer (TopLoc_IndexedMapOfLocation::*)() const ) &TopLoc_IndexedMapOfLocation::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TopLoc_MapOfLocation, std::unique_ptr<TopLoc_MapOfLocation, Deleter<TopLoc_MapOfLocation>>, NCollection_BaseMap> cls_TopLoc_MapOfLocation(mod, "TopLoc_MapOfLocation", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TopLoc_MapOfLocation.def(py::init<>());
	cls_TopLoc_MapOfLocation.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopLoc_MapOfLocation.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopLoc_MapOfLocation.def(py::init([] (const TopLoc_MapOfLocation &other) {return new TopLoc_MapOfLocation(other);}), "Copy constructor", py::arg("other"));
	cls_TopLoc_MapOfLocation.def("cbegin", (TopLoc_MapOfLocation::const_iterator (TopLoc_MapOfLocation::*)() const ) &TopLoc_MapOfLocation::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopLoc_MapOfLocation.def("cend", (TopLoc_MapOfLocation::const_iterator (TopLoc_MapOfLocation::*)() const ) &TopLoc_MapOfLocation::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopLoc_MapOfLocation.def("Exchange", (void (TopLoc_MapOfLocation::*)(TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("Assign", (TopLoc_MapOfLocation & (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("assign", (TopLoc_MapOfLocation & (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("ReSize", (void (TopLoc_MapOfLocation::*)(const Standard_Integer)) &TopLoc_MapOfLocation::ReSize, "ReSize", py::arg("N"));
	cls_TopLoc_MapOfLocation.def("Add", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_Location &)) &TopLoc_MapOfLocation::Add, "Add", py::arg("K"));
	cls_TopLoc_MapOfLocation.def("Added", (const TopLoc_Location & (TopLoc_MapOfLocation::*)(const TopLoc_Location &)) &TopLoc_MapOfLocation::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TopLoc_MapOfLocation.def("Contains", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_Location &) const ) &TopLoc_MapOfLocation::Contains, "Contains", py::arg("K"));
	cls_TopLoc_MapOfLocation.def("Remove", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_Location &)) &TopLoc_MapOfLocation::Remove, "Remove", py::arg("K"));
	cls_TopLoc_MapOfLocation.def("Clear", [](TopLoc_MapOfLocation &self) -> void { return self.Clear(); });
	cls_TopLoc_MapOfLocation.def("Clear", (void (TopLoc_MapOfLocation::*)(const Standard_Boolean)) &TopLoc_MapOfLocation::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopLoc_MapOfLocation.def("Clear", (void (TopLoc_MapOfLocation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopLoc_MapOfLocation::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopLoc_MapOfLocation.def("Size", (Standard_Integer (TopLoc_MapOfLocation::*)() const ) &TopLoc_MapOfLocation::Size, "Size");
	cls_TopLoc_MapOfLocation.def("IsEqual", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &) const ) &TopLoc_MapOfLocation::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("Contains", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &) const ) &TopLoc_MapOfLocation::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("Union", (void (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &, const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TopLoc_MapOfLocation.def("Unite", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("HasIntersection", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &) const ) &TopLoc_MapOfLocation::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TopLoc_MapOfLocation.def("Intersection", (void (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &, const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TopLoc_MapOfLocation.def("Intersect", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("Subtraction", (void (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &, const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TopLoc_MapOfLocation.def("Subtract", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TopLoc_MapOfLocation.def("Difference", (void (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &, const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TopLoc_MapOfLocation.def("Differ", (Standard_Boolean (TopLoc_MapOfLocation::*)(const TopLoc_MapOfLocation &)) &TopLoc_MapOfLocation::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopLoc_MapOfLocation.hxx

}
