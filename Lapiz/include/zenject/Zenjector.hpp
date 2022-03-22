#pragma once

#include "enum/LocationEnum.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "System/Collections/Generic/IEnumerable_1.hpp"
#include "Zenject/IInstaller.hpp"

namespace lapiz::zenject {
    class Zenjector {
      public:
        /// @brief Installs a custom installer alongside custom type.
        /// @tparam TCustomInstaller Your installer class. Required for this to work.
        /// @tparam TCustomType A custom type to make Garbage Collection not cause potential Null pointer dereferences unnecessarily.
        /// @param location Required to install something to the DiContainer location.
        template<class TCustomInstaller, class TCustomType>
        requires (std::is_convertible_v<TCustomInstaller, Zenject::IInstaller>, std::is_convertible_v<TCustomType, Zenject::IInstaller>)
        static void Install(zenject::Location location) {
            std::unordered_set < Il2CppClass * > installerTypes = zenject::getInstallerForLocation(location);
        };

        /// @brief Install bindings to a custom location with a backing installer(s).
        static void Install(zenject::Location location, std::function<void(Zenject::DiContainer*)> installCallback) {
            std::unordered_set < Il2CppClass * > installerTypes = zenject::getInstallerForLocation(location);
        };

        /// @brief Install bindings to another installer without a custom installer
        template<class TKey>
        void UseMetadataBinder(TKey) {

        };

        /// @brief Lets you use Lapiz' HTTP service system. Not implemented, nor used currently.
        void UseHttpService() {

        };

        /// @brief Makes it possible for Quest mods to sync to an external service, like GitHub. Not implemented, nor used currently.
        void UseLapizSync() {

        };
    };
}
